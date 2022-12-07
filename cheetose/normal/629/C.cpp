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
#define INF 1000000009
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
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

ll d[2002][2002];
char s[100005];
int main() {
	d[0][0]=1;
	fup(i,1,2000,1)
		fup(j,0,i,1)
	{
		d[i][j]=d[i-1][j+1];
		if(j>0)d[i][j]=(d[i][j]+d[i-1][j-1])%MOD;
	}
	int n,m;
	scanf("%d%d%s",&n,&m,s);
	int N=strlen(s);
	int c1=0,c2=0,t=0;
	fup(i,0,N-1,1)
	{
		if(s[i]=='(')t--;
		else t++;
		c1=max(c1,t);
	}
	t=0;
	fdn(i,N-1,0,1)
	{
		if(s[i]=='(')t++;
		else t--;
		c2=max(c2,t);
	}
	ll ans=0;
	fup(i,0,n-m,1)
	{
		fup(j,c1,i,1)
		{
			int ii=n-m-i;
			if(j+t<c2 || j+t>ii)continue;
			ans=(ans+d[i][j]*d[ii][j+t])%MOD;
		}
	}
	printf("%lld",ans);
}