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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int n,k;
int a[100005];
Vi v[100005];
int s[100005][40];
int ans[100005];
void dfs(int N,int p=-1){
	s[N][0]^=a[N];
	if(p!=-1 && v[N].size()==1){
		return;
	}
	for(int next:v[N]){
		if(next==p)continue;
		dfs(next,N);
		s[N][0]^=s[next][2*k-1];
		fup(i,1,2*k-1,1){
			s[N][i]^=s[next][i-1];
		}
	}
}
void dfs2(int N,Vi vv,int p=-1){
	int r=0;
	fup(i,k,2*k-1,1)r^=vv[i];
	if(r)ans[N]=1;
	if(p!=-1 && v[N].size()==1)return;
	for(int next:v[N]){
		if(next==p)continue;
		Vi nv(2*k);
		nv[0]=vv[2*k-1];
		fup(i,1,2*k-1,1)nv[i]=vv[i-1];
		fup(i,0,2*k-1,1){
			nv[i]^=s[next][i];
			nv[(i+2)%(2*k)]^=s[next][i];
		}
		dfs2(next,nv,N);
	}
}
int main() {
	scanf("%d%d",&n,&k);
	fup(i,1,n-1,1){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	fup(i,1,n,1)scanf("%d",a+i);
	dfs(1);
	Vi vv(2*k);
	fup(i,0,2*k-1,1)vv[i]=s[1][i];
	dfs2(1,vv);
	fup(i,1,n,1)printf("%d ",ans[i]);
}