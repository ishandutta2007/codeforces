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

int a[100005];
void solve(){
	int n;
	scanf("%d",&n);
	iota(a,a+n+1,0);
	ll ans=0;
	VPi res;
	fup(i,1,n-1,1){
		int t1=i-1,t2=n-i;
		if(t1<t2){
			ans+=1LL*t2*t2;
			swap(a[i],a[n]);
			res.pb(mp(i,n));
		}else{
			ans+=1LL*t1*t1;
			swap(a[1],a[i]);
			res.pb(mp(i,1));
		}
	}
	printf("%lld\n",ans);
	fup(i,1,n,1)printf("%d ",a[i]);
	puts("");
	printf("%d\n",res.size());
	reverse(ALL(res));
	for(auto [x,y]:res)printf("%d %d\n",x,y);
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}