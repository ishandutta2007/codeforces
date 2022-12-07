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
#define INF 1987654321987654321
#define PI 3.14159265358979323846264
#define MOD 20091101
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

int len(ll n)
{
	int c = 0;
	while (n)
	{
		c++;
		n /= 10;
	}
	return c;
}
ll rev(ll n)
{
	queue<int> st;
	while (n)
	{
		st.push(n % 10);
		n /= 10;
	}
	ll c = 0;
	while (!st.empty())
	{
		c *= 10;
		c += st.front();
		st.pop();
	}
	return c;
}
ll pal(ll n)
{
	int l = len(n);
	ll t = 1;
	fup(i, 1, l, 1)
		t *= 10;
	return n*t + rev(n);
}
int main() {
	ll k, p;
	scanf("%I64d%I64d", &k, &p);
	ll ans = 0;
	fup(i, 1, k, 1)
		ans = (ans + pal(i)) % p;
	printf("%I64d", ans);
}