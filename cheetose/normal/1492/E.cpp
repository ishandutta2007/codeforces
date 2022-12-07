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

vector<Vi> a;
int n,m;
int ans[250000];
void dfs(int dep){
	fup(i,0,n-1,1){
		Vi vv;
		fup(j,0,m-1,1)if(ans[j]!=a[i][j])vv.pb(j);
		if(vv.size()>2){
			if(vv.size()>6-dep)return;
			for(int x:vv){
				int t=ans[x];
				ans[x]=a[i][x];
				dfs(dep+1);
				ans[x]=t;
			}
			return;
		}
	}
	puts("Yes");
	fup(j,0,m-1,1)printf("%d ",ans[j]);
	exit(0);
}
int main() {
	scanf("%d%d",&n,&m);
	a.resize(n,Vi(m));
	fup(i,0,n-1,1)fup(j,0,m-1,1)scanf("%d",&a[i][j]);
	fup(j,0,m-1,1)ans[j]=a[0][j];
	dfs(0);
	puts("No");
}