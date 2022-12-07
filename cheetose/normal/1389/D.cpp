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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM=MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

void solve(){
	int n;
	ll k;
	scanf("%d%lld",&n,&k);
	ll l1,r1,l2,r2;
	scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
	if(l1>l2){
		swap(l1,l2);
		swap(r1,r2);
	}
	bool ok=0;
	ll rem=0,rem2=max(r1,r2)-l1;
	if(l2<=r1){
		ok=1;
		k-=n*(min(r1,r2)-l2);
		if(k<=0){
			puts("0");
			return;
		}
		rem2=l2-l1+max(r1,r2)-min(r1,r2);
	}else rem=l2-r1;
	ll ans=INF;
	fup(i,1,n,1){
		ll tmp=i*rem;
		ll k1=k/i+1,r1=k%i;
		ll k2=k/i,r2=i-r1;
		ll tt=min(rem2,k1);
		tmp+=tt*r1;
		k1-=tt;
		tmp+=2*k1*r1;
		tt=min(rem2,k2);
		tmp+=tt*r2;
		k2-=tt;
		tmp+=2*k2*r2;
		ans=min(ans,tmp);
	}
	printf("%lld\n",ans);
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}