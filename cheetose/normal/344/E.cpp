#include<cstdio>
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
#include<algorithm>
#include<list>
#include<functional>
#define mp make_pair
#define X first
#define Y second
#define INF 1987654321
#define PI 3.14159265358979323846264
#define MOD 1000000007LL
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
typedef complex<double> base;
ll POW(ll a, ll b) { if (b == 0)return 1; if (b == 1)return a; if (b & 1)return (a*POW(a, b - 1)) % MOD; ll t = POW(a, b / 2); return (t*t) % MOD; }
int gcd(int a, int b){return b ? gcd(b, a%b) : a;}
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//

int n, m;
ll h[100000], p[100000];
bool ok(ll t)
{
	ll pos=0;
	int posp=0;
	fup(i, 0, n - 1, 1)
	{
		if (posp==m)return 1;
		if (h[i] - t > p[posp])return 0;
		if (h[i] > p[posp])pos = max(h[i]+(t-h[i]+p[posp])/2,h[i] + t - 2 * (h[i] - p[posp]));
		else pos =max(pos, h[i] + t);
		for (; posp < m && p[posp] <= pos; posp++);
	}
	return posp == m;
}
int main() {
	scanf("%d%d", &n, &m);
	fup(i, 0, n - 1, 1)scanf("%I64d", h + i);
	fup(i, 0, m - 1, 1)scanf("%I64d", p + i);
	ll l = 0, r = 20000000005;
	while (l <= r)
	{
		ll t = (l + r) / 2;
		if (ok(t)) r = t - 1;
		else l = t + 1;
	}
	printf("%I64d", l);
}