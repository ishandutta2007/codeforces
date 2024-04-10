#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 2987654321987654321
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
const int MOD = 993244853;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int n,m,k;
ll a[100000],b[100000],c[100000];
void solve(){
	scanf("%d%d%d",&n,&m,&k);
	fup(i,0,n-1,1)scanf("%lld",a+i);
	sort(a,a+n);
	fup(i,0,m-1,1)scanf("%lld",b+i);
	sort(b,b+m);
	fup(i,0,k-1,1)scanf("%lld",c+i);
	sort(c,c+k);
	ll ans=INF;
	fup(i,0,n-1,1){
		ll x=a[i];
		int t=lower_bound(b,b+m,x)-b;
		fup(j,max(0,t-1),min(t+1,m-1),1){
			ll y=b[j];
			int tt=lower_bound(c,c+k,(x+y)/2)-c;
			fup(l,max(0,tt-1),min(tt+1,k-1),1){
				ll z=c[l];
				ans=min(ans,(x-y)*(x-y)+(y-z)*(y-z)+(z-x)*(z-x));
			}
		}
		t=lower_bound(c,c+k,x)-c;
		fup(l,max(0,t-1),min(t+1,l-1),1){
			ll z=c[l];
			int tt=lower_bound(b,b+m,(x+z)/2)-b;
			fup(j,max(0,tt-1),min(tt+1,m-1),1){
				ll y=b[j];
				ans=min(ans,(x-y)*(x-y)+(y-z)*(y-z)+(z-x)*(z-x));
			}
		}
	}
	fup(j,0,m-1,1){
		ll y=b[j];
		int t=lower_bound(c,c+k,y)-c;
		fup(l,max(0,t-1),min(t+1,k-1),1){
			ll z=c[l];
			int tt=lower_bound(a,a+n,(y+z)/2)-a;
			fup(i,max(0,tt-1),min(tt+1,n-1),1){
				ll x=a[i];
				ans=min(ans,(x-y)*(x-y)+(y-z)*(y-z)+(z-x)*(z-x));
			}
		}
	}
	printf("%lld\n",ans);
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}