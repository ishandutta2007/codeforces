#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 1987654321
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

int d[500][500][11];
int n,m,k;
int a[500][500],b[500][500];
int go(int N,int M,int K){
	if(K==0)return 0;
	int &ret=d[N][M][K];
	if(~ret)return ret;
	ret=INF;
	if(M+1<m)ret=min(ret,a[N][M]+go(N,M+1,K-1));
	if(M-1>=0)ret=min(ret,a[N][M-1]+go(N,M-1,K-1));
	if(N+1<n)ret=min(ret,b[N][M]+go(N+1,M,K-1));
	if(N-1>=0)ret=min(ret,b[N-1][M]+go(N-1,M,K-1));
	return ret;
}
int main(){
	MEM_1(d);
	scanf("%d%d%d",&n,&m,&k);
	if(k&1){
		fup(i,0,n-1,1){
			fup(j,0,m-1,1)printf("-1 ");
			puts("");
		}
		return 0;
	}
	k>>=1;
	fup(i,0,n-1,1)fup(j,0,m-2,1)scanf("%d",&a[i][j]);
	fup(i,0,n-2,1)fup(j,0,m-1,1)scanf("%d",&b[i][j]);
	fup(i,0,n-1,1){
		fup(j,0,m-1,1){
			printf("%d ",go(i,j,k)<<1);
		}
		puts("");
	}
}