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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

ll a[200005];
ll s[2][200005];
void solve(){
	int n;
	scanf("%d",&n);
	ll sum=0;
	fup(i,1,n,1)scanf("%lld",a+i),sum+=a[i];
	sum=sum/2+1;
	fup(i,1,n,1){
		s[0][i]=s[0][i-1],s[1][i]=s[1][i-1];
		s[i&1][i]+=a[i];
	}
	ll ans=0;
	fup(i,1,n-1,1){
		if(s[0][i]+s[1][i]>=sum)ans++;
	}
	ll tmp=0;
	fdn(i,n,1,1){
		tmp+=a[i];
		if(tmp>=sum)ans++;
	}
	fup(ST,n-1,n,1){
		tmp=0;
		fdn(i,ST,2,1){
			tmp+=a[i];
			if(tmp>=sum){
				if(ST==n-1){
					ans=(ans+i-1)%MOD;
				}else{
					ans=(ans+i-2)%MOD;
				}
				continue;
			}
			int l=1,r=i;
			int c=i&1;
			int ok=0;
			while(l<=r){
				int m=l+r>>1;
				if(tmp+s[c][i-1]-s[c][m-1]>=sum)l=m+1,ok=m;
				else r=m-1;
			}
			if(ok){
				ans=(ans+ok/2)%MOD;
			}
			l=3,r=i,ok=0;
			while(l<=r){
				int m=l+r>>1;
				if(tmp+s[c][i-1]-s[c][m-1]+a[1]>=sum)l=m+1,ok=m;
				else r=m-1;
			}
			if(ok>=3)ans=(ans+(ok-1)/2)%MOD;
		}
	}
	printf("%lld\n",ans);
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}