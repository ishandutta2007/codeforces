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
#define INF 987654321987654321
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
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int n,T;
struct A {
	int a, t, i;
	bool operator <(const A& a1)
	{
		return t < a1.t;
	}
}aa[200000];
bool ok(int k)
{
	if (k == 0)return 1;
	int cnt = 0;
	int nowt = 0;
	fup(i, 0, n - 1, 1)
	{
		if (aa[i].a >= k)
		{
			cnt++;
			nowt += aa[i].t;
		}
		if (nowt > T)return 0;
		if (cnt == k)return 1;
	}
	return 0;
}
void go(int k)
{
	if (k == 0)return;
	int cnt = 0;
	fup(i, 0, n - 1, 1)
	{
		if (aa[i].a >= k)
		{
			printf("%d ", aa[i].i);
			cnt++;
		}
		if (cnt == k)return;
	}
}
int main()
{
	scanf("%d%d", &n, &T);
	fup(i, 0, n-1, 1)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		aa[i] = { x,y,i + 1 };
	}
	sort(aa, aa + n);
	int l = 0, r = 200000;
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (ok(m))l = m + 1;
		else r = m - 1;
	}
	printf("%d\n%d\n", r,r);
	go(r);
}