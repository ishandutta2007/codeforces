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
#define INF 1987654321987654321
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
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

Pi p[1000001];
int L[1000002],R[1000002];
int main() {
	MEM_1(L);
	MEM_1(R);
	int n,x;
	scanf("%d%d",&n,&x);
	fup(i,1,n,1)
	{
		int c;
		scanf("%d",&c);
		p[c].Y=i;
		if(!p[c].X)p[c].X=i;
	}
	L[0]=0;
	fup(i,1,x,1)
	{
		if(p[i].X==0)L[i]=L[i-1];
		else if(p[i].X<L[i-1])break;
		else L[i]=p[i].Y;
	}
	R[x+1]=n+1;
	fdn(i,x,1,1)
	{
		if(p[i].Y>R[i+1])break;
		if(p[i].Y==0)R[i]=R[i+1];
		else R[i]=p[i].X;
	}
	int ii=0,jj=0;
	ll ans=0;
	while(ii<=x && ~L[ii])
	{
		while(ii>=jj || (jj<=x && R[jj]<=L[ii]))jj++;
		ans+=x+2-jj;
		if(ii+1==jj)ans--;
		ii++;
	}
	printf("%lld",ans);
}