#include <bits/stdc++.h>
#define mk make_pair
using namespace std;
const int N=2005;
typedef long long ll;
const ll MOD=(ll)1e9+7;
const ll inf=(ll)5e18;
const ll inv2=(MOD+1)/2;
typedef pair<ll,ll> pii;

ll q,n,m,a[N],b[N],w[N],ans=0;
ll dis[N][N],d[N];//dis:point  d:edge
vector<pii> v[N];

ll calc(ll e,ll step)
{
	return d[e]+(step-m)*w[e];
}

int main() 
{
	scanf("%lld%lld%lld",&n,&m,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&a[i],&b[i],&w[i]);
		v[a[i]].push_back(mk(b[i],w[i]));
		v[b[i]].push_back(mk(a[i],w[i]));
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m;j++) dis[i][j]=-inf;
	dis[1][0]=0;//pos,step:maxdis
	for(int j=1;j<=m;j++) 
	{
		ll mx=-inf;
		for(int i=1;i<=n;i++)
		{
			for(int e=0;e<(int)v[i].size();e++)
			{
				if(dis[v[i][e].first][j-1]==-inf) continue;
				dis[i][j]=max(dis[i][j],dis[v[i][e].first][j-1]+v[i][e].second);
			}
			mx=max(mx,dis[i][j]);
		}
		ans=(ans+mx)%MOD;
	}
	for(int i=1;i<=m;i++) d[i]=max(dis[a[i]][m],dis[b[i]][m]);//init value,one more step,one more time w[i]
	ll now=m+1;
	//cout<<ans<<endl;
	while(now<=q)
	{
		ll id=-1,mx=-inf;
		for(int i=1;i<=m;i++) 
			if(mx<calc(i,now)) mx=calc(i,now),id=i;
		ll left=now;
		now=q+1;//left,nowid,(step) 
		for(int i=1;i<=m;i++)
		{
			if(w[i]<=w[id]) continue;
			ll tmp=(d[id]-d[i])/(w[i]-w[id])+1+m;//
			now=min(now,tmp); 
		}
		//cout<<left<<" "<<now<<endl;
		ans=(ans+(calc(id,left)+calc(id,now-1))%MOD*(now-left)%MOD*inv2%MOD)%MOD;
	}
	cout<<ans<<endl;
	return 0;
}