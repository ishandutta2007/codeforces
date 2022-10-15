#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb emplace_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define INF 1000000000
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define MAXN 500110
ll MOD = 1e9+7;

int N,a,b;
vi V[MAXN];
vi out;

void dfs(int x, int p){
	for (auto v:V[x])if(v!=p){
		out.pb(v);
	}
	out.pb(x);
	reverse(ALL(V[x]));
	for (auto v:V[x])if(v!=p){
		dfs(v,x);
	}
}

pi ans[MAXN];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	for (int i=1;i<N;++i){
		cin>>a>>b;
		V[a].pb(b);
		V[b].pb(a);
	}
	out.pb(1);
	dfs(1,-1);
	for (int i=0;i<2*N;++i){
		int t = out[i];
		if (ans[t].f == 0)ans[t].f=i+1;
		else ans[t].s=i+1;
	}
	for (int i=1;i<=N;++i)cout<<ans[i].f<<' '<<ans[i].s<<'\n';
}