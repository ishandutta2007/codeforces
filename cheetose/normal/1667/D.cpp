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

Vi v[200005];
int E[200005];
bool dfs(int N,int p=-1){
	int e=0,o=0;
	for(int next:v[N]){
		if(next==p)continue;
		if(!dfs(next,N))return 0;
		if(E[next])e++;
		else o++;
	}
	if(p!=-1){
		if(e>=o){
			o++;
		}else{
			E[N]=1;
			e++;
		}
	}
	if(e>o || o-e>1)return 0;
	return 1;
}
void go(int N,int p=-1){
	Vi vv[2];
	for(int next:v[N]){
		if(next==p)vv[E[N]^1].pb(N);
		else vv[E[next]^1].pb(next);
	}
	int c=v[N].size()&1;
	while(!vv[0].empty() || !vv[1].empty()){
		int t=vv[c].back();
		vv[c].pop_back();
		if(t==N){
			printf("%d %d\n",N,p);
		}else go(t,N);
		c^=1;
	}
}
void solve(){
	int n;
	scanf("%d",&n);
	fup(i,1,n,1){
		E[i]=0;
		v[i].clear();
	}
	fup(i,1,n-1,1){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	if(!dfs(1)){
		puts("NO");
	}else{
		puts("YES");
		go(1);
	}
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}