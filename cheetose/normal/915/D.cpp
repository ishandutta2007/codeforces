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
typedef complex<double> base;
ll POW(ll a, ll b) { if (b == 0)return 1; if (b == 1)return a; if (b & 1)return (a*POW(a, b - 1)) % MOD; ll t = POW(a, b / 2); return (t*t) % MOD; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

bool link[501][501];
Vi v[501];
stack<int> st;
vector<Vi> scc;
int num[501], sccn[501],ind[501];
int cnt, sn;
bool finish[501];
int dfs(int N)
{
	num[N] = ++cnt;
	st.push(N);
	int res = cnt;
	for (int i = 0; i < v[N].size(); i++)
	{
		int next = v[N][i];
		if (num[next] == 0) res = min(res, dfs(next));
		else if (!finish[next]) res = min(res, num[next]);
	}
	if (num[N] == res)
	{
		Vi temp;
		while (!st.empty())
		{
			int x = st.top();
			st.pop();
			finish[x] = 1;
			temp.push_back(x);
			sccn[x] = sn;
			if (x == N)break;
		}
		scc.push_back(temp);
		sn++;
	}
	return res;
}
Vi nv[501];
int to, from;
int visited[501];
bool Cycle(int here) {
	if (visited[here]) {
		if (visited[here] == -1) {
			return true;
		}
		return false;
	}

	visited[here] = -1;
	for (int there : v[here]) {
		if (here == from && to == there)continue;
		if (Cycle(there)) {
			return true;
		}
	}
	visited[here] = 1;

	return false;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	fup(i, 0, m - 1, 1)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		link[x][y] = 1;
	}
	int tt = 0;
	fup(i,1,n,1)
		fup(j, i + 1, n, 1)
	{
		if (link[i][j] && link[j][i])tt++;
	}
	if (tt > 1)
	{
		puts("NO");
		return 0;
	}
	for (int i = 1; i <= n; i++)
		if (num[i] == 0)dfs(i);
	int cc[501] = { 0 };
	fup(i, 1, n, 1)
		cc[sccn[i]]++;
	tt = 0;
	int group = -1;
	fup(i, 0, sn, 1)
		if (cc[i] > 1)
		{
			tt++;
			group = i;
		}
	if (tt > 1)
	{
		puts("NO");
		return 0;
	}
	if (tt == 0)
	{
		puts("YES");
		return 0;
	}
	Vi what;
	fup(i, 1, n, 1)if (sccn[i] == group)what.push_back(i);
	int N = what.size();
	fup(i,0,N-1,1)
		fup(j, 0, N - 1, 1)
	{
		int x = what[i], y = what[j];
		if (link[x][y])
		{
			nv[x].push_back(y);
			ind[y]++;
		}
	}
	fup(i, 0, N - 1, 1)
	{
		int x = what[i];
		if (ind[x] == 1)
		{
			fup(j, 0, N - 1, 1)
			{
				int tt = what[j];
				if (link[tt][x])
				{
					from = tt, to = x;
					break;
				}
			}
			MEM0(visited);
			if (!Cycle(x))
			{
				puts("YES");
				return 0;
			}
		}
	}
	puts("NO");
}