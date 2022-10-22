#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
inline int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int num[10][8],n,N,flag=-1,map[10][10],ans,a[200001],Past;
char s[200001];
void init()
{
	num[0][1]=num[0][2]=num[0][3]=num[0][5]=num[0][6]=num[0][7]=1;
	num[1][3]=num[1][6]=1;
	num[2][1]=num[2][3]=num[2][4]=num[2][5]=num[2][7]=1;
	num[3][1]=num[3][3]=num[3][4]=num[3][6]=num[3][7]=1;
	num[4][2]=num[4][3]=num[4][4]=num[4][6]=1;
	num[5][1]=num[5][2]=num[5][4]=num[5][6]=num[5][7]=1;
	num[6][1]=num[6][2]=num[6][4]=num[6][5]=num[6][6]=num[6][7]=1;
	num[7][1]=num[7][3]=num[7][6]=1;
	num[8][1]=num[8][2]=num[8][3]=num[8][4]=num[8][5]=num[8][6]=num[8][7]=1;
	num[9][1]=num[9][2]=num[9][3]=num[9][4]=num[9][6]=num[9][7]=1;
	for(int i=0;i<=9;++i)
		for(int j=0;j<=9;++j)
			for(int k=1;k<=7;++k)
				map[i][j]+=(num[i][k] && num[j][k]);
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	init();
	scanf("%s",s);
	n=strlen(s);
	N=n/2;
	for(int i=1;i<=n;++i)
		a[i]=s[i-1]-'0';
	for(int i=1;i<=N;++i)
		ans+=map[a[i]][a[i+N]];
	Past=ans;
	for(int i=n;i>=1;--i)
	{
		for(int j=a[i]+1;j<=9;++j)
			if(i<=N)
			{
				if(ans-map[a[i]][8]+map[j][8]>Past)
				{
					ans+=map[j][8]-map[a[i]][8];
					flag=i;
					a[i]=j;
					break;
				}
			}
			else
			{
				if(ans-map[a[i-N]][a[i]]+map[a[i-N]][j]>Past)
				{
					ans+=map[a[i-N]][j]-map[a[i-N]][a[i]];
					flag=i;
					a[i]=j;
					break;
				}
			}
		if(flag!=-1)
			break;
		if(i<=N)
			ans+=map[8][8]-map[a[i]][8];
		else
			ans+=map[a[i-N]][8]-map[a[i-N]][a[i]];
		a[i]=8;
	}
	if(flag==-1)
	{
		puts("-1");
		return 0;
	}
	for(int i=flag+1;i<=n;++i)
		for(int j=0;j<8;++j)
			if(i<=N)
			{
				if(ans+map[j][8]-map[8][8]>Past)
				{
					ans+=map[j][8]-map[8][8];
					a[i]=j;
					break;
				}
			}
			else
			{
				if(ans+map[a[i-N]][j]-map[a[i-N]][8]>Past)
				{
					ans+=map[a[i-N]][j]-map[a[i-N]][8];
					a[i]=j;
					break;
				}
			}
	for(int i=1;i<=n;++i)
		printf("%d",a[i]);
	putchar('\n');
	return 0;
}