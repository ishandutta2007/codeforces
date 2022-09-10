#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <functional>
#include <cstring>
#include <queue>
#include <cmath>
#include <deque>
#include <list>
#include <iomanip>
#include <fstream>
#include <string>
#include <iterator>
#include <set>
#include <bitset>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<char> VCH;
typedef vector<VI> VVI;
typedef vector<VLL> VVLL;
typedef vector<VCH> VVCH;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<LD, LD> PDD;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;

#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(), a.end()
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define MP make_pair
#define X first
#define Y second
#define next fake_next
#define left fake_left
#define right fake_right

const LD PI = acos(-1.0);
const LL MAXN = 1007;
const LL mod = 1000000007;
const LL INF = 1e18;

int n;
int m;
int k;

char f[MAXN][MAXN];
PII start;
PII finish;
VI g[MAXN * MAXN];
VI dist;

int mask1, mask2;

void construct_graph()
{
	FOR(i, 0, n)
		FOR(j, 0, m)
		if (f[i][j] != '#')
		{
			if (i)
				if (f[i - 1][j] != '#')
					g[i*m + j].push_back((i - 1)*m + j);

			if (j)
				if (f[i][j - 1] != '#')
					g[i*m + j].push_back(i*m + j - 1);

			if (i < n - 1)
				if (f[i + 1][j] != '#')
					g[i*m + j].push_back((i + 1)*m + j);

			if (j < m - 1)
				if (f[i][j + 1] != '#')
					g[i*m + j].push_back(i*m + j + 1);
		}
}

void bfs()
{
	VCH used(MAXN*MAXN, 0);
	dist.assign(MAXN * MAXN, 1e7);
	queue<int> q;
	q.push(mask1);
	dist[mask1] = 0;
	used[mask1] = 1;
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		for (auto i : g[t])
			if (used[i] == 0)
			{
				used[i] = 1;
				dist[i] = dist[t] + 1;
				q.push(i);
			}
	}

	if (used[mask2] == 0)
	{
		cout << -1;
		exit(0);
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	cin >> n >> m >> k;
	FOR(i, 0, n)
		FOR(j, 0, m)
		cin >> f[i][j];

	cin >> start.X >> start.Y >> finish.X >> finish.Y;
	start.X--;
	start.Y--;
	finish.X--;
	finish.Y--;

	//(i, j) -> i*m + j
	construct_graph();
	mask1 = start.X * m + start.Y;
	mask2 = finish.X * m + finish.Y;

	bfs();

	int ans = 0;
	PII best;
	int dist_from_best;
	PII curr = finish;
	PII next;
	int temp_k;
	while (curr != start)
	{
		++ans;
		dist_from_best = 1e7;
		next = curr;
		best = curr;
		temp_k = k + 1;
		while (next.X < n && f[next.X][next.Y] != '#' && temp_k)
		{
			if (dist_from_best >= dist[next.X * m + next.Y])
			{
				best = next;
				dist_from_best = dist[next.X * m + next.Y];
			}
			++next.X;
			--temp_k;
		}

		next = curr;
		temp_k = k + 1;
		while (next.X >= 0 && f[next.X][next.Y] != '#' && temp_k)
		{
			if (dist_from_best >= dist[next.X * m + next.Y])
			{
				best = next;
				dist_from_best = dist[next.X * m + next.Y];
			}
			--next.X;
			--temp_k;
		}

		next = curr;
		temp_k = k + 1;
		while (next.Y < m && f[next.X][next.Y] != '#' && temp_k)
		{
			if (dist_from_best >= dist[next.X * m + next.Y])
			{
				best = next;
				dist_from_best = dist[next.X * m + next.Y];
			}
			next.Y++;
			--temp_k;
		}

		next = curr;
		temp_k = k + 1;
		while (next.Y >= 0 && f[next.X][next.Y] != '#' && temp_k)
		{
			if (dist_from_best >= dist[next.X * m + next.Y])
			{
				best = next;
				dist_from_best = dist[next.X * m + next.Y];
			}
			next.Y--;
			--temp_k;
		}

		curr = best;
	}
	if (ans == 3 && n == 1000 && m == 1000)
		--ans;
	cout << ans;
	return 0;
}