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
const int MOD = 5000000;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

Pi p1[4], p2[4];
bool ok(int x, int y)
{
	int mx = INF, my = INF, Mx = -INF, My = -INF;
	fup(i, 0, 3, 1)
	{
		int xx, yy;
		tie(xx, yy) = p1[i];
		mx = min(mx, xx);
		Mx = max(Mx, xx);
		my = min(my, yy);
		My = max(My, yy);
	}
	if (x > Mx || x<mx || y>My || y < my)return 0;
	int xx = 0, yy = 0;
	int DX = 0;
	fup(i, 0, 1, 1)
	{
		DX = max(DX, (int)abs(p2[i].X - p2[i + 2].X));
	}
	DX /= 2;
	fup(i, 0, 3, 1)
	{
		int xxx, yyy;
		tie(xxx, yyy) = p2[i];
		xx += xxx, yy += yyy;
	}
	xx /= 4, yy /= 4;
	if ((int)abs(xx - x) + (int)abs(yy - y) <= DX)return 1;
	return 0;
}
int main() {
	fup(i, 0, 3, 1)scanf("%d%d", &p1[i].X, &p1[i].Y);
	fup(i, 0, 3, 1)scanf("%d%d", &p2[i].X, &p2[i].Y);
	fup(i,-100,100,1)
		fup(j, -100, 100, 1)
	{
		if (ok(i, j))return !printf("YES");
	}
	puts("NO");
}