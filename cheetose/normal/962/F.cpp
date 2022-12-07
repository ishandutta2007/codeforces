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
#define INF 1000000005
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
int MOD = 10000;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int num[100001], low[100001];
bool vis[100001], chk[100001], chke[100001];
VPi v[100001];
Vi bcc[100001];
set<int> BCCV[100001], BCCE[100001];
int cnt,ccnt;
void dfs(int x, int p) {
	num[x] = low[x] = ++cnt;
	for (auto& P : v[x])
	{
		int next = P.X;
		if (next == p) continue;
		if (!num[next])
		{
			dfs(next, x);
			low[x] = min(low[x], low[next]);
		}
		else 
		{
			low[x] = min(low[x], num[next]);
		}
	}
}
void color(int x, int c) {
	if (c > 0)
	{
		bcc[x].push_back(c);
		BCCV[c].insert(x);
	}
	vis[x] = 1;
	for (auto& P : v[x])
	{
		int next = P.X;
		if (vis[next])
		{
			if (!chke[P.Y])
			{
				BCCE[c].insert(P.Y);
				chke[P.Y] = 1;
			}
			continue;
		}
		if (num[x] <= low[next]) 
		{
			bcc[x].push_back(++ccnt);
			BCCE[ccnt].insert(P.Y);
			chke[P.Y] = 1;
			BCCV[ccnt].insert(x);
			color(next, ccnt);
		}
		else 
		{
			BCCE[c].insert(P.Y);
			chke[P.Y] = 1;
			color(next, c);
		}
	}
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	fup(i, 1, m, 1)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(mp(y,i));
		v[y].push_back(mp(x,i));
	}
	fup(i, 1, n, 1) if (num[i] == 0)dfs(i, -1);
	fup(i, 1, n, 1) if (!vis[i])color(i, 0);
	fup(i, 1, ccnt, 1)
	{
		if (BCCV[i].size() == BCCE[i].size())
		{
			for (int e : BCCE[i])chk[e] = 1;
		}
	}
	int ans = 0;
	fup(i, 1, m, 1)if (chk[i])ans++;
	printf("%d\n", ans);
	fup(i, 1, m, 1)if (chk[i])printf("%d ", i);
}