#include<bits/stdc++.h>
const int MaxN = 1010, MaxM = 60010;
int n, m, s, t, first = true;
int total, dfn_index, omitted, now_eid;
int head[MaxN], point[MaxM], next[MaxM], weight[MaxM], eid[MaxM];
int dfn[MaxN], low[MaxN], reachable[MaxM];

void add_edge(int u, int v, int w, int id)
{
	point[++total] = v;
	weight[total] = w;
	eid[total] = id;
	next[total] = head[u];
	head[u] = total;
}

bool tarjan(int u, int from_eid)
{
	using std::min; 

	dfn[u] = low[u] = ++dfn_index;

	bool flag = u == t;

	for(int k = head[u]; k; k = next[k])
	{
		int v = point[k];
		if(eid[k] == from_eid || eid[k] == omitted) continue;
		if(dfn[v])
		{
			low[u] = min(low[u], dfn[v]);
		} else {
			if(tarjan(v, eid[k]))
			{
				flag = true;
				if(low[v] > dfn[u] && weight[k] < weight[now_eid])
					now_eid = k;
			}

			low[u] = min(low[u], low[v]);
		}
	}

	if(first && flag) reachable[from_eid] = 1;

	return flag;
}

int main()
{
	std::scanf("%d %d %d %d", &n, &m, &s, &t);
	for(int i = 1; i <= m; ++i)
	{
		int u, v, w;
		std::scanf("%d %d %d", &u, &v, &w);
		add_edge(u, v, w, i);
		add_edge(v, u, w, i);
	}

	weight[0] = ~0u >> 1;

	int ans_cnt = 0, ans_val = ~0u >> 1;
	int ans_eid[2] = {0, 0};
	if(!tarjan(s, 0))
	{
		std::printf("0\n0\n");
		return 0;
	}

	first = false;
	for(int i = 1; i <= m; ++i)
	{
		if(!reachable[i]) continue;
		std::memset(dfn, 0, sizeof(dfn));
		omitted = i;
		now_eid = dfn_index = 0;

		int w = weight[i * 2];

		if(tarjan(s, 0))
		{
			if(now_eid != 0 && ans_val > w + weight[now_eid]) 
			{
				ans_val = w + weight[now_eid];
				ans_cnt = 2;
				ans_eid[0] = i;
				ans_eid[1] = eid[now_eid];
			}
		} else {
			if(ans_val > w)
			{
				ans_val = w;
				ans_cnt = 1;
				ans_eid[0] = i;
			}
		}
	}

	if(ans_cnt == 0)
	{
		std::puts("-1");
	} else {
		std::printf("%d\n%d\n", ans_val, ans_cnt);
		for(int i = 0; i != ans_cnt; ++i)
			std::printf("%d ", ans_eid[i]);
	}
	return 0;
}