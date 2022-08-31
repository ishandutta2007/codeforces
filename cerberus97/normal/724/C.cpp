#include <iostream>
#include <cstdlib>
#include <set>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <pii, int> p3;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5, INF = 2147483647;

set <int> sum[2*N], diff[2*N];
pii points[N];
ll seen[N];
int n, m, c;
set <p3> bfsSeen;

pii getEnd(int x, int y, int dir)
{
	if (dir == 0)
	{
		c = min(n-x, m-y);
		return {x+c, y+c};
	}

	if (dir == 1)
	{
		c = min(x, y);
		return {x-c, y-c};
	}

	if (dir == 2)
	{
		c = min(x, m-y);
		return {x-c, y+c};
	}

	if (dir == 3)
	{
		c = min(n-x, y);
		return {x+c, y-c};
	}
}

void delSum(int x, int y, ll tm)
{
	for (auto &i : sum[x+y])
	{
		seen[i] = abs(x - points[i].first) + tm;
		diff[points[i].first - points[i].second + N].erase(i);
	}

	sum[x+y].clear();
}

void delDiff(int x, int y, ll tm)
{
	for (auto &i : diff[x-y+N])
	{
		seen[i] = abs(x - points[i].first) + tm;
		sum[points[i].first + points[i].second].erase(i);
	}

	diff[x-y+N].clear();
}

void bfs(int x, int y, int dir, ll tm)
{
	if (bfsSeen.find({{x,y}, dir}) != bfsSeen.end())
		return;

	bfsSeen.insert({{x,y}, dir});

	if ((x == 0 and y == m) or (x == n and y == 0) or (x == n and y == m) or (!x and !y and dir))
		return;

	pii end = getEnd(x, y, dir);

	if (dir >= 2)
	{
		delSum(x, y, tm);
	}

	else
	{
		delDiff(x, y, tm);
	}

	int newDir;

	if ((dir == 3 and end.second == 0) or (dir == 2 and end.first == 0))
	{
		newDir = 0;
	}

	else if ((dir == 3 and end.first == n) or (dir == 2 and end.second == m))
	{
		newDir = 1;
	}

	else if ((dir == 1 and end.second == 0) or (dir == 0 and end.first == n))
	{
		newDir = 2;
	}

	else
		newDir = 3;

	bfs(end.first, end.second, newDir, tm + c);
}

int main()
{
	int k;
	cin >> n >> m >> k;

	for (int i = 0; i < k; ++i)
	{
		int x, y;

		cin >> x >> y;
		points[i] = {x, y};
		seen[i] = -1;

		sum[x+y].insert(i);
		diff[x-y+N].insert(i);
	}

	bfs(0, 0, 0, 0);

	for (int i = 0; i < k; ++i)
		cout << seen[i] << '\n';
}