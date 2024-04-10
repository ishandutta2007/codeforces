#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset((a),0,sizeof(a))
#define MEM_1(a) memset((a),-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define COMPRESS(a) sort(ALL(a));a.resize(unique(ALL(a))-a.begin())
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef pair<ld, ld> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<ld> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

Vi v[100001];
int parent[100001][17], depth[100001],S[100001],E[100001],cc;
void dfs(int N,int p=-1)
{
	S[N]=++cc;
	parent[N][0]=p;
	for(int next:v[N])
	{
		if(next==p)continue;
		depth[next]=depth[N]+1;
		dfs(next,N);
	}
	E[N]=cc;
}
int LCA(int x, int y)
{
	if (depth[x] < depth[y])swap(x, y);
	int dif = depth[x] - depth[y];
	for (int j = 0; dif > 0; j++)
	{
		if (dif & 1)x = parent[x][j];
		dif >>= 1;
	}

	if (x != y)
	{
		fdn(j,16,0,1)
		{
			if (parent[x][j] != -1 && parent[x][j] != parent[y][j])
			{
				x = parent[x][j];
				y = parent[y][j];
			}
		}
		x = parent[x][0];
	}
	return x;
}
int lca(int r,int x,int y){
	int t1=LCA(r,x),t2=LCA(r,y),t3=LCA(x,y);
	if(depth[t1]<depth[t2])swap(t1,t2);
	if(depth[t1]<depth[t3])swap(t1,t3);
	return t1;
}
ll a[100001], tree[262144], lazy[262144];
void propagation(int node, int S, int E)
{
	if (lazy[node] != 0)
	{
		tree[node] += lazy[node] * (E - S + 1);
		if (S != E)
		{
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}
void upd(int node, int S, int E, int i, int j, ll val)
{
	propagation(node, S, E);
	if (i > E || j < S) return;
	if (j >= E && i <= S)
	{
		lazy[node] += val;
		propagation(node, S, E);
		return;
	}
	upd(2 * node, S, (S + E) / 2, i, j, val);
	upd(2 * node + 1, (S + E) / 2 + 1, E, i, j, val);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}
ll find(int node, int S, int E, int i, int j)
{
	propagation(node, S, E);
	if (i > E || j < S) return 0;
	if (j >= E && i <= S) return tree[node];
	return find(node * 2, S, (S + E) / 2, i, j) + find(2 * node + 1, (S + E) / 2 + 1, E, i, j);
}
int main() {
	int n,q;
	scanf("%d%d",&n,&q);
	fup(i,1,n,1)scanf("%lld",a+i);
	fup(i,1,n-1,1){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1);
	fup(i,1,n,1)upd(1,1,n,S[i],S[i],a[i]);
	fup(j,0,15,1)
		fup(i,1,n,1)
		if (parent[i][j] != -1)
			parent[i][j + 1] = parent[parent[i][j]][j];
	int r=1;
	while(q--){
		int o,u;
		scanf("%d",&o);
		if(o==1){
			scanf("%d",&r);
		}else if(o==2){
			int x,y;
			ll z;
			scanf("%d%d%lld",&x,&y,&z);
			u=lca(r,x,y);
			if(u==r){
				upd(1,1,n,1,n,z);
			}else if(S[r]<=S[u] && E[u]<=E[r]){
				upd(1,1,n,S[u],E[u],z);
			}else if(S[u]<=S[r] && E[r]<=E[u]){
				upd(1,1,n,1,n,z);
				int rr=r;
				fdn(i,16,0,1){
					int tt=parent[rr][i];
					if(tt!=-1 && depth[tt]>depth[u])rr=tt;
				}
				upd(1,1,n,S[rr],E[rr],-z);
			}else{
				upd(1,1,n,S[u],E[u],z);
			}
		}else{
			scanf("%d",&u);
			ll res;
			if(u==r){
				res=find(1,1,n,1,n);
			}else if(S[r]<=S[u] && E[u]<=E[r]){
				res=find(1,1,n,S[u],E[u]);
			}else if(S[u]<=S[r] && E[r]<=E[u]){
				res=find(1,1,n,1,n);
				int rr=r;
				fdn(i,16,0,1){
					int tt=parent[rr][i];
					if(tt!=-1 && depth[tt]>depth[u])rr=tt;
				}
				res-=find(1,1,n,S[rr],E[rr]);
			}else{
				res=find(1,1,n,S[u],E[u]);
			}
			printf("%lld\n",res);
		}
	}
}