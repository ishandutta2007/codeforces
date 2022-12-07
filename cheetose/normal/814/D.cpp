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
typedef vector<iii> Viii;
typedef complex<double> base;
typedef tuple<ll, ll, ll> TT;
ll MOD = 1000000007;
ll POW(ll a, ll b){ll ret = 1;for (; b; b >>= 1, a = (a*a) % MOD)if (b & 1)ret = (ret*a) % MOD; return ret;}
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if(a==0||b==0)return a+b; return a*(b / gcd(a, b)); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

TT a[1000];
int ind[1000];
Vi v[1000];
ll d[1000][2][2];
void go(int N)
{
	ll t[2][2] = { 0 };
	for (int next : v[N])
	{
		go(next);
		fup(i, 0, 1, 1)
			fup(j, 0, 1, 1)
			t[i][j] += d[next][i][j];
	}
	fup(i,0,1,1)
		fup(j, 0, 1, 1)
	{
		d[N][i][j] = max(t[1 - i][j] + get<0>(a[N])*get<0>(a[N])*(i == 0 ? 1 : -1), t[i][1 - j] + get<0>(a[N])*get<0>(a[N])*(j == 0 ? 1 : -1));
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	fup(i, 0, n - 1, 1)
	{
		ll x, y, r;
		scanf("%lld%lld%lld", &x, &y, &r);
		a[i] = TT(r, x, y);
	}
	sort(a, a + n);
	fup(i, 0, n - 1, 1)
	{
		ll x1, y1, r1;
		tie(r1, x1, y1) = a[i];
		fup(j, i + 1, n - 1, 1)
		{
			ll x2, y2, r2;
			tie(r2, x2, y2) = a[j];
			if ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) <= (r1 - r2)*(r1 - r2))
			{
				v[j].push_back(i);
				ind[i]++;
				break;
			}
		}
	}
	ll ans = 0;
	fup(i, 0, n - 1, 1)
		if (ind[i] == 0)
		{
			go(i);
			ans += d[i][0][0];
		}
	printf("%.10f", (double)ans*PI);
}