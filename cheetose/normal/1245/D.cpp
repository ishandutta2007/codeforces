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
#define INF 987654321987654321
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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

int n,x[2000],y[2000],op[2000];
ll c[2000],k[2000];
bool chk[2000];
Vi v;
VPi p;
int main(){
	MEM_1(op);
	scanf("%d",&n);
	fup(i,0,n-1,1)scanf("%d%d",x+i,y+i);
	fup(i,0,n-1,1)scanf("%lld",c+i);
	fup(i,0,n-1,1)scanf("%lld",k+i);
	ll ans=0;
	fup(ttt,1,n,1)
	{
		ll mn=INF;
		int w=-1;
		fup(i,0,n-1,1)
		{
			if(chk[i])continue;
			if(c[i]<mn)
			{
				mn=c[i];
				w=i;
			}
		}
		ans+=mn;
		chk[w]=1;
		if(op[w]==-1)v.pb(w);
		else p.pb(mp(w,op[w]));
		fup(i,0,n-1,1)
		{
			if(chk[i])continue;
			if((k[i]+k[w])*(abs(x[i]-x[w])+abs(y[i]-y[w]))<c[i])
			{
				c[i]=(k[i]+k[w])*(abs(x[i]-x[w])+abs(y[i]-y[w]));
				op[i]=w;
			}
		}
	}
	printf("%lld\n",ans);
	printf("%d\n",v.size());
	for(int x:v)printf("%d ",x+1);
	puts("");
	printf("%d\n",p.size());
	for(Pi x:p)printf("%d %d\n",x.X+1,x.Y+1);
}