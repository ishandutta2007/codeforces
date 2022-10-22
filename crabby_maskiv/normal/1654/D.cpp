#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2e5+5;
const int mod=998244353;
int n,m;
inline int po(int x,int k){
	int res=1;
	while(k){
		if(k&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		k>>=1;
	}
	return res;
}
struct edge{
	int v,x,y;
	inline edge(int v,int x,int y):v(v),x(x),y(y){}
};
vector<edge> g[N];
map<int,int> mp[N];
int sum[N],a[N],b[N],inv[N];
bool np[N];
int pri[N],tot;
int d[N];
void euler(){
	for(int i=2;i<N;i++){
		if(!np[i]){
			pri[++tot]=i;
			d[i]=i;
		}
		for(int j=1;j<=tot;j++){
			if(i*pri[j]>=N) break;
			np[i*pri[j]]=1;
			d[i*pri[j]]=pri[j];
			if(i%pri[j]==0) break;
		}
	}
}
void dfs(int u,int fa){
	sum[u]=0;
	a[u]=1;
	int son=0;
	for(auto e:g[u]){
		int v=e.v,x=e.x,y=e.y;
		if(v==fa) continue;
		dfs(v,u);
		b[v]=a[v];
		int t=y;
		while(t>1){
			if(mp[v][d[t]]){
				mp[v][d[t]]--;
				b[v]=1ll*b[v]*inv[d[t]]%mod;
			}
			t/=d[t];
		}
		t=x;
		while(t>1){
			mp[v][d[t]]++;
			b[v]=1ll*b[v]*d[t]%mod;
			t/=d[t];
		}
		if(mp[v].size()>mp[son].size()) son=v;
	}
	swap(mp[son],mp[u]);
	a[u]=b[son];
	for(auto e:g[u]){
		int v=e.v,x=e.x,y=e.y;
		if(v==fa||v==son) continue;
		for(auto o:mp[v]){
			int t=mp[u][o.fr];
			if(o.sc>t){
				a[u]=1ll*a[u]*po(o.fr,o.sc-t)%mod;
				mp[u][o.fr]=o.sc;
			}
		}
		mp[v].clear();
	}
	for(auto e:g[u]){
		int v=e.v,x=e.x,y=e.y;
		if(v==fa) continue;
		b[v]=1ll*a[u]*inv[x]%mod*y%mod;
		sum[v]=1ll*sum[v]*b[v]%mod*po(a[v],mod-2)%mod;
		sum[u]=(sum[u]+sum[v])%mod;
	}
	sum[u]=(sum[u]+a[u])%mod;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	euler();
	int i,j;
	inv[1]=1;b[0]=1;
	for(i=2;i<N;i++) inv[i]=ll(mod-mod/i)*inv[mod%i]%mod;
	int _;cin>>_;
	while(_--){
		cin>>n;
		for(i=1;i<n;i++){
			int u,v,x,y;cin>>u>>v>>x>>y;
			int f=__gcd(x,y);
			x/=f;y/=f;
			g[u].push_back(edge(v,x,y));
			g[v].push_back(edge(u,y,x));
		}
		dfs(1,0);
		cout<<sum[1]<<endl;
		for(i=1;i<=n;i++){
			sum[i]=a[i]=0;
			g[i].clear();
			mp[i].clear();
		}
	}
	return 0;
}