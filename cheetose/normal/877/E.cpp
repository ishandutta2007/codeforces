#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<cstring>
#include<complex>
#include<cmath>
#include<iomanip>
#include<numeric>
#include<algorithm>
#include<list>
#include<functional>
#include<cassert>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define INF 98765432198765432
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef pair<double, double> Pd;
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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

Vi v[200005];
int sum[400005];
Pi p[200005];
int cc;
void dfs(int N)
{
	p[N].X=++cc;
	sum[p[N].X]++;
	for(int next:v[N])dfs(next);
	p[N].Y=++cc;
}
int tree[1048576];
bool lazy[1048576];
void propagation(int node, int S, int E)
{
	if (lazy[node])
	{
		int t=sum[E]-sum[S-1];
		tree[node]=t-tree[node];
		if (S != E)
		{
			lazy[node * 2] = !lazy[node*2];
			lazy[node * 2 + 1] = !lazy[node*2+1];
		}
		lazy[node] = 0;
	}
}
void upd(int node, int S, int E, int i, int j)
{
	propagation(node,S,E);
	if (i > E || j < S) return;
	if (j >= E && i <= S)
	{
		lazy[node]=!lazy[node];
		propagation(node,S,E);
		return;
	}
	upd(2 * node, S, (S + E) / 2, i, j);
	upd(2 * node + 1, (S + E) / 2 + 1, E, i, j);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}
int find(int node, int S, int E, int i, int j)
{
	propagation(node, S, E);
	if (i > E || j < S) return 0;
	if (j >= E && i <= S) return tree[node];
	return find(node * 2, S, (S + E) / 2, i, j) + find(2 * node + 1, (S + E) / 2 + 1, E, i, j);
}
int main() {
	int n;
	scanf("%d",&n);
	fup(i,2,n,1)
	{
		int x;
		scanf("%d",&x);
		v[x].pb(i);
	}
	dfs(1);
	fup(i,1,2*n,1)sum[i]+=sum[i-1];
	fup(i,1,n,1)
	{
		int x;
		scanf("%d",&x);
		if(x)upd(1,1,cc,p[i].X,p[i].X);
	}
	int q;
	scanf("%d",&q);
	while(q--)
	{
		char s[5]={0};
		int x;
		scanf("%s%d",s,&x);
		if(s[0]=='g') printf("%d\n",find(1,1,cc,p[x].X,p[x].Y));
		else upd(1,1,cc,p[x].X,p[x].Y);
	}
}