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

int a[501][501];
VPi v[250005];
VPi e;
int par[250005],ans[250005];
int find(int x){return x==par[x]?x:par[x]=find(par[x]);}
void add(int x,int y){
	x=find(x),y=find(y);
	e.pb(mp(y,x));
	par[y]=x;
}
int main() {
	int k;
	scanf("%d",&k);
	Vi vv;
	fup(i,1,k,1){
		fup(j,1,k,1){
			scanf("%d",&a[i][j]);
			vv.pb(a[i][j]);
		}
	}
	COMPRESS(vv);
	fup(i,1,k,1){
		fup(j,1,k,1){
			a[i][j]=lower_bound(ALL(vv),a[i][j])-vv.begin();
			v[a[i][j]].pb(mp(i,j));
		}
	}
	int N=vv.size();
	iota(par,par+250005,0);
	int cc=k+1;
	fup(i,1,k,1)ans[i]=a[i][i];
	fup(x,0,N-1,1){
		for(Pi P:v[x]){
			P.X=find(P.X),P.Y=find(P.Y);
			if(P.X==P.Y)continue;
			if(ans[P.X]==x){
				add(P.X,P.Y);
			}else if(ans[P.Y]==x){
				add(P.Y,P.X);
			}else{
				add(cc,P.X);
				add(cc,P.Y);
				ans[cc++]=x;
			}
		}
	}
	printf("%d\n",cc-1);
	fup(i,1,cc-1,1)printf("%d ",vv[ans[i]]);
	puts("");
	printf("%d\n",cc-1);
	for(auto [x,y]:e)printf("%d %d\n",x,y);
}