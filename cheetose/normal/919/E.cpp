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
ll MOD = 900528;
ll POW(ll a, ll b){ll ret = 1;for (; b; b >>= 1, a = (a*a) % MOD)if (b & 1)ret = (ret*a) % MOD; return ret;}
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if(a==0||b==0)return a+b; return a*(b / gcd(a, b)); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

ll a, b, p, x;
ll inv(ll u, ll v)
{
	ll r, r1=u, r2=v, s, s1=1, s2=0;
	while (r2)
	{
		ll q = r1 / r2;
		r = r2;
		r2 = r1 - r2*q;
		r1 = r;
		s = s2;
		s2 = s1 - s2*q;
		s1 = s;
	}
	return (s1+v)%v;
}
ll go(ll u, ll v)
{
	ll P = p*(p - 1);
	ll n = (u*p*inv(p, p-1) + v*(p - 1)*inv(p-1, p)) % P;
	ll c = x%P;
	ll res = x / P + (n <= c);
	return res;
}
int main()
{
	scanf("%lld%lld%lld%lld", &a, &b, &p, &x);
	MOD = p;
	ll ans = 0;
	fup(i, 0, p - 2, 1)
	{
		ans += go(i, (b*POW(a, p - i - 1)) % p);
	}
	printf("%lld", ans);
}