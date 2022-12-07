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

VLLL ans;
Pll exgcd(ll a, ll b){
	if (!b) return{ 1, 0 };
	ll x, y;
	tie(x, y) = exgcd(b, a%b);
	return{ y, x - (a / b)*y };
}
void go(ll x,ll a){
	int k=63-__builtin_clzll(a);
	Vll t={x};
	ll y=x;
	fup(i,1,k,1){
		ans.pb({y,1,y});
		y<<=1;
		t.pb(y);
	}
	fdn(i,k-1,0,1){
		if(a&(1ll<<i)){
			ans.pb({y,1,t[i]});
			y+=t[i];
		}
	}
}
int main(){
	ll a;
	scanf("%lld",&a);
	int k=63-__builtin_clzll(a);
	ll c=a;
	fup(i,1,k,1){
		ans.pb({c,1,c});
		c<<=1;
	}
	ans.pb({a,2,c});
	ll b=a^c;
	if(b&1){
		ans.pb({b,1,b});
		b<<=1;
	}
	auto [x,y]=exgcd(a,-b);
	if(a*x-b*y==-1){
		x=-x,y=-y;
		x+=b;y+=a;
	}
	go(a,x);go(b,y);
	ans.pb({a*x,2,b*y});
	printf("%d\n",ans.size());
	for(auto [a,b,c]:ans){
		printf("%lld %c %lld\n",a,b==1?'+':'^',c);
	}
}