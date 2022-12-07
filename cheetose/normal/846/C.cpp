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

int n;
ll a[5000];
ll d[5005][4];
ll go(int N,int k)
{
	if(k==4)return N==n?0:-INF;
	ll &ret=d[N][k];
	if(ret!=-INF-5)return ret;
	ret=go(N,k+1);
	if(N<n)
	{
		if(k&1)ret=max(ret,go(N+1,k)-a[N]);
		else ret=max(ret,go(N+1,k)+a[N]);
	}
	return ret;
}
void track(int N,int k)
{
	if(k==4)return;
	ll t1=go(N,k+1);
	ll t2;
	if(N<n)
	{
		if(k&1)t2=go(N+1,k)-a[N];
		else t2=go(N+1,k)+a[N];
	}
	else t2=-INF;
	if(t1>=t2)
	{
		if(k<3)printf("%d ",N);
		track(N,k+1);
	}
	else track(N+1,k);
}
int main() {
	fill(&d[0][0],&d[5004][4],-INF-5);
	scanf("%d",&n);
	fup(i,0,n-1,1)scanf("%lld",a+i);
	track(0,0);
}