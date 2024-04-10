#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#include<set>
using namespace std;
typedef long long ll;
ll t1 = 114514334, t2 = 810893364;
ll m1 = 1000000007, m2 = 1000000009;
typedef pair<ll, ll>pii;
pii gethash(vector<int>v)
{
	sort(v.begin(), v.end());
	pii z = make_pair(123123, 23454);
	for (int i = 0; i < v.size(); i++)
	{
		z.first *= t1;
		z.second *= t2;
		z.first += v[i];
		z.second += v[i];
		z.first %= m1;
		z.second %= m2;
	}
	return z;
}
vector<int>pat[300000];
typedef pair<pii, ll>pi3;
int dat[300000];
set<int>se[300000];
int ans[300000];
int c1[300000], c2[300000];
int ko[300000];
int main()
{
	int num, way;
	scanf("%d%d", &num, &way);
	for (int i = 0; i < way; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--, zb--;
		pat[za].push_back(zb);
		pat[zb].push_back(za);
	}
	for (int i = 0; i < num; i++)pat[i].push_back(i);
	vector<pi3>v;
	for (int i = 0; i < num; i++)v.push_back(make_pair(gethash(pat[i]), i));
	sort(v.begin(), v.end());
	pii now = make_pair(-1, -1);
	int pt = 0;
	for (int i = 0; i < num; i++)
	{
		if (now != v[i].first)
		{
			now = v[i].first;
			pt++;
		}
		dat[v[i].second] = pt - 1;
	}
	for (int i = 0; i < num; i++)
	{
		//printf("%d %d\n", i + 1, dat[i]);
		for (int j = 0; j < pat[i].size(); j++)
		{
			int v = pat[i][j];
			if (dat[i] != dat[v])se[dat[i]].insert(dat[v]);
		}
	}
	int rr = -1;
	for (int i = 0; i < pt; i++)
	{
		if (se[i].size() >= 3)
		{
			printf("NO\n");
			return 0;
		}
		if (se[i].size() <= 1)rr = i;
	}
	if (rr == -1)
	{
		printf("NO\n");
		return 0;
	}
	int tt = 0;
	for (;;)
	{
		ans[rr] = tt++;
		if (se[rr].size() == 0)break;
		set<int>::iterator it = se[rr].begin();
		se[*it].erase(rr);
		rr = *it;
	}
	for (int i = 0; i < num; i++)
	{
		ko[ans[dat[i]]]++;
		for (int j = 0; j < pat[i].size(); j++)
		{
			if (ans[dat[i]] == ans[dat[pat[i][j]]])c1[ans[dat[i]]]++;
			else c2[min(ans[dat[i]], ans[dat[pat[i][j]]])]++;
		}
	}
	for (int i = 0; i < pt; i++)
	{
		if ((ll)ko[i] * (ll)ko[i] != c1[i])
		{
			printf("NO\n");
			return 0;
		}
	}
	for (int i = 0; i < pt - 1; i++)
	{
		if ((ll)ko[i] * (ll)ko[i + 1] * 2 != c2[i])
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for (int i = 0; i < num; i++)printf("%d ", ans[dat[i]] + 1);
	printf("\n");
}