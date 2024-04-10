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
#define INF 987654321
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

int n, m;
int a[5005];
Vi v[5005], vv[5005];
Pi res[5005];
int main() {
	scanf("%d%d", &n, &m);
	fup(i, 1, n, 1)
	{
		scanf("%d", a + i);
		v[a[i]].pb(i);
	}
	fup(i, 1, m, 1)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		vv[x].pb(y);
	}
	fup(i, 1, n, 1)sort(ALL(vv[i]));
	fup(i, 0, n, 1)
	{
		bool ok = 1;
		Pll rr=mp(0,1);
		fup(k, 1, n, 1)
		{
			int L = 0, R = 0;
			for (int x : v[k])
			{
				if (x <= i)L++;
				else R++;
			}
			if (k == a[i])
			{
				int l = 0, r = 0;
				for (int x : vv[k])
				{
					if (x == L)l++;
					else if (x <= R)r++;
				}
				if (l == 0)
				{
					ok = 0;
					break;
				}
				if (r)
				{
					rr.X += 2;
					rr.Y = (rr.Y*r) % MOD;
				}
				else
				{
					rr.X++;
				}
			}
			else
			{
				int l = 0, r = 0, b = 0;
				for (int x : vv[k])
				{
					if (x <= L && x <= R)b++;
					else if (x <= L)l++;
					else if (x <= R)r++;
				}
				if (!l && !r && !b)continue;
				if (!l && !b)
				{
					rr.X++;
					rr.Y = (rr.Y*r) % MOD;
				}
				else if (!r && !b)
				{
					rr.X++;
					rr.Y = (rr.Y*l) % MOD;
				}
				else if (!l && !r && b == 1)
				{
					rr.X++;
					rr.Y = (rr.Y * 2) % MOD;
				}
				else
				{
					rr.X += 2;
					ll tmp = 0;
					tmp += (1LL * l*b) % MOD;
					tmp += (1LL * r*b) % MOD;
					tmp += (1LL * b*(b - 1)) % MOD;
					tmp %= MOD;
					rr.Y = (rr.Y*tmp) % MOD;
				}
			}
		}
		if (!ok)continue;
		res[i] = rr;
	}
	Pi ans = mp(0, 1);
	fup(i, 0, n, 1)
	{
		if (res[i].X > ans.X)ans = res[i];
		else if (res[i].X == ans.X)ans.Y = (ans.Y + res[i].Y) % MOD;
	}
	if (ans.X == 0)ans.Y = 1;
	printf("%d %d\n", ans.X, ans.Y);
}