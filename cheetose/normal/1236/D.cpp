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
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

int n,m,k;
Vi x[100001],y[100001],rx[100001],ry[100001];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	if(!k)return !printf("Yes");
	fup(i,0,k-1,1)
	{
		int xx,yy;
		scanf("%d%d",&xx,&yy);
		x[xx].pb(yy);
		rx[xx].pb(-yy);
		y[yy].pb(xx);
		ry[yy].pb(-xx);
	}
	fup(i,1,n,1)
	{
		x[i].pb(m+1);
		sort(ALL(x[i]));
		rx[i].pb(0);
		sort(ALL(rx[i]));
	}
	fup(i,1,m,1)
	{
		y[i].pb(n+1);
		sort(ALL(y[i]));
		ry[i].pb(0);
		sort(ALL(ry[i]));
	}
	int x1=1,x2=n,y1=1,y2=m;
	int dir=0;
	int nx=1,ny=1;
	ll tot=1LL*n*m-k,cnt=1;
	while(x1<=x2 && y1<=y2)
	{
		if(dir==0)
		{
			int t=*upper_bound(ALL(x[nx]),ny);
			if(t>y2)cnt+=y2-ny,ny=y2;
			else cnt+=t-1-ny,ny=t-1,y2=ny;
			dir++,x1++;
		}
		else if(dir==1)
		{
			int t=*upper_bound(ALL(y[ny]),nx);
			if(t>x2)cnt+=x2-nx,nx=x2;
			else cnt+=t-1-nx,nx=t-1,x2=nx;
			dir++,y2--;
		}
		else if(dir==2)
		{
			int t=-(*upper_bound(ALL(rx[nx]),-ny));
			if(t<y1)cnt+=ny-y1,ny=y1;
			else cnt+=ny-t-1,ny=t+1,y1=ny;
			dir++,x2--;
		}
		else
		{
			int t=-(*upper_bound(ALL(ry[ny]),-nx));
			if(t<x1)cnt+=nx-x1,nx=x1;
			else cnt+=nx-t-1,nx=t+1,x1=nx;
			dir=0,y1++;
		}
	}
	puts(cnt==tot?"Yes":"No");
}