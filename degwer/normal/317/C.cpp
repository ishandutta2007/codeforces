#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>pat[300];
typedef pair<int, int>pii;
typedef pair<pii, int>pi3;
int now[300], mok[300];
bool flag[300];
vector<int>st, flow;
bool found;
void dfs(int node)
{
	if (found)return;
	if (flag[node])return;
	st.push_back(node);
	flag[node] = true;
	if (now[node] < mok[node])
	{
		found = true;
		flow = st;
		return;
	}
	for (int i = 0; i < pat[node].size(); i++)dfs(pat[node][i]);
	st.pop_back();
}
int main()
{
	int num, gen, way;
	scanf("%d%d%d", &num, &gen, &way);
	for (int i = 0; i < num; i++)scanf("%d", &now[i]);
	for (int i = 0; i < num; i++)scanf("%d", &mok[i]);
	for (int i = 0; i < way; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--, zb--;
		pat[za].push_back(zb);
		pat[zb].push_back(za);
	}
	vector<pi3>ans;
	for (;;)
	{
		bool ffff = false;
		for (int p = 0; p < num; p++)
		{
			if (now[p] > mok[p])
			{
				ffff = true;
				fill(flag, flag + num, false);
				st.clear();
				flow.clear();
				found = false;
				dfs(p);
				if (!found)
				{
					printf("NO\n");
					return 0;
				}
				//for (int i = 0; i < flow.size(); i++)printf(" %d", flow[i]+1); printf("\n");
				for (int i = 0; i < int(flow.size()) - 2; i++)
				{
					if (now[flow[i]]>now[flow[i + 1]])ans.push_back(make_pair(make_pair(flow[i], flow[i + 1]), now[flow[i]] - now[flow[i + 1]]));
					else ans.push_back(make_pair(make_pair(flow[i + 1], flow[i]), now[flow[i + 1]] - now[flow[i]]));
					swap(now[flow[i]], now[flow[i + 1]]);
				}
				int f = min(now[flow[flow.size() - 2]] - mok[p], mok[flow[flow.size() - 1]] - now[flow[flow.size() - 1]]);
				ans.push_back(make_pair(make_pair(flow[flow.size() - 2], flow[flow.size() - 1]), f));
				now[flow[flow.size() - 2]] -= f, now[flow[flow.size() - 1]] += f;
				for (int i = int(flow.size()) - 3; i >= 0; i--)
				{
					if (now[flow[i]]>now[flow[i + 1]])ans.push_back(make_pair(make_pair(flow[i], flow[i + 1]), now[flow[i]] - now[flow[i + 1]]));
					else ans.push_back(make_pair(make_pair(flow[i + 1], flow[i]), now[flow[i + 1]] - now[flow[i]]));
					swap(now[flow[i]], now[flow[i + 1]]);
				}
				//for (int i = 0; i < num; i++)printf("%d ", now[i]); printf("\n");
			}
		}
		if (!ffff)break;
	}
	for (int i = 0; i < num; i++)
	{
		if (mok[i] != now[i])
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)printf("%d %d %d\n", ans[i].first.first + 1, ans[i].first.second + 1, ans[i].second);
}