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
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

ll a[100][100],d[100][100];
ll T;
int n,m;
ll go(int N,int M){
	if(a[N][M]<T)return INF;
	if(N==n-1 && M==m-1)return a[N][M]-T;
	ll &ret=d[N][M];
	if(~ret)return ret;
	ret=INF;
	if(N+1<n)ret=min(ret,a[N][M]-T+go(N+1,M));
	if(M+1<m)ret=min(ret,a[N][M]-T+go(N,M+1));
	return ret;
}
void solve(){
	scanf("%d%d",&n,&m);
	fup(i,0,n-1,1)fup(j,0,m-1,1)scanf("%lld",a[i]+j),a[i][j]-=i+j;
	ll ans=INF;
	fup(i,0,n-1,1){
		fup(j,0,m-1,1){
			T=a[i][j];
			fup(ii,0,n-1,1)fup(jj,0,m-1,1)d[ii][jj]=-1;
			ans=min(ans,go(0,0));
		}
	}
	printf("%lld\n",ans);
}
int main() {
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}