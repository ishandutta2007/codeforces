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
ll k,ans;
ll a[20][20];
Vll v1,v2;
void dfs1(int x,int y,ll c)
{
	if(x<0 || y<0)return;
	if(x==0 && y==0)
	{
		v1.pb(c^a[0][0]);
		return;
	}
	dfs1(x-1,y,c^a[x][y]);
	dfs1(x,y-1,c^a[x][y]);
}
void dfs2(int x,int y,ll c)
{
	if(x>=n || y>=m)return;
	if(x==n-1 && y==m-1)
	{
		v2.pb(c^a[x][y]);
		return;
	}
	dfs2(x+1,y,c^a[x][y]);
	dfs2(x,y+1,c^a[x][y]);
}
void go(int x,int y)
{
	v1.clear();v2.clear();
	dfs1(x,y,0);dfs2(x,y,0);
	sort(ALL(v1));sort(ALL(v2));
	fup(i,0,(int)v1.size()-1,1)
	{
		ans+=upper_bound(ALL(v2),k^v1[i]^a[x][y])-lower_bound(ALL(v2),k^v1[i]^a[x][y]);
	}
}
int main() {
	scanf("%d%d%lld",&n,&m,&k);
	fup(i,0,n-1,1)fup(j,0,m-1,1)scanf("%lld",a[i]+j);
	if(n==1 && m==1)
	{
		return !printf("%d",a[0][0]==k);
	}
	fup(i,0,n-1,1)
	{
		int j=(n+m)/2-i;
		if(j>=0 && j<m)go(i,j);
	}
	printf("%lld",ans);
}