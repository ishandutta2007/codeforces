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
ll MOD = 1999;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

Vi v[1000001];
int a[1000001];
int cnt[1000001];
int t1, t2;
int R;
Vi ans;
void dfs(int N)
{
	cnt[N] = a[N];
	for (int next : v[N])
	{
		dfs(next);
		cnt[N] += cnt[next];
	}
}

int go(int N)
{
	int ret = 0;
	for (int next : v[N])ret=max(ret,go(next));
	if (N != R && ret == 0 && cnt[N] == t1)
	{
		ans.push_back(N);
		ret = 1;
	}
	else if (N != R && ret == 1 && cnt[N] == t2)
	{
		ans.push_back(N);
		ret = 2;
	}
	return ret;
}
int main() {
	int n;
	scanf("%d", &n);
	int sum = 0;
	fup(i, 1, n, 1)
	{
		int p;
		scanf("%d%d", &p, a + i);
		sum += a[i];
		if (p)v[p].push_back(i);
		if (!p)R = i;
	}
	if (sum % 3)return !printf("-1");
	t1 = sum / 3, t2 = t1 * 2;
	dfs(R);
	go(R);
	if (ans.size() <= 1)return !printf("-1");
	fup(i, 0, 1, 1)printf("%d ", ans[i]);
}