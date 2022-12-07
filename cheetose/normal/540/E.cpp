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
#define INF 987654321987654321
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
ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

Vi v;
Pi p[100000];
int a[200005];
inline int getidx(int x)
{
	return lower_bound(ALL(v), x) - v.begin();
}
int tree[524288];
void upd(int node, int S, int E, int k)
{
	tree[node] ++;
	if (S == E)return;
	if (k <= (S + E) / 2)upd(node * 2, S, (S + E) / 2, k);
	else upd(node * 2 + 1, (S + E) / 2 + 1, E, k);
}

int find(int node, int S, int E, int i, int j)
{
	if (i > E || j < S)return 0;
	if (i <= S && j >= E)return tree[node];
	return find(node * 2, S, (S + E) / 2, i, j) + find(node * 2 + 1, (S + E) / 2 + 1, E, i, j);
}
inline int cnt(int l, int r)
{
	return upper_bound(ALL(v), r) - lower_bound(ALL(v), l);
}
int main() {
	int n;
	scanf("%d", &n);
	fup(i, 0, n - 1, 1)
	{
		scanf("%d%d", &p[i].X, &p[i].Y);
		v.push_back(p[i].X);
		v.push_back(p[i].Y);
	}
	sort(ALL(v));
	v.resize(unique(ALL(v)) - v.begin());
	int N = v.size();
	fup(i, 0, n - 1, 1)
	{
		p[i].X = getidx(p[i].X);
		p[i].Y = getidx(p[i].Y);
	}
	fup(i, 0, N - 1, 1)a[i] = i;
	fup(i, 0, n - 1, 1)
		swap(a[p[i].X], a[p[i].Y]);
	ll ans = 0;
	fup(i, 0, N - 1, 1)
	{
		int t = find(1, 0, N - 1, a[i] + 1, N - 1);
		ans += t;
		int ori = v[i];
		if (ori < v[a[i]])
		{
			ans+=v[a[i]] - ori - 1;
			ans -= cnt(ori + 1, v[a[i]] - 1);
		}
		if (ori > v[a[i]])
		{
			ans += ori - v[a[i]] - 1;
			ans -= cnt(v[a[i]] + 1, ori - 1);
		}
		upd(1, 0, N - 1, a[i]);
	}
	printf("%lld", ans);
}