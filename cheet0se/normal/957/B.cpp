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

char s[50][51];
ll R[50], C[50];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	fup(i, 0, n - 1, 1)scanf("%s", s[i]);
	fup(i, 0, n - 1, 1)
	{
		fup(j, 0, m - 1, 1)
		{
			if (s[i][j] == '#')R[i] += (1LL << j);
		}
	}
	fup(j, 0, m - 1, 1)
	{
		fup(i, 0, n - 1, 1)
			if (s[i][j] == '#')C[j] += (1LL << i);
	}
	fup(i, 0, n - 1, 1)
		fup(j, 0, n - 1, 1)
	{
		ll c = R[i] & R[j];
		if (c != R[i] && c != 0)return puts("No");
	}
	fup(i, 0, m - 1, 1)
		fup(j, 0, m - 1, 1)
	{
		ll c = C[i] & C[j];
		if (c != C[i] && c != 0)return puts("No");
	}
	puts("Yes");
}