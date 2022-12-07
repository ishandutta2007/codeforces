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
#define INF 987654321
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
const ll MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

Vll v[11];
ll r[11][11];
void add(ll &a,ll b){a=(a+b)%MOD;}
ll mul(ll a,ll b){return (a*b)%MOD;}
int len(ll x)
{
	int c=0;
	while(x)
	{
		c++;
		x/=10;
	}
	return c;
}
ll p[22];
int main() {
	p[0]=1;
	fup(i,1,21,1)p[i]=mul(p[i-1],10);
	int n;
	scanf("%d",&n);
	fup(i,0,n-1,1)
	{
		ll x;
		scanf("%lld",&x);
		v[len(x)].pb(x);
	}
	fup(i,1,10,1)
	{
		fup(k,0,i-1,1)
		{
			ll t=0;
			for(ll &x:v[i])
			{
				add(r[i][k],x%10);
				x/=10;
			}
		}
	}
	ll ans=0;
	fup(i,1,10,1)
	{
		ll t=0;
		fup(j,0,i-1,1)
		{
			add(t,mul(p[j*2],r[i][j]));
			add(t,mul(p[j*2+1],r[i][j]));
		}
		add(ans,mul(t,v[i].size()));
	}
	fup(i,1,10,1)
	{
		fup(j,i+1,10,1)
		{
			ll t1=0,t2=0;
			fup(k,0,i-1,1)
			{
				add(t1,mul(r[i][k],p[k*2]));
				add(t1,mul(r[i][k],p[k*2+1]));
				add(t2,mul(r[j][k],p[k*2]));
				add(t2,mul(r[j][k],p[k*2+1]));
			}
			fup(k,i,j-1,1)
			{
				add(t2,2*mul(r[j][k],p[i+k]));
			}
			t1=mul(t1,v[j].size());
			t2=mul(t2,v[i].size());
			add(ans,t1);
			add(ans,t2);
		}
	}
	printf("%lld",ans);
}