#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

#define SIZE 200228
#define pint pair<int, int>
#define mp make_pair

int	n, m, s, d;
int x[SIZE];
pint din[SIZE];
int pr[SIZE];
vector<pint> ans;


int main()
{
	scanf("%d%d%d%d", &n, &m, &s, &d);
	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);
	sort(x, x + n);
	if (x[0] <= s || d == 1)
	{
		printf("IMPOSSIBLE\n");
		return 0;
	}
	//din[0] = mp(max(s, x[0] - d + 1), x[0] - 1);
 	din[0] = mp(x[0] + 1, x[0] + d - 1);
	for (int i = 1; i < n; i++)
	{
		if (x[i] - x[i - 1] - 2 >= s)
		{
			din[i] = mp(x[i] + 1, x[i] + d - 1);
			pr[i] = i;
		}
		else
		{
			if (din[i - 1].second > x[i])
			{
				pr[i] = pr[i - 1];
				din[i] = mp(x[i] + 1, din[i - 1].second);
			}
			else
			{
				printf("IMPOSSIBLE\n");
				return 0;
			}
		}
	}
	if (din[n - 1].second < m)
		ans.push_back(mp(0, m - din[n - 1].second));
	int pos = n - 1;
	int last = min(din[n - 1].second, m);
	while (pos != -1)
	{
		ans.push_back(mp(1, last - x[pr[pos]] + 1));
		last = x[pr[pos]] - 1;
		pos = pr[pos] - 1;
		if (pos != -1)
		{
			int prev = min(din[pos].second, last - s);
			ans.push_back(mp(0, last - prev));
			last = prev;
		}
		else
			ans.push_back(mp(0, last));
	}
	reverse(ans.begin(), ans.end());
	for (size_t i = 0; i < ans.size(); i++)
	{
		if (ans[i].first == 0)
			printf("RUN ");
		else
			printf("JUMP ");
		printf("%d\n", ans[i].second);
	}
	return 0;
}