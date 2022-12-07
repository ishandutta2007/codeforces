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

int n,k;
char s[1001];
int d[1001][2001];
int go(int N,int K)
{
	if(N==n)return (K==1000+k || K==1000-k) ;
	if((K==1000+k) || (K==1000-k))return 0;
	int &ret=d[N][K];
	if(ret!=-1)return ret;
	ret=0;
	if(s[N]=='?')
	{
		ret=max(ret,go(N+1,K));
		ret=max(ret,go(N+1,K-1));
		ret=max(ret,go(N+1,K+1));
	}
	else if(s[N]=='W')ret=max(ret,go(N+1,K+1));
	else if(s[N]=='D')ret=max(ret,go(N+1,K));
	else if(s[N]=='L')ret=max(ret,go(N+1,K-1));
	return ret;
}
void track(int N,int K)
{
	if(N==n)return;
	if(s[N]=='?')
	{
		if(go(N+1,K+1)==1)
		{
			putchar('W');
			track(N+1,K+1);
		}
		else if(go(N+1,K)==1)
		{
			putchar('D');
			track(N+1,K);
		}
		else if(go(N+1,K-1)==1)
		{
			putchar('L');
			track(N+1,K-1);
		}
	}
	else if(s[N]=='W')putchar('W'),track(N+1,K+1);
	else if(s[N]=='D')putchar('D'),track(N+1,K);
	else if(s[N]=='L')putchar('L'),track(N+1,K-1);
}
int main() {
	MEM_1(d);
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	if(go(0,1000)==0)return !printf("NO");
	else track(0,1000);
}