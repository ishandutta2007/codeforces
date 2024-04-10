#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;

vector<vector<pair<int, pair<int, int>>>> fir(MAXN);
vector<int> ans(MAXN);

int main()
{
	int n, m;
	scanf("%i%i", &n, &m);
	for (int x = 0; x < m; x++)
	{
		int s, d, c;
		scanf("%i%i%i", &s, &d, &c);
		fir[s].push_back({d, {c, x + 1}});
		ans[d] = m + 1;
	}
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> buf;
	for (int x = 1; x <= n; x++)
	{
		for (auto y : fir[x])
			buf.push(y);
		if (!buf.empty() && !ans[x])
		{
			auto p = buf.top();
			buf.pop();
			int curf = p.first, cur = p.second.second, rem = p.second.first;
			if (curf <= x)
				goto NXT;
			ans[x] = cur;
			rem--;
			if (rem)
				buf.push({curf, {rem, cur}});
		}
	}
	if (!buf.empty())
		goto NXT;
	for (int x = 1; x <= n; x++)
		printf("%i ", ans[x]);
	printf("\n");
	return 0;
NXT:;
	printf("-1\n");
}