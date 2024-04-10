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

int a[55];
int main(){
	int n;
	scanf("%d",&n);
	fup(i,0,n-1,1)scanf("%d",a+i);
	vector<Vi> ans;
	fup(k,1,n,1){
		Vi vv;
		int r=n+1-k;
		if(r&1){
			fup(x,0,n-1,1){
				if(a[x]==k){
					if(x>0)vv.pb(x);
					if(r-x>0)vv.pb(r-x);
				}
			}
			fup(t,1,n-r,1)vv.pb(1);
		}else{
			fup(t,1,n-r,1)vv.pb(1);
			fup(x,0,n-1,1){
				if(a[x]==k){
					if(x+r-n+1>0)vv.pb(x+r-n+1);
					if(n-x-1>0)vv.pb(n-x-1);
				}
			}
		}
		if(vv.size()==1)continue;
		ans.pb(vv);
		int c=0;
		VPi tmp;
		for(int x:vv){
			tmp.pb(mp(c,c+x-1));
			c+=x;
		}
		reverse(ALL(tmp));
		Vi na;
		for(Pi P:tmp){
			fup(x,P.X,P.Y,1)na.pb(a[x]);
		}
		fup(i,0,n-1,1)a[i]=na[i];
	}
	printf("%d\n",ans.size());
	for(auto &V:ans){
		printf("%d ",V.size());
		for(int x:V)printf("%d ",x);
			puts("");
	}
}