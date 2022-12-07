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

int L,R;
ll d[30][2][2][2][2];
ll go(int i,int x,int y,int z,int w)
{
	if(i==-1)return 1;
	ll &ret=d[i][x][y][z][w];
	if(~ret)return ret;
	ret=0;
	int nx,ny,nz,nw;
	//(0,0)
	if(x)nx=1;
	else if(L&(1<<i))nx=-1;
	else nx=0;
	
	if(y)ny=1;
	else if(L&(1<<i))ny=-1;
	else ny=0;
	
	if(z)nz=1;
	else if(R&(1<<i))nz=1;
	else nz=0;
	
	if(w)nw=1;
	else if(R&(1<<i))nw=1;
	else nw=0;
	
	if(nx!=-1 && ny!=-1)ret+=go(i-1,nx,ny,nz,nw);
	//(0,1)
	if(x)nx=1;
	else if(L&(1<<i))nx=-1;
	else nx=0;
	
	if(y)ny=1;
	else if(L&(1<<i))ny=0;
	else ny=1;
	
	if(z)nz=1;
	else if(R&(1<<i))nz=1;
	else nz=0;
	
	if(w)nw=1;
	else if(R&(1<<i))nw=0;
	else nw=-1;
	
	if(nx!=-1 && nw!=-1)ret+=go(i-1,nx,ny,nz,nw);
	//(1,0)
	if(x)nx=1;
	else if(L&(1<<i))nx=0;
	else nx=1;
	
	if(y)ny=1;
	else if(L&(1<<i))ny=-1;
	else ny=0;
	
	if(z)nz=1;
	else if(R&(1<<i))nz=0;
	else nz=-1;
	
	if(w)nw=1;
	else if(R&(1<<i))nw=1;
	else nw=0;
	
	if(ny!=-1 && nz!=-1)ret+=go(i-1,nx,ny,nz,nw);
	
	return ret;
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		MEM_1(d);
		scanf("%d%d",&L,&R);
		printf("%lld\n",go(29,0,0,0,0));
	}
}