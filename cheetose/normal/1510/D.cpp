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
const int MOD = 1000000021;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int n,k;
db d[100000][11],lg[100000];
int a[100000];
db go(int N,int K){
	if(N==n){
		if(K==k)return 0;
		return -INF;
	}
	db &ret=d[N][K];
	if(ret!=-1)return ret;
	ret=go(N+1,K);
	if(K==10){
		ret=max(ret,lg[N]+go(N+1,a[N]%10));
	}else{
		ret=max(ret,lg[N]+go(N+1,(K*a[N])%10));
	}
	return ret;
}
Vi ans;
void track(int N,int K){
	if(N==n)return;
	db ret=go(N,K);
	if(go(N+1,K)==ret){
		track(N+1,K);
		return;
	}
	ans.pb(a[N]);
	if(K==10){
		track(N+1,a[N]%10);
	}else{
		track(N+1,(K*a[N])%10);
	}
}
int main(){
	fill(&d[0][0],&d[99999][11],-1.0);
	scanf("%d%d",&n,&k);
	fup(i,0,n-1,1)scanf("%d",a+i),lg[i]=log2(a[i]);
	db t=go(0,10);
	if(t<0)return !printf("-1\n");
	track(0,10);
	printf("%d\n",ans.size());
	for(int x:ans)printf("%d ",x);
}