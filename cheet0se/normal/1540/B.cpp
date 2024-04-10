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

ll fac[100001],inv[100001];
ll nCr(int n, int r)
{
	if(r<0 || r>n)return 0;
	ll c = fac[n];
	c = (c*inv[r]) % MOD;
	c = (c*inv[n - r]) % MOD;
	return c;
}
Vi v[202];
int d[202],par[202],LCA[202][202];
void dfs(int N,int p=-1,int D=0){
	d[N]=D;
	par[N]=p;
	for(int next:v[N]){
		if(next==p)continue;
		dfs(next,N,D+1);
	}
}
int n;
int lca(int x,int y){
	if(x==y)return x;
	int &ret=LCA[x][y];
	if(~ret)return ret;
	if(d[x]==d[y])return ret=lca(par[x],par[y]);
	if(d[x]>d[y])return ret=lca(par[x],y);
	return ret=lca(x,par[y]);
}
ll C=(MOD+1)/2;
ll d2[202][202];
ll go2(int L,int R){
	if(L==0)return 1;
	if(R==0)return 0;
	ll &ret=d2[L][R];
	if(~ret)return ret;
	return ret=(go2(L-1,R)+go2(L,R-1))*C%MOD;
}
ll go(int N){
	MEM_1(LCA);
	ll res=0;
	dfs(N);
	fup(i,1,n,1){
		fup(j,1,i-1,1){
			int t=lca(i,j);
			if(i==t)res=(res+1)%MOD;
			else if(j==t)continue;
			else{
				int c1=d[i]-d[t],c2=d[j]-d[t];
				res=(res+go2(c1,c2))%MOD;
			}
		}
	}
	return res;
}

int main(){
	MEM_1(d2);
	fac[0] = inv[0] = 1;
	fup(i, 1, 100000, 1)
		fac[i] = (fac[i - 1] * i) % MOD;
	inv[100000] = POW(fac[100000], MOD - 2);
	fdn(i, 99999, 1, 1)
		inv[i] = (inv[i + 1] * (i+1)) % MOD;
	scanf("%d",&n);
	fup(i,1,n-1,1){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	ll ans=0;
	fup(i,1,n,1){
		ans=(ans+go(i))%MOD;
	}
	ans=ans*(POW(n,MOD-2))%MOD;
	printf("%lld\n",ans);
}