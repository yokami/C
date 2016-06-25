#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int GetRandom(int min,int max);
int GetRandom(int min,int max)
{
	return min+(int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}
int main()
{
        int a,b,c,i,sum,sumA=0,sumB=0,sumC=0;
	srand((unsigned int)time(NULL));
	for(i=0;i<5;i++)
	{
	c=GetRandom(1,5);
	printf("自分の出す数字は%dです。\n",c);
	printf("A君の出した数字を入力\n");
        scanf("%d",&a);
	printf("B君の出した数字を入力\n");
	scanf("%d",&b);
	sum=a+b+c;
	if(a>b&&a>c){printf("A君の勝ちです！！\n");sumA+=sum;}
	if(b>a&&b>c){printf("B君の勝ちです！！\n");sumB+=sum;}
	if(c>a&&c>b){printf("自分の勝ちです！！\n");sumC+=sum;}
	if(a==b&&a>c){printf("A君とB君が上位で同じ数のため、自分が%d+%d+%d=%d\n点獲得\n",a,b,c,sum);sumC+=sum;}
	if(a==c&&a>b){printf("A君と自分が上位で同じ数のため、B君が%d+%d+%d=%d\n点獲得\n",a,c,b,sum);sumB+=sum;}
	if(b==c&&b>a){printf("B君と自分が上位で同じ数のため、A君が%d+%d+%d=%d\n点獲得\n",b,c,a,sum);sumA+=sum;}
	if(a==b&&b==c)printf("同じ数のため、全員0点\n");
	printf("(%d回戦)\n",i+1);
	printf("A君:%d点,B君:%d点,自分:%d点\n",sumA,sumB,sumC);
	}
}
//三人で対戦するゲーム
//１～５の数字を自分の手札として持っている
//自分のプログラムがどれかの数字を出力して相手に伝える
//自分以外の相手二人が伝えてきた数字をscanfで自分のプログラムに入力する
//自分と相手二人の出した数字の大きさを比較し一番大きい数を出した方が勝ちとなり、全員の数字を自分の点数にできる
//三人が同じ数を出した場合は、三人ともに得点０
//上位二人が同じ数を出した場合は、残りの一人がラッキーで点数獲得
