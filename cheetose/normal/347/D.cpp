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
#include<cassert>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define INF 987654321
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
ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int n, m, l;
char a[101], b[101], c[101];
int pi[100];
int d[100][100][100];
int go(int N, int M, int L)
{
	if (L == l)return -INF;
	if (N == n || M == m)return 0;
	int &ret = d[N][M][L];
	if (ret != -1)return ret;
	ret = 0;
	ret = max(ret, go(N + 1, M, L));
	ret = max(ret, go(N, M + 1, L));
	if (a[N] == b[M])
	{
		if (a[N] == c[L])ret = max(ret, 1 + go(N + 1, M + 1, L + 1));
		else
		{
			while (L != 0 && a[N] != c[L])L = pi[L-1];
			if (a[N] == c[L])ret = max(ret, 1 + go(N + 1, M + 1, L + 1));
			else ret = max(ret, 1 + go(N + 1, M + 1, L));
		}
	}
	return ret;
}
void track(int N, int M, int L)
{
	if (N == n || M == m)return;
	int t1 = go(N + 1, M, L);
	int t2 = go(N, M + 1, L);
	int t3 = -INF, t4 = -INF, t5 = -INF;
	int tl = L;
	if (a[N] == b[M])
	{
		if (a[N] == c[L])t3 = 1 + go(N + 1, M + 1, L + 1);
		else
		{
			while (tl != 0 && a[N] != c[tl])tl = pi[tl-1];
			if (a[N] == c[tl])t4 = 1 + go(N + 1, M + 1, tl + 1);
			else t5 = 1 + go(N + 1, M + 1, tl);
		}
	}
	int MAX = max({ t1,t2,t3,t4,t5 });
	if (t1 == MAX)track(N + 1, M, L);
	else if (t2 == MAX)track(N, M + 1, L);
	else if (t3 == MAX)
	{
		printf("%c", a[N]);
		track(N + 1, M + 1, L + 1);
	}
	else if (t4 == MAX)
	{
		printf("%c", a[N]);
		track(N + 1, M + 1, tl+1);
	}
	else
	{
		printf("%c", a[N]);
		track(N + 1, M + 1, tl);
	}
}
int main() {
	MEM_1(d);
	scanf("%s%s%s", a, b, c);
	n = strlen(a), m = strlen(b), l = strlen(c);
	for (int i = 1, j = 0; i < l; i++)
	{
		while (j > 0 && c[i] != c[j]) j = pi[j - 1];
		if (c[i] == c[j]) pi[i] = ++j;
	}
	int t = go(0, 0, 0);
	if (t == 0)return !printf("0");
	track(0, 0, 0);
}