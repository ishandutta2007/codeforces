#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<pi> vpi;
typedef set<ll> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e9;
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()
#define MAXN 100100
#define MAXL 17

ll N,L,S,a,b;
ll val[MAXN];
ll dst[MAXN], p[MAXN][MAXL], depth[MAXN];
ll MAXH[MAXN];
vi V[MAXN];

void dfs(ll x){
	for (auto v : V[x]){
		dst[v]=dst[x]+val[v];
		depth[v]=depth[x]+1;
		dfs(v);
	}
}

ll fmax(ll t){
	ll x = t;
	for (ll i=MAXL-1;i>=0;--i){
		if (p[t][i] == -1)continue;
		ll l = p[t][i];
		ll d = dst[x] - dst[l] + val[l];
		// cout<<"From "<<l<<" to "<<x<<" distance "<<d<<'\n';
		if (d <= S){
			t = p[t][i];
		}
	}
	return depth[x]-depth[t]+1;
}

ll ans=0;
ll dfs2(ll x){
	if (SZ(V[x]) == 0){ans++;return MAXH[x];}
	ll p=-1;
	for (auto v: V[x]){
		p = max(p,dfs2(v)-1);
	}
	if (p == 0){
		// Add new node
		++ans;
		p = MAXH[x];
	}
	return p;
}

int main(){
	// freopen("in.txt","r",stdin);
	cin>>N>>L>>S;
	for (ll i=1;i<=N;++i){
		cin>>val[i];
		if (val[i] > S){
			cout<<-1;
			return 0;
		}
	}
	memset(p,-1,sizeof(p));
	for (ll i=2;i<=N;++i){
		cin>>a;
		p[i][0]=a;
		V[a].pb(i);
	}
	dst[1]=val[1];
	dfs(1);

	for (ll i=1;i<MAXL;++i){
		for (ll j=2;j<=N;++j){
			if (p[j][i-1] != -1)p[j][i] = p[p[j][i-1]][i-1];
		}
	}
	for (ll i=2;i<=N;++i){
		ll h=fmax(i);
		MAXH[i] = min(h,L);
		// cout<<MAXH[i]<<' ';
	}
	dfs2(1);
	cout<<ans;
}