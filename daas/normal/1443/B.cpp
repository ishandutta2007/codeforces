#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
int read()
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
int T,A,B,n,mem[100001][2],cnt,cost[100001];
char s[100001];
int main()
{
	T=read();
	while(T--)
	{
		A=read(),B=read();
		scanf("%s",s);
		n=strlen(s);
		cnt=0;
		for(int l=1,r;l<=n;l=r+1)
		{
			r=l;
			while(r+1<=n && s[l-1]==s[r])
				++r;
			if(s[l-1]=='1')
				mem[++cnt][0]=l,mem[cnt][1]=r;
		}
		if(!cnt)
		{
			puts("0");
			continue;
		}
		if(cnt==1)
		{
			printf("%d\n",A);
			continue;
		}
		for(int i=2;i<=cnt;++i)
			cost[i-1]=mem[i][0]-mem[i-1][1]-1;
		sort(cost+1,cost+cnt);
		int ans=cnt*A;
		for(int i=1;i<cnt;++i)
		{
			if(cost[i]*B>=A)
				break;
			ans+=cost[i]*B-A;
		}
		printf("%d\n",ans);
	}
	return 0;
}