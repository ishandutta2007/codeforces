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
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

ll a[200000], s[200000];
int parent[200000][18];
map<ll, int> pre;
int ans, n;
void go(int x)
{
	int res = 0, now = x;
	fdn(i, 16, 0, 1)
	{
		if (parent[now][i] == -1)continue;
		if (parent[now][i] <= x + n)now = parent[now][i], res += (1 << i);
	}
	ans = min(ans, n - res);
}
int main() {
	MEM_1(parent);
	scanf("%d", &n);
	ans = n;
	fup(i, 0, n - 1, 1)scanf("%lld", a + i), a[i + n] = a[i];
	s[0] = a[0];
	fup(i, 1, 2 * n - 1, 1)s[i] = s[i - 1] + a[i];
	fdn(i, 2 * n - 1, 0, 1)
	{
		int t = pre[s[i]];
		if (t)parent[i][0] = t;
		pre[s[i]] = i;
	}
	for (int j = 0; j < 17; j++)
		for (int i = 0; i < 2*n; i++)
			if (parent[i][j] != -1)
				parent[i][j + 1] = parent[parent[i][j]][j];
	fup(i, 0, n - 1, 1)go(i);
	printf("%d", ans);
}