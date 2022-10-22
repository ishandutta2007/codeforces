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
#define INF 1987654321
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
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

Pi p[200000];
int ans[200000], cnt[200000];
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	fup(i, 0, n - 1, 1)
	{
		scanf("%d", &p[i].X);
		p[i].Y = i;
	}
	while (k--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--, y--;
		if (p[x].X > p[y].X)cnt[x]++;
		if (p[x].X < p[y].X)cnt[y]++;
	}
	sort(p, p + n);
	int now = 0;
	int c = 0;
	while (1)
	{
		if (now == n)break;
		int t = p[now].X;
		queue<int> q;
		while (now < n && p[now].X == t)
		{
			q.push(p[now].Y);
			now++;
		}
		int tt = q.size();
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			ans[x] = c - cnt[x];
		}
		c += tt;
	}
	fup(i, 0, n - 1, 1)printf("%d ", ans[i]);
}