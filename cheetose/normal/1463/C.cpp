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

ll t[100000],x[100001];
void solve(){
	int n;
	scanf("%d",&n);
	fup(i,0,n-1,1)scanf("%lld%lld",t+i,x+i);
	int ans=0;
	ll S=0,E=0,t1=0,t2=0;
	fup(i,0,n-1,1){
		if(t2<=t[i]){
			S=E,E=x[i];
			t1=t[i],t2=t1+abs(S-E);
			if(i==n-1 || t[i+1]>=t2)ans++;
		}else{
			if(i==n-1 || t[i+1]>=t2){
				ll tt=t[i]-t1;
				ll y;
				if(S>E){
					y=S-tt;
					if(E<=x[i] && x[i]<=y)ans++;
				}else {
					y=S+tt;
					if(y<=x[i] && x[i]<=E)ans++;
				}	
			}else{
				ll tt=t[i]-t1;
				ll y,z;
				if(S>E){
					y=S-tt,z=y-(t[i+1]-t[i]);
					if(z<=x[i] && x[i]<=y)ans++;
				}else {
					y=S+tt,z=y+(t[i+1]-t[i]);
					if(y<=x[i] && x[i]<=z)ans++;
				}	
			}
		}
	}
	printf("%d\n",ans);
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}