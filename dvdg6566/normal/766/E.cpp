#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define MAXN 5000000

vi centroids;

struct CentDecomp{
	ll N;
	vi sub, ban, par;
	vector<vi> V;
	CentDecomp(ll _N):N(_N){
		sub.resize(N+1,0);
		ban.resize(N+1,-1);
		par.resize(N+1,0);
		V.resize(N+1);
	}
	void build (ll u, ll p, ll l){
		ll sz = dfs1(u,p,l);
		ll cent = dfs2(u,p,sz);
		if (p == -1)p = cent;
		par[cent] = p;
		ban[cent] = l++;
		centroids.pb(cent);
		for (auto v : V[cent])if (ban[v] == -1){
			build(v,u,l);
		}
	}
	ll dfs1(ll u, ll p,ll l){
		sub[u] = 1;
		for (auto v:V[u])if(v!=p && ban[v] == -1){
			sub[u] += dfs1(v,u,l);
		}
		return sub[u];
	}
	ll dfs2(ll u, ll p, ll n){
		for (auto v : V[u])if (ban[v] == -1 && v != p){
			if (sub[v] > n/2)return dfs2(v,u,n);
		}
		return u;
	}
}*G;

ll N,a,b;
ll A[MAXN];
ll D[MAXN];

vi cur,loc;
ll GL[MAXN],CL[MAXN];
ll MAXL = 20;

void dfs(ll x, ll p, ll l){
	cur.pb(x);
	loc.pb(x);
	// cout<<"Node "<<x<<" xor "<<D[x]<<'\n';
	for (auto v : G->V[x]){
		if (G->ban[v] <= l)continue;
		if (v == p)continue;
		D[v] = A[v] ^ D[x];
		dfs(v,x,l);
	}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	for (ll i=1;i<=N;++i)cin>>A[i];
	G = new CentDecomp(N);

	for (ll i=1;i<N;++i){
		cin>>a>>b;
		G->V[a].pb(b);
		G->V[b].pb(a);
	}

	G->build(1,-1,1);
	ll ans = 0;

	for (auto v : centroids){
		cur.clear();
		ll l = G->ban[v];
		for (auto u : G->V[v])if (G->ban[u] > l){
			loc.clear();
			D[u] = A[u];
			dfs(u,v,l);
			for (ll i=0;i<MAXL;++i){
				ll z = 0;
				ll o = 0;
				for (auto l : loc){
					// cout<<l<<' '<<D[l]<<'\n';
					if ((1<<i) & D[l])++o;
					else ++z;
				}
				ll t = z*o;
				if ((1<<i) & A[v])t = ((z+o) * (z+o-1))/2 - t;
				ans -= (t<<i);
				// if(t)cout<<"Rmv "<<(t<<i)<<'\n';
			}
		}
		for (ll i=0;i<MAXL;++i){
			ll z = 0;
			ll o = 0;
			for (auto l : cur){
				if ((1<<i) & D[l])++o;
				else ++z;
			}
			ll t = z*o;
			if ((1<<i) & A[v])t = ((z+o) * (z+o-1))/2 - t;
			ans += (t<<i);
			// if(t)cout<<"Add "<<(t<<i)<<'\n';
		}
		for (auto i : cur){
			ans += D[i]^A[v];
		}
		ans += A[v];
		for (auto i : cur)D[i] = 0;
		// cout<<v<<' '<<ans<<'\n';
	}
	cout<<ans<<'\n';
}