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
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,ans=1e9,pd[10];
ll a[10],val[10];
vector<ll> fac[10];
int calc(ll tmp,int k)
{
	int bck=0;
	for(int i=0;i<(int)fac[k].size();++i)
	{
		while(tmp%fac[k][i]==0) tmp/=fac[k][i],++bck;
	}
	return bck;
}
void solve()
{
	int bck=n;
	for(int i=1;i<=n;++i)
	{
		int v=calc(val[i],i);
		if(v==1 && !pd[i]) continue;
		bck+=v;
	}
	if(pd[0]!=1) ++bck;
	ans=min(ans,bck);
}
void dfs(int k)
{
	if(k==n+1) {solve();return;}
	for(int i=0;i<k;++i)
	{
		if(val[i]%a[k]) continue;
		val[i]/=a[k];
		++pd[i];
		dfs(k+1);
		--pd[i];
		val[i]*=a[k];
	}
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	for(int i=1;i<=n;++i)
	{
		ll tmp=a[i];
		for(int j=2;j<=sqrt(tmp);++j) if(tmp%j==0)
		{
			while(tmp%j==0) tmp/=j;
			fac[i].push_back(j);
		}
		if(tmp!=1) fac[i].push_back(tmp);
	}
	for(int i=1;i<=n;++i) val[i]=a[i];
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
//ore no turn,draw!