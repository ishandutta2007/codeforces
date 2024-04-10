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
#define INF 1987654321
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

int a[10], MIN;
int d[1000001][10];
int go(int N, int k)
{
	if (N < MIN)return 0;
	if (k == 0)return 0;
	int &ret = d[N][k];
	if (ret != -1)return ret;
	ret = 0;
	if (N >= a[k])ret = max(ret, 1 + go(N - a[k], k));
	ret = max(ret, go(N, k-1));
	return ret;
}
void track(int N, int k)
{
	if (N < MIN || k == 0)return;
	int t1 = -INF, t2 = -INF;
	if (N >= a[k]) t1 = max(t1, 1 + go(N - a[k], k));
	t2 = go(N, k-1);
	if (t1 >= t2)
	{
		printf("%d", k);
		track(N - a[k], k);
	}
	else track(N, k - 1);
}
int main() {
	MEM_1(d);
	int n;
	scanf("%d", &n);
	fup(i, 1, 9, 1)scanf("%d", a + i);
	MIN = *min_element(a + 1, a + 10);
	if (n < MIN)return !printf("-1");
	go(n, 9);
	track(n, 9);
}