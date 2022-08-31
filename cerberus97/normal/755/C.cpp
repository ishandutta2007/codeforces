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

const int N = 1e4 + 5;

vector <int> g[N];
bool seen[N] = {0};

void dfs(int u);

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int p;
		cin >> p;
		g[i].pb(p);
		g[p].pb(i);
	}	

	int trees = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (!seen[i])
		{
			++trees;
			dfs(i);
		}
	}

	cout << trees;
}

void dfs(int u)
{
	seen[u] = true;
	for (auto &i : g[u])
	{
		if (!seen[i])
			dfs(i);
	}
}