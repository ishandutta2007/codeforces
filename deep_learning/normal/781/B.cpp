#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std; 
int son[4096][26], tot, num[4096], fa[4096]; 
char str[32], ans[1024][4]; 
bool vis[4096]; 
void work(int p, string str)
{
	vis[p] = true; 
	if (num[p] == -2)
	{
		for (int i = 0; i < 26; i++)
		{
			if (-1 != son[p][i])
			{
				if (-2 == num[son[p][i]])
				{
					printf("NO\n");
					exit(0); 
				}
				for (int j = 0; j < 26; j++)
				{
					if (-1 != son[fa[p]][j] && -1 != son[son[fa[p]][j]][i] && num[son[son[fa[p]][j]][i]] == -3)
					{
						printf("NO\n");
						exit(0); 
					}
				}
				ans[num[son[p][i]]][0] = str[0]; 
				ans[num[son[p][i]]][1] = str[1]; 
				ans[num[son[p][i]]][2] = i + 'A'; 
				if (son[fa[p]][i] != -1 && num[son[fa[p]][i]] != -1)
					num[son[fa[p]][i]] = -2; 
				num[son[p][i]] = -3; 
			}
		}
		return; 
	}
	if (num[p] != -1)
	{
		ans[num[p]][0] = str[0]; 
		ans[num[p]][1] = str[1]; 
		ans[num[p]][2] = str[2]; 
		return; 
	}
	bool f = true; 
	while (f)
	{
		f = false; 
		for (int i = 0; i < 26; i++)
		{
			if (-1 != son[p][i] && -2 == num[son[p][i]] && !vis[son[p][i]])
			{
				f = true; 
				work(son[p][i], str + (char)(i + 'A')); 
			}
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (-1 != son[p][i] && !vis[son[p][i]])
			work(son[p][i], str + (char)(i + 'A')); 
	}
}
int main()
{
	// freopen("B.in", "r", stdin); 
	memset(son, -1, sizeof(son)); 
	memset(num, -1, sizeof(num)); 
	int n; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str); 
		int p = 0; 
		for (int j = 0; j < 3; j++)
		{
			if (-1 == son[p][str[j] - 'A'])
			{
				son[p][str[j] - 'A'] = ++tot; 
				fa[tot] = p; 
			}
			p = son[p][str[j] - 'A']; 
		}
		num[p] = num[p] == -1 ? i : -2; 
		scanf("%s", str); 
		if (-1 == son[p][str[0] - 'A'])
		{
			son[p][str[0] - 'A'] = ++tot; 
			fa[tot] = p; 
		}
		p = son[p][str[0] - 'A']; 
		num[p] = num[p] == -1 ? i : -2; 
	}
	work(0, string()); 
	printf("YES\n");
	for (int i = 0; i < n; i++)
		printf("%s\n", ans[i]);
	return 0; 
}