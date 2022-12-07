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
#define INF 987654321987654321
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
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

ll inv(ll n, ll a) // a*x%n==1
{
	ll s, s1, s2, t, t1, t2, r, r1, r2;
	r1 = a, r2 = n, s1 = 1, s2 = 0, t1 = 0, t2 = 1;
	while (r2 > 0)
	{
		ll q = r1 / r2;
		r = r1 - q*r2;
		r1 = r2;
		r2 = r;
		s = s1 - q*s2;
		s1 = s2;
		s2 = s;
		t = t1 - q*t2;
		t1 = t2;
		t2 = t;
	}
	if (r1 != 1)return -1;
	return (s1+n)%n;
}
int n,m;
bitset<200001> prime,chk;
Vi v[200001],vv[200001];
int d[200001];
int go(int x)
{
	if(~d[x])return d[x];
	int t=v[x].size();
	int r=0;
	for(int next:vv[x])
		r=max(r,go(next));
	return d[x]=r+t;
}
int pre=-1;
void track(int x)
{
	if(!v[x].empty())
	{
		if(!~pre) printf("%d ",v[x][0]);
		else 
		{
			int g=gcd(m,pre);
			int t=inv(m/g,pre/g);
			t=(1LL*t*(v[x][0]/g))%(m/g);
			printf("%d ",t);
		}
		pre=v[x][0];
		fup(i,1,(int)v[x].size()-1,1)
		{
			int t=inv(m/x,pre/x);
			t=(1LL*t*(v[x][i]/x))%m;
			printf("%d ",t);
			pre=v[x][i];
		}
	}
	int t1=0,t2=-1;
	for(int next:vv[x])
	{
		int t=go(next);
		if(t>t1)
		{
			t1=t;
			t2=next;
		}
	}
	if(t2!=-1)track(t2);
}
int main() {
	MEM_1(d);
	prime.set();
	prime[0]=prime[1]=0;
	fup(i,2,100000,1)
	{
		if(!prime[i])continue;
		fup(j,i+i,200000,i)
			prime[j]=0;
	}
	scanf("%d%d",&n,&m);
	fup(i,1,n,1)
	{
		int x;
		scanf("%d",&x);
		chk[x]=1;
	}
	fup(i,1,m-1,1)
	{
		if(!chk[i])v[gcd(m,i)].pb(i);
	}
	fup(i,1,m-1,1)
	{
		fup(j,i+i,m,i)vv[i].pb(j);
	}
	printf("%d\n",go(1)+(!chk[0]));
	track(1);
	if(!chk[0])puts("0");
}