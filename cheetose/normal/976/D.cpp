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
ll MOD = 12345678910;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int d[305];
bool chk[1005][1005];
int main() {
	int n;
	scanf("%d", &n);
	fup(i, 1, n, 1)scanf("%d", d + i);
	int sz = d[n] + 1;
	int L = 1, R = sz;
	int Li = 1, Ri = n;
	while (1)
	{
		if (Li == Ri)
		{
			fup(i, L, R, 1)fup(j, i + 1, R, 1)chk[i][j] = 1;
			break;
		}
		if (Li + 1 == Ri)
		{
			fup(i, L, L + d[Li] - 1, 1)fup(j, i + 1, R, 1)chk[i][j] = 1;
			break;
		}
		fup(i, L, L + d[Li] - 1, 1)fup(j, i + 1, R, 1)chk[i][j] = 1;
		fup(i, Li + 1, Ri - 1, 1)d[i] -= d[Li];
		L += d[Li];
		R = L + d[Ri-1];
		Li++, Ri--;
	}
	VPi ans;
	fup(i, 1, sz, 1)fup(j, i + 1, sz, 1)if (chk[i][j] || chk[j][i])ans.push_back(mp(i, j));
	printf("%d\n", ans.size());
	for (auto &p : ans)printf("%d %d\n", p.X, p.Y);
}