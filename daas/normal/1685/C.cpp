#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
const int MAXN=1e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,pre[MAXN*2];
char s[MAXN*2];
int main()
{
	T=read();
	while(T--)
	{
		n=read()*2;
		scanf("%s",s+1);
		for(int i=1;i<=n;++i)
			if(s[i]=='(') pre[i]=pre[i-1]+1;
			else pre[i]=pre[i-1]-1;
		int flag=0;
		for(int i=1;i<=n;++i) if(pre[i]<0) flag=1;
		if(!flag) {puts("0");continue;}
		int l=1; while(pre[l]>=0) ++l;
		int r=n; while(pre[r]>=0) --r;
		int maxn=0;
		for(int i=l;i<=r;++i) maxn=max(maxn,pre[i]);
		int bjr=r,bjl=l-1;
		for(int i=1;i<l;++i) if(pre[i]>pre[bjl]) bjl=i;
		for(int i=r;i<=n;++i) if(pre[i]>pre[bjr]) bjr=i;
		if(pre[bjr]-maxn+pre[bjl]>=0)
		{
			puts("1");
			printf("%d %d\n",bjl+1,bjr);
			continue;
		}
		int bj=1;
		for(int i=1;i<=n;++i) if(pre[i]>pre[bj]) bj=i;
		puts("2");
		printf("1 %d\n",bj);
		printf("%d %d\n",bj+1,n);
	}
	return 0;
}
//ore no turn,draw!