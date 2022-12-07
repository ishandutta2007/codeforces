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
#define INF (ll)1e17
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
const ll MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int a[5];
int main() {
	int n;
	scanf("%d", &n);
	fup(i, 1, n, 1)
	{
		int x;
		scanf("%d", &x);
		a[x]++;
	}
	if (a[1] == 0 && a[2] == 0)return !printf("0");
	int ans = 0;
	int t = min(a[1], a[2]);
	ans += t, a[1] -= t, a[2] -= t, a[3] += 2 * t;
	t = a[1] / 3;
	ans += 2 * t, a[1] -= 3 * t, a[3] += t;
	t = a[2] / 3;
	ans += 2 * t, a[2] -= 3 * t, a[3] += 2*t;
	if (a[1] == 1)
	{
		if (a[3] >= 1)a[1]--, ans++;
		else if (a[4] >= 2)a[1]--, ans += 2;
	}
	else if (a[1] == 2)
	{
		if (a[4] >= 1)a[1]=0,ans += 2;
		else if (a[3] >= 2)a[1]=0,ans += 2;
	}
	else if (a[2] == 1)
	{
		if (a[4] >= 1)a[2]=0,ans++;
		else if (a[3] >= 2)a[2] = 0, ans += 2;
	}
	else if (a[2] == 2)
	{
		a[2] = 0, ans += 2;
	}
	if (a[1] > 0 || a[2] > 0)return !printf("-1");
	printf("%d", ans);
}