/*
Hanit Banga
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 5;

int parent[N], size[N], n;
map <string, int> a;

int comp(int x);
int find(int x);
void join(int x, int y);

int main()
{
	fast_cin();
	int m, q;
	cin >> n >> m >> q;

	for (int i = 1; i <= n; ++i)
	{
		string s;
		cin >> s;
		a[s] = i;
	}

	for (int i = 1; i <= 2*n; ++i)
	{
		parent[i] = i;
		size[i] = 1;
	}

	for (int i = 0; i < m; ++i)
	{
		int t; string s1, s2;
		cin >> t >> s1 >> s2;
		int x = a[s1], y = a[s2];
		if (t == 2)
			y = comp(y);

		if (find(x) != find(comp(y)) and find(comp(x)) != find(y))
		{
			cout << "YES\n";
			join(x, y);
			join(comp(x), comp(y));
		}
		else
			cout << "NO\n";
	}

	for (int i = 0; i < q; ++i)
	{
		string s1, s2;
		cin >> s1 >> s2;
		int x = a[s1], y = a[s2];

		if (find(x) == find(y) or find(comp(x)) == find(comp(y)))
			cout << "1\n";
		else if (find(x) == find(comp(y)) or find(comp(x)) == find(y))
			cout << "2\n";
		else
			cout << "3\n";
	}
}

int comp(int x)
{
	return 2*n + 1 - x;
}

int find(int x)
{
	while (parent[x] != x)
		x = parent[x];

	return x;
}

void join(int x, int y)
{
	int rx = find(x), ry = find(y);
	if (size[rx] <= size[ry])
	{
		parent[rx] = ry;
		size[ry] = max(size[ry], size[rx] + 1);
	}
	else
	{
		parent[ry] = rx;
		size[rx] = max(size[rx], size[ry] + 1);
	}
}