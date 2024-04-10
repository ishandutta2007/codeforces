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
#define INF 987654321987654231
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

int n,m;
ll nC3(int x){return (ll)x*(x-1)*(x-2)/6;}
ll nC2(int x){return (ll)x*(x-1)/2;}
Vi v[100001];
int depth[100001];
bool visit[100001];
bool dfs(int N,int d)
{
	depth[N]=d;
	for(int next:v[N])
	{
		if(depth[next]!=-1 && (depth[next]-depth[N])%2==0)return 1;
		if(depth[next]==-1 && dfs(next,d+1))return 1;
	}
	return 0;
}
int a[2];
void go(int N,int c)
{
	visit[N]=1;
	a[c]++;
	for(int next:v[N])
	{
		if(!visit[next])go(next,1-c);
	}
}
int main() {
	MEM_1(depth);
	scanf("%d%d",&n,&m);
	if(m==0)return !printf("3 %lld",nC3(n));
	fup(i,1,m,1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	fup(i,1,n,1)if(depth[i]==-1 && dfs(i,0))return !printf("0 1");
	bool ok=0;
	fup(i,1,n,1)if(v[i].size()>1)ok=1;
	if(ok)
	{
		ll ans=0;
		fup(i,1,n,1)
		{
			if(!visit[i])
			{
				MEM0(a);
				go(i,0);
				ans+=nC2(a[0])+nC2(a[1]);
			}
		}
		return !printf("1 %lld",ans);
	}
	else return !printf("2 %lld",(ll)(n-2)*m);
}