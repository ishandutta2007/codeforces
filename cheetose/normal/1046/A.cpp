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
#define PI 3.14159265358979323846264
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

iii a[100000];
map<int, Vi> M,T;
inline int UPPER(int i, int x)
{
	Vi &v = T[i];
	return upper_bound(ALL(v), x) - v.begin();
}
inline int LOWER(int i, int x)
{
	Vi &v = T[i];
	return lower_bound(ALL(v), x) - v.begin();
}
void upd(int i, Vi &tree)
{
	int n = tree.size()-5;
	while (i <= n+2)
	{
		tree[i]++;
		i += (i&-i);
	}
}
int sum(int i, Vi &tree)
{
	int c = 0;
	while (i > 0)
	{
		c += tree[i];
		i -= (i&-i);
	}
	return c;
}
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	ll ans = 0;
	fup(i, 0, n - 1, 1)
	{
		int x, r, q;
		scanf("%d%d%d", &x, &r, &q);
		T[q].push_back(x);
		a[i] = iii(r, x, q);
	}
	for (auto it = T.begin(); it != T.end(); it++)
	{
		sort(ALL(it->Y));
		int N = it->Y.size();
		M[it->X].resize(N + 5);
	}
	sort(a, a + n);
	fdn(i, n - 1, 0, 1)
	{
		int x, r, q;
		tie(r, x, q) = a[i];
		fup(K, q - k, q + k, 1)
		{
			Vi &vv = M[K];
			if (vv.empty())continue;
			int L = LOWER(K, x - r), R = UPPER(K, x + r);
			ans += sum(R, vv) - sum(L, vv);
		}
		upd(LOWER(q, x)+1, M[q]);
	}
	printf("%lld", ans);
}