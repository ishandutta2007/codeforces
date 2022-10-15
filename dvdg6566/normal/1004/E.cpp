#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define MAXN 100100
#define MAXL 18
ll INF =1e18;
 
ll N,K,Q,a,b,w;
ll dst[MAXN];
ll p[MAXN][MAXL];
ll low[MAXN],depth[MAXN];
vpi V[MAXN];
ll topar[MAXN];
vpi vert;
vpi ones;
 
void dfs(ll x, ll pa){
	for (auto v : V[x])if (v.f != pa){
		// cerr<<v.f<<'\n';
		p[v.f][0]=x;
		dst[v.f] = dst[x]+v.s;
		depth[v.f]=depth[x]+1;
		topar[v.f]=v.s;
		dfs(v.f,x);
		low[x] = max(low[x],low[v.f]+v.s);
	}
}
 
ll lca(ll a, ll b){
	if (a==b)return a;
	if (depth[a] > depth[b])swap(a,b);
	ll h=depth[b]-depth[a];
	for (ll i=0;i<MAXL;++i)if ((1<<i & h) > 0){
		b = p[b][i];
	}
	if (a==b)return a;
	for (ll i=MAXL-1;i>=0;--i){
		if (p[a][i] == p[b][i])continue;
		a=p[a][i];b=p[b][i];
	}
	return p[a][0];
}
 
ll fp(ll x, ll h){
	if (depth[x] <= h)return 1;
	for (ll i=0;i<MAXL;++i)if ((1<<i & h) > 0){
		x = p[x][i];
	}
	return x;
}
 
ll is_par(ll x, ll y){
	int l=lca(x,y);
	return (l==x)||(l==y); // Y is a parent
}

ll dfs2(int x, int p){
	ll m=0;
	for (auto v:V[x])if(v.f!=p){
		m=max(m, v.s + dfs2(v.f,x));
	}
	return m;
}

ll find_dst(int x){
	if (x == 1){
		return 0;
	}
	return dfs2(p[x][0], x) + topar[x];
}
 
bool query(ll x){
	ll a=-1;
	ll b=-1;
	for (auto i : vert){
		int t=i.s;
		if (low[t] <= x && low[t] + topar[t] > x){
			// cout<<t<<'\n';
			if (a == -1){
				a=t;
				continue;
			}else if (b != -1){
				if (is_par(t,a) || is_par(t,b)){
					continue;
				}else return 0;
			}else{
				if (is_par(t,a))continue;
				else b=t;
			}
		}
	}

	if (a == -1)return 1;
	if (b == -1){
		ll cp = fp(a,K-1);
		if (find_dst(cp) > x)return 0;
		else return 1;
	}

	ll cp = lca(a,b);
	ll d=find_dst(cp);
	
	ll newk = depth[a] + depth[b] - 2*depth[cp] + 1;

	if (newk > K)return 0;
	if (d > x)return 0;
 	return 1;
}
 
int main(){
	// freopen("in.txt","r",stdin);
	cin>>N>>K;
	for (ll i=1;i<N;++i){
		cin>>a>>b>>w;
		V[a].pb(mp(b,w));
		V[b].pb(mp(a,w));
	}
 
	memset(p,-1,sizeof(p));
	dfs(1,0);
 
	for (ll i=1;i<MAXL;++i){
		for (ll j=2;j<=N;++j){
			if (p[j][i-1] != -1)p[j][i] = p[p[j][i-1]][i-1];
		}
	}
 
	for (ll i=1;i<=N;++i){
		vert.pb(mp(depth[i],i));
	}
 
	sort(ALL(vert));
	reverse(ALL(vert));
	// cout<<query(14);
	// return 0;
	// for (auto v : vert)cout<<v.s<<' ';
	// for (ll i=1;i<=20;++i)cout<<query(i)<<'\n';
	ll low=0;
	ll high=1e9;
	while (high>low+1){
		ll mid=(low+high)/2;
		if (query(mid))high=mid;
		else low=mid+1;
	}
	if (query(low))cout<<low;
	else cout<<high;
}