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
typedef vector<double> Vd;
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

VPi v[500001];
Viii query[500001];
ll tree[1048576], lazy[1048576],ans[500000];
void propagation(int node, int S, int E)
{
	if (lazy[node] != 0)
	{
		tree[node] += lazy[node];
		if (S != E)
		{
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}
void upd(int node, int S, int E, int i, int j, ll val)
{
	propagation(node, S, E);
	if (i > E || j < S) return;
	if (j >= E && i <= S)
	{
		tree[node] += val;
		if (S != E)
		{
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
		}
		return;
	}
	upd(2 * node, S, (S + E) / 2, i, j, val);
	upd(2 * node + 1, (S + E) / 2 + 1, E, i, j, val);
	tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}
ll find(int node, int S, int E, int i, int j)
{
	propagation(node, S, E);
	if (i > E || j < S) return INF;
	if (j >= E && i <= S) return tree[node];
	return min(find(node * 2, S, (S + E) / 2, i, j), find(2 * node + 1, (S + E) / 2 + 1, E, i, j));
}
int S[500005],E[500005];
int n,q;
void dfs1(int N, ll d)
{
	S[N]=E[N]=N;
	if(v[N].empty())upd(1,1,n,N,N,d);
	else upd(1,1,n,N,N,INF);
	for(auto P:v[N])
	{
		dfs1(P.X,d+P.Y);
		E[N]=max(E[N],E[P.X]);
	}
}
void dfs2(int N)
{
	for(auto &I:query[N])
	{
		int l,r,i;
		tie(l,r,i)=I;
		ans[i]=find(1,1,n,l,r);
	}
	for(auto P:v[N])
	{
		int L=S[P.X],R=E[P.X];
		upd(1,1,n,1,L-1,P.Y);
		upd(1,1,n,L,R,-P.Y);
		upd(1,1,n,R+1,n,P.Y);
		dfs2(P.X);
		upd(1,1,n,1,L-1,-P.Y);
		upd(1,1,n,L,R,P.Y);
		upd(1,1,n,R+1,n,-P.Y);
	}
}
int main(){
	scanf("%d%d",&n,&q);
	fup(i,2,n,1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(mp(i,y));
	}
	fup(i,0,q-1,1)
	{
		int x,l,r;
		scanf("%d%d%d",&x,&l,&r);
		query[x].pb(iii(l,r,i));
	}
	dfs1(1,0);
	dfs2(1);
	fup(i,0,q-1,1)printf("%lld\n",ans[i]);
}