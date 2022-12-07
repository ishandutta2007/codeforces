#include <bits/stdc++.h>
#include <ext/rope>
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
#define MEM0(a) memset((a),0,sizeof(a));
#define MEM_1(a) memset((a),-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
using namespace __gnu_cxx;
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
typedef vector<double> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int,int,int,int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

Vi v;
int a[4004],N,n;
bool chk[4004];
int d[4001][2001];
int go(int nn,int K){
	if(K==n)return 1;
	if(nn==N)return 0;
	int &ret=d[nn][K];
	if(~ret)return ret;
	ret=go(nn+1,K);
	if(K+v[nn]<=n)ret=max(ret,go(nn+1,K+v[nn]));
	return ret;
}
void solve(){
	v.clear();
	scanf("%d",&n);
	fup(i,1,2*n,1)scanf("%d",a+i),chk[i]=0;
	fup(i,0,2*n,1)fup(j,0,n,1)d[i][j]=-1;
	int now=2*n,t=0;
	fdn(i,2*n,1,1){
		t++;
		if(a[i]==now){
			v.pb(t);
			t=0;
		}
		chk[a[i]]=1;
		while(now>0 && chk[now])now--;
	}
	N=v.size();
	int tt=go(0,0);
	puts(tt?"YES":"NO");
}
int main() {
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}