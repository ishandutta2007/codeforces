#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<map>
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
#define PI 3.14159265358979323846264
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
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
int DX[] = { 2,2,1,1,-1,-1,-2,-2 }, DY[] = { 1,-1,2,-2,2,-2,1,-1 };

bitset<10001> t[32768];
Vi v[32768];
void upd(int node, int S, int E, int l, int r, int x)
{
	if (l > r)return;
	if (S == l && E == r)
	{
		v[node].push_back(x);
		return;
	}
	int M = (S + E) >> 1;
	upd(node * 2, S, M, l, min(r,M), x);
	upd(node * 2 + 1, M + 1, E, max(l,M+1), r, x);
}
void solve(int node, int S, int E)
{
	t[node][0] = 1;
	if (S != E)
	{
		int M = (S + E) >> 1;
		solve(node * 2, S, M);
		solve(node * 2 + 1, M + 1, E);
		t[node] = t[node * 2] | t[node * 2 + 1];
	}
	for (int x : v[node])t[node] |= (t[node]) << x;
}
int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	fup(i, 0, q - 1, 1)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		upd(1, 1, n, x, y, z);
	}
	solve(1, 1, n);
	Vi ans;
	fup(i, 1, n, 1)
		if (t[1][i])ans.push_back(i);
	printf("%d\n", ans.size());
	for (int x : ans)printf("%d ", x);
}