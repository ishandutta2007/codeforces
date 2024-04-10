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
ll a[2001],b[2001];
VLLL v;
ll ans0,ans1,ans2;
Pi an1,an21,an22;
int main() {
	scanf("%d",&n);
	fup(i,1,n,1)scanf("%lld",a+i);
	scanf("%d",&m);
	fup(i,1,m,1)scanf("%lld",b+i);
	ll t1=accumulate(a+1,a+n+1,0LL),t2=accumulate(b+1,b+m+1,0LL);
	ans0=(ll)abs(t1-t2);
	ans1=ans2=INF;
	fup(i,1,n,1)
	{
		fup(j,1,m,1)
		{
			ll tt1=t1-a[i]+b[j];
			ll tt2=t2-b[j]+a[i];
			if(ans1>(ll)abs(tt1-tt2))
			{
				ans1=(ll)abs(tt1-tt2);
				an1=mp(i,j);
			}
		}
	}
	fup(i,1,m,1)fup(j,i+1,m,1)v.pb(LLL(b[i]+b[j],i,j));
	sort(ALL(v));
	ll dif=t1-t2;
	fup(i,1,n,1)
		fup(j,i+1,n,1)
	{
		ll tt1=t1-a[i]-a[j];
		ll tt2=t2+a[i]+a[j];
		auto it=lower_bound(ALL(v),LLL((tt2-tt1)/2,-1,-1));
		if(it!=v.end())
		{
			ll z,x,y;
			tie(z,x,y)=*it;
			ll ttt1=tt1+z;
			ll ttt2=tt2-z;
			if(ans2>(ll)abs(ttt1-ttt2))
			{
				ans2=(ll)abs(ttt1-ttt2);
				an21=mp(i,x);
				an22=mp(j,y);
			}
		}
		if(it!=v.begin())
		{
			it--;
			ll z,x,y;
			tie(z,x,y)=*it;
			ll ttt1=tt1+z;
			ll ttt2=tt2-z;
			if(ans2>(ll)abs(ttt1-ttt2))
			{
				ans2=(ll)abs(ttt1-ttt2);
				an21=mp(i,x);
				an22=mp(j,y);
			}
		}
	}
	if(ans0<=ans1 && ans0<=ans2)
		return !printf("%lld\n0",ans0);
	if(ans1<=ans0 && ans1<=ans2)
		return !printf("%lld\n1\n%d %d",ans1,an1.X,an1.Y);
	return !printf("%lld\n2\n%d %d\n%d %d",ans2,an21.X,an21.Y,an22.X,an22.Y);
}