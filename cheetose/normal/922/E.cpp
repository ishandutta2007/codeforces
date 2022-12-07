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
#include<iomanip>
#include<numeric>
#include<algorithm>
#include<list>
#include<functional>
#define mp make_pair
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
typedef vector<iii> Viii;
typedef complex<double> base;
typedef tuple<ll, ll, ll> TT;
ll MOD = 1000000007;
ll POW(ll a, ll b){ll ret = 1;for (; b; b >>= 1, a = (a*a) % MOD)if (b & 1)ret = (ret*a) % MOD; return ret;}
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if(a==0||b==0)return a+b; return a*(b / gcd(a, b)); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

ll d[1001][10001];
int c[1001];
ll cost[1001];
int main()
{
	MEM_1(d);
	int n;
	ll W, B, X;
	scanf("%d%lld%lld%lld", &n, &W, &B, &X);
	int m = 0;
	fup(i, 1, n, 1)
	{
		scanf("%d", c + i);
		m += c[i];
	}
	fup(i, 1, n, 1) scanf("%lld", cost + i);
	int ans = 0;
	d[0][0] = W;
	fup(i, 1, n, 1)
	{
		fup(j, 0, m, 1)
		{
			ll cap = W + j*B;
			fup(k, 0, min(c[i], j), 1)
			{
				if (d[i - 1][j - k] == -1)continue;
				ll MM = min(cap - k*B, d[i - 1][j - k] + X) - cost[i] * k;
				if (MM < 0)continue;
				d[i][j] = max(d[i][j],MM);
				ans = max(ans, j);
			}
		}
	}
	printf("%d", ans);
}