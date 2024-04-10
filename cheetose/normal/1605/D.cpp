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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

Vi v[200005];
Vi V[2];
void dfs(int N,int p=-1,int d=0){
	V[d].pb(N);
	for(int next:v[N]){
		if(next==p)continue;
		dfs(next,N,d^1);
	}
}
Vi vv[20];
int ans[200005];
void solve(){
	V[0].clear(),V[1].clear();
	int n;
	scanf("%d",&n);
	fup(i,1,n,1)v[i].clear();
	fup(i,1,n-1,1){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1);
	int c;
	fup(i,1,n,1){
		int x=31-__builtin_clz(i);
		if(i==n)c=x;
		vv[x].pb(i);
	}
	int q=0,w=min(V[0].size(),V[1].size());
	if(V[0].size()>V[1].size())q=1;
	Vi tmp,tmp2;
	fup(i,0,c,1){
		if(w&(1<<i))tmp.pb(i);
		else tmp2.pb(i);
	}
	for(int x:tmp){
		while(vv[x].size()){
			ans[V[q].back()]=vv[x].back();
			V[q].pop_back();
			vv[x].pop_back();
		}
	}
	q^=1;
	for(int x:tmp2){
		while(vv[x].size()){
			ans[V[q].back()]=vv[x].back();
			V[q].pop_back();
			vv[x].pop_back();
		}
	}
	fup(i,1,n,1)printf("%d ",ans[i]);
	puts("");
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}