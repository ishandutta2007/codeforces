#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int>pii;
typedef pair<pii, int>pi3;
pii ans[100000];
typedef long long ll;
int main()
{
	int num, way;
	scanf("%d%d", &num, &way);
	vector<pi3>vec;
	for (int i = 0; i < way; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		vec.push_back(make_pair(make_pair(za, 1 - zb), i));
	}
	sort(vec.begin(), vec.end());
	vector<pii>zv;
	ll pt = 1;
	for (int i = 0; i < way; i++)
	{
		if (vec[i].first.second == 0)
		{
			pt++;
			ans[vec[i].second] = make_pair(1, pt);
			if (zv.size() <= 200000)for (int j = 2; j < pt; j++)zv.push_back(make_pair(j, pt));
		}
		else
		{
			if (zv.empty())
			{
				printf("-1\n");
				return 0;
			}
			ans[vec[i].second] = zv[zv.size() - 1];
			zv.pop_back();
		}
	}
	for (int i = 0; i < way; i++)printf("%d %d\n", ans[i].first, ans[i].second);
}