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

ll fac[2001];
ll d[2001][2001];
bool chk1[2001],chk2[2001];
int n;
ll go(int N,int K)
{
	if(K==0)return fac[N];
	if(K==1)return (N*fac[N])%MOD;
	ll &ret=d[N][K];
	if(ret!=-1)return ret;
	ret=(N*go(N,K-1))%MOD;
	ret=(ret+(K-1)*go(N+1,K-2))%MOD;
	return ret;
}
int main() {
	MEM_1(d);
	fac[0]=1;
	fup(i,1,2000,1)fac[i]=(fac[i-1]*i)%MOD;
	scanf("%d",&n);
	fup(i,1,n,1)
	{
		int x;
		scanf("%d",&x);
		if(x==i)return !printf("0");
		if(x!=-1)chk2[i]=1,chk1[x]=1;
	}
	int c1=0,c2=0;
	fup(i,1,n,1)
	{
		if(!chk1[i]&&!chk2[i])c2++;
		else if(!chk1[i] && chk2[i])c1++;
	}
	printf("%lld",go(c1,c2));
}