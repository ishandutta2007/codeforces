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
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int n, m, k, s;
Vi v[100001], vv[101];;
int a[100001];
int dist[101][100001];
void bfs(int K)
{
	queue<int> q;
	for (int x : vv[K])
	{
		q.push(x);
		dist[K][x] = 0;
	}
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int next : v[x])
		{
			if (dist[K][next] == -1)
			{
				q.push(next);
				dist[K][next] = dist[K][x] + 1;
			}
		}
	}
}
int main() {
	MEM_1(dist);
	scanf("%d%d%d%d", &n, &m, &k, &s);
	fup(i, 1, n, 1)
	{
		scanf("%d", a + i);
		vv[a[i]].push_back(i);
	}
	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	fup(i, 1, k, 1)bfs(i);
	fup(i, 1, n, 1)
	{
		priority_queue<int, Vi, greater<int> >pq;
		fup(j, 1, k, 1)pq.push(dist[j][i]);
		int ans = 0;
		fup(tt, 1, s, 1)
		{
			ans += pq.top();
			pq.pop();
		}
		printf("%d ", ans);
	}
}