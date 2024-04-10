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
#define INF 987654321
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
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

pair<ld,int> p[100000];
ld ang(ld x,ld y)
{
	if(x==0)
	{
		if(y>0)return 90;
		if(y<0)return 270;
	}
	if(y==0)
	{
		if(x>0)return 0;
		if(x<0)return 180;
	}
	ld t=atan(y/x)*180.0/PI;
	if(x>0 && y>0)return t;
	if(x<0)return t+180;
	return t+360;
}
int main() {
	int n;
	scanf("%d",&n);
	fup(i,0,n-1,1)
	{
		ld x,y;
		cin>>x>>y;
		p[i]=mp(ang(x,y),i+1);
	}
	sort(p,p+n);
	ld res=9876543.0L;
	Pi ans;
	fup(i,0,n-2,1)
	{
		ld t=p[i+1].X-p[i].X;
		t=min(t,360.0L-t);
		if(res>t)
		{
			res=t;
			ans=mp(p[i+1].Y,p[i].Y);
		}
	}
	ld t=360+p[0].X-p[n-1].X;
	t=min(t,360.0L-t);
	if(res>t)
	{
		res=t;
		ans=mp(p[n-1].Y,p[0].Y);
	}
	printf("%d %d",ans.X,ans.Y);
}