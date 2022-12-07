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
typedef tuple<int, int, int> iii;
typedef complex<double> base;
ll POW(ll a, ll b) { if (b == 0)return 1; if (b == 1)return a; if (b & 1)return (a*POW(a, b - 1)) % MOD; ll t = POW(a, b / 2); return (t*t) % MOD; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

bool prime[200001];
int main() {
	fill(prime + 2, prime + 200001, true);
	fup(i, 2, 100000, 1)
	{
		if (!prime[i])continue;
		fup(j, i + i, 200000, i)prime[j] = 0;
	}
	int n, m;
	scanf("%d%d", &n, &m);
	int e = n - 1;
	int ii;
	for (ii = 1;; ii++)
	{
		if (prime[ii] && ii >= e)break;
	}
	int two = ii - e;
	int one = e - two;
	printf("%d %d\n", ii, ii);
	fup(i, 1, n - 1, 1)
	{
		printf("%d %d ", i, i + 1);
		if (one > 0)
		{
			puts("1");
			one--;
		}
		else
		{
			puts("2");
			two--;
		}
		m--;
	}
	if (m == 0)return 0;
	fup(i,1,n-1,1)
		fup(j, i + 2, n, 1)
	{
		printf("%d %d 1000000000\n", i, j);
		m--;
		if (m == 0)return 0;
	}
}