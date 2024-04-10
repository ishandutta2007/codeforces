#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MAXN = 100100;
const ll MAXL = 17;

ll N,E,a,b,w,Q;
ll p[MAXN][MAXL];
typedef pair<ll,pi> pii;
vector<pii> extras, edgeList;
vpi V[MAXN];
ll depth[MAXN];
ll dst[MAXN];
ll u[MAXN];
ll par(ll x){return (u[x] == x)?x:u[x] = par(u[x]);}
ll mem[MAXN][43];

void dfs(ll x, ll pa){
	for (auto v:V[x])if(v.f!=pa){
		dst[v.f] = dst[x] + v.s;
		depth[v.f] = depth[x] +1;
		p[v.f][0] = x;
		dfs(v.f,x);
	}
}

ll lca(ll a, ll b){
	if (a==b)return a;
	if (depth[a] > depth[b])swap(a,b);
	ll h=depth[b] - depth[a];
	for (ll i=0;i<MAXL;++i)if((1<<i) & h){
		b = p[b][i];
	}
	if (a==b)return a;
	for (ll i=MAXL-1;i>=0;--i){
		if (p[a][i] != p[b][i]){a=p[a][i];b=p[b][i];}
	}
	assert(p[a][0] == p[b][0]);
	assert(a!=b);
	return p[a][0];
}

ll ask(ll a, ll b){
	return dst[a] + dst[b] - 2*dst[lca(a,b)];
}
priority_queue<pi, vpi, greater<pi>> pq;

void dijkstra(ll x, ll d){
	for (ll i=1;i<=N;++i)mem[i][d] = 10000000000000000LL;
	mem[x][d] = 0;
	pq.emplace(0,x);
	while (SZ(pq)){
		ll c = pq.top().s;
		ll ds = pq.top().f;
		pq.pop();
		if (mem[c][d] != ds)continue;
		for (auto v:V[c]){
			ll nd = ds + v.s;
			if (mem[v.f][d] > nd){
				mem[v.f][d] = nd;
				pq.emplace(nd, v.f);
			}
		}
	}
	// for (int i=1;i<=N;++i)cout<<mem[i][d]<<' ';cout<<'\n';
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>E;
	for (ll i=0;i<E;++i){
		cin>>a>>b>>w;
		edgeList.pb(mp(w, mp(a,b)));
	}
	for (ll i=1;i<=N;++i)u[i]=i;
	sort(ALL(edgeList));
	memset(p,-1,sizeof(p));
	for (auto i : edgeList){
		ll a=i.s.f;
		ll b=i.s.s;
		if (par(a) == par(b)){
			extras.pb(i);
			continue;
		}
		// cout<<a<<' '<<b<<'\n';
		u[par(a)] = par(b);
		V[a].pb(b,i.f);
		V[b].pb(a,i.f);
	}
	assert(SZ(extras) == E-N+1);
	dfs(1,-1);
	for (ll k=1;k<MAXL;++k){
		for (ll i=2;i<=N;++i){
			if (p[i][k-1] != -1)p[i][k] = p[p[i][k-1]][k-1];
		}
	}
	for (auto i:extras){
		ll a=i.s.f;
		ll b = i.s.s;
		V[a].pb(b,i.f);
		V[b].pb(a,i.f);
	}
	for (ll i=0;i<SZ(extras);++i){
		dijkstra(extras[i].s.f, i*2);
		dijkstra(extras[i].s.s, i*2+1);
	}

	cin>>Q;
	while (Q--){
		cin>>a>>b;
		// cout<<a<<' '<<b<<' '<<lca(a,b)<<'\n';
		ll ans = ask(a,b);
		for (ll i=0;i<SZ(extras);++i){
			ll f1 = i*2;
			ll f2 = i*2+1;
			ans = min(ans, extras[i].f+mem[a][f1]+mem[b][f2]);
			ans = min(ans, extras[i].f+mem[b][f1]+mem[a][f2]);
		}
		cout<<ans<<'\n';
	}
}