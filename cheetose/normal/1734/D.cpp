#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define eb emplace_back
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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

ll a[200005];
void solve(){
	int n,k;
	scanf("%d%d",&n,&k);
	fup(i,1,n,1)scanf("%lld",a+i);
	VPll L,R;
	for(int tmp=k;tmp<n;){
		ll x=0,y=0;
		for(int cur=tmp+1;cur<=n;cur++){
			y+=a[cur];
			x=min(x,y);
			if(y>=0 || cur==n){
				tmp=cur;
				break;
			}
		}
		R.eb(y,-x);
	}
	for(int tmp=k;tmp>1;){
		ll x=0,y=0;
		for(int cur=tmp-1;cur>=1;cur--){
			y+=a[cur];
			x=min(x,y);
			if(y>=0 || cur==1){
				tmp=cur;
				break;
			}
		}
		L.eb(y,-x);
	}
	reverse(ALL(L));reverse(ALL(R));
	ll now=a[k];
	while(L.size() && R.size()){
		bool ok=0;
		if(now>=L.back().Y){
			now+=L.back().X;
			L.pop_back();
			ok=1;
		}else if(now>=R.back().Y){
			now+=R.back().X;
			R.pop_back();
			ok=1;
		}
		if(!ok){
			puts("NO");
			return;
		}
	}
	puts("YES");
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}