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
int n,q,a[MAXN],lim[MAXN];
double dp[MAXN][110],ans;
int main()
{
	n=read();
	for(int i=1;i<=n;++i) a[i]=lim[i]=read(),dp[i][a[i]]=1,ans+=dp[i][0];
	q=read();
	while(q--)
	{
		int u=read(),v=read(),K=read();
		ans-=dp[u][0];
		int tmp=a[u];
		a[u]-=K;
		a[v]+=K;
		while(K--)
		{
			for(int i=0;i<=lim[u];++i)
				dp[u][i]=dp[u][i]*(tmp-i)/tmp+dp[u][i+1]*(i+1)/tmp;
			--tmp;
		}
		ans+=dp[u][0];
		printf("%.12lf\n",ans);
	}
	return 0;
}
//ore no turn,draw