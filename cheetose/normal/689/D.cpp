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
#define INF 1987654321
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

int n,mn[200000][18],mx[200000][18],a[200000],b[200000];
int res(int l,int r)
{
	int mm=INF,MM=-INF;
	int t=r-l+1;
	int now=l;
	fdn(j,17,0,1)
	{
		if(t&(1<<j))
		{
			mm=min(mm,mn[now][j]);
			MM=max(MM,mx[now][j]);
			now+=(1<<j);
		}
	}
	return MM-mm;
}
int main() {
	scanf("%d",&n);
	fup(i,0,n-1,1)
	{
		scanf("%d",a+i);
		mx[i][0]=a[i];
	}
	fup(i,0,n-1,1)
	{
		scanf("%d",b+i);
		mn[i][0]=b[i];
	}
	fup(j,1,17,1)
	{
		fup(i,0,n-1,1)
		{
			if(i+(1<<(j-1))>=n)break;
			mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
			mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
		}
	}
	ll ans=0;
	fup(i,0,n-1,1)
	{
		int l=i,ll=i,r=n-1,rr=n-1;
		while(l<=r)
		{
			int k=(l+r)>>1;
			if(res(i,k)<0)l=k+1;
			else r=k-1;
		}
		while(ll<=rr)
		{
			int k=(ll+rr)>>1;
			if(res(i,k)<=0)ll=k+1;
			else rr=k-1;
		}
		ans+=rr-r;
	}
	printf("%lld",ans);
}