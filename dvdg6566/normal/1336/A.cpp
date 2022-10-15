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
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()
const ll MOD = 1e9+7;
const ll INF = 1e18;
const ll MAXN = 200100;
ll T,a,b,c,d,e,f,N,M,E;
ll A[MAXN];
vi V[MAXN];
vi B;
ll dst[MAXN];
ll pa[MAXN];
ll sub[MAXN];
priority_queue<pi> pq;
ll done[MAXN];
ll ans;

void dfs(ll x, ll p){
	ll child=0;
	pa[x] = p;
	sub[x]=1;
	for (auto v:V[x])if(v!=p){
		++child;
		dst[v]=dst[x]+1;
		dfs(v,x);
		sub[x] += sub[v];
	}
	done[x] = child;
	if (child == 0){
		pq.push(mp(dst[x],x));
	}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>T;
	for (ll i=1;i<N;++i){
		cin>>a>>b;
		V[a].pb(b);V[b].pb(a);
	}
	dfs(1,-1);
	for(ll i=0;i<T;++i){
		pi t = pq.top();pq.pop();
		ll n = t.s;
		ll parent = pa[n];
		ans += t.f;
		--done[parent];
		if (done[parent] == 0){
			ll nw = dst[parent] - sub[parent] + 1;
			pq.push(mp(nw,parent));
			// cout<<"Push "<<' '<<parent<<'\n';
		}
	}
	cout<<ans;
}