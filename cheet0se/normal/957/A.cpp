#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<cstring>
#include<complex>
#include<cmath>
#include<iomanip>
#include<numeric>
#include<algorithm>
#include<list>
#include<functional>
#define mp make_pair
#define X first
#define Y second
#define INF 987654321987654321
#define PI 3.14159265358979323846264
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
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
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
int MOD = 20000303;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int n;
char s[101];
int d[101][4];
int CtoI(char c)
{
	if (c == 'C')return 1;
	if (c == 'M')return 2;
	if (c == 'Y')return 3;
	return 0;
}
int go(int N, int c)
{
	if (N == n)return 1;
	int &ret = d[N][c];
	if (ret != -1)return ret;
	ret = 0;
	int now = CtoI(s[N]);
	if (c == 0)
	{
		if (now == 0)
		{
			fup(i, 1, 3, 1)ret = min(2, ret + go(N + 1, i));
		}
		else ret = min(2, ret + go(N + 1, now));
	}
	else
	{
		if (now == c)return ret = 0;
		if (now == 0)
		{
			fup(i,1,3,1)
				if(i!=c)ret = min(2, ret + go(N + 1, i));
		}
		else ret = min(2, ret + go(N + 1, now));
	}
	return ret;
}
int main()
{
	MEM_1(d);
	scanf("%d%s", &n, s);
	puts(go(0, 0) == 2 ? "Yes" : "No");
}