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
const int MOD = 1000000021;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

db ans;
db EPS=1e-9;
void dfs(int N,db P,db c,db m,db p,db v){
	ans+=p*P*N;
	if(c!=-1){
		if(c<=v+EPS){
			if(m!=-1){
				dfs(N+1,P*c,-1,m+c/2,p+c/2,v);
			}else{
				dfs(N+1,P*c,-1,-1,p+c,v);
			}
		}else{
			if(m!=-1){
				dfs(N+1,P*c,c-v,m+v/2,p+v/2,v);
			}else{
				dfs(N+1,P*c,c-v,-1,p+v,v);
			}
		}
	}
	if(m!=-1){
		if(m<=v+EPS){
			if(c!=-1){
				dfs(N+1,P*m,c+m/2,-1,p+m/2,v);
			}else{
				dfs(N+1,P*m,-1,-1,p+m,v);
			}
		}else{
			if(c!=-1){
				dfs(N+1,P*m,c+v/2,m-v,p+v/2,v);
			}else{
				dfs(N+1,P*m,-1,m-v,p+v,v);
			}
		}
	}
}
void solve(){
	db c,m,p,v;
	scanf("%lf%lf%lf%lf",&c,&m,&p,&v);
	ans=0;
	dfs(1,1,c,m,p,v);
	printf("%.9f\n",ans);
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}