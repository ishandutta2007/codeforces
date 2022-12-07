#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654321987654321
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
typedef pair<ld, ld> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<ld> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

ll fac[200001],inv[200001],t[200002],p[200002];
ll nCr(int n, int r)
{
	if(r<0 || r>n)return 0;
	ll c = fac[n];
	c = (c*inv[r]) % MOD;
	c = (c*inv[n - r]) % MOD;
	return c;
}
int main() {
	int n;
	ll T;
	scanf("%d%lld",&n,&T);
	fac[0] = inv[0] = 1;
	fup(i, 1, 200000, 1)
		fac[i] = (fac[i - 1] * i) % MOD;
	inv[200000] = POW(fac[200000], MOD - 2);
	fdn(i, 199999, 1, 1)
		inv[i] = (inv[i + 1] * (i+1)) % MOD;
	p[0]=1,p[1]=inv[2];
	fup(i,2,200000,1)p[i]=(p[i-1]*p[1])%MOD;
	ll ans=0, S=0;
	fup(i,1,n,1)scanf("%lld",t+i);
	t[n+1]=INF;
	ll tmp=0,l=0,r=-1;
	fup(x,1,n,1)
	{
		S+=t[x];
		ll L=max(0LL,T-S-t[x+1]+1),R=min(1LL*x,T-S);
		if(L<=R){
			while(r<R)tmp=(tmp+nCr(x,++r))%MOD;
			while(r>R)tmp=(tmp+MOD-nCr(x,r--))%MOD;
			while(l>L)tmp=(tmp+nCr(x,--l))%MOD;
			while(l<L)tmp=(tmp+MOD-nCr(x,l++))%MOD;
			ans=(ans+(tmp*p[x])%MOD * x)%MOD;
		}
		ll LL=max(0LL,T-S-t[x+1]);
		if(LL<=R){
			while(r<R)tmp=(tmp+nCr(x,++r))%MOD;
			while(r>R)tmp=(tmp+MOD-nCr(x,r--))%MOD;
			while(l>LL)tmp=(tmp+nCr(x,--l))%MOD;
			while(l<LL)tmp=(tmp+MOD-nCr(x,l++))%MOD;
			ans=(ans+(tmp*p[x])%MOD * x)%MOD;
		}
		tmp=(tmp+tmp+nCr(x,l-1)-nCr(x,r))%MOD;
	}
	ans=(ans*inv[2])%MOD;
	printf("%lld",ans);
}