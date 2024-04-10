#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

vector<bool> used(MAXN);
vector<pair<int, int>> edge;

int main()
{
	int n, m;
	scanf("%i%i", &n, &m);
	used[m] = true;
	int lst = m, top = n;
	for (int x = 2; x < n; x++)
	{
		int a;
		scanf("%i", &a);
		if (used[a])
		{
			while (used[top])
				top--;
			edge.push_back({lst, top});
			used[top] = true;
		}
		else
		{
			edge.push_back({lst, a});
			used[a] = true;
		}
		lst = a;
	}
	while (used[top])
		top--;
	edge.push_back({lst, top});
	printf("%i\n", m);
	for (auto &x : edge)
		printf("%i %i\n", x.first, x.second);
}