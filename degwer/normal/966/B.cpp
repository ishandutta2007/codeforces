#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int>pii;
void solve(vector<pii>v, int a, int b, bool tt)
{
	vector<pii>ned;
	int now = -2000000000, rr = -1;
	for (int i = 0; i < v.size(); i++)
	{
		int t = (a + v[i].first - 1) / v[i].first;
		if (now<int(v.size()) - i - t)now = int(v.size()) - i - t, rr = i;
		ned.push_back(make_pair(now, rr));
	}
	for (int i = int(v.size()) - 1; i >= 0; i--)
	{
		int t = (b + v[i].first - 1) / v[i].first;
		if (ned[i].first >= t && i + t <= v.size())
		{
			printf("Yes\n");
			if (tt)
			{
				printf("%d %d\n", int(v.size()) - ned[i].first - ned[i].second, t);
				for (int j = ned[i].second; j<int(v.size()) - ned[i].first; j++)printf("%d ", v[j].second); printf("\n");
				for (int j = v.size() - t; j < v.size(); j++)printf("%d ", v[j].second); printf("\n");
			}
			else
			{
				printf("%d %d\n", t, int(v.size()) - ned[i].first - ned[i].second);
				for (int j = v.size() - t; j < v.size(); j++)printf("%d ", v[j].second); printf("\n");
				for (int j = ned[i].second; j<int(v.size()) - ned[i].first; j++)printf("%d ", v[j].second); printf("\n");
			}
			exit(0);
		}
	}
}
int main()
{
	int num, k1, k2;
	scanf("%d%d%d", &num, &k1, &k2);
	vector<pii>v;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		v.push_back(make_pair(z, i + 1));
	}
	sort(v.begin(), v.end());
	solve(v, k1, k2, true);
	solve(v, k2, k1, false);
	printf("No\n");
}