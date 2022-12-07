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
#define INF 987654321987654231
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

int n;
Pll p[5000];
db d[2500][2500][2];
db dist(Pll p1,Pll p2)
{
	ll x=p1.X-p2.X,y=p1.Y-p2.Y;
	return sqrt(x*x+y*y);
}
db go(int L,int R,int c)
{
	if((R+1)%n==L)return 0;
	db &ret=d[L][R][c];
	if(ret!=-1)return ret;
	ret=0;
	int l=L,r=R;
	if(l>r)r+=n;
	if(c==0)
	{
		if(l>0)ret=max(ret,dist(p[l],p[l-1])+go((l-1+n)%n,R,0));
		if(r<2*n-1)ret=max(ret,dist(p[l],p[r+1])+go(L,(r+1)%n,1));
	}
	else
	{
		if(l>0)ret=max(ret,dist(p[r],p[l-1])+go((l-1+n)%n,R,0));
		if(r<2*n-1)ret=max(ret,dist(p[r],p[r+1])+go(L,(r+1)%n,1));
	}
	return ret;
}
int main() {
	scanf("%d",&n);
	fup(i,0,n-1,1)
	{
		scanf("%lld%lld",&p[i].X,&p[i].Y);
		p[i+n]=p[i];
	}
	fill(&d[0][0][0],&d[2499][2499][2],-1.0);
	db ans=-1;
	fup(i,0,n-1,1)ans=max(ans,go(i,i,0));
	printf("%.10f",ans);
}