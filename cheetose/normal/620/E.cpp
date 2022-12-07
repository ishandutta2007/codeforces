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
#define INF 987654321987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
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
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

Pi p[400001];
int cc,a[400001],r[800001];
Vi v[400001];
void dfs(int N,int pp)
{
	p[N].X=++cc;
	r[cc]=N;
	for(int next:v[N])
	{
		if(next==pp)continue;
		dfs(next,N);
	}
	p[N].Y=++cc;
	r[cc]=N;
}

ll tree[2097152], lazy[2097152];
void init(int node, int S, int E)
{
	if (S == E)
	{
		tree[node] = 1LL<<a[r[S]];
		return;
	}
	init(2 * node, S, (S + E) / 2);
	init(2 * node + 1, (S + E) / 2 + 1, E);
	tree[node] = tree[2 * node] | tree[2 * node + 1];
}
void propagation(int node, int S, int E)
{
	if (lazy[node] != 0)
	{
		tree[node] = 1LL<<lazy[node];
		if (S != E)
		{
			lazy[2 * node] = lazy[node];
			lazy[2 * node + 1] = lazy[node];
		}
		lazy[node] = 0;
	}
}
void upd(int node, int S, int E, int i, int j, int val)
{
	propagation(node, S, E);
	if (i > E || j < S) return;
	if (j >= E && i <= S)
	{
		tree[node] = 1LL<<val;
		if (S != E)
		{
			lazy[node * 2] = val;
			lazy[node * 2 + 1] = val;
		}
		return;
	}
	upd(2 * node, S, (S + E) / 2, i, j, val);
	upd(2 * node + 1, (S + E) / 2 + 1, E, i, j, val);
	tree[node] = tree[2 * node] | tree[2 * node + 1];
}
ll find(int node, int S, int E, int i, int j)
{
	propagation(node, S, E);
	if (i > E || j < S) return 0;
	if (j >= E && i <= S) return tree[node];
	return find(node * 2, S, (S + E) / 2, i, j) | find(2 * node + 1, (S + E) / 2 + 1, E, i, j);
}
inline int cnt(ll x){return bitset<64>(x).count();}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	fup(i,1,n,1)scanf("%d",a+i);
	fup(i,2,n,1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1,-1);
	init(1,1,cc);
	while(m--)
	{
		int o,x,y;
		scanf("%d",&o);
		if(o==1)
		{
			scanf("%d%d",&x,&y);
			upd(1,1,cc,p[x].X,p[x].Y,y);
		}
		else
		{
			scanf("%d",&x);
			printf("%d\n",cnt(find(1,1,cc,p[x].X,p[x].Y)));
		}
	}
}