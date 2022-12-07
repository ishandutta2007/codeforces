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

int t[100001];
Vi v[100001];
int d[100001];
int go(int N)
{
	if (t[N])return 1;
	if (v[N].empty())return -INF;
	int &ret = d[N];
	if (ret != -INF - 5)return ret;
	ret = -INF;
	if (v[N].size() > 1)return ret;
	ret = max(ret, 1 + go(v[N][0]));
	return ret;
}
void track(int N)
{
	printf("%d ", N);
	if (t[N])return;
	track(v[N][0]);
}
int main() {
	fill(d, d + 100001, -INF - 5);
	int n;
	scanf("%d", &n);
	fup(i, 1, n, 1)scanf("%d", t + i);
	fup(i, 1, n, 1)
	{
		int x;
		scanf("%d", &x);
		if (x)v[x].push_back(i);
	}
	int ans = -INF;
	fup(i, 1, n, 1)ans = max(ans, go(i));
	printf("%d\n", ans);
	fup(i, 1, n, 1)
	{
		if (go(i) == ans)
		{
			track(i);
			return 0;
		}
	}
}