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
typedef pair<db, db> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<double> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int,int,int,int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM=MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

ll c[200005],d[200005][2];
Vi v[200005];
void dfs(int N,int p=-1){
	if(p!=-1 && v[N].size()==1){
		d[N][0]=c[N];
		return;
	}
	d[N][1]=INF;
	for(int next:v[N]){
		if(next==p)continue;
		dfs(next,N);
		d[N][1]=min(d[N][1]+d[next][0],d[N][0]+d[next][1]);
		d[N][0]+=d[next][0];
	}
	d[N][0]=min(d[N][0],d[N][1]+c[N]);
}
bool ans[200005];
void dfs2(int N,int k,int p=-1){
	if(p!=-1 && v[N].size()==1){
		if(k&1)ans[N]=1;
		return;
	}
	ll sum=0,mx=-INF;
	for(int next:v[N]){
		if(next==p)continue;
		sum+=d[next][0];
		mx=max(mx,d[next][0]-d[next][1]);
	}
	if(k&1 && sum-mx+c[N]==d[N][0])ans[N]=1;
	
	int t=0;
	for(int next:v[N]){
		if(next==p)continue;
		bool ok=0;
		if(k&1 && sum-d[next][0]+d[next][1]+c[N]==d[N][0])ok=1;
		if(k&2 && sum-d[next][0]+d[next][1]==d[N][1])ok=1;
		t+=ok;
	}
	for(int next:v[N]){
		if(next==p)continue;
		bool ok=0;
		if(k&1 && sum-d[next][0]+d[next][1]+c[N]==d[N][0])ok=1;
		if(k&2 && sum-d[next][0]+d[next][1]==d[N][1])ok=1;
		int nk=ok?2:0;
		if(!ok || t>ok || (k&1 && sum==d[N][0]))nk|=1;
		dfs2(next,nk,N);
	}
}
int main() {
	int n;
	scanf("%d",&n);
	fup(i,1,n,1)scanf("%lld",c+i);
	fup(i,1,n-1,1){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1);
	printf("%lld ",d[1][0]);
	dfs2(1,1);
	Vi vv;
	fup(i,1,n,1)if(ans[i])vv.pb(i);
	printf("%d\n",vv.size());
	for(int x:vv)printf("%d ",x);
}