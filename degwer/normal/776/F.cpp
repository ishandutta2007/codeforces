#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>pat[200000];
bool flag[200000];
int ans[200000];
int dfs(int node)
{
	flag[node] = true;
	int d[20];
	fill(d, d + 20, 0);
	for (int i = 0; i < pat[node].size(); i++)
	{
		if (!flag[pat[node][i]])
		{
			int t = dfs(pat[node][i]);
			for (int j = 0; j < 20; j++)if ((t&(1 << j)) != 0)d[j]++;
		}
	}
	int lb = 0;
	for (int i = 0; i < 20; i++)if (d[i] >= 2)lb = i + 1;
	int r = 0;
	for (int i = lb; i < 20; i++)
	{
		if (d[i] == 0)
		{
			r = i;
			break;
		}
	}
	int ret = (1 << r);
	ans[node] = r;
	for (int i = r + 1; i < 20; i++)if (d[i]>0)ret += 1 << i;
	return ret;
}
typedef pair<int, int>pii;
#include<set>
#include<map>
map<pii, int>ma;
int main()
{
	int num, way;
	scanf("%d%d", &num, &way);
	vector<pii>vec;
	for (int i = 0; i < way; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--, zb--;
		vec.push_back(make_pair(max(za, zb) - min(za, zb), min(za, zb)));
	}
	vec.push_back(make_pair(num - 1, 0));
	sort(vec.begin(), vec.end());
	set<int>se;
	for (int i = 0; i < num; i++)se.insert(i);
	vector<pair<vector<int>,int> >dat;
	for (int i = 0; i < vec.size(); i++)
	{
		int s = vec[i].second, t = vec[i].second + vec[i].first;
		vector<int>v;
		set<int>::iterator it = se.find(s);
		it++;
		v.push_back(s);
		for (;;)
		{
			if (*it == t)break;
			v.push_back(*it);
			se.erase(it++);
		}
		v.push_back(t);
		for (int j = 0; j < int(v.size()) - 1; j++)
		{
			if (v[j + 1] - v[j]>1)
			{
				int low = lower_bound(vec.begin(), vec.end(), make_pair(v[j + 1] - v[j], v[j])) - vec.begin();
				//printf("::%d %d\n", i, low);
				pat[i].push_back(low);
				pat[low].push_back(i);
			}
		}
		reverse(v.begin(), v.end());
		for (;;)
		{
			if (v.size() <= 3)break;
			v.pop_back();
		}
		dat.push_back(make_pair(v, i));
	}
	sort(dat.begin(), dat.end());
	fill(flag, flag + vec.size(), false);
	dfs(0);
	for (int i = 0; i < vec.size(); i++)printf("%d ", 19 - ans[dat[i].second] + 1);
	printf("\n");
}