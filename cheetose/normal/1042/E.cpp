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

int a[1000][1000];
ll d[1000][1000];
vector<pair<int, Pi> > v;
void add(ll &a, ll b){a=(a+b)%MOD;if(a<0)a+=MOD;}
ll mul(ll a,ll b){return (a*b)%MOD;}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	fup(i,0,n-1,1)fup(j,0,m-1,1)
	{
		scanf("%d",&a[i][j]);
		v.pb(mp(a[i][j],mp(i,j)));
	}
	int xx,yy;
	scanf("%d%d",&xx,&yy);
	xx--,yy--;
	sort(ALL(v));
	ll sum=0,sumx=0,sumy=0,sumxx=0,sumyy=0;
	int l=0;
	while(l<n*m)
	{
		int r=l;
		while(r<n*m&&v[r].X==v[l].X)r++;
		if(l!=0)
		{
			ll inv=POW(l,MOD-2);
			fup(i,l,r-1,1)
			{
				int x=v[i].Y.X,y=v[i].Y.Y;
				add(d[x][y],mul(sum,inv));
				add(d[x][y],mul(x,x));
				add(d[x][y],mul(y,y));
				add(d[x][y],mul(sumxx,inv));
				add(d[x][y],mul(sumyy,inv));
				add(d[x][y],mul(2*mul(-x,sumx),inv));
				add(d[x][y],mul(2*mul(-y,sumy),inv));
			}
		}
		fup(i,l,r-1,1)
		{
			int x=v[i].Y.X,y=v[i].Y.Y;
			add(sum,d[x][y]);
			add(sumx,x);
			add(sumy,y);
			add(sumxx,x*x);
			add(sumyy,y*y);
		}
		l=r;
	}
	printf("%lld",d[xx][yy]);
}