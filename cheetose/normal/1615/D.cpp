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

VPi v[200005],vv[200005];
int s[200005];
int parent[200001];
void dfs(int N,int p=-1){
	parent[N]=p;
	for(auto [next,z]:v[N]){
		if(next==p)continue;
		dfs(next,N);
	}
}
bool dfs2(int N,int p=-1,int c=0){
	s[N]=c;
	for(auto [next,z]:vv[N]){
		if(next==p)continue;
		if(s[next]==-1 && !dfs2(next,N,c^z))return 0;
		else if(s[next]!=c^z)return 0;
	}
	return 1;
}
void solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	fup(i,1,n,1)v[i].clear(),vv[i].clear(),s[i]=-1;
	fup(i,1,n-1,1){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		v[x].pb(mp(y,z));
		v[y].pb(mp(x,z));
		if(z!=-1){
			int zz=__builtin_popcount(z)&1;
			vv[x].pb(mp(y,zz));
			vv[y].pb(mp(x,zz));
		}
	}
	dfs(1);
	fup(i,0,m-1,1){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		vv[x].pb(mp(y,z));
		vv[y].pb(mp(x,z));
	}
	fup(i,1,n,1){
		if(s[i]==-1){
			bool t=dfs2(i);
			if(!t){
				puts("NO");
				return;
			}
		}
	}
	puts("YES");
	fup(x,1,n,1){
		for(auto [y,z]:v[x]){
			if(parent[y]==x){
				if(z!=-1)printf("%d %d %d\n",x,y,z);
				else printf("%d %d %d\n",x,y,s[x]^s[y]);
			}
		}
	}
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}