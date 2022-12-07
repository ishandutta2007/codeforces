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
const int MOD = 1000000021;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

Vi v[105];
int n,k,mx,p[105],depth[105];
bool chk[105];
void dfs(int N,int d=0){
	depth[N]=d;
	mx=max(mx,d);
	for(int next:v[N]){
		dfs(next,d+1);
	}
}
int T,R,rem;
void dfs2(int N){
	printf("%d ",N);
	if(N==R)return;
	if(!chk[N])rem--;
	for(int next:v[N]){
		if(chk[next])continue;
		if(rem>0){
			dfs2(next);
			printf("%d ",N);
		}
	}
	for(int next:v[N]){
		if(chk[next])dfs2(next);
	}
}
void solve(){
	MEM0(chk);
	mx=0;
	scanf("%d%d",&n,&k);
	fup(i,1,n,1)v[i].clear();
	fup(i,2,n,1){
		int x;
		scanf("%d",&x);
		v[x].pb(i);
		p[i]=x;
	}
	if(k==1){
		puts("0\n1");
		return;
	}
	dfs(1);
	mx=min(mx,k-1);
	printf("%d\n",2*(k-1)-mx);
	fup(i,1,n,1){
		if(depth[i]==mx){
			T=R=i;
			break;
		}
	}
	while(T!=1){
		chk[T]=1;
		T=p[T];
	}
	rem=k-mx;
	dfs2(1);
	puts("");
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}