#include <bits/stdc++.h>

const int MaxN = 1e5 + 5; 

int n, m, cnt, pri[MaxN]; 
int tmp[MaxN], tmp_cnt; 
int ans[MaxN][2]; 
bool vis[MaxN]; 

inline void init(const int &n)
{
	static bool bo[MaxN]; 
	
	for (int i = 2; i <= n; ++i)
	{
		if (!bo[i])
			pri[++cnt] = i; 
		for (int j = 1; j <= cnt && i * pri[j] <= n; ++j)
		{
			bo[i * pri[j]] = true; 
			if (i % pri[j] == 0)
				break; 
		}
	}
}

int main()
{
	scanf("%d", &n); 
	init(n); 
	
	for (int i = cnt; i >= 1; --i)
	{
		tmp_cnt = 0; 
		for (int j = pri[i]; j <= n; j += pri[i])
			if (!vis[j])
				tmp[++tmp_cnt] = j; 
		if (tmp_cnt & 1)
			std::swap(tmp[2], tmp[tmp_cnt--]); 
		for (int j = 1; j <= tmp_cnt; j += 2)
		{
			++m; 
			vis[ans[m][0] = tmp[j]] = true; 
			vis[ans[m][1] = tmp[j + 1]] = true; 
		}
	}
	
	printf("%d\n", m); 
	for (int i = 1; i <= m; ++i)
		printf("%d %d\n", ans[i][0], ans[i][1]);
	return 0; 
}