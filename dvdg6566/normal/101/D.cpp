#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MAXN = 100100;
const ll INF = 1e10;

vpi V[MAXN];
ll N,a,b,w;
ll cost[MAXN];
ll entry[MAXN];
ll sub[MAXN];
vector<pi> X;

bool cmp(pi a, pi b){
	return a.f*b.s < b.f*a.s;
}

void dfs(int x, int p){
	sub[x] = 1;
	if (x!=1&&SZ(V[x]) == 1){
		cost[x] = entry[x] = 0;
		return;
	}

	ll totcost = 0;

	for (auto v:V[x])if(v.f!=p){
		dfs(v.f,x);
		sub[x] += sub[v.f];
		totcost += cost[v.f]+v.s*sub[v.f];
		entry[x] = entry[x] + v.s*2 + entry[v.f];
	}

	X.clear();
	for (auto v:V[x])if(v.f!=p){
		X.pb(mp(entry[v.f]+v.s*2, sub[v.f]));
	}

	sort(ALL(X), cmp);
	ll run=0;
	for (auto v:X){
		// cout<<v.f<<' '<<v.s<<'\n';
		totcost += v.s*run;
		run += v.f;
	}
	// cout<<x<<' '<<entry[x]<<' '<<totcost<<'\n';
	cost[x] = totcost;
}

int main(){
	cin>>N;
	for (int i=1;i<N;++i){
		cin>>a>>b>>w;
		V[a].pb(b,w);
		V[b].pb(a,w);
	}
	dfs(1,-1);
	printf("%.9lf", (double)cost[1] / (N-1));
}