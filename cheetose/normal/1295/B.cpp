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
typedef pair<ld, ld> Pd;
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
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

char s[100005];
int a[100005];
int g(int x, int m)
{
	x %= m;
	if (x < 0)x += m;
	return x;
}
void solve() {
	int n, x;
	scanf("%d%d%s", &n, &x, s+1);
	fup(i, 1, n, 1)
		a[i] = a[i - 1] + (s[i] == '0' ? 1 : -1);
	int mx = *max_element(a, a + n + 1), mn = *min_element(a, a + n + 1);
	if (a[n] == 0)
	{
		if (mn <= x && x <= mx)puts("-1");
		else puts("0");
	}
	else
	{
		int t = a[n],ans=0;
		if (t < 0)
		{
			fup(i, 1, n, 1)a[i] = -a[i];
			x = -x;
			t = -t;
		}
		if (x >= 0)
		{
			fup(i, 1, n, 1)
			{
				if (a[i] <=x && g(a[i],t)==g(x,t))ans++;
			}
		}
		else
		{
			fup(i, 1, n, 1)
			{
				if (a[i] <=x && g(a[i],t) == g(x,t))ans++;
			}
		}
		if (x == 0)ans++;
		printf("%d\n", ans);
	}
}
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--)solve();
}