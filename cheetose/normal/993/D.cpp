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
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

Pll p[50];
ll d[50][50][5001];
int n;
ll go(int N,int k,int c){
	if(N==n){
		if(c==0)return 0;
		return INF;
	}
	ll &ret=d[N][k][c];
	if(~ret)return ret;
	ret=INF;
	int M=N;
	while(M<n && p[N].X==p[M].X)M++;
	M--;
	ll s=0;
	int t=0,cnt=0;
	fup(i,N,M,1){
		s+=p[i].X,t+=p[i].Y;
	}
	if(c>=t){
		ret=min(ret,s+go(M+1,k+M-N+1,c-t));
	}
	fdn(i,M,N,1){
		cnt++;
		if(cnt>k)break;
		s-=p[i].X,t-=p[i].Y;
		ret=min(ret,s+go(M+1,k+M-N+1-2*cnt,c-t));
	}
	return ret;
}
int main(){
	MEM_1(d);
	scanf("%d",&n);
	fup(i,0,n-1,1){
		scanf("%lld",&p[i].X);
		p[i].X*=1000;
	}
	fup(i,0,n-1,1){
		scanf("%lld",&p[i].Y);
	}
	if(n==1){
		return !printf("%lld\n",(p[0].X-1)/p[0].Y+1);
	}
	sort(p,p+n);reverse(p,p+n);
	ll ans=INF;
	fup(i,1,5000,1){
		ll t=go(0,0,i);
		if(t!=INF)ans=min(ans,(t-1)/i+1);
	}
	printf("%lld\n",ans);
}