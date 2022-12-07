#include<cstdio>
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
#include<algorithm>
#include<list>
#include<functional>
#define mp make_pair
#define X first
#define Y second
#define INF 987654321
#define PI 3.14159265358979323846264
#define MOD 1000000007LL
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
typedef vector<iii> Viii;
typedef complex<double> base;
ll POW(ll a, ll b) { if (b == 0)return 1; if (b == 1)return a; if (b & 1)return (a*POW(a, b - 1)) % MOD; ll t = POW(a, b / 2); return (t*t) % MOD; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return gcd(a, b); return a*b / gcd(a, b); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

VPi v[101];
int d[101][101][26][2];
int go(int N,int M, int last,int who)
{
	int &ret = d[N][M][last][who];
	if (ret != -1)return ret;
	ret = 1-who;
	if (who == 0)
	{
		for (const Pi& p : v[N])
		{
			int next = p.X;
			int cost = p.Y - 'a';
			if (cost >= last)
			{
				ret = min(ret, go(next, M, cost, 1 - who));
			}
		}
	}
	else
	{
		for (const Pi& p : v[M])
		{
			int next = p.X;
			int cost = p.Y - 'a';
			if (cost >= last)
			{
				ret = max(ret, go(N, next, cost, 1 - who));
			}
		}
	}
	return ret;
}
int main() {
	MEM_1(d);
	int n, m;
	scanf("%d%d", &n, &m);
	fup(i, 0, m - 1, 1)
	{
		int x, y;
		char c;
		scanf("%d %d %c", &x, &y, &c);
		v[x].push_back(Pi(y, c));
	}
	fup(i, 1, n, 1)
	{
		fup(j, 1, n, 1)
		{
			if (go(i, j, 0, 0) == 0)printf("A");
			else printf("B");
		}
		puts("");
	}
}