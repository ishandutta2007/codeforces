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

int n,m;
Vi v[400];
int dist[400][400];
void bfs(int i){
	fup(j,0,n-1,1)dist[i][j]=-1;
	dist[i][i]=0;
	queue<int> q;
	q.push(i);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int y:v[x]){
			if(dist[i][y]==-1){
				dist[i][y]=dist[i][x]+1;
				q.push(y);
			}
		}
	}
}
ll ans[400][400];
int main(){
	scanf("%d%d",&n,&m);
	fup(i,0,m-1,1){
		int x,y;
		scanf("%d%d",&x,&y);
		--x,--y;
		v[x].pb(y);
		v[y].pb(x);
	}
	fup(i,0,n-1,1)bfs(i);
	fup(i,0,n-1,1){
		fup(j,i,n-1,1){
			Vi chk(n);
			int cnt=0;
			fup(k,0,n-1,1){
				if(dist[i][k]+dist[k][j]==dist[i][j])chk[k]=1,cnt++;
			}
			if(cnt!=dist[i][j]+1)continue;
			ans[i][j]=1;
			fup(x,0,n-1,1){
				if(chk[x])continue;
				int t=0;
				for(int y:v[x]){
					if(dist[i][y]+1==dist[i][x] && dist[j][y]+1==dist[j][x])t++;
				}
				ans[i][j]=ans[i][j]*t%MOD;
			}
			ans[j][i]=ans[i][j];
		}
	}
	fup(i,0,n-1,1){
		fup(j,0,n-1,1)printf("%lld ",ans[i][j]);
		puts("");
	}
}