#include<cstdio>
int f[10][10];
int main()
{
	int i,j,x,y,ans=-1;char s[3];
	for(i=1;i<9;i++)for(j=1;j<9;j++)f[i][j]=1;
	scanf("%s",&s);
	x=s[0]-'a';y=s[1]-'1';
	for(i=x;i<x+3;i++)for(j=y;j<y+3;j++)ans+=f[i][j];
	printf("%d",ans);
}