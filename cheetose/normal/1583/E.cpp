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

Vi v[300005];
int p[300005];
int S[300005],E[300005];
Vi V[300005];
bool cc[300005];
int f(int x){return x==p[x]?x:p[x]=f(p[x]);}
void merge(int x,int y){p[f(x)]=f(y);}

int parent[300005][19], depth[300005];
void dfs(int N,int p=-1) {
	parent[N][0]=p;
	for(int next:v[N]) {
		if(next==p)continue;
		depth[next]=depth[N]+1;
		dfs(next,N);
	}
}
int LCA(int x, int y) {
	if (depth[x] < depth[y])swap(x, y);
	int dif = depth[x] - depth[y];
	for (int j = 0; dif > 0; j++) {
		if (dif & 1)x = parent[x][j];
		dif >>= 1;
	}

	if (x != y) {
		fdn(j,18,0,1) {
			if (parent[x][j] != -1 && parent[x][j] != parent[y][j]) {
				x = parent[x][j];
				y = parent[y][j];
			}
		}
		x = parent[x][0];
	}
	return x;
}
int cnt[300005];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	iota(p,p+n+1,0);
	fup(i,1,m,1){
		int x,y;
		scanf("%d%d",&x,&y);
		if(f(x)==f(y))continue;
		v[x].pb(y);
		v[y].pb(x);
		merge(x,y);
	}
	dfs(1);
	fup(j,0,17,1){
		fup(i,1,n,1){
			if (parent[i][j]!=-1)parent[i][j+1]=parent[parent[i][j]][j];
			else parent[i][j+1]=-1;
		}
	}
	int q;
	scanf("%d",&q);
	fup(i,0,q-1,1){
		scanf("%d%d",S+i,E+i);
		int u=LCA(S[i],E[i]);
		int now=S[i];
		while(now!=u){
			cc[now]^=1;
			V[i].pb(now);
			now=parent[now][0];
		}
		Vi tmp;
		now=E[i];
		while(now!=u){
			cc[now]^=1;
			tmp.pb(now);
			now=parent[now][0];
		}
		V[i].pb(u);
		while(!tmp.empty()){
			V[i].pb(tmp.back());
			tmp.pop_back();
		}
	}
	bool ok=1;
	fup(i,1,n,1){
		if(cc[i])ok=0;
	}
	if(ok){
		puts("YES");
		fup(i,0,q-1,1){
			printf("%d\n",V[i].size());
			for(int x:V[i])printf("%d ",x);
				puts("");
		}
	}else{
		puts("NO");
		fup(i,1,n,1){
			if(cc[i]){
				cnt[i]++;
				cnt[parent[i][0]]++;
			}
		}
		int r=0;
		fup(i,1,n,1)if(cnt[i]&1)r++;
		printf("%d\n",r/2);
	}
}