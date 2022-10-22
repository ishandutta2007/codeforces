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
#define INF 1000000055
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

Vi v[1000001];
int parent[1000001][21], depth[1000001];
bool chk[1000001];
void MT(int N)
{
	queue<int> q;
	q.push(N);
	depth[N] = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++)
		{
			int next = v[x][i];
			if (depth[next] == -1)
			{
				depth[next] = depth[x] + 1;
				parent[next][0] = x;
				q.push(next);
			}
		}
	}
}
int LCA(int x, int y)
{
	if (depth[x] < depth[y])swap(x, y);
	int dif = depth[x] - depth[y];
	for (int j = 0; dif > 0; j++)
	{
		if (dif & 1)x = parent[x][j];
		dif /= 2;
	}

	if (x != y)
	{
		for (int j = 20; j >= 0; j--)
		{
			if (parent[x][j] != -1 && parent[x][j] != parent[y][j])
			{
				x = parent[x][j];
				y = parent[y][j];
			}
		}
		x = parent[x][0];
	}
	return x;
}
int dist(int x)
{
	int y = x;
	fdn(i, 20, 0, 1)
	{
		if (parent[y][i] == -1 || chk[parent[y][i]])continue;
		y = parent[y][i];
	}
	return depth[x] - depth[y] + 1;
}
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	fup(i, 1, n - 1, 1)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	MEM_1(parent);
	MEM_1(depth);
	MT(n);
	for (int j = 0; j < 20; j++)
		for (int i = 1; i <= n; i++)
			if (parent[i][j] != -1)
				parent[i][j + 1] = parent[parent[i][j]][j];
	int rem = n - k - 1;
	int now = n;
	chk[n] = 1;
	fdn(k, n - 1, 1, 1)
	{
		if (chk[k])continue;
		int t = dist(k);
		if (t <= rem)
		{
			now = k;
			int kk = k;
			while (!chk[kk])
			{
				chk[kk] = 1;
				rem--;
				kk = parent[kk][0];
			}
		}
	}
	fup(i, 1, n, 1)
		if (!chk[i])printf("%d ", i);
}