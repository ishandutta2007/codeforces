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
#define MEM0(a) memset((a),0,sizeof(a));
#define MEM_1(a) memset((a),-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
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
typedef vector<db> Vd;
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
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int n,k;
VPi v[500001];
ll d[500001][2];
void dfs(int N,int p=-1){
	ll cur=0;
	Vll vv;
	for(Pi &P:v[N]){
		auto [next,cost]=P;
		if(next==p)continue;
		dfs(next,N);
		cur+=d[next][0];
		vv.pb(d[next][1]-d[next][0]+cost);
	}
	sort(vv.rbegin(),vv.rend());
	fup(i,0,min((int)vv.size(),k)-1,1){
		if(vv[i]>0)cur+=vv[i];
	}
	d[N][0]=d[N][1]=cur;
	if(vv.size()>=k && vv[k-1]>0)d[N][1]-=vv[k-1];
}
void solve(){
	scanf("%d%d",&n,&k);
	fup(i,1,n,1)v[i].clear();
	fup(i,1,n-1,1){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		v[x].pb(mp(y,z));
		v[y].pb(mp(x,z));
	}
	dfs(1);
	printf("%lld\n",d[1][0]);
}
int main() {
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}