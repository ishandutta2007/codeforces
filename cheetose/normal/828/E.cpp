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

char s[100005];
int tree[4][11][10][100005];
int n;
void upd(int what,int len, int rem, int i, int k)
{
	while (i <= n)
	{
		tree[what][len][rem][i] += k;
		i += (i&-i);
	}
}
int sum(int what, int len,int rem, int i)
{
	int c = 0;
	while (i > 0)
	{
		c += tree[what][len][rem][i];
		i -= (i&-i);
	}
	return c;
}
map<char, int> CtoI;
char e[11];
int main() {
	CtoI['A'] = 0;
	CtoI['T'] = 1;
	CtoI['G'] = 2;
	CtoI['C'] = 3;
	scanf("%s", s+1);
	n = strlen(s + 1);
	fup(i, 1, n, 1)
	{
		int now = CtoI[s[i]];
		fup(l, 1, 10, 1)
		{
			upd(now, l, i%l, i, 1);
		}
	}
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int c;
		scanf("%d", &c);
		if (c == 1)
		{
			int x;
			char C;
			scanf("%d %c", &x, &C);
			int now = CtoI[s[x]], next = CtoI[C];
			s[x] = C;
			fup(l, 1, 10, 1)
				upd(now, l, x%l, x, -1);
			fup(l, 1, 10, 1)
				upd(next, l, x%l, x, 1);
		}
		else
		{
			int ans = 0;
			int l, r;
			scanf("%d%d%s", &l, &r, e);
			int N = strlen(e);
			int t = l%N;
			rotate(e, e + N - t, e + N);
			fup(i, 0, N - 1, 1)
				ans += sum(CtoI[e[i]], N, i, r) - sum(CtoI[e[i]], N, i, l - 1);
			printf("%d\n", ans);
		}
	}
}