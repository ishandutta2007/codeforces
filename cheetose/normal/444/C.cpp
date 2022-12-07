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
#define y0 y12
#define y1 y22
#define INF 987654321
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
typedef tuple<int,int,int,int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const ll MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

int n,m;
ll a[100001], tree[262144], tree2[262144], lazy[262144], lazy2[262144];
void init2(int node, int S, int E)
{
	if (S == E)
	{
		tree2[node] = S;
		return;
	}
	init2(2 * node, S, (S + E) / 2);
	init2(2 * node + 1, (S + E) / 2 + 1, E);
}
void propagation(int node, int S, int E)
{
	if (lazy[node] != 0)
	{
		tree[node] += lazy[node] * (E - S + 1);
		if (S != E)
		{
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}
void propagation2(int node, int S, int E)
{
	if (lazy2[node] != 0)
	{
		tree2[node] = lazy2[node];
		if (S != E)
		{
			lazy2[2 * node] = lazy2[node];
			lazy2[2 * node + 1] = lazy2[node];
		}
		lazy2[node] = 0;
	}
}
void upd(int node, int S, int E, int i, int j, ll val)
{
	propagation(node, S, E);
	if (i > E || j < S) return;
	if (j >= E && i <= S)
	{
		tree[node] += val*(E - S + 1);
		if (S != E)
		{
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
		}
		return;
	}
	upd(2 * node, S, (S + E) / 2, i, j, val);
	upd(2 * node + 1, (S + E) / 2 + 1, E, i, j, val);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}
void upd2(int node, int S, int E, int i, int j, ll val)
{
	if (i > E || j < S) return;
	propagation2(node, S, E);
	if(tree2[node]!=0 && j>=E && i<=S)
	{
		upd(1,1,n,S,E,(ll)abs(tree2[node]-val));
		if (j >= E && i <= S)
		{
			tree2[node] = val;
			if (S != E)
			{
				lazy2[node * 2] = val;
				lazy2[node * 2 + 1] = val;
			}
			return;
		}
	}
	else
	{
		if(S==E)return;
		upd2(2 * node, S, (S + E) / 2, i, j, val);
		upd2(2 * node + 1, (S + E) / 2 + 1, E, i, j, val);
		if(tree2[node*2]==tree2[node*2+1])tree2[node]=tree2[node*2];
		else tree2[node]=0;
	}
}
ll find(int node, int S, int E, int i, int j)
{
	propagation(node, S, E);
	if (i > E || j < S) return 0;
	if (j >= E && i <= S) return tree[node];
	return find(node * 2, S, (S + E) / 2, i, j) + find(2 * node + 1, (S + E) / 2 + 1, E, i, j);
}
int main() {
	scanf("%d%d",&n,&m);
	init2(1,1,n);
	while(m--)
	{
		int o,l,r;
		ll x;
		scanf("%d%d%d",&o,&l,&r);
		if(o==1)
		{
			scanf("%lld",&x);
			upd2(1,1,n,l,r,x);
		}
		else printf("%lld\n",find(1,1,n,l,r));
	}
}