/*
Hanit Banga
*/

#include <iostream>
#include <vector>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e6 + 5, ADD = 3e8;

int a[N], sum[N], ctr[N] = {0};
bool cut[N] = {0};
vector <int> g[N];

void count_need(int cur, int need);
bool solve(int cur, int need);
void print(int cur);

int main()
{	
	fast_cin();
	int n;
	cin >> n;

	int root, total = 0;
	for (int i = 1; i <= n; ++i)
	{
		int p;
		cin >> p >> a[i];
		total += a[i];
		if (p == 0)
			root = i;
		else
		{
			g[p].pb(i);
			// g[i].pb(p);
		}
	}

	if ((total + ADD) % 3)
	{
		cout << -1;
		return 0;
	}

	int need = total/3;
	count_need(root, need);
	if (!solve(root, need))
		cout << -1;
}

void count_need(int cur, int need)
{
	ctr[cur] = 0;
	sum[cur] = a[cur];
	for (auto &i : g[cur])
	{
		count_need(i, need);
		ctr[cur] += ctr[i];
		sum[cur] += sum[i];
	}

	if (sum[cur] == need)
	{
		++ctr[cur];
		cut[cur] = true;
	}
}

bool solve(int cur, int need)
{
	int c = 0;
	for (auto &i : g[cur])
	{
		if (solve(i, need))
			return true;

		if (ctr[i])
			++c;
	}

	if (c >= 2)
	{
		c = 2;
		for (auto &i : g[cur])
		{
			if (ctr[i])
			{
				print(i);
				--c;
			}

			if (!c)
				break;
		}

		return true;
	}

	for (auto &i : g[cur])
	{
		if (sum[i] == 2*need and ctr[i] and !cut[i])
		{
			print(i);
			cout << i << ' ';
			return true;
		}
	}

	return false;
}

void print(int cur)
{
	if (cut[cur])
	{
		cout << cur << ' ';
		return;
	}

	for (auto &i : g[cur])
	{
		if (ctr[i])
		{
			print(i);
			return;
		}
	}
}