#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset((a),0,sizeof(a))
#define MEM_1(a) memset((a),-1,sizeof(a))
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
typedef pair<ld, ld> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<db> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

ll fac[1000001],inv[1000001];
ll nCr(int n, int r)
{
	if(r>n)return 0;
	ll c = fac[n];
	c = (c*inv[r]) % MOD;
	c = (c*inv[n - r]) % MOD;
	return c;
}
ll p[1000001];
int main(){
	fac[0] = inv[0] = 1;
	fup(i, 1, 1000000, 1)
		fac[i] = (fac[i - 1] * i) % MOD;
	inv[1000000] = POW(fac[1000000], MOD - 2);
	fdn(i, 999999, 1, 1)
		inv[i] = (inv[i + 1] * (i+1)) % MOD;
	p[0]=1;
	fup(i,1,1000000,1)p[i]=p[i-1]*3%MOD;
	ll ans=0;
	int n;
	scanf("%d",&n);
	fup(i,1,n,1){
		ll t=nCr(n,i);
		t=t*POW(3,1LL*n*(n-i)+i)%MOD;
		if(!(i&1))t=-t;
		ans=(ans+t)%MOD;
		if(ans<0)ans+=MOD;
	}
	ans=ans*2%MOD;
	ll tt=0;
	fup(i,0,n-1,1){
		ll t1=p[i];
		t1=-t1;
		ll t2=t1;
		t1=(t1+1)%MOD;
		if(t1<0)t1+=MOD;
		t1=POW(t1,n);
		if(t2<0)t2+=MOD;
		t2=POW(t2,n);
		t1=(t1-t2)%MOD;
		if(t1<0)t1+=MOD;
		t1=t1*nCr(n,i)%MOD;
		if(i&1)t1=-t1;
		tt=(tt+t1)%MOD;
		if(tt<0)tt+=MOD;
	}
	tt=tt*(-3)%MOD;
	if(tt<0)tt+=MOD;
	ans=(ans+tt)%MOD;
	printf("%lld\n",ans);
}