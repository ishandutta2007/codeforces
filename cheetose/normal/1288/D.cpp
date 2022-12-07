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
#define INF 98765432
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
typedef vector<ld> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int,int,int,int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={-1,-2,1,-2,2,-1,2,1},ddy[]={-2,-1,-2,1,-1,2,1,2};

int a[300000][8],c[300000];
Vi v[256];
int n,m,sz;
bool ok(int k,bool f=0)
{
	MEM0(c);
	fup(i,0,sz-1,1)v[i].clear();
	fup(i,0,n-1,1)
	{
		int t=0;
		fup(j,0,m-1,1)
		{
			if(a[i][j]>=k)t|=(1<<j);
		}
		v[t].pb(i);
	}
	Pi res;
	bool o=0;
	fup(i,0,sz-1,1)
		fup(j,0,sz-1,1)
	{
		if((i|j)==sz-1 && !v[i].empty() && !v[j].empty())
		{
			o=1;
			res=mp(v[i].back(),v[j].back());
		}
	}
	if(f)printf("%d %d\n",res.X+1,res.Y+1);
	return o;
}
int main(){
	scanf("%d%d",&n,&m);
	sz=1<<m;
	fup(i,0,n-1,1)fup(j,0,m-1,1)scanf("%d",&a[i][j]);
	int l=0,r=(int)1e9;
	while(l<=r)
	{
		int k=(l+r)>>1;
		if(ok(k))l=k+1;
		else r=k-1;
	}
	ok(r,1);
}