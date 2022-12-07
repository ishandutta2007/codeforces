#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 1000000000000000000
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
typedef pair<db, db> Pd;
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
ll POW(ll a, ll b, ll MMM=MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

int moe[101];
ll ppow(ll a,int i){
	if(i==0)return 1;
	if(i==1)return a;
	ll t=ppow(a,i/2);
	if(t>INF/t)return INF+1;
	t*=t;
	if(i&1){
		if(t>INF/a)return INF+1;
		t*=a;
	}
	return t;
}
int main() {
	moe[1] = 1;
	for(int i=1; i<=100; i++){
		for(int j=2*i; j<=100; j+=i){
			moe[j] -= moe[i];
		}
	}
	int tc;
	scanf("%d",&tc);
	while(tc--){
		ll n;
		scanf("%lld",&n);
		ll ans=0;
		fup(i,2,60,1){
			db t=log(n)/i;
			ll x=(ll)(exp(t));
			ll y=0;
			for(ll tt=max(1LL,x-1);tt<=x+1;tt++){
				if(ppow(tt,i)<=n)y=tt;
			}
			ans-=moe[i]*y;
		}
		printf("%lld\n",n-ans+1);
	}
}