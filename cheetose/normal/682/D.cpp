#include<cstdio>
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
#include<algorithm>
#include<list>
#include<functional>
#define mp make_pair
#define X first
#define Y second
#define INF 987654321
#define PI 3.14159265358979323846264
#define MOD 1000000007LL
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
typedef complex<double> base;
typedef pair<int, ll> P;
ll POW(ll a, ll b) { if (b == 0)return 1; if (b == 1)return a; if (b & 1)return (a*POW(a, b - 1)) % MOD; ll t = POW(a, b / 2); return (t*t) % MOD; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//

char a[1001], b[1001];
int n, m, k;
int d[1000][1000][10][2];
int go(int N, int M, int K,int c)
{
	if (K == k)return 0;
	if (N == n || M == m)
	{
		if (K == k - 1 && c == 1)return 0;
		else return -INF;
	}
	int &ret = d[N][M][K][c];
	if (ret != -1)return ret;
	ret = 0;
	if (c == 0)
	{
		ret = max(ret, go(N + 1, M, K, 0));
		ret = max(ret, go(N, M + 1, K, 0));
		if (a[N] == b[M])ret = max(ret, 1 + go(N + 1, M + 1, K, 1));
	}
	else
	{
		ret = max(ret, go(N, M, K + 1, 0));
		ret = max(ret, go(N + 1, M, K+1, 0));
		ret = max(ret, go(N, M + 1, K+1, 0));
		if (a[N] == b[M])ret = max(ret, 1 + go(N + 1, M + 1, K, 1));
	}
	return ret;
}
int main() {
	MEM_1(d);
	scanf("%d%d%d", &n, &m, &k);
	scanf("%s%s", a, b);
	printf("%d", go(0, 0, 0, 0));
}