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
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

int x[100000],y[100000];
VPi xx[100000],yy[100000];
Vi v[100000];
bool chk[100000];
set<int> XX,YY;
ll pow2[200001];
int sz,deg;
void dfs(int N)
{
	chk[N]=1;
	sz++;
	deg+=v[N].size();
	XX.insert(x[N]);
	YY.insert(y[N]);
	for(int next:v[N])
	{
		if(!chk[next])dfs(next);
	}
}
int main() {
	pow2[0]=1;
	fup(i,1,200000,1)pow2[i]=(pow2[i-1]<<1)%MOD;
	int n;
	scanf("%d",&n);
	Vi vx,vy;
	fup(i,0,n-1,1)
	{
		scanf("%d%d",x+i,y+i);
		vx.pb(x[i]);
		vy.pb(y[i]);
	}
	sort(ALL(vx));sort(ALL(vy));
	vx.resize(unique(ALL(vx))-vx.begin());
	vy.resize(unique(ALL(vy))-vy.begin());
	fup(i,0,n-1,1)
	{
		x[i]=lower_bound(ALL(vx),x[i])-vx.begin();
		y[i]=lower_bound(ALL(vy),y[i])-vy.begin();
		xx[x[i]].pb(mp(y[i],i));
		yy[y[i]].pb(mp(x[i],i));
	}
	fup(i,0,n-1,1)
	{
		sort(ALL(xx[i]));sort(ALL(yy[i]));
		fup(j,1,(int)xx[i].size()-1,1)
		{
			int a=xx[i][j-1].Y,b=xx[i][j].Y;
			v[a].pb(b);
			v[b].pb(a);
		}
		fup(j,1,(int)yy[i].size()-1,1)
		{
			int a=yy[i][j-1].Y,b=yy[i][j].Y;
			v[a].pb(b);
			v[b].pb(a);
		}
	}
	ll ans=1;
	fup(i,0,n-1,1)
	{
		if(!chk[i])
		{
			XX.clear();YY.clear();sz=deg=0;
			dfs(i);
			ll k=pow2[XX.size()+YY.size()];
			if(deg/2==sz-1)k--;
			ans=(ans*k)%MOD;
		}
	}
	printf("%lld",ans);
}