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
#define MEM0(a) memset((a),0,sizeof(a))
#define MEM_1(a) memset((a),-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define COMPRESS(a) sort(ALL(a));a.resize(unique(ALL(a))-a.begin())
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
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

ll fac[3000001],inv[3000001];
ll nCr(int n,int r){
	if(n<0 || r>n)return 0;
	ll c=fac[n];
	c=c*inv[r]%MOD;
	c=c*inv[n-r]%MOD;
	return c;
}
ll d[3000001][2];
int main() {
	fac[0]=inv[0]=1;
	fup(i,1,3000000,1)fac[i]=fac[i-1]*i%MOD;
	inv[3000000]=POW(fac[3000000],MOD-2);
	fdn(i,2999999,1,1)inv[i]=inv[i+1]*(i+1)%MOD;
	int n,q;
	scanf("%d%d",&n,&q);
	fup(i,0,n-1,1){
		fup(j,0,1,1){
			d[1][j]=(d[1][j]+nCr(3*i+j,1))%MOD;
		}
	}
	ll inv3=POW(3,MOD-2);
	fup(x,2,3*n,1){
		ll c=nCr(3*n,x+1);
		c=(c-2*d[x-1][0]-d[x-1][1])%MOD;
		if(c<0)c+=MOD;
		d[x][0]=(c*inv3)%MOD;
		d[x][1]=(d[x-1][0]+d[x][0])%MOD;
	}
	while(q--){
		int x;
		scanf("%d",&x);
		printf("%lld\n",(d[x][0]+nCr(3*n,x))%MOD);
	}
}