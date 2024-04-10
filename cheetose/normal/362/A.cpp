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
#define INF 2000000007
#define PI 3.14159265358979323846264
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
int DX[] = { 2,2,-2,-2 }, DY[] = { 2,-2,-2,2 };

char s[8][9];
int chk1[8][8], chk2[8][8];
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		MEM_1(chk1);
		MEM_1(chk2);
		fup(i, 0, 7, 1)scanf("%s", s[i]);
		VPi K;
		fup(i,0,7,1)
			fup(j, 0, 7, 1)
		{
			if (s[i][j] == 'K')K.push_back(mp(i, j));
		}
		queue<Pi> q;
		chk1[K[0].X][K[0].Y] = 0;
		chk2[K[1].X][K[1].Y] = 0;
		q.push(K[0]);
		while (!q.empty())
		{
			int x, y;
			tie(x, y) = q.front();
			q.pop();
			fup(i, 0, 3, 1)
			{
				int nx = x + DX[i], ny = y + DY[i];
				if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && chk1[nx][ny] == -1)
				{
					chk1[nx][ny] = chk1[x][y] + 1;
					q.push(mp(nx, ny));
				}
			}
		}
		q.push(K[1]);
		while (!q.empty())
		{
			int x, y;
			tie(x, y) = q.front();
			q.pop();
			fup(i, 0, 3, 1)
			{
				int nx = x + DX[i], ny = y + DY[i];
				if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && chk2[nx][ny] == -1)
				{
					chk2[nx][ny] = chk2[x][y] + 1;
					q.push(mp(nx, ny));
				}
			}
		}
		bool ok = 0;
		fup(i,0,7,1)
			fup(j, 0, 7, 1)
		{
			if (chk1[i][j] != -1 && chk2[i][j] != -1 && s[i][j] != '#'&&chk1[i][j] + chk2[i][j] % 2 == 0)ok = 1;
		}
		puts(ok ? "YES" : "NO");
	}
}