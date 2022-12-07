#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 1987654321
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

int a[400005];

Pi tree[1050000],tree2[1050000];
void init(int node,int S,int E){
	tree2[node]=mp(0,0);
	if(S==E){
		tree[node]=mp(a[S],a[S]);
		return;
	}
	int L=node<<1,R=L|1,M=S+E>>1;
	init(L,S,M);
	init(R,M+1,E);
	tree[node].X=min(tree[L].X,tree[L].Y+tree[R].X);
	tree[node].Y=tree[L].Y+tree[R].Y;
}
void upd(int node, int S, int E, int i){
	if (S == E){
		tree[node]=mp(0,0);
		return;
	}
	int L=node<<1,R=L|1,M=S+E>>1;
	if (i <= M)upd(L, S, M, i);
	else upd(R, M + 1, E, i);
	tree[node].X=min(tree[L].X,tree[L].Y+tree[R].X);
	tree[node].Y=tree[L].Y+tree[R].Y;
}
void upd2(int node, int S, int E, int i,int k){
	if (S == E){
		tree2[node]=mp(k,k);
		return;
	}
	int L=node<<1,R=L|1,M=S+E>>1;
	if (i <= M)upd2(L, S, M, i,k);
	else upd2(R, M + 1, E, i,k);
	tree2[node].X=min(tree2[L].X,tree2[L].Y+tree2[R].X);
	tree2[node].Y=tree2[L].Y+tree2[R].Y;
}
void solve(){
	int n;
	scanf("%d",&n);
	fup(i,1,2*n,1)a[i]=1;
	fup(i,1,n,1){
		int x;
		scanf("%d",&x);
		a[x]=-1;
	}
	Vi A,B;
	fup(i,1,2*n,1){
		if(a[i]==-1)A.pb(i);
		else B.pb(i);
	}
	init(1,1,2*n);
	int ans=0;
	if(tree[1].X>=0)ans++;
	fup(i,0,n-1,1){
		upd(1,1,2*n,A[i]);
		upd(1,1,2*n,B[n-1-i]);
		upd2(1,1,2*n,2*n+1-A[i],-1);
		upd2(1,1,2*n,2*n+1-B[n-1-i],1);
		if(tree2[1].X>=0 && tree[1].X>=0)ans++;
	}
	printf("%d\n",ans);
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}