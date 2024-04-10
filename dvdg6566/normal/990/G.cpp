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
#define MAXN 5000000
#define MAXL 22

vi centroids;

struct CentDecomp{
	int N;
	vi sub, ban, par;
	vector<vi> V;
	CentDecomp(int _N):N(_N){
		sub.resize(N+1,0);
		ban.resize(N+1,-1);
		par.resize(N+1,0);
		V.resize(N+1);
	}
	void build (int u, int p, int l){
		int sz = dfs1(u,p,l);
		int cent = dfs2(u,p,sz);
		if (p == -1)p = cent;
		par[cent] = p;
		ban[cent] = l++;
		centroids.pb(cent);
		for (auto v : V[cent])if (ban[v] == -1){
			build(v,u,l);
		}
	}
	int dfs1(int u, int p,int l){
		sub[u] = 1;
		for (auto v:V[u])if(v!=p && ban[v] == -1){
			sub[u] += dfs1(v,u,l);
		}
		return sub[u];
	}
	int dfs2(int u, int p, int n){
		for (auto v : V[u])if (ban[v] == -1 && v != p){
			if (sub[v] > n/2)return dfs2(v,u,n);
		}
		return u;
	}
}*G;

int N,a,b;
int A[MAXN];
int D[MAXN];
vi divisors[MAXN];

int gcd(int a, int b){
	if (a < b)swap(a,b);
	if (b == 0)return a;
	return gcd(b, a%b);
}

vi cur;
int GL[MAXN],CL[MAXN];
ll ans[MAXN];

void dfs(int x, int p, int l){
	GL[D[x]]++;
	if (GL[D[x]] == 1)cur.pb(D[x]);
	ans[D[x]]++;
	// cout<<"Node "<<x<<" gcd "<<D[x]<<'\n';
	for (auto v : G->V[x]){
		if (G->ban[v] <= l)continue;
		if (v == p)continue;
		D[v] = gcd(D[x], A[v]);
		dfs(v,x,l);
	}
}

void dfs2(int x, int p, int l){
	CL[D[x]]++;
	for (auto v : G->V[x]){
		if (G->ban[v] <= l)continue;
		if (v == p)continue;
		dfs2(v,x,l);
	}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	for (int i=1;i<=N;++i)cin>>A[i];
	G = new CentDecomp(N);

	int MAXV = 200000;
	for (int i=1;i<=MAXV;++i){
		for (int j=i;j<=MAXV;j+=i){
			divisors[j].pb(i);
		}
	}

	for (int i=1;i<N;++i){
		cin>>a>>b;
		G->V[a].pb(b);
		G->V[b].pb(a);
	}

	G->build(1,-1,1);

	for (auto v : centroids){
		cur.clear();
		D[v] = A[v];
		int l = G->ban[v];
		dfs(v,-1,l);
		for (auto i : cur){
			ans[i] += (ll)GL[i] * (ll)(GL[i]-1) / 2;
			for (auto j : cur){
				if (j >= i)continue;
				int t = gcd(i,j);
				ans[t] += (ll)GL[i] * (ll)GL[j];
			}
		}

		for (auto u : G->V[v]) {
			if (G->ban[u] <= l)continue;
			dfs2(u,-1,l);
			for (auto i : cur){
				ans[i] += (ll)CL[i] * (ll)(CL[i]-1) / 2;
				for (auto j : cur){
					if (j > i)continue;
					int t = gcd(i,j);
					ans[t] -= (ll)CL[i] * (ll)CL[j];
				}
			}
			for (auto u : cur)CL[u] = 0;
		}
		for (auto u : cur)GL[u] = 0;
	}
	for (int i=0;i<=MAXV;++i)if(ans[i])cout<<i<<' '<<ans[i]<<'\n';
}