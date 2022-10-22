#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500005;
const ll mod=998244353;
int n,m;
map<ll,ll> mp;
ll gcd(ll a,ll b){
	if(!b) return a;
	return gcd(b,a%b);
}
ll p[N];
ll c[N],a[N];
vector<int> g[N];
int main(){
	int i,j;
	int T;scanf("%d",&T);
	p[0]=1;
	for(i=1;i<N;i++) p[i]=p[i-1]*114515;
	while(T--){
		mp.clear();
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) scanf("%I64d",&a[i]);
		for(i=1;i<=n;i++) c[i]=0,g[i].clear();
		for(i=1;i<=m;i++){
			int x,y;scanf("%d%d",&x,&y);
			g[x].push_back(y);
		}
		for(i=1;i<=n;i++){
			sort(g[i].begin(),g[i].end());
			g[i].resize(unique(g[i].begin(),g[i].end())-g[i].begin());
			for(auto v:g[i]) c[v]+=p[i];
		}
		for(i=1;i<=n;i++) mp[c[i]]+=a[i];
		map<ll,ll>::iterator it;
		ll ans=0;
		for(it=mp.begin();it!=mp.end();it++)
			if(it->first){
			//	cout<<(it->second)<<endl;
				ans=gcd(ans,(it->second));
			}
		printf("%I64d\n",ans);
	}
	return 0;
}