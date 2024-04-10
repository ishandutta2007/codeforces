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
const ll MAXN = 500100;
const ll INF = 1e18;
const ll MOD = 1e9+7;

ll N,a,b,c,d,T,A[MAXN];
ll sum,ans;
ll B[MAXN];
vi V[MAXN];
ll deg[MAXN];
int fail;

pi dfs(int x, int p){
	int odd = 0;
	int even = 0;
	if (SZ(V[x]) == 1)return mp(0,1);
	for (auto v:V[x])if(v!=p){
		pi t = dfs(v,x);
		if (t.f)even=1;
		else odd=1;
	}
	if (odd&&even)fail=1;
	return mp(odd,even);
}

int main(){
	cin>>N;
	for (int i=1;i<N;++i){
		cin>>a>>b;
		V[a].pb(b);
		V[b].pb(a);
		++deg[a];++deg[b];
	}
	int mst=N-1;
	for (int i=1;i<=N;++i)if(deg[i]>1){
		int leafs = 0;
		for (auto v:V[i])if(deg[v]==1)++leafs;
		if (leafs>1){
			mst -= (leafs-1);
		}
	}
	int t=1;
	while (deg[t]==1)++t;
	dfs(t,-1);
	if (fail==1){
		cout<<"3 ";
	}else{
		cout<<"1 ";
	}
	cout<<mst<<'\n';
}