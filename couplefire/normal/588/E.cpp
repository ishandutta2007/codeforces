#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define Foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define rof(i,a,b) for(int (i)=(a);(i) > (b); --(i))
#define rep(i, c) for(auto &(i) : (c))
#define x first
#define y second
#define pb push_back
#define PB pop_back()
#define iOS ios_base::sync_with_stdio(false)
#define sqr(a) (((a) * (a)))
#define all(a) a.begin() , a.end()
#define error(x) cerr << #x << " = " << (x) <<endl
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define errop(a) cerr<<#a<<" = ( "<<((a).x)<<" , "<<((a).y)<<" )\n";
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
#define L(x) ((x)<<1)
#define R(x) (((x)<<1)+1)
#define umap unordered_map
typedef long long ll;
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef complex<double> point;
template <class T>  inline void smax(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smin(T &x,T y){ x = min((x), (y));}
template <typename T> using os =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 1e5 + 100, maxl = 20;
struct myvec{
	int n = 0;
	int a[10] = {};
	inline void pop_back(){if(n)--n;}
	inline int & operator [](const int &x){return a[x];}
	inline int back(){if(n)return a[n-1];return -1;}
	inline void push_back(const int &x){if(n < 10 && x != back())a[n ++] = x;}
	inline int size(){return n;}
	inline bool empty(){return !n;}
}vec[maxn][maxl], ins[maxn];
vi adj[maxn];
int par[maxn][maxl], h[maxn];
inline myvec operator +(myvec &v,myvec &u){
	myvec ans;
	int i = 0, j = 0;
	while(i < v.size() && j < u.size()){
		if(v[i] <= u[j])
			ans.pb(v[i ++]);
		else
			ans.pb(u[j ++]);
	}
	while(i < v.size())
		ans.pb(v[i ++]);
	while(j < u.size())
		ans.pb(u[j ++]);
//	ans.n = unique(ans.a, ans.a + ans.n) - ans.a;
	return ans;
}
inline void dfs(int v = 0, int p = -1){
	par[v][0] = p;
	vec[v][0] = ins[v];
	if(p + 1){
		h[v] = h[p] + 1;
		vec[v][0] = ins[v] + ins[p];
	}
	For(i,1,maxl)
		if(par[v][i-1] + 1){
			par[v][i] = par[par[v][i-1]][i-1];
			vec[v][i] = vec[v][i-1] + vec[par[v][i-1]][i-1];
		}
	rep(u, adj[v])	if(p - u)
		dfs(u, v);
}
inline myvec lca(int v, int u){
	myvec ans = ins[v] + ins[u];
	if(h[v] < h[u])	swap(v, u);
	rof(i,maxl-1,-1)
		if(par[v][i] + 1 && h[par[v][i]] >= h[u]){
			ans = ans + vec[v][i];
			v = par[v][i];
		}
	if(v == u)	return ans;
	rof(i,maxl-1,-1)
		if(par[v][i] - par[u][i]){
			ans = ans + vec[v][i];
			ans = ans + vec[u][i];
			v = par[v][i], u = par[u][i];
		}
	ans = ans + ins[par[v][0]];
	return ans;
}
int n, m, q;
int main(){
	memset(par, -1, sizeof par);
	scanf("%d %d %d", &n, &m, &q);
	For(i,1,n){
		int v, u;
		scanf("%d %d", &v, &u);
		-- v, -- u;
		adj[v].pb(u);
		adj[u].pb(v);
	}
	For(i,1,m + 1){
		int v;
		scanf("%d", &v);
		-- v;
		if((int)ins[v].size() < 10)
			ins[v].pb(i);
	}
	dfs();
	while(q--){
		int v, u, a;
		scanf("%d %d %d", &v, &u, &a);
		-- v, -- u;
		myvec ans = lca(v, u);
		if(ans.size() > a)
			ans.n = a;
		vi vec;
		vec.pb(ans.size());
		For(i,0,ans.size())
			vec.pb(ans[i]);
		For(i,0,vec.size()){
			printf("%d", vec[i]);
			if(i + 1 == vec.size())
				puts("");
			else
				printf(" ");
		}
	}
	return 0;
}