#include<iostream>
#include<set>
#include<map>
#include<vector>
using namespace std;
const int N = 1e5;

vector <int> g[N];
vector <int> colors[N];
int c[N];
int best = -1;
bool done = false;

void build(int v, int p = -1)
{
	for (auto to : g[v])
		if (to != p)
		{
			build(to, v);
			if (colors[v].size() > 1)
				continue;
			else
			{
				for (auto x : colors[to])
					if (x != colors[v][0])
					{
						colors[v].push_back(x);
						break;
					}
			}
		}
}

void dfs(int v, set <int> &topsidecolor, int p = -1)
{
	if (best != -1)
		return;
	int bad = 0;
	if (topsidecolor.size() > 1)
		return;
	map <int, int> keep;
	for (auto to : g[v])
	{
		if (to == p) continue;
		if (colors[to].size() > 1)
			++bad;
		for (auto x : colors[to])
			keep[x]++;
	}
	if (!bad)
	{
		best = v;
		return;
	}
	if (bad > 1)
		return;
	for (auto to : g[v])
	{
		if (to == p)
			continue;
		for (auto x : colors[to])
			if (--keep[x] == 0)
				keep.erase(x);
		set <int> things = topsidecolor;
		things.insert(c[v]);
		for (auto x : keep)
		{
			things.insert(x.first);
			if (things.size() > 1)
				break;
		}
		dfs(to, things, v);
		for (auto x : colors[to])
			++keep[x];
	}
}

int main()
{
	int n;
cin >> n;
	for (int i = 0; i < n - 1; ++i)
	{
		int a , b ;
cin >> a>> b;
		--a, --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> c[i];
		colors[i].push_back(c[i]);
	}
	build(0);
	set <int> q;
	dfs(0, q);
	if (best == -1)
		cout << "NO\n";
	else
		cout << "YES\n" << best + 1 << endl;
	return 0;
}