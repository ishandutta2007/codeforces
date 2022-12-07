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

int n,M;
ll p[404],f[404],inv[404];
ll d[404][404];
ll go(int N,int K){
	if(N==n)return 0;
	if(N==n+1)return f[K];
	ll &ret=d[N][K];
	if(~ret)return ret;
	ret=0;
	fup(i,N,n-1,1){
		int t=i-N+1;
		ret=(ret+(p[t-1]*go(i+2,K+t)%M)*inv[t])%M;
	}
	return ret;
}
int main() {
	MEM_1(d);
	scanf("%d%d",&n,&M);
	f[0]=inv[0]=p[0]=1;
	fup(i,1,n,1){
		p[i]=(p[i-1]*2)%M;
		f[i]=(f[i-1]*i)%M;
		inv[i]=POW(f[i],M-2,M);
	}
	printf("%lld\n",go(0,0));
}