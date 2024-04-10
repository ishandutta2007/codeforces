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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int d[505][505],p[505][505],nCr[505][505];
int go(int N,int K){
	if(K<=0 || N<=0)return 0;
	if(N==1)return K;
	int &ret=d[N][K];
	if(~ret)return ret;
	ret=0;
	fup(i,0,N,1){
		int t=1ll*nCr[N][i]*p[N-1][i]%MOD;
		ret=(ret+1ll*t*go(N-i,K-N+1))%MOD;
	}
	return ret;
}
int main(){
	MEM_1(d);
	int n,k;
	scanf("%d%d",&n,&k);
	fup(i,0,500,1){
		fup(j,0,500,1){
			if(j==0)p[i][j]=1;
			else p[i][j]=1ll*p[i][j-1]*i%MOD;
		}
		nCr[i][0]=nCr[i][i]=1;
		fup(j,1,i-1,1){
			nCr[i][j]=(nCr[i-1][j-1]+nCr[i-1][j])%MOD;
		}
	}
	int ans=p[k][n];
	printf("%d\n",(ans+MOD-go(n,k))%MOD);
}