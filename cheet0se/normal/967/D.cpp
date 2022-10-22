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
ll MOD = 1000000000;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

Pll p[300001], p2[300001];
ll temp[300001];
Vi V1, V2;
int nn; ll x1, x2;
bool NOK()
{
	int n = nn;
	fup(i, 1, n, 1)
		temp[i] = p[i].X*i;
	int now = -1;
	fup(i, 1, n, 1)
	{
		V1.push_back(p[i].Y);
		if (x1 <= temp[i])
		{
			now = i;
			break;
		}
	}
	if (now == -1)return 0;
	fup(i, now + 1, n, 1)p2[i - now] = p[i];
	n -= now;
	now = -1;
	MEM0(temp);
	fup(i, 1, n, 1)
		temp[i] = p2[i].X*i;
	fup(i, 1, n, 1)
	{
		V2.push_back(p2[i].Y);
		if (x2 <= temp[i])
		{
			now = i;
			break;
		}
	}
	if (now == -1)return 0;
	puts("Yes");
	printf("%d %d\n", V1.size(), V2.size());
	for (int x : V1)printf("%d ", x);
	puts("");
	for (int x : V2)printf("%d ", x);
	puts("");
	return 1;
}
bool OK()
{
	int n = nn;
	swap(x1, x2);
	fup(i, 1, n, 1)
		temp[i] = p[i].X*i;
	int now = -1;
	fup(i, 1, n, 1)
	{
		V1.push_back(p[i].Y);
		if (x1 <= temp[i])
		{
			now = i;
			break;
		}
	}
	if (now == -1)return 0;
	fup(i, now + 1, n, 1)p2[i - now] = p[i];
	n -= now;
	now = -1;
	MEM0(temp);
	fup(i, 1, n, 1)
		temp[i] = p2[i].X*i;
	fup(i, 1, n, 1)
	{
		V2.push_back(p2[i].Y);
		if (x2 <= temp[i])
		{
			now = i;
			break;
		}
	}
	if (now == -1)return 0;
	swap(V1, V2);
	puts("Yes");
	printf("%d %d\n", V1.size(), V2.size());
	for (int x : V1)printf("%d ", x);
	puts("");
	for (int x : V2)printf("%d ", x);
	puts("");
	return 1;
}
int main() {
	scanf("%d%lld%lld", &nn, &x1, &x2);
	fup(i, 1, nn, 1)
	{
		scanf("%lld", &p[i].X);
		p[i].Y = i;
	}
	sort(p + 1, p + nn + 1);
	reverse(p + 1, p + nn + 1);
	if (NOK())return 0;
	V1.clear();
	V2.clear();
	if (OK())return 0;
	puts("No");
}