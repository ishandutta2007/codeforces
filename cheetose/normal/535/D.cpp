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

int n,m,k;
char s[1000002];
int z[1000002],a[1000002];
int main() {
	scanf("%d%d%s",&m,&k,s);
	n=strlen(s);
	reverse(s,s+n);
	fup(i,0,k-1,1)
	{
		scanf("%d",a+i);
		a[i]=m+2-n-a[i];
	}
	reverse(a,a+k);
	if(k==0)
	{
		ll ans=1;
		while(m--)ans=(ans*26)%MOD;
		return !printf("%lld",ans);
	}
	int L = 0, R = 0;
	fup(i,1,n-1,1)
	{
		if (i > R) 
		{
			L = R = i;
			while (R < n && s[R - L] == s[R])
				R++;
			z[i] = R - L;
			R--;
		}
		else
		{
			int k = i - L;
			if (z[k] < R - i + 1)
				z[i] = z[k];
			else 
			{
				L = i;
				while (R < n && s[R - L] == s[R]) R++;
				z[i] = R - L;
				R--;
			}
		}
	}
	fup(i,1,k-1,1)
	{
		int t=a[i]-a[i-1];
		if(t>=n)continue;
		if(t+z[t]!=n)return !printf("0");
	}
	ll ans=1;
	int tt=1;
	fup(i,0,k-1,1)
	{
		while(tt<a[i])
		{
			ans=(ans*26)%MOD;
			tt++;
		}
		tt=a[i]+n;
	}
	while(tt<=m)
	{
		ans=(ans*26)%MOD;
		tt++;
	}
	printf("%lld",ans);
}