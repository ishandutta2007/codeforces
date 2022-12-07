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
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

Pll ori[100001];
int n,cf,cm;
ll A,m,a[100001],sum[100001];
int main() {
	scanf("%d%lld%d%d%lld",&n,&A,&cf,&cm,&m);
	fup(i,1,n,1)
	{
		ll x;
		scanf("%lld",&x);
		ori[i]=mp(x,i);
	}
	sort(ori+1,ori+n+1);
	reverse(ori+1,ori+n+1);
	fup(i,1,n,1)sum[i]=sum[i-1]+ori[i].X;
	ll ans=-1,tmp=-1,tmpj=-1,tmpjj=-1;
	fup(i,0,n,1)
	{
		ll rem=m;
		rem-=A*i-sum[i];
		if(rem<0)break;
		ll cost=i*cf;
		int l=i+1,r=n;
		while(l<=r)
		{
			int k=(l+r)>>1;
			if(ori[k].X*(n-k)-(sum[n]-sum[k])<=rem)r=k-1;
			else l=k+1;
		}
		ll mm;
		if(i==n)mm=A;
		else if(l<=n)mm=(rem+sum[n]-sum[l-1])/(n-l+1);
		else mm=rem+ori[n].X;
		mm=min(A,mm);
		cost+=mm*cm;
		if(ans<cost)
		{
			ans=cost;
			tmp=i;
			tmpj=l;
			tmpjj=mm;
		}
	}
	printf("%lld\n",ans);
	fup(i,1,n,1)
	{
		if(i<=tmp)a[ori[i].Y]=A;
		else if(i>=tmpj)a[ori[i].Y]=tmpjj;
		else a[ori[i].Y]=ori[i].X;
	}
	fup(i,1,n,1)printf("%lld ",a[i]);
}