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
#define MOD 1000000007
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
typedef pair<ll, int> P;
typedef vector<P> VP;
typedef complex<double> base;
ll POW(ll a, ll b) { if (b == 0)return 1; if (b == 1)return a; if (b & 1)return (a*POW(a, b - 1)) % MOD; ll t = POW(a, b / 2); return (t*t) % MOD; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//

char s[50][51];
char a[101];
int n, m, N;
Pi dd[4] = { {-1,0},{0,-1},{0,1},{1,0} };
Pi S, E;
bool chk()
{
	int x = S.X, y = S.Y;
	fup(i, 0, N - 1, 1)
	{
		x = x + dd[a[i]-'0'].X, y = y + dd[a[i]-'0'].Y;
		if (x < 0 || x >= n||y<0 || y >= m)return 0;
		if (s[x][y] == '#')return 0;
		if (Pi(x, y) == E)return 1;
	}
	return 0;
}
int main() {
	scanf("%d%d", &n, &m);
	fup(i, 0, n - 1, 1)
		scanf("%s", s[i]);
	fup(i,0,n-1,1)
		fup(j, 0, m - 1, 1)
	{
		if (s[i][j] == 'S')S = Pi(i, j);
		if (s[i][j] == 'E')E = Pi(i, j);
	}
	scanf("%s", a);
	N = strlen(a);
	int cnt = 0;
	do {
		if (chk())
			cnt++;
	} while (next_permutation(dd, dd + 4));
	printf("%d", cnt);
}