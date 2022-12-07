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

int n, m, k;
int a[1000000];
Pi p[1000000];
bool ok(int M)
{
	int day = 0;
	int l = 0, r = M - 1;
	while (l<n || r>=0)
	{
		fup(kkk, 1, k, 1)
		{
			if (l < n && r >= 0)
			{
				if (a[l] <= p[r].X)
				{
					if (a[l] < day)return 0;
					l++;
				}
				else
				{
					if (p[r].X < day)return 0;
					r--;
				}
			}
			else if (r >= 0)
			{
				if (p[r].X < day)return 0;
				r--;
			}
			else if (l < n)
			{
				if (a[l] < day)return 0;
				l++;
			}
			else break;
		}
		day++;
	}
	return 1;
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	fup(i, 0, n - 1, 1)scanf("%d", a + i);
	fup(i, 0, m - 1, 1)
	{
		scanf("%d", &p[i].X);
		p[i].Y = i + 1;
	}
	sort(a, a + n);
	sort(p, p + m);
	reverse(p, p + m);
	int l = 0, r = m;
	while (l <= r)
	{
		int M = (l + r) >> 1;
		if (ok(M))l = M + 1;
		else r = M - 1;
	}
	printf("%d\n", r);
	if (r > 0)
	{
		fup(i, 0, r - 1, 1)printf("%d ", p[i].Y);
	}
}