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
ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

char s[500][501];
bool chk[500][500];
int n, m;
int X1,Y1,x2, y2;
bool dfs(int x, int y)
{
	if (x == x2&&y == y2)return 1;
	if ((x!=X1 || y!=Y1) && s[x][y] == 'X')return 0;
	fup(i, 0, 3, 1)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= 0 && nx < n&&ny >= 0 && ny < m&& !chk[nx][ny])
		{
			chk[nx][ny] = 1;
			if(dfs(nx, ny))return 1;
		}
	}
	return 0;
}
int main() {
	scanf("%d%d", &n, &m);
	fup(i, 0, n - 1, 1)scanf("%s", s[i]);
	if (n == 1 && m == 1)return !printf("NO");
	int x1, y1;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	x1--, y1--, x2--, y2--;
	X1 = x1, Y1 = y1;
	if (x1 == x2 && y1 == y2)
	{
		int c = 0;
		fup(i, 0, 3, 1)
		{
			int nx = x1 + dx[i], ny = y1 + dy[i];
			if (nx >= 0 && nx < n&&ny >= 0 && ny < m&&s[nx][ny] == '.')return !printf("YES");
		}
		return !printf("NO");
	}
	chk[x1][y1] = 1;
	if (!dfs(x1,y1))return !printf("NO");
	int c = 0;
	fup(i, 0, 3, 1)
	{
		int nx = x2 + dx[i], ny = y2 + dy[i];
		if (nx >= 0 && nx < n&&ny >= 0 && ny < m&&s[nx][ny] == '.')c++;
		if (nx == x1 && ny == y1)c++;
	}
	puts(c+(s[x2][y2]=='X') >= 2 ? "YES" : "NO");
}