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
const int MOD = 1000000009;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

iii e[1000];
VPi v[1000];
int d[1000][1000];
bool chk[1000];
int n,m,k;
void dij(int i){
	MEM0(chk);
	fup(j,0,n-1,1)d[i][j]=INF;
	priority_queue<Pi> q;
	d[i][i]=0;
	q.push({0,i});
	while(!q.empty()){
		int x=q.top().Y;
		q.pop();
		if(chk[x])continue;
		chk[x]=1;
		for(auto [next,cost]:v[x]){
			d[i][next]=min(d[i][next],d[i][x]+cost);
			q.push({-d[i][next],next});
		}
	}
}
int a[1000],b[1000];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	fup(i,0,m-1,1){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		--x,--y;
		e[i]=iii(x,y,z);
		v[x].pb(mp(y,z));
		v[y].pb(mp(x,z));
	}
	fup(i,0,n-1,1)dij(i);
	fup(i,0,k-1,1){
		scanf("%d%d",a+i,b+i);
		--a[i],--b[i];
	}
	int ans=INF;
	fup(i,0,m-1,1){
		auto [x,y,z]=e[i];
		int tmp=0;
		fup(j,0,k-1,1){
			tmp+=min({d[a[j]][b[j]],d[x][a[j]]+d[b[j]][y],d[x][b[j]]+d[a[j]][y]});
		}
		ans=min(ans,tmp);
	}
	printf("%d\n",ans);
}