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

int sz[200001],p[200001];
bool kill[200001];
Vi v[200001];
char s[200002];
int getSz(int N,int pp)
{
    sz[N]=1;
    for(int next:v[N])
	{
        if(next==pp || kill[next])continue;
        sz[N]+=getSz(next,N);
    }
    return sz[N];
}
int get_centroid(int N,int pp,int cap)
{
    for(int next:v[N])
	{
        if(kill[next] || next==pp)continue;
        if(sz[next]>cap) return get_centroid(next,N,cap);
    }
    return N;
}
int a[200001];
ll ans[200001],cnt[1<<20];
void dfs1(int N,int pp,int val,int c)
{
	val^=a[N];
	cnt[val]+=c;
	for(int next:v[N])
	{
		if(next==pp || kill[next])continue;
		dfs1(next,N,val,c);
	}
}
ll dfs2(int N,int pp,int val)
{
	val^=a[N];
	ll res=cnt[val];
	fup(i,0,19,1)res+=cnt[val^(1<<i)];
	for(int next:v[N])
	{
		if(next==pp || kill[next])continue;
		res+=dfs2(next,N,val);
	}
	ans[N]+=res;
	return res;
}
ll dfs3(int N,int pp,int val)
{
	val^=a[N];
	ll res=0;
	if(bitset<20>(val).count()<=1)res++;
	for(int next:v[N])
	{
		if(next==pp || kill[next])continue;
		res+=dfs3(next,N,val);
	}
	return res;
}
void go(int N)
{
    int cap=getSz(N,-1)/2;
    int cen=get_centroid(N,-1,cap);
	ans[cen]++;
	cnt[a[cen]]++;
	for(int next:v[cen])
	{
		if(!kill[next])dfs1(next,cen,a[cen],1);
	}
	ll c=0;
	for(int next:v[cen])
	{
		if(!kill[next])
		{
			dfs1(next,cen,a[cen],-1);
			c+=dfs2(next,cen,0);
			dfs1(next,cen,a[cen],1);
		}
	}
	cnt[a[cen]]--;
	for(int next:v[cen])
	{
		if(!kill[next])dfs1(next,cen,a[cen],-1);
	}
	for(int next:v[cen])
	{
		if(!kill[next])c+=dfs3(next,cen,a[cen]);
	}
	ans[cen]+=c/2;
    kill[cen]=1;
    for(int next:v[cen])
	{
        if(!kill[next])go(next);
    }
}
int main() {
	int n;
	scanf("%d",&n);
	fup(i,1,n-1,1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	scanf("%s",s+1);
	fup(i,1,n,1)a[i]=1<<(s[i]-'a');
	go(1);
	fup(i,1,n,1)printf("%lld ",ans[i]);
}