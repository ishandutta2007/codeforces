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

int x[200005],y[200005],p[100005],par[100005][17],depth[100001],ans[100001];
Vi v[100005];
bool chk[200005];
int cnt[100005];
int f(int x){return x==p[x]?x:p[x]=f(p[x]);}
void dfs(int N,int p=-1) {
	par[N][0]=p;
	for(int next:v[N]) {
		if(next==p)continue;
		depth[next]=depth[N]+1;
		dfs(next,N);
	}
}
int LCA(int x,int y) {
	if(depth[x]<depth[y])swap(x,y);
	int dif=depth[x]-depth[y];
	for(int j=0;dif>0;j++) {
		if (dif&1)x=par[x][j];
		dif>>=1;
	}
	if(x!=y){
		fdn(j,16,0,1){
			if(par[x][j]!=-1 && par[x][j]!=par[y][j]) {
				x=par[x][j];
				y=par[y][j];
			}
		}
		x=par[x][0];
	}
	return x;
}
int kth(int x,int k){
	fdn(i,16,0,1){
		if(k&(1<<i))x=par[x][i];
	}
	return x;
}
void dfs2(int N,int p=-1){
	for(int next:v[N]){
		if(next==p)continue;
		cnt[next]+=cnt[N];
		dfs2(next,N);
	}
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	iota(p,p+n+1,0);
	fup(i,1,m,1){
		scanf("%d%d",x+i,y+i);
		if(f(x[i])!=f(y[i])){
			p[f(x[i])]=f(y[i]);
			v[x[i]].pb(y[i]);
			v[y[i]].pb(x[i]);
			chk[i]=1;
		}
	}
	dfs(1);
	fup(j,0,15,1){
		fup(i,1,n,1){
			if (par[i][j]!=-1)par[i][j+1]=par[par[i][j]][j];
			else par[i][j+1]=-1;
		}
	}
	fup(i,1,m,1){
		if(!chk[i]){
			if(depth[x[i]]<depth[y[i]])swap(x[i],y[i]);
			int u=LCA(x[i],y[i]);
			if(u==y[i]){
				cnt[kth(x[i],depth[x[i]]-depth[y[i]]-1)]++;
				cnt[x[i]]--;
			}else{
				cnt[1]++;
				cnt[x[i]]--;
				cnt[y[i]]--;
			}
		}
	}
	dfs2(1);
	fup(i,1,n,1)printf("%d",cnt[i]==0);
}