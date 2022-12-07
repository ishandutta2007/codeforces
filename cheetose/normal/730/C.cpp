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
#define INF 987654321987654321
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

int n,m;
Vi v[5001];
VPi s[5001];
Viii vv;
int d[5001];
bool ok(int N,int cnt,int pri,int k)
{
	int rem=pri,cc=0;
	for(auto aa:vv)
	{
		int zz,xx,kk;
		tie(zz,xx,kk)=aa;
		if(kk>k)continue;
		int t=rem/zz;
		t=min(t,xx);
		cc+=t;
		rem-=zz*t;
	}
	return cc>=cnt;
}
int query(int N,int cnt,int pri)
{
	vv.clear();
	MEM_1(d);
	queue<int> q;
	d[N]=0;
	for(auto aa:s[N])vv.pb(iii(aa.X,aa.Y,0));
	q.push(N);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int next:v[x])
		{
			if(d[next]==-1)
			{
				d[next]=d[x]+1;
				q.push(next);
				for(auto aa:s[next])vv.pb(iii(aa.X,aa.Y,d[next]));
			}
		}
	}
	sort(ALL(vv));
	int l=0,r=n;
	while(l<=r)
	{
		int k=(l+r)>>1;
		if(ok(N,cnt,pri,k))r=k-1;
		else l=k+1;
	}
	if(l==n+1)return -1;
	return l;
}
int main() {
	scanf("%d%d",&n,&m);
	fup(i,1,m,1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	int w;
	scanf("%d",&w);
	while(w--)
	{
		int c,k,p;
		scanf("%d%d%d",&c,&k,&p);
		s[c].pb(mp(p,k));
	}
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		printf("%d\n",query(a,b,c));
	}
}