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

ll rem;
struct UF{
	int p[200005];
	void init(int n){
		iota(p,p+n+1,0);
	}
	int f(int x){
		return x==p[x]?x:p[x]=f(p[x]);
	}
	void merge(int x,int y){
		p[f(x)]=f(y);
	}
}A,B;
Vi v[200005];
set<int> S;
void dfs(int N){
	S.erase(N);
	int x=0;
	while(1){
		auto it=S.upper_bound(x);
		if(it==S.end())return;
		x=*it;
		if(!binary_search(ALL(v[N]),x)){
			rem--;
			A.merge(N,x);
			dfs(x);
		}
	}
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	rem=1ll*n*(n-1)/2-m;
	A.init(n);B.init(n);
	Viii vv;
	int c=0;
	fup(i,1,m,1){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		v[x].pb(y);
		v[y].pb(x);
		vv.pb(iii(z,x,y));
		c^=z;
	}
	fup(i,1,n,1)sort(ALL(v[i]));
	sort(ALL(vv));
	fup(i,1,n,1)S.insert(i);
	fup(i,1,n,1){
		if(S.find(i)!=S.end())dfs(i);
	}
	if(rem>0)c=0;
	ll ans=0;
	for(auto [z,x,y]:vv){
		if(A.f(x)!=A.f(y)){
			ans+=z;
			A.merge(x,y);
			B.merge(x,y);
		}else if(B.f(x)!=B.f(y)){
			c=min(c,z);
			B.merge(x,y);
		}
	}
	printf("%lld\n",ans+c);
}