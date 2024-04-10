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

int n,k;
Vi v[5000];
void add(int &a,int b){a=(a+b)%MOD;}
int mul(int a,int b){return (1ll*a*b)%MOD;}
int d[5000][5000];
int dfs(int N,int p=-1){
	d[N][0]=1;
	int h=0;
	for(int next:v[N]){
		if(next==p)continue;
		int nh=dfs(next,N);
		Vi tmp(max(h,nh+1)+1);
		fup(i,0,h,1){
			fup(j,0,nh,1){
				if(i+j+1<=k)add(tmp[max(i,j+1)],mul(d[N][i],d[next][j]));
				if(max(i,j)<=k)add(tmp[i],mul(d[N][i],d[next][j]));
			}
		}
		h=max(h,nh+1);
		fup(i,0,h,1)d[N][i]=tmp[i];
	}
	return h;
}
int main(){
	scanf("%d%d",&n,&k);
	fup(i,1,n-1,1){
		int x,y;
		scanf("%d%d",&x,&y);
		--x,--y;
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(0);
	int ans=0;
	fup(i,0,k,1)add(ans,d[0][i]);
	printf("%d\n",ans);
}