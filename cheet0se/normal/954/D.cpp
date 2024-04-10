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
#define INF 987654321
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
int MOD = 9901;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

set<Pi> St;
Vi v[1001];
int distS[1001], distE[1001];
int main()
{
	MEM_1(distS);
	MEM_1(distE);
	int n, m, S, E;
	scanf("%d%d%d%d", &n, &m, &S, &E);
	fup(i,1,m,1)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
		if (x > y)swap(x, y);
		St.insert(mp(x, y));
	}
	queue<int> q;
	distS[S] = 0;
	q.push(S);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int next : v[x])
		{
			if (distS[next] == -1)
			{
				distS[next] = distS[x] + 1;
				q.push(next);
			}
		}
	}
	distE[E] = 0;
	q.push(E);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int next : v[x])
		{
			if (distE[next] == -1)
			{
				distE[next] = distE[x] + 1;
				q.push(next);
			}
		}
	}
	int D = distS[E];
	int ans = 0;
	fup(i,1,n,1)
		fup(j, i + 1, n, 1)
	{
		if (St.find(mp(i, j)) != St.end())continue;
		int t = min(distS[i] + distE[j] + 1, distS[j] + distE[i] + 1);
		if (t >= D)ans++;
	}
	printf("%d", ans); 
}