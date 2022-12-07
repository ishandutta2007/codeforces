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

VPi v[300005];
int n,m;
ll x;
ll a[300005];
int p[300005];
int find(int x){
	return x==p[x]?x:p[x]=find(p[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x!=y){
		p[y]=x;
	}
}
Vi v1,v2;
void dfs(int N,int p=-1,int pi=-1){
	for(auto [next,i]:v[N]){
		if(next==p)continue;
		dfs(next,N,i);
	}
	if(p!=-1){
		if(a[find(N)]+a[find(p)]>=x){
			v1.pb(pi);
			a[find(N)]+=a[find(p)]-x;
			merge(N,p);
		}else{
			v2.pb(pi);
		}
	}
}
int main() {
	scanf("%d%d%lld",&n,&m,&x);
	fup(i,1,n,1)scanf("%lld",a+i);
	if(accumulate(a+1,a+n+1,0LL)<(n-1)*x)return !printf("NO\n");
	puts("YES");
	iota(p,p+n+1,0);
	fup(i,1,m,1){
		int x,y;
		scanf("%d%d",&x,&y);
		if(find(x)==find(y))continue;
		v[x].pb({y,i});
		v[y].pb({x,i});
		merge(x,y);
	}
	iota(p,p+n+1,0);
	dfs(1);
	for(int x:v1)printf("%d\n",x);
	while(!v2.empty()){
		printf("%d\n",v2.back());
		v2.pop_back();
	}
}