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
ll MOD = 1000000000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };
int DX[] = { 1,1,2,2,-1,-1,-2,-2 }, DY[] = { 2,-2,1,-1,2,-2,1,-1 };

bool prime[1500001], chk[1500001];
Vi v[1500001];
int a[100000],b[100000];
bool ok(int k)
{
	for (int x : v[k])if (chk[x])return 0;
	return 1;
}
int main() {
	fill(prime + 2, prime + 1500001, true);
	fup(i, 2, 750000, 1)
	{
		if (!prime[i])continue;
		fup(j, i, 1500000, i)
		{
			v[j].push_back(i);
			if(j!=i)prime[j] = 0;
		}
	}
	int n;
	scanf("%d", &n);
	fup(i, 0, n - 1, 1)
		scanf("%d", a + i);
	int i = 0;
	for (; i < n; i++)
	{
		if (ok(a[i]))
		{
			b[i] = a[i];
			for (int x : v[a[i]])chk[x] = 1;
		}
		else
		{
			int t = a[i] + 1;
			while (!ok(t))t++;
			b[i] = t;
			for (int x : v[t])chk[x] = 1;
			break;
		}
	}
	i++;
	int t = 2;
	for (; i < n; i++)
	{
		while (!prime[t] || chk[t])t++;
		b[i] = t;
		t++;
	}
	fup(i, 0, n - 1, 1)printf("%d ", b[i]);
}