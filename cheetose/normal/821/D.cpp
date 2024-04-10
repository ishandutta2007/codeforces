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
#define INF 9876543
#define PI 3.14159265358979323846264
#define MOD 20091101
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
typedef complex<double> base;
ll POW(ll a, ll b) { if (b == 0)return 1; if (b == 1)return a; if (b & 1)return (a*POW(a, b - 1)) % MOD; ll t = POW(a, b / 2); return (t*t) % MOD; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//

struct xx {
	int x, y, i;
}px[10001];
struct yy {
	int x, y, i;
}py[10001];
int n, m, k;
Pi p[10001];
int lowerx(int x)
{
	int l = 0, r = k - 1;
	while (l <= r)
	{
		int M = (l + r) / 2;
		if (px[M].x >= x)r = M - 1;
		else l = M + 1;
	}
	return l;
}
int lowery(int x)
{
	int l = 0, r = k - 1;
	while (l <= r)
	{
		int M = (l + r) / 2;
		if (py[M].y >= x)r = M - 1;
		else l = M + 1;
	}
	return l;
}
inline int cost(Pi p1, Pi p2)
{
	if ((p1.X == p2.X && (int)abs(p1.Y - p2.Y) == 1) || (p1.Y == p2.Y && (int)abs(p1.X - p2.X) == 1)) return 0;
	if ((int)abs(p1.Y - p2.Y) <= 2 || (int)abs(p1.X - p2.X) <= 2)return 1;
	return INF;
}
bool chk[10001];
bool f1(xx p1, xx p2)
{
	if (p1.x != p2.x)return p1.x < p2.x;
	return p1.y < p2.y;
}
bool f2(yy p1, yy p2)
{
	if (p1.y != p2.y)return p1.y < p2.y;
	return p1.x < p2.x;
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	bool ok = 0;
	fup(i, 0, k - 1, 1)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		p[i] = Pi(x, y);
		px[i] = { x,y,i };
		py[i] = { x,y,i };
		if (Pi(x,y) == Pi(n, m))ok = 1;
	}
	sort(px, px + k,f1);
	sort(py, py + k, f2);
	int dist[10001];
	fill(dist, dist + 10001, INF);
	dist[0] = 0;
	priority_queue<Pi> q;
	q.push(Pi(0, 0));
	while (!q.empty())
	{
		int x = q.top().second;
		q.pop();
		if (chk[x])continue;
		chk[x] = 1;
		for (int ii = lowerx(p[x].X - 2);ii<k && px[ii].x<=p[x].X+2;ii++)
		{
			int next = px[ii].i;
			int Cost = cost(p[x], p[next]);
			if (chk[next])continue;
			if (dist[next] > dist[x] + Cost)
			{
				dist[next] = dist[x] + Cost;
				q.push(Pi(-dist[next], next));
			}
		}
		for (int ii = lowery(p[x].Y - 2); ii<k &&py[ii].y <= p[x].Y + 2; ii++)
		{
			int next = py[ii].i;
			int Cost = cost(p[x], p[next]);
			if (chk[next])continue;
			if (dist[next] > dist[x] + Cost)
			{
				dist[next] = dist[x] + Cost;
				q.push(Pi(-dist[next], next));
			}
		}
	}
	if (ok)
	{
		if (dist[k - 1] == INF)puts("-1");
		else printf("%d", dist[k - 1]);
	}
	else
	{
		int res = INF;
		fup(i, 0, k - 1, 1)
		{
			if (p[i].X >= n - 1 || p[i].Y >= m - 1)res = min(res, dist[i]);
		}
		if (res == INF)puts("-1");
		else printf("%d", res + 1);
	}
}