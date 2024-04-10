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
#define MEM0(a) memset((a),0,sizeof(a));
#define MEM_1(a) memset((a),-1,sizeof(a));
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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

VPi v[5001];
int depth[5001],parent[5001];
int lca[5001][5001],mx[5001][5001];
int LCA(int x,int y){
	if(x==y)return x;
	int &ret=lca[x][y];
	if(~ret)return ret;
	if(depth[x]>depth[y])return ret=LCA(parent[x],y);
	return ret=LCA(x,parent[y]);
}
void dfs(int N,int d=0,int p=-1){
	depth[N]=d,parent[N]=p;
	for(Pi P:v[N]){
		if(P.X==p)continue;
		dfs(P.X,d+1,N);
	}
}
int x[5000],y[5000],z[5000],ans[5000];
void dfs2(int N,int p=-1){
	for(Pi P:v[N]){
		if(P.X==p)continue;
		ans[P.Y]=mx[N][P.X];
		dfs2(P.X,N);
	}
}
int main() {
	MEM_1(lca);
	int n,q;
	scanf("%d",&n);
	fup(i,1,n,1)fup(j,1,n,1)mx[i][j]=1;
	fup(i,1,n-1,1){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(mp(y,i));
		v[y].pb(mp(x,i));
	}
	dfs(1);
	scanf("%d",&q);
	fup(i,0,q-1,1){
		scanf("%d%d%d",x+i,y+i,z+i);
		int u=LCA(x[i],y[i]);
		int xx=x[i],yy=y[i];
		while(xx!=u){
			mx[parent[xx]][xx]=max(mx[parent[xx]][xx],z[i]);
			xx=parent[xx];
		}
		while(yy!=u){
			mx[parent[yy]][yy]=max(mx[parent[yy]][yy],z[i]);
			yy=parent[yy];
		}
	}
	fup(i,0,q-1,1){
		int m=INF;
		int u=LCA(x[i],y[i]);
		int xx=x[i],yy=y[i];
		while(xx!=u){
			m=min(m,mx[parent[xx]][xx]);
			xx=parent[xx];
		}
		while(yy!=u){
			m=min(m,mx[parent[yy]][yy]);
			yy=parent[yy];
		}
		if(m!=z[i])return !printf("-1\n");
	}
	dfs2(1);
	fup(i,1,n-1,1)printf("%d ",ans[i]);
}