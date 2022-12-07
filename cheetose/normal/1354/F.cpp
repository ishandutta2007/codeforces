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

int n,k;
int d[76][76];
struct A{
	int x,y,i;
}p[75];
Vi v1,v2;
int go(int N,int K){
	if(N==n){
		if(K==k)return 0;
		return -INF;
	}
	int &ret=d[N][K];
	if(~ret)return ret;
	ret=(k-1)*p[N].y+go(N+1,K);
	if(K<k)ret=max(ret,K*p[N].y+p[N].x+go(N+1,K+1));
	return ret;
}
void track(int N,int K){
	if(N==n)return;
	int ret=go(N,K);
	if(ret==(k-1)*p[N].y+go(N+1,K)){
		v2.pb(p[N].i+1);
		track(N+1,K);
	}else{
		v1.pb(p[N].i+1);
		track(N+1,K+1);
	}
}
void solve(){
	MEM_1(d);
	v1.clear(),v2.clear();
	scanf("%d%d",&n,&k);
	fup(i,0,n-1,1){
		int x,y;
		scanf("%d%d",&x,&y);
		p[i]={x,y,i};
	}
	sort(p,p+n,[&](A p1,A p2){return p1.y<p2.y;});
	track(0,0);
	printf("%d\n",2*n-k);
	fup(i,0,k-2,1)printf("%d ",v1[i]);
	for(int x:v2)printf("%d %d ",x,-x);
	printf("%d\n",v1.back());
}
int main() {
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}