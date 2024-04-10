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
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

VPi v[100001];
ll a[100001],cnt[100001],T,d[100001];
int t[100001];
Pll tree[2097152];
void upd(int node, int S, int E, int k, ll dif)
{
	if (S == E)
	{
		tree[node].X+=dif;
		tree[node].Y+=dif*k;
		return;
	}
	if (k <= (S + E) / 2)upd(node * 2, S, (S + E) / 2, k, dif);
	else upd(node * 2 + 1, (S + E) / 2 + 1, E, k, dif);
	tree[node].X=tree[node*2].X+tree[node*2+1].X;
	tree[node].Y=tree[node*2].Y+tree[node*2+1].Y;
}
ll find(int node, int S, int E, ll time)
{
	if(S==E)return min(tree[node].X,time/S);
	int m=(S+E)/2;
	if(tree[node*2].Y<=time)return tree[node*2].X+find(node*2+1,m+1,E,time-tree[node*2].Y);
	else return find(node*2,S,m,time);
}
int n;
void dfs(int N,ll time)
{
	if(time<=0)return;
	upd(1,1,1000000,t[N],a[N]);
	cnt[N]=find(1,1,1000000,time);
	for(auto next:v[N])
	{
		dfs(next.X,time-2*next.Y);
	}
	upd(1,1,1000000,t[N],-a[N]);
}
void dfs2(int N)
{
	d[N]=cnt[N];
	if(v[N].empty())return;
	for(auto next:v[N])dfs2(next.X);
	int a=-1,b=-1;
	for(auto P:v[N])
	{
		int next=P.X;
		if(a==-1)a=next;
		else if(d[a]<=d[next])b=a,a=next;
		else if(b==-1 || d[b]<=d[next])b=next;
	}
	if(N==1)d[N]=max(d[N],d[a]);
	else d[N]=max(d[N],d[b]);
}
int main() {
	scanf("%d%lld",&n,&T);
	fup(i,1,n,1)scanf("%lld",a+i);
	fup(i,1,n,1)scanf("%d",t+i);
	fup(i,2,n,1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(mp(i,y));
	}
	dfs(1,T);
	dfs2(1);
	printf("%lld",d[1]);
}