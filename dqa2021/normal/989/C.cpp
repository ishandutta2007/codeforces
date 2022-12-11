#include<cstdio>
char ans[60][60];
int a,b,c,d;
int main()
{
	int x,y;
	puts("50 50");
	for (int i=1;i<=25;i++)
	{
		for (int j=1;j<=25;j++) ans[i][j]='a';
		for (int j=26;j<=50;j++) ans[i][j]='b';
	}
	for (int i=26;i<=50;i++)
	{
		for (int j=1;j<=25;j++) ans[i][j]='c';
		for (int j=26;j<=50;j++) ans[i][j]='d';
	}
	scanf("%d%d%d%d",&a,&b,&c,&d);a--;b--;c--;d--;
	for (x=2,y=2;d--;)
	{
		ans[x][y]='d';
		y+=2;if (y>25) y=2,x+=2;
	}
	for (x=2,y=27;c--;)
	{
		ans[x][y]='c';
		y+=2;if (y>50) y=27,x+=2;
	}
	for (x=27,y=2;b--;)
	{
		ans[x][y]='b';
		y+=2;if (y>25) y=2,x+=2;
	}
	for (x=27,y=27;a--;)
	{
		ans[x][y]='a';
		y+=2;if (y>50) y=27,x+=2;
	}
	for (int i=1;i<=50;i++,putchar('\n'))
		for (int j=1;j<=50;j++)
			putchar(ans[i][j]);
	return 0;
}