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
int q,n,lim,T,dp[MAXN],a[MAXN],b[MAXN];
int main()
{
	q=read(),n=read(),lim=read(),T=read();
	while(q--)
	{
		for(int i=1;i<=n;++i) a[i]=b[i]=read();
		sort(b+1,b+n+1);
		int cnt=unique(b+1,b+n+1)-b-1;
		if(T>=cnt) {printf("%d\n",cnt);continue;}
		memset(dp,0,sizeof(dp));
		for(int p=1;p<=T;++p)
		{
			for(int i=1;i<=n;++i)
			{
				int v=dp[a[i]-1]+1;
				int cur=a[i];
				while(v>dp[cur] && cur<=lim) dp[cur]=v,++cur;
			}
		}
		int ans=0;
		for(int i=1;i<=lim;++i) ans=max(ans,dp[i]);
		printf("%d\n",ans);
	}
	return 0;
}
//ore no turn,draw!