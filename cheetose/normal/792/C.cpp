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

int d[100000][3][2];
char s[100005];
int n;
int go(int N,int k,int c)
{
	if(N==n)
	{
		if(k==0 && c==1)return 0;
		return -INF;
	}
	int &ret=d[N][k][c];
	if(ret!=-1)return ret;
	ret=-INF;
	if(c)ret=max({ret,1+go(N+1,(k+s[N]-'0')%3,1),go(N+1,k,1)});
	else
	{
		ret=go(N+1,k,0);
		if(s[N]!='0')ret=max(ret,1+go(N+1,(k+s[N]-'0')%3,1));
	}
	return ret;
}

void track(int N,int k,int c)
{
	if(N==n)return;
	if(c)
	{
		int a=1+go(N+1,(k+s[N]-'0')%3,1),b=go(N+1,k,1);
		if(a>=b)
		{
			putchar(s[N]);
			track(N+1,(k+s[N]-'0')%3,1);
		}
		else
		{
			track(N+1,k,1);
		}
	}
	else
	{
		if(s[N]=='0')track(N+1,k,0);
		else
		{
			int a=1+go(N+1,(k+s[N]-'0')%3,1),b=go(N+1,k,0);
			if(a>=b)
			{
				putchar(s[N]);
				track(N+1,(k+s[N]-'0')%3,1);
			}
			else
			{
				track(N+1,k,0);
			}
		}
	}
}
int main() {
	MEM_1(d);
	scanf("%s",s);
	n=strlen(s);
	int t=go(0,0,0);
	if(t<0)return 0*puts(count(s,s+n,'0')==0?"-1":"0");
	track(0,0,0);
}