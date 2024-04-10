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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int p[1000005];
int d[1000005],h[1000005];
Pi dd[1000005];
Vi v[1000005];
int n,k;
void dfs1(int N,int dep=0){
	h[N]=dep;
	dd[N]=mp(INF,0);
	if(v[N].empty())dd[N]=mp(h[N]-k,1);
	for(int next:v[N]){
		dfs1(next,dep+1);
		if(dd[next].X<=h[N]){
			dd[N].X=min(dd[N].X,dd[next].X);
			dd[N].Y+=dd[next].Y;
		}
	}
}
void dfs2(int N){
	if(v[N].empty()){
		d[N]=1;
		return;
	}
	for(int next:v[N]){
		dfs2(next);
		int tmp=dd[N].Y;
		if(dd[next].X<=h[N])tmp-=dd[next].Y;
		d[N]=max(d[N],tmp+d[next]);
	}
}
int main() {
	scanf("%d%d",&n,&k);
	fup(i,2,n,1){
		scanf("%d",p+i);
		v[p[i]].pb(i);
	}
	dfs1(1);dfs2(1);
	printf("%d\n",d[1]);
}