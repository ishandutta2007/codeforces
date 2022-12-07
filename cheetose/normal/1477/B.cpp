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

Pi p[200000];
int a[200000],b[200000], tree[524288], lazy[524288];

void init(int node, int S, int E)
{	
	lazy[node]=-1;
	if (S == E){
		tree[node]=b[S];
		return;
	}
	init(2 * node, S, (S + E) / 2);
	init(2 * node + 1, (S + E) / 2 + 1, E);
	tree[node]=tree[node*2]+tree[node*2+1];
}
void propagation(int node, int S, int E)
{
	if (lazy[node] != -1)
	{
		tree[node] = lazy[node]*(E-S+1);
		if (S != E)
		{
			lazy[2 * node] = lazy[node];
			lazy[2 * node + 1] = lazy[node];
		}
		lazy[node] = -1;
	}
}
void upd(int node, int S, int E, int i, int j, int val)
{
	propagation(node, S, E);
	if (i > E || j < S) return;
	if (j >= E && i <= S)
	{
		lazy[node] = val;
		propagation(node, S, E);
		return;
	}
	upd(2 * node, S, (S + E) / 2, i, j, val);
	upd(2 * node + 1, (S + E) / 2 + 1, E, i, j, val);
	tree[node]=tree[node*2]+tree[node*2+1];
}
int find(int node, int S, int E, int i, int j)
{
	propagation(node, S, E);
	if (i > E || j < S) return 0;
	if (j >= E && i <= S) return tree[node];
	return find(node * 2, S, (S + E) / 2, i, j) + find(2 * node + 1, (S + E) / 2 + 1, E, i, j);
}
void solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	fup(i,0,n-1,1)scanf("%1d",a+i);
	fup(i,0,n-1,1)scanf("%1d",b+i);
	init(1,0,n-1);
	fup(i,0,m-1,1){
		scanf("%d%d",&p[i].X,&p[i].Y);
		--p[i].X,--p[i].Y;
	}
	fdn(i,m-1,0,1){
		auto [l,r]=p[i];
		int L=r-l+1;
		int t=find(1,0,n-1,l,r);
		if(L%2==0 && t==L/2){
			puts("NO");
			return;
		}
		if(t<=L/2)upd(1,0,n-1,l,r,0);
		else upd(1,0,n-1,l,r,1);
	}
	fup(i,0,n-1,1){
		if(a[i]!=find(1,0,n-1,i,i)){
			puts("NO");
			return;
		}
	}
	puts("YES");
}
int main() {
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}