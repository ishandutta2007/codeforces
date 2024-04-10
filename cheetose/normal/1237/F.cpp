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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

ll fac[4001],inv[4001];
ll nCr(int n, int r)
{
	if(r>n)return 0;
	ll c = fac[n];
	c = (c*inv[r]) % MOD;
	c = (c*inv[n - r]) % MOD;
	return c;
}
ll dr[3605][1805],dc[3605][1805];
bool R[4001],C[4001];
int main() {
	fac[0] = inv[0] = 1;
	fup(i, 1, 4000, 1)
		fac[i] = (fac[i - 1] * i) % MOD;
	inv[4000] = POW(fac[4000], MOD - 2);
	fdn(i, 3999, 1, 1)
		inv[i] = (inv[i + 1] * (i+1)) % MOD;
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	fup(i,1,k,1)
	{
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		R[x1]=R[x2]=C[y1]=C[y2]=1;
	}
	int N=n,M=m;
	fup(i,1,max(n,m),1)
	{
		if(R[i])N--;
		if(C[i])M--;
	}
	dr[0][0]=dc[0][0]=1;
	fup(i,1,n,1)
	fup(j,0,i>>1,1)
	{
		dr[i][j]=dr[i-1][j];
		if(i>=2 && j>=1 && !R[i-1] && !R[i])dr[i][j]=(dr[i][j]+dr[i-2][j-1])%MOD;
	}
	fup(i,1,m,1)
	fup(j,0,i>>1,1)
	{
		dc[i][j]=dc[i-1][j];
		if(i>=2 && j>=1 && !C[i-1] && !C[i])dc[i][j]=(dc[i][j]+dc[i-2][j-1])%MOD;
	}
	ll ans=0;
	fup(i,0,N>>1,1)
	fup(j,0,M>>1,1)
	{
		ll RR=(dr[n][i]*nCr(N-2*i,j))%MOD,CC=(dc[m][j]*nCr(M-2*j,i))%MOD;
		ll tmp=(fac[i]*fac[j])%MOD;
		tmp=(tmp*RR)%MOD;
		tmp=(tmp*CC)%MOD;
		ans=(ans+tmp)%MOD;
	}
	printf("%lld",ans);
}