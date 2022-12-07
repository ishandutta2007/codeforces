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

int d[505][505],R;
int o[505];
Pi x[505];
int n;
int go(int N,int K){
	if(N==n)return K>=0;
	int &ret=d[N][K];
	if(~ret)return ret;
	ret=0;
	if(N==R)return ret=go(N+1,K);
	if(o[N]==1){
		if(x[N]<x[R]){
			return ret=(go(N+1,K)+go(N+1,K+1))%MOD;
		}
		else return ret=2*go(N+1,K)%MOD;
	}
	if(o[N]==-1){
		if(K>0)return ret=(go(N+1,K)+go(N+1,K-1))%MOD;
		if(N<R)return ret=2*go(N+1,K)%MOD;
		return ret=go(N+1,K);
	}
}
int main(){
	scanf("%d",&n);
	fup(i,0,n-1,1){
		char c;
		scanf(" %c",&c);
		if(c=='-'){
			o[i]=-1;
		}else{
			o[i]=1;
			scanf("%d",&x[i].X);
			x[i].Y=i;
		}
	}
	int ans=0;
	fup(i,0,n-1,1){
		if(o[i]==1){
			MEM_1(d);
			R=i;
			ans=(ans+1ll*x[i].X*go(0,0))%MOD;
		}
	}
	printf("%d\n",ans);
}