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
#define INF 1987654321
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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

Vi v[100001];
int parent[100001][17], depth[100001];
int num[100001],rev[100001];
int cc,n,q;
int mintree[262144],maxtree[262144];
void upd(int node, int S, int E, int k, int dif)
{
	if (S == E)
	{
		mintree[node]=maxtree[node]=dif;
		return;
	}
	if (k <= (S + E) / 2)upd(node * 2, S, (S + E) / 2, k, dif);
	else upd(node * 2 + 1, (S + E) / 2 + 1, E, k, dif);
	maxtree[node]=max(maxtree[node*2],maxtree[node*2+1]);
	mintree[node]=min(mintree[node*2],mintree[node*2+1]);
}
int minfind(int node, int S, int E, int i, int j)
{
	if (i > E || j < S)return INF;
	if (i <= S && j >= E)return mintree[node];
	return min(minfind(node * 2, S, (S + E) / 2, i, j), minfind(node * 2 + 1, (S + E) / 2 + 1, E, i, j));
}
int maxfind(int node, int S, int E, int i, int j)
{
	if (i > E || j < S)return 0;
	if (i <= S && j >= E)return maxtree[node];
	return max(maxfind(node * 2, S, (S + E) / 2, i, j), maxfind(node * 2 + 1, (S + E) / 2 + 1, E, i, j));
}
void dfs(int N,int d)
{
	depth[N]=d;
	num[N]=++cc;
	rev[cc]=N;
	upd(1,1,n,N,cc);
	for(int next:v[N])
	{
		dfs(next,d+1);
	}
}
int LCA(int x, int y)
{
	if (depth[x] < depth[y])swap(x, y);
	int dif = depth[x] - depth[y];
	for (int j = 0; dif > 0; j++)
	{
		if (dif & 1)x = parent[x][j];
		dif /= 2;
	}

	if (x != y)
	{
		fdn(j,16,0,1)
		{
			if (parent[x][j] != -1 && parent[x][j] != parent[y][j])
			{
				x = parent[x][j];
				y = parent[y][j];
			}
		}
		x = parent[x][0];
	}
	return x;
}
int main() {
	MEM_1(depth);
	MEM_1(parent);
	scanf("%d%d",&n,&q);
	fup(i,2,n,1)
	{
		scanf("%d",&parent[i][0]);
		v[parent[i][0]].pb(i);
	}
	dfs(1,0);
	fup(j,0,15,1)
		fup(i,1,n,1)
		if (parent[i][j] != -1)
			parent[i][j + 1] = parent[parent[i][j]][j];
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		int a1=rev[minfind(1,1,n,l,r)],a2=rev[maxfind(1,1,n,l,r)];
		int b1=LCA(rev[min(minfind(1,1,n,l,a1-1),minfind(1,1,n,a1+1,r))],rev[max(maxfind(1,1,n,l,a1-1),maxfind(1,1,n,a1+1,r))]);
		int b2=LCA(rev[min(minfind(1,1,n,l,a2-1),minfind(1,1,n,a2+1,r))],rev[max(maxfind(1,1,n,l,a2-1),maxfind(1,1,n,a2+1,r))]);
		if(depth[b1]>depth[b2])printf("%d %d\n",a1,depth[b1]);
		else printf("%d %d\n",a2,depth[b2]);
	}
}