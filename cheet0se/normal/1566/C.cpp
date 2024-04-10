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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int c[4];
int d[100005][4];
int a[100005],b[100005],n;
int go(int N,int K){
	if(N==n)return c[K];
	int &ret=d[N][K];
	if(~ret)return ret;
	return ret=max(go(N+1,K|a[N]|b[N]),c[K]+go(N+1,a[N]|b[N]));
}
void solve(){
	scanf("%d",&n);
	fup(i,0,n-1,1)fup(j,0,3,1)d[i][j]=-1;
	fup(i,0,n-1,1){
		scanf("%1d",a+i);
		if(a[i]==0)a[i]=1;
		else a[i]=2;
	}
	fup(i,0,n-1,1){
		scanf("%1d",b+i);
		if(b[i]==0)b[i]=1;
		else b[i]=2;
	}
	printf("%d\n",go(0,0));
}
int main(){
	c[0]=0,c[1]=1,c[2]=0,c[3]=2;
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}