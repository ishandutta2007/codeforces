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
#define mp make_pair
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
int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

Vi v[200001];
bool chk[200001];
int visited[200001];
bool Cycle(int here) {
	if (visited[here]) {
		if (visited[here] == -1) {
			return true;
		}
		return false;
	}

	visited[here] = -1;
	for (int there : v[here]) {
		if (Cycle(there)) {
			return true;
		}
	}
	visited[here] = 1;

	return false;
}
int d[200001][2];
bool chk2[200001][2];
int go(int N, int c)
{
	if (v[N].empty() && c == 1)return 1;
	chk2[N][c] = 1;
	int &ret = d[N][c];
	if (ret != -1)return ret;
	ret = 0;
	for (int next : v[N])
	{
		if (!chk2[next][1 - c])
			if (go(next, 1 - c) == 1)return ret = 1;
	}
	return ret;
}
void track(int N, int c)
{
	printf("%d ", N);
	if (v[N].empty() && c == 1)
	{
		exit(0);
	}
	chk2[N][c] = 1;
	for (int next : v[N])
	{
		if (!chk2[next][1 - c])
			if (go(next, 1 - c) == 1)track(next, 1 - c);
	}
}
int main()
{
	MEM_1(d);
	int n, m;
	scanf("%d%d", &n, &m);
	fup(i, 1, n, 1)
	{
		int c;
		scanf("%d", &c);
		while (c--)
		{
			int x;
			scanf("%d", &x);
			v[i].push_back(x);
		}
	}
	int s;
	scanf("%d", &s);
	if (go(s, 0) == 1)
	{
		puts("Win");
		MEM0(chk2);
		track(s, 0);
	}
	else
	{
		if (Cycle(s))puts("Draw");
		else puts("Lose");
	}
}