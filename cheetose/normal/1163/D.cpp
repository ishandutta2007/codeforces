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
#define INF 1987654321
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
typedef pair<double, double> Pd;
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

char c[1002],s[52],t[52];
int spi[52],tpi[52];
int n,m,k;
int d[1000][50][50];
int go(int N,int M,int K)
{
	if(N==n)return 0;
	int &ret=d[N][M][K];
	if(ret!=-INF-5)return ret;
	ret=-INF;
	if(c[N]=='*')
	{
		fup(i,'a','z',1)
		{
			int tm=M,tk=K,cc=0;
			while (tm > 0 && i != s[tm]) tm = spi[tm-1];
			while (tk > 0 && i != t[tk]) tk = tpi[tk-1];
			if(i==s[tm])
			{
				if(tm==m-1)
				{
					cc++;
					tm=spi[tm];
				}
				else tm++;
			}
			if(i==t[tk])
			{
				if(tk==k-1)
				{
					cc--;
					tk=tpi[tk];
				}
				else tk++;
			}
			ret=max(ret,cc+go(N+1,tm,tk));
		}
	}
	else
	{
		int tm=M,tk=K,cc=0;
		while (tm > 0 && c[N] != s[tm]) tm = spi[tm-1];
		while (tk > 0 && c[N] != t[tk]) tk = tpi[tk-1];
		if(c[N]==s[tm])
		{
			if(tm==m-1)
			{
				cc++;
				tm=spi[tm];
			}
			else tm++;
		}
		if(c[N]==t[tk])
		{
			if(tk==k-1)
			{
				cc--;
				tk=tpi[tk];
			}
			else tk++;
		}
		ret=max(ret,cc+go(N+1,tm,tk));
	}
	return ret;
}
int main() {
	scanf("%s%s%s",c,s,t);
	n=strlen(c),m=strlen(s),k=strlen(t);
	fup(i,0,n-1,1)fup(j,0,m-1,1)fup(kk,0,k-1,1)d[i][j][kk]=-INF-5;
	for (int i = 1, j = 0; i < m; i++)
	{
		while (j > 0 && s[i] != s[j]) j = spi[j - 1];
		if (s[i] == s[j]) spi[i] = ++j;
	}
	for (int i = 1, j = 0; i < k; i++)
	{
		while (j > 0 && t[i] != t[j]) j = tpi[j - 1];
		if (t[i] == t[j]) tpi[i] = ++j;
	}
	printf("%d",go(0,0,0));
}