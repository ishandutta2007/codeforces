#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define MAXN 200010

ll val[MAXN];
vi V[MAXN];
ll desc[MAXN];
ll d2[MAXN];
ll ans[MAXN];
ll N,a,b;

void dfs1(int x, int p){
	if (SZ(V[x]) == 1 && x != 1){
		ans[x] = 0;
		desc[x] = val[x];
		return;
	}
	desc[x] += val[x];
	for (auto v : V[x])if(v!=p){
		dfs1(v,x);
		desc[x] += desc[v];
		ans[x] += (desc[v]+ans[v]);
	}
}

void dfs2(int x, int p){
	for (auto v : V[x])if(v!=p){
		d2[v] = desc[1] - desc[v];
		ans[v] = ans[x] - (desc[v]) + d2[v];
		dfs2(v,x);
	}
}

int main(){
	// freopen("in.txt","r",stdin);
	cin>>N;
	for (int i=1;i<=N;++i)cin>>val[i];
	for (int i=1;i<N;++i){
		cin>>a>>b;
		V[a].pb(b);
		V[b].pb(a);
	}
	dfs1(1,0);
	// for (int i=1;i<=N;++i)cout<<desc[i]<<' '<<ans[i]<<'\n';
	// cout<<'\n';
	dfs2(1,0);
	cout<<*max_element(ans+1,ans+N+1);
	// for (int i=1;i<=N;++i)cout<<d2[i]<<' '<<ans[i]<<'\n';
}