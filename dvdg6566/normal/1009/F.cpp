#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
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
#define MAXN 1010000
#define MAXL 18

vi V[MAXN];
int N,a,b;
vi R[MAXN];
pi res[MAXN];

void dfs(int x, int p){
	if (SZ(V[x]) == 1 && x>1){
		res[x] = mp(0,1);
		R[x].pb(1);
		// cout<<"Output for "<<x<<'\n';
		// for (auto i : R[x])cout<<i<<' ';cout<<'\n';
		return;
	}
	// cout<<"Running dsu "<<x<<' '<<p<<'\n';
	int longest=0;
	int ind=-1;
	for (auto v:V[x])if(v!=p){
		dfs(v,x);
		if (longest<SZ(R[v])){
			longest=SZ(R[v]);
			ind=v;
		}
	}
	
	// cout<<"Longest "<<ind<<'\n';

	swap(R[x], R[ind]);
	pi ans = res[ind];
	for (auto v:V[x])if(v!=p&&v!=ind){
		if (res[v].s > ans.s || (res[v].s == ans.s && res[v].f < ans.f))ans = res[v];
		int tmp=SZ(R[x])-1;
		int layer=0;
		for (int i=SZ(R[v])-1;i>=0;--i,--tmp){
			int t = R[v][i];
			R[x][tmp] += t;
			if (R[x][tmp] > ans.s || (R[x][tmp] == ans.s && layer < ans.f)){
				ans.f = layer;
				ans.s = R[x][tmp];
			}
			++layer;
		}
		// if(x==1)cout<<v<<' '<<ans.f<<' '<<ans.s<<'\n';
	}
	// cout<<"Output for "<<x<<'\n';
	// for (auto i : R[x])cout<<i<<' ';cout<<'\n';
	
	++ans.f;
	R[x].pb(1);
	if (ans.s <= 1){
		ans.s=1;
		ans.f=0;
	}
	// cout<<"R array for "<<x<<'\n';
	// for (auto i : R[x])cout<<i<<' ';cout<<'\n';
	res[x] = ans;
}

int main(){
	cin>>N;
	for (int i=1;i<N;++i){
		cin>>a>>b;V[a].pb(b);V[b].pb(a);
	}
	dfs(1,-1);
	for (int i=1;i<=N;++i)cout<<res[i].f<<'\n';
}