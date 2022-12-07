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
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//

ll fac[1010001];
ll inv[1010001];
ll nCr(int n, int r)
{
	ll c = fac[n];
	c = (c*inv[r]) % MOD;
	c = (c*inv[n - r]) % MOD;
	return c;
}
int prime[1010001];
int main() {
	fac[0] = inv[0] = 1;
	fup(i, 1, 1010000, 1)
	{
		fac[i] = (fac[i - 1] * i) % MOD;
		inv[i] = POW(fac[i], MOD-2);
	}
	fup(i, 2, 1010000, 1)
	{
		if (prime[i])continue;
		fup(j, i, 1010000, i)
		{
			if (!prime[j])prime[j] = i;
		}
	}
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		ll ans = POW(2,y-1);
		int t = x;
		Vi v;
		for (int i = 2; i*i <= x; i++)
		{
			int temp = 0;
			while (prime[t] == i)
			{
				temp++;
				t /= i;
			}
			if (temp)v.push_back(temp);
		}
		if (t != 1)v.push_back(1);
		for (int k : v)
		{
			ans = (ans*nCr(k + y - 1,k))%MOD;
		}
		printf("%I64d\n", ans);
	}
}