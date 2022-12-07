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
const ll MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

int num[300001], low[300001],x[300001],y[300001],z[300001];
bool edge[300001];
VPi v[300001];
int cnt;
void dfs(int x, int p) {
	num[x] = low[x] = ++cnt;
	for (auto& P : v[x])
	{
		int next = P.X;
		if (next == p) continue;
		if (!num[next])
		{
			dfs(next, x);
			low[x] = min(low[x], low[next]);
			if(num[next]==low[next])edge[P.Y]=1;
		}
		else 
		{
			low[x] = min(low[x], num[next]);
		}
	}
}
int parent[300001];
bool has[300001];
int find(int a)
{
	if (parent[a] < 0)return a;
	has[parent[a]]|=has[a];
	return parent[a] = find(parent[a]);
}
void merge(int a, int b,int c)
{
	a = find(a), b = find(b);
	has[a]|=c;
	has[a]|=has[b];
	if (a != b)
	{
		parent[a] += parent[b];
		parent[b] = a;
	}
}
VPi nv[300001];
bool go(int N,int des,bool A,int p=-1)
{
	if(N==des)return A;
	for(auto next:nv[N])
	{
		if(next.X==p)continue;
		if(go(next.X,des,A|z[next.Y]|has[next.X],N))return 1;
	}
	return 0;
}
int main() {
	MEM_1(parent);
	int n, m;
	scanf("%d%d", &n, &m);
	fup(i, 1, m, 1)
	{
		scanf("%d%d%d", &x[i], &y[i], &z[i]);
		v[x[i]].push_back(mp(y[i],i));
		v[y[i]].push_back(mp(x[i],i));
	}
	dfs(1,-1);
	fup(i,1,m,1)
		if(!edge[i])
			merge(x[i],y[i],z[i]);
	fup(i,1,m,1)
		if(edge[i])
		{
			x[i]=find(x[i]),y[i]=find(y[i]);
			nv[x[i]].pb(mp(y[i],i));
			nv[y[i]].pb(mp(x[i],i));
		}
	int a,b;
	scanf("%d%d",&a,&b);
	a=find(a),b=find(b);
	puts(go(a,b,has[a])?"YES":"NO");
}