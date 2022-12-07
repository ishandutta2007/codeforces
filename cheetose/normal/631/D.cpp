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

int n,m;
vector<pair<ll,char> > a,b;
int pi[200005];
int main() {
	scanf("%d%d",&n,&m);
	fup(i,1,n,1)
	{
		ll x;char c;
		scanf("%lld-%c ",&x,&c);
		if(a.empty())a.pb(mp(x,c));
		else if(a.back().Y==c)a.back().X+=x;
		else a.pb(mp(x,c));
	}
	fup(i,1,m,1)
	{
		ll x;char c;
		scanf("%lld-%c ",&x,&c);
		if(b.empty())b.pb(mp(x,c));
		else if(b.back().Y==c)b.back().X+=x;
		else b.pb(mp(x,c));
	}
	n=a.size(),m=b.size();
	if(n<m)return !printf("0");
	ll ans=0;
	if(m==1)
	{
		fup(i,0,n-1,1)
			if(a[i].Y==b[0].Y)ans+=max(0LL,a[i].X-b[0].X+1);
		return !printf("%lld",ans);
	}
	if(m==2)
	{
		fup(i,0,n-2,1)
			if(b[0].Y==a[i].Y && b[1].Y==a[i+1].Y && b[0].X<=a[i].X && b[1].X<=a[i+1].X)ans++;
		return !printf("%lld",ans);
	}
	pi[1]=1;
	for (int i = 2, j = 1; i < m-1; i++)
	{
		while (j > 1 && b[i] != b[j]) j = pi[j - 1];
		if (b[i] == b[j]) pi[i] = ++j;
	}
	for (int i = 1, j = 1; i < n-1; i++)
	{
		while (j > 1 && a[i] != b[j]) j = pi[j-1];
		if (a[i] == b[j])
		{
			if (j == m - 2)
			{
				if(a[i+1].Y==b[m-1].Y && b[0].Y==a[i-m+2].Y && a[i+1].X>=b[m-1].X && b[0].X<=a[i-m+2].X)ans++;
				j=pi[j];
			}
			else j++;
		}
	}
	printf("%lld",ans);
}