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
#define INF 987654321
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
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

Vi v[300001];
int sz[300001],t[600001],ans[300001];
Pi p[300001];
int cc;
void dfs(int N)
{
	p[N].X = ++cc;
	t[cc] = N;
	sz[N] = 1;
	for (int next : v[N])
	{
		dfs(next);
		sz[N] += sz[next];
	}
	p[N].Y = ++cc;
	t[cc] = N;
}
int tree[2097152], a[600001];
void init(int node, int S, int E)
{
	if (S == E)
	{
		a[S] = INF;
		tree[node] = S;
		return;
	}
	init(2 * node, S, (S + E) / 2);
	init(2 * node + 1, (S + E) / 2 + 1, E);
	if (a[tree[node * 2]] <= a[tree[node * 2 + 1]])tree[node] = tree[node * 2];
	else tree[node] = tree[node * 2 + 1];
}

void upd(int node, int S, int E, int k)
{
	if (S == E)
	{
		tree[node] = S;
		return;
	}
	if (k <= (S + E) / 2)upd(node * 2, S, (S + E) / 2, k);
	else upd(node * 2 + 1, (S + E) / 2 + 1, E, k);
	if (a[tree[node * 2]] <= a[tree[node * 2 + 1]])tree[node] = tree[node * 2];
	else tree[node] = tree[node * 2 + 1];
}

int find(int node, int S, int E, int i, int j)
{
	if (i > E || j < S)return INF;
	if (i <= S && j >= E)return tree[node];
	int t1 = find(node * 2, S, (S + E) / 2, i, j), t2 = find(node * 2 + 1, (S + E) / 2 + 1, E, i, j);
	if (t1 == INF)return t2;
	if (t2 == INF)return t1;
	if (a[t1]<=a[t2])return t1;
	return t2;
}
int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	fup(i, 2, n, 1)
	{
		int x;
		scanf("%d", &x);
		v[x].pb(i);
	}
	dfs(1);
	VPi vv;
	fup(i, 1, n, 1)vv.pb(mp(sz[i], i));
	sort(ALL(vv), [&](Pi p1, Pi p2) {return p1.X > p2.X;});
	init(1, 1, cc);
	int pt = 0;
	fup(i, 0, n-1, 1)
	{
		while (pt < n && vv[pt].X*2 >= vv[i].X)
		{
			a[p[vv[pt].Y].X] = vv[pt].X;
			upd(1, 1, cc, p[vv[pt].Y].X);
			pt++;
		}
		int tt = find(1, 1, cc, p[vv[i].Y].X, p[vv[i].Y].Y);
		ans[vv[i].Y] = t[tt];
	}

	while (q--)
	{
		int x;
		scanf("%d", &x);
		printf("%d\n", ans[x]);
	}
}