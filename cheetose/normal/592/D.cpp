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

bool chk[130000];
Vi v[130000];
int n,m,R;
int edge;
Pi ans=mp(-1,-1);
void upd(Pi &a,Pi &b,Pi c)
{
	if(c.X>a.X || (c.X==a.X && c.Y<a.Y))
	{
		b=a;
		a=c;
		return;
	}
	else if(c.X>b.X || (c.X==b.X && c.Y<b.Y))
		b=c;
}
void upd2(Pi &a,Pi b)
{
	if(b.X>a.X || (b.X==a.X && b.Y<a.Y))a=b;
}
Pi dfs(int N,int p)
{
	Pi a=mp(-1,-1),b=mp(-1,-1);
	if(chk[N])upd(a,b,mp(0,N));
	for(int next:v[N])
	{
		if(next==p)continue;
		Pi c=dfs(next,N);
		if(c.X!=-1)edge++;
		else continue;
		c.X++;
		upd(a,b,c);
	}
	if(a.X==-1)return a;
	upd2(ans,a);
	if(b.X!=-1)upd2(ans,mp(a.X+b.X,min(a.Y,b.Y)));
	return a;
}
int main() {
	scanf("%d%d",&n,&m);
	fup(i,2,n,1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	fup(i,1,m,1)
	{
		scanf("%d",&R);
		chk[R]=1;
	}
	dfs(R,-1);
	printf("%d\n%d",ans.Y,2*edge-ans.X);
}