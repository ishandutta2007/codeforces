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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

ll a,b,c,d;
ll val(ll k){
	ll x;
	if(k<=c)x=0;
	else x=(k-c-1)/d+1;
	ll y=k/d;
	ll res=(-a+b*c)*(y+1);
	res-=((y-x+1)*(x+y)/2*d+(y-x+1)*(c-k))*b;
	return res;
}
ll solve(){
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	if(a>b*c)return -1;
	ll l=0,r=(ll)(1e6)/d;
	while(l+3<r){
		ll m1=(2*l+r)/3,m2=(l+2*r)/3;
		if(val(m1*d)<val(m2*d))r=m2;
		else l=m1;
	}
	ll ans=-a;
	for(ll i=l;i<=r;i++){
		ans=min(ans,val(i*d));
	}
	return -ans;
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)printf("%lld\n",solve());
}