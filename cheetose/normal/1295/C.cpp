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
#define y0 y12
#define y1 y22
#define INF 1987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset((a),0,sizeof(a));
#define MEM_1(a) memset((a),-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef pair<ld, ld> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<double> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

char s[100001], t[100001];
int c1[26], c2[26];
Vi v[26];
void solve() {
	scanf("%s%s", s, t);
	int n = strlen(s), m = strlen(t);
	MEM0(c1); MEM0(c2);
	fup(i, 0, 25, 1)v[i].clear();
	fup(i, 0, n - 1, 1)
	{
		c1[s[i] - 'a']++;
		v[s[i] - 'a'].pb(i);
	}
	fup(i, 0, m - 1, 1)c2[t[i] - 'a']++;
	fup(i, 0, 25, 1)
	{
		if (c2[i] && !c1[i])
		{
			puts("-1");
			return;
		}
	}
	int ans = 0;
	int now = 0, tt = -1;
	while (now < m)
	{
		ans++;
		while (1)
		{
			int c = t[now] - 'a';
			auto tmp = upper_bound(ALL(v[c]), tt);
			if (tmp == v[c].end())
			{
				break;
			}
			now++, tt = *tmp;
		}
		tt = -1;
	}
	printf("%d\n", ans);
}
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--)solve();
}