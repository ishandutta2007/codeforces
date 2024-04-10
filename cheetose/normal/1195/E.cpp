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

ll h[3002][3002],mn[3002][3002];
int main() {
	int n,m,a,b;
	ll x,y,z,g;
	scanf("%d%d%d%d%lld%lld%lld%lld",&n,&m,&a,&b,&g,&x,&y,&z);
	h[1][1]=g;
	fup(i,1,n*m-1,1)
	{
		g=(g*x+y)%z;
		h[i/m+1][(i%m)+1]=g;
	}
	fup(j,1,m,1)
	{
		deque<Pll> q;
		fup(i,1,n,1)
		{
			while(!q.empty() && q.back().X>=h[i][j])q.pop_back();
			while(!q.empty() && q.front().Y<=i-a)q.pop_front();
			q.pb(mp(h[i][j],i));
			mn[i][j]=q.front().X;
		}
	}
	ll ans=0;
	fup(i,a,n,1)
	{
		deque<Pll> q;
		fup(j,1,m,1)
		{
			while(!q.empty() && q.back().X>=mn[i][j])q.pop_back();
			while(!q.empty() && q.front().Y<=j-b)q.pop_front();
			q.pb(mp(mn[i][j],j));
			if(j>=b)ans+=q.front().X;
		}
	}
	printf("%lld",ans);
}