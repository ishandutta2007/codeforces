#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
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
#define y0 y12
#define y1 y22
#define INF 98765432198765321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset((a),0,sizeof(a));
#define MEM_1(a) memset((a),-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
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
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

ll fac[100001];
ll inv[100001];
ll nCr(ll n, ll r)
{
	if(n<0)return 0;
	if(r<0 || r>n)return 0;
	ll c = fac[n];
	c = (c*inv[r]) % MOD;
	c = (c*inv[n - r]) % MOD;
	return c;
}
ll cnt(ll W,ll F,ll w,ll f)
{
	return (nCr(W-1,w-1)*nCr(F-1,f-1))%MOD;
}
int main() {
	fac[0] = inv[0] = 1;
	fup(i, 1, 100000, 1)
		fac[i] = (fac[i - 1] * i) % MOD;
	inv[100000] = POW(fac[100000], MOD - 2);
	fdn(i, 99999, 1, 1)
		inv[i] = (inv[i + 1] * (i+1)) % MOD;
	ll f,w,h;
	scanf("%lld%lld%lld",&f,&w,&h);
	if(w==0) return !printf("1");
	if(f==0)
	{
		if(w>h)return !printf("1");
		return !printf("0");
	}
	ll p=0,q=0;
	fup(i,1,100000,1)
	{
		p=(p+cnt(w-h*i,f,i,i)*2)%MOD;
		q=(q+cnt(w,f,i,i)*2)%MOD;
	}
	fup(i,1,99999,1)
	{
		p=(p+cnt(w-h*(i+1),f,i+1,i))%MOD;
		q=(q+cnt(w,f,i+1,i))%MOD;
		p=(p+cnt(w-h*i,f,i,i+1))%MOD;
		q=(q+cnt(w,f,i,i+1))%MOD;
	}
	printf("%lld",(p*POW(q,MOD-2))%MOD);
}