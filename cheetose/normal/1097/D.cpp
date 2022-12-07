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

VPll v;
ll P;
ll d[51][10001];
ll inv[51];
ll go(int a,int k)
{
	ll &ret=d[a][k];
	if(ret!=-1)return ret;
	if(k==0)return ret=POW(P,a);
	ret=0;
	fup(i,0,a,1)ret=(ret+inv[a+1]*go(i,k-1))%MOD;
	return ret;
}
ll res(ll a,ll k)
{
	MEM_1(d);
	return go(a,k);
}
int main() {
	fup(i,1,50,1)inv[i]=POW(i,MOD-2);
	ll n;
	int k;
	scanf("%lld%d",&n,&k);
	for(ll i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			ll c=0;
			while(n%i==0)
			{
				c++;
				n/=i;
			}
			v.pb(mp(i,c));
		}
	}
	if(n>1)v.pb(mp(n,1));
	ll ans=1;
	for(Pll p:v)
	{
		P=(p.X)%MOD;
		ans=(ans*res(p.Y,k))%MOD;
	}
	printf("%lld",ans);
}