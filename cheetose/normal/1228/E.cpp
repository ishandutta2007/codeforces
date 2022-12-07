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
#define INF 987654321
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
typedef vector<double> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int,int,int,int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

ll fac[301];
ll inv[301];
ll powk[301],powk1[301];
int n;
ll k;
ll nCr(int n, int r)
{
	if(r>n)return 0;
	ll c = fac[n];
	c = (c*inv[r]) % MOD;
	c = (c*inv[n - r]) % MOD;
	return c;
}
ll d[255][255];
ll go(int N,int c)
{
	if(N==n)
	{
		return c==n;
	}
	ll &ret=d[N][c];
	if(~ret)return ret;
	ret=0;
	if(c>0)
	{
		ll cc=powk[c]-powk1[c];
		if(cc<0)cc+=MOD;
		cc=(cc*powk1[n-c])%MOD;
		ret=(ret+cc*go(N+1,c))%MOD;
	}
	fup(i,1,n-c,1)
	{
		ll cc=nCr(n-c,i);
		cc=(cc*powk1[n-c-i])%MOD;
		cc=(cc*powk[c])%MOD;
		ret=(ret+cc*go(N+1,c+i))%MOD;
	}
	return ret;
}
int main(){
	MEM_1(d);
	fac[0] = inv[0] = 1;
	fup(i, 1, 300, 1)
		fac[i] = (fac[i - 1] * i) % MOD;
	inv[300] = POW(fac[300], MOD - 2);
	fdn(i, 299, 1, 1)
		inv[i] = (inv[i + 1] * (i+1)) % MOD;
	scanf("%d%lld",&n,&k);
	powk[0]=powk1[0]=1;
	fup(i,1,300,1)
	{
		powk[i]=(powk[i-1]*k)%MOD;
		powk1[i]=(powk1[i-1]*(k-1))%MOD;
	}
	if(n==1 || k==1)return !printf("1");
	printf("%lld",go(0,0));
}