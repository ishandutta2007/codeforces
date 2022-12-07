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
#define INF 987654321
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

map<ll, ll> M;
Vll div(ll n)
{
	Vll v;
	for (ll i = 2; i*i <= n; i++)
	{
		if (n%i == 0)
		{
			v.push_back(i);
			if (i*i != n)v.push_back(n / i);
		}
	}
	v.push_back(n);
	return v;
}
ll solve(ll a, ll b)
{
	if (b%a != 0)return 0;
	if (a==b)return 1;
	b /= a;
	if (M.find(b) != M.end())return M[b];
	ll res = POW(2,b-1);
	Vll v = div(b);
	for (ll x:v)
	{
		res = (res+MOD-solve(x, b))%MOD;
	}
	return M[b]=res;
}
int main() {
	ll a, b;
	scanf("%I64d%I64d", &a, &b);
	printf("%I64d", solve(a, b));
}