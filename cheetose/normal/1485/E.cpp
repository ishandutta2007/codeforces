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

Vi v[200001],vv[200001];
ll a[200001],d[200001],p[200001];
int mx;
void dfs(int N,int depth=0){
	vv[depth].pb(N);
	mx=max(mx,depth);
	for(int next:v[N])dfs(next,depth+1);
}
void solve(){
	mx=0;
	int n;
	scanf("%d",&n);
	fup(i,1,n,1)v[i].clear(),vv[i].clear(),d[i]=0;
	fup(i,2,n,1){
		int x;
		scanf("%d",&x);
		v[x].pb(i);
		p[i]=x;
	}
	fup(i,2,n,1)scanf("%lld",a+i);
	dfs(1);
	priority_queue<ll> q1,q2;
	fdn(i,mx,1,1){
		sort(ALL(vv[i]),[&](int a,int b){return d[a]<d[b];});
		while(!q1.empty())q1.pop();
		while(!q2.empty())q2.pop();
		for(int x:vv[i]){
			q1.push(a[x]);
			q2.push(-a[x]);
			d[p[x]]=max({d[p[x]],d[x]+q1.top()-a[x],d[x]+a[x]+q2.top()});
		}
		while(!q1.empty())q1.pop();
		while(!q2.empty())q2.pop();
		reverse(ALL(vv[i]));
		for(int x:vv[i]){
			q1.push(d[x]+a[x]);
			q2.push(d[x]-a[x]);
			d[p[x]]=max({d[p[x]],q1.top()-a[x],q2.top()+a[x]});
		}
	}
	printf("%lld\n",d[1]);
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}