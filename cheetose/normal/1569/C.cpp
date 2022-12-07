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

ll fac[200005],inv[200005];
int a[200005];
void solve(){
	int n;
	scanf("%d",&n);
	int t1=0,t2=0;
	fup(i,0,n-1,1){
		scanf("%d",a+i);
		if(a[i]>t1){
			t2=t1,t1=a[i];
		}else if(a[i]>t2)t2=a[i];
	}
	if(t1==t2){
		printf("%lld\n",fac[n]);
		return;
	}
	if(t1-t2>1){
		puts("0");
		return;
	}
	int cnt=0;
	fup(i,0,n-1,1){
		if(a[i]==t2)cnt++;
	}
	int rem=n-cnt-1;
	ll ans=0;
	fup(i,cnt,n-1,1){
		ll t=1ll*i*cnt%MOD;
		t=t*fac[rem]%MOD;
		t=t*inv[rem-n+i+1]%MOD;
		t=t*fac[i-1]%MOD;
		ans=(ans+t)%MOD;
	}
	printf("%lld\n",ans);
}
int main(){
	fac[0]=inv[0]=1;
	fup(i,1,200000,1)fac[i]=fac[i-1]*i%MOD;
	inv[200000]=POW(fac[200000],MOD-2);
	fdn(i,199999,1,1)inv[i]=inv[i+1]*(i+1)%MOD;
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}