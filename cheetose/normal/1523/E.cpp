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

ll fac[200001],inv[200001],rev[100001];
ll nCr(int n,int r){
	if(n<0 || r>n)return 0;
	ll c=fac[n];
	c=c*inv[r]%MOD;
	c=c*inv[n-r]%MOD;
	return c;
}
int main(){
	fup(i,1,100000,1)rev[i]=POW(i,MOD-2);
	fac[0]=inv[0]=1;
	fup(i,1,200000,1)fac[i]=fac[i-1]*i%MOD;
	inv[200000]=POW(fac[200000],MOD-2);
	fdn(i,199999,1,1)inv[i]=inv[i+1]*(i+1)%MOD;
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int n,k;
		scanf("%d%d",&n,&k);
		ll pr=n,ans=0,prob=rev[n];
		fup(x,2,n,1){
			prob=prob*rev[n-x+1]%MOD;
			int t=k*(x-1)+1;
			if(t>n){
				ll tmp=pr*prob%MOD;
				tmp=tmp*(n-x+1)%MOD;
				ans=(ans+tmp*x)%MOD;
				break;
			}
			ll tot=pr*(n-x+1)%MOD;
			ll now=nCr(x+n-t,n-t)*fac[x]%MOD;
			ll fail=(tot-now+MOD)%MOD;
			fail=fail*prob%MOD;
			fail=fail*x%MOD;
			ans=(ans+fail)%MOD;
			pr=now;
		}
		printf("%lld\n",ans);
	}
}