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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

void solve(){
	ll x1,y1,z1,x2,y2,z2;
	scanf("%lld%lld%lld%lld%lld%lld",&x1,&y1,&z1,&x2,&y2,&z2);
	if(x2<x1 || x2+(z2-1)*y2>x1+(z1-1)*y1 || y2%y1){
		puts("0");
		return;
	}
	if(((x1%y1)+y1)%y1 != ((x2%y1)+y1)%y1){
		puts("0");
		return;
	}
	ll l1=x1+(z1-1)*y1,l2=x2+(z2-1)*y2;
	if(x2-x1<y2 || l1-l2<y2){
		puts("-1");
		return;
	}
	ll ans=0;
	for(ll d=1;d*d<=y2;d++){
		if(y2%d==0){
			if(lcm(d,y1)==y2)ans=(ans+(y2/d)*(y2/d))%MOD;
			if(d*d!=y2){
				ll e=y2/d;
				if(lcm(e,y1)==y2)ans=(ans+(y2/e)*(y2/e))%MOD;
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