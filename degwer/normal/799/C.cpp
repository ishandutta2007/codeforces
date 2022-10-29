#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int>pii;
int get(vector<pii>v, int g)
{
	if (v.size() < 2)return 0;
	vector<pii>x;
	int now = -1;
	int maxi = 0;
	for (int i = 0; i < v.size(); i++)
	{
		int upp = upper_bound(x.begin(), x.end(), make_pair(g - v[i].first, 1000000000)) - x.begin() - 1;
		if (upp >= 0)maxi = max(maxi, x[upp].second + v[i].second);
		if (now < v[i].second)now = v[i].second, x.push_back(v[i]);
	}
	return maxi;
}
int main()
{
	int num, ga, gb;
	scanf("%d%d%d", &num, &ga, &gb);
	vector<pii>v1, v2;
	int m1 = -1000000000, m2 = -1000000000;
	for (int i = 0; i < num; i++)
	{
		int za, zb;
		char zc;
		scanf("%d%d %c", &za, &zb, &zc);
		if (zc == 'C')
		{
			v1.push_back(make_pair(zb, za));
			if (zb <= ga)m1 = max(m1, za);
		}
		else
		{
			v2.push_back(make_pair(zb, za));
			if (zb <= gb)m2 = max(m2, za);
		}
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	printf("%d\n", max(m1 + m2, max(get(v1, ga), get(v2, gb))));
}