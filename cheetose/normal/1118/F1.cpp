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
#define INF 987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
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
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

Pi operator + (Pi p1, Pi p2)
{
	Pi p;
	p.X=p1.X+p2.X;
	p.Y=p1.Y+p2.Y;
	return p;
}
Pi operator - (Pi p1, Pi p2)
{
	Pi p;
	p.X=p1.X-p2.X;
	p.Y=p1.Y-p2.Y;
	return p;
}
int a[300001],ans;
Vi v[300001];
Pi cnt[300001];
Pi dfs1(int N,int p)
{
	if(a[N]==1)cnt[N].X++;
	if(a[N]==2)cnt[N].Y++;
	for(int next:v[N])
	{
		if(next==p)continue;
		dfs1(next,N);
		cnt[N]=cnt[N]+cnt[next];
	}
	return cnt[N];
}
void dfs2(int N,int p,Pi P)
{
	if(N>1 && (P.X==0 || P.Y==0) && (cnt[N].X==0 || cnt[N].Y==0))ans++;
	for(int next:v[N])
	{
		if(next==p)continue;
		dfs2(next,N,P+cnt[N]-cnt[next]);
	}
}
int main() {
	int n;
	scanf("%d",&n);
	fup(i,1,n,1)scanf("%d",a+i);
	fup(i,1,n-1,1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs1(1,-1);
	dfs2(1,-1,mp(0,0));
	printf("%d",ans);
}