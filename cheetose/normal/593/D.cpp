#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<cstring>
#include<complex>
#include<cmath>
#include<iomanip>
#include<numeric>
#include<algorithm>
#include<list>
#include<functional>
#include<cassert>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 1987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset((a),0,sizeof(a));
#define MEM_1(a) memset((a),-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef pair<double, double> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<double> Vd;
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
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

const ll eps=1e18;
vector<Vll> tree;
vector<Vi> path;
Vi v[200001];
Pi edge[200001];
int sz[200001], depth[200001], parent[200001][18], path_index[200001];
ll cost[200001];
ll mul(ll x,ll y)
{
	if(x==0 || y==0 || x>eps/y)return 0;
	return x*y;
}
void precal(int N, int p)
{
	if (N == 1)depth[N] = 1;
	else depth[N] = 1 + depth[p];
	sz[N] = 1;
	for (int next : v[N])
	{
		if (next == p)continue;
		precal(next, N);
		parent[next][0] = N;
		sz[N] += sz[next];
	}
}
int treesz(int n)
{
	int c = 1;
	while (c < n)c *= 2;
	return c * 2;
}
int LCA(int x, int y)
{
	if (depth[x] < depth[y])swap(x, y);
	int dif = depth[x] - depth[y];
	for (int j = 0; dif > 0; j++)
	{
		if (dif & 1)x = parent[x][j];
		dif /= 2;
	}

	if (x != y)
	{
		for (int j = 17; j >= 0; j--)
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
void HLD(int N)
{
	queue<int> q;
	q.push(N);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		for (int next : v[x])
		{
			if (next == parent[x][0])continue;
			q.push(next);
		}

		if (x == N) continue;

		int p = parent[x][0];

		if (sz[x] * 2 >= sz[p] && p != N)
		{
			int parent_index = path_index[p];
			path[parent_index].push_back(x);
			path_index[x] = parent_index;
		}
		else 
		{
			path_index[x] = path.size();
			path.push_back(vector<int>(2));
			path.back()[0] = p;
			path.back()[1] = x;
		}
	}
}
void make_tree()
{
	for (const auto& P : path)
	{
		int m = P.size();
		tree.push_back(Vll(treesz(m)));
	}
}
ll find(int index, int node, int S, int E, int i, int j)
{
	if (i > E || j < S)return 1;
	if (i <= S && j >= E)return tree[index][node];
	return mul(find(index, 2 * node, S, (S + E) / 2, i, j),find(index, 2 * node + 1, (S + E) / 2 + 1, E, i, j));
}
void tree_upd(int index, int node, int S, int E, int k, ll c)
{
	if (S == E)
	{
		tree[index][node] = c;
		return;
	}
	if (k<=(S + E) / 2)tree_upd(index, 2 * node, S, (S + E) / 2, k, c);
	else tree_upd(index, 2 * node + 1, (S + E) / 2 + 1, E, k, c);
	tree[index][node]=mul(tree[index][node*2],tree[index][node*2+1]);
}
int find_edge(int path_index, int x) {
	int top = path[path_index][0];
	return depth[parent[x][0]] - depth[top];
}
void upd(int x, int y, ll c)
{
	if (parent[x][0] == y) swap(x, y);
	int index = path_index[y];
	int k = find_edge(index, y);
	tree_upd(index, 1, 0, (int)path[index].size() - 2, k, c);
}
ll query2(int x, int y)
{
	if (x == y)return 1;
	if (path_index[x] == path_index[y])
	{
		int index = path_index[x];
		int first = find_edge(index, x) + 1;
		int last = find_edge(index, y);
		return find(index, 1, 0, path[index].size() - 2, first, last);
	}
	int index = path_index[y];
	int top = path[index][0];

	int last = find_edge(index, y);
	return mul(query2(x, top),find(index,1,0,path[index].size()-2,0,last));
}
ll query(int x, int y)
{
	int t = LCA(x, y);
	return mul(query2(t, x), query2(t, y));
}
int main() {
	MEM_1(parent);
	int n,q;
	scanf("%d%d", &n,&q);
	fup(i, 1, n - 1, 1)
	{
		int x, y;
		ll z;
		scanf("%d%d%lld", &x, &y, &z);
		v[x].push_back(y);
		v[y].push_back(x);
		cost[i] = z;
		edge[i] = Pi(x, y);
	}
	precal(1, 0);
	for (int j = 0; j < 17; j++)
		for (int i = 1; i <= n; i++)
			if (parent[i][j] != -1)
				parent[i][j + 1] = parent[parent[i][j]][j];
	HLD(1);
	make_tree();
	fup(i,1,n-1,1)upd(edge[i].X,edge[i].Y,cost[i]);
	while(q--)
	{
		int o,a,b;
		ll c;
		scanf("%d",&o);
		if(o==1)
		{
			scanf("%d%d%lld",&a,&b,&c);
			ll t=query(a,b);
			if(t==0)puts("0");
			else printf("%lld\n",c/t);
		}
		else
		{
			scanf("%d%lld",&a,&c);
			upd(edge[a].X,edge[a].Y,c);
		}
	}
}