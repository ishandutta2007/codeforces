#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int>pii;
int main()
{
	int num,l;
	scanf("%d%d", &num, &l);
	int maxi = 0;
	bool f = true;
	vector<pii>v;
	for (int i = 0; i < l; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		if (i == 0)
		{
			maxi = max(maxi, zb + za - 1);
		}
		if (i == l - 1)
		{
			maxi = max(maxi, zb + (num - za));
		}
		v.push_back(make_pair(za, zb));
	}
	for (int i = 0; i < l - 1; i++)
	{
		if (v[i].second + (v[i + 1].first - v[i].first) < v[i + 1].second)f = false;
		if (v[i].second - (v[i + 1].first - v[i].first) > v[i + 1].second)f = false;
		maxi = max(maxi, v[i + 1].second + (v[i + 1].first - v[i].first - (v[i + 1].second - v[i].second)) / 2);
	}
	if (!f)printf("IMPOSSIBLE\n");
	else printf("%d\n", maxi);
}