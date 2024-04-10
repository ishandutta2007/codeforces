#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll get(vector<ll>v1, vector<ll>v2)
{
	ll m1 = -1, m2 = -1;
	for (int i = 0; i < v1.size() - 1; i++)m1 = max(m1, v1[i + 1] - v1[i]);
	for (int i = 0; i < v2.size() - 1; i++)m2 = max(m2, v2[i + 1] - v2[i]);
	return min((v1[v1.size() - 1] - v1[0]) * 2, (v1[v1.size() - 1] - v1[0]) * 3 - m1 - m2);
}
int main()
{
	int num;
	scanf("%d", &num);
	ll ans = 0;
	vector<ll>v1, v2;
	bool f = false;
	for (int i = 0; i < num; i++)
	{
		int za;
		char zb;
		scanf("%d %c", &za, &zb);
		if (zb == 'R')v1.push_back(za);
		else if (zb == 'B')v2.push_back(za);
		else
		{
			v1.push_back(za);
			v2.push_back(za);
			if (!f)
			{
				ans += za - v1[0];
				ans += za - v2[0];
				f = true;
			}
			else ans += get(v1, v2);
			v1.clear();
			v2.clear();
			v1.push_back(za);
			v2.push_back(za);
		}
	}
	if (!v1.empty())ans += v1[v1.size() - 1] - v1[0];
	if (!v2.empty())ans += v2[v2.size() - 1] - v2[0];
	printf("%I64d\n", ans);
}