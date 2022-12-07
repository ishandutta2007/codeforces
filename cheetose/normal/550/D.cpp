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
const ll MOD = 1000000009;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

VPi e;
Vi v;
int cc=2;
int main() {
	int k;
	scanf("%d",&k);
	if(k%2==0)return !printf("NO");
	puts("YES");
	if(k==1)
	{
		puts("2 1");
		puts("1 2");
		return 0;
	}
	e.pb(mp(1,2));
	fup(i,1,k-1,1)
	{
		e.pb(mp(1,++cc));
		v.pb(cc);
	}
	while(v.size()%k != 0)
	{
		int t=v.back();
		v.pop_back();
		fup(i,1,k-1,1)
		{
			e.pb(mp(t,++cc));
			v.pb(cc);
		}
	}
	int N=v.size();
	fup(i,0,N-1,k)
	{
		fup(ii,0,k-1,1)
			fup(jj,ii+1,k-1,1)
		{
			e.pb(mp(v[i+ii],v[i+jj]));
		}
	}
	v.clear();
	fup(i,1,k-1,1)
	{
		e.pb(mp(2,++cc));
		v.pb(cc);
	}
	while(v.size()%k != 0)
	{
		int t=v.back();
		v.pop_back();
		fup(i,1,k-1,1)
		{
			e.pb(mp(t,++cc));
			v.pb(cc);
		}
	}
	N=v.size();
	fup(i,0,N-1,k)
	{
		fup(ii,0,k-1,1)
			fup(jj,ii+1,k-1,1)
		{
			e.pb(mp(v[i+ii],v[i+jj]));
		}
	}
	printf("%d %d\n",cc,e.size());
	for(Pi p:e)printf("%d %d\n",p.X,p.Y);
}