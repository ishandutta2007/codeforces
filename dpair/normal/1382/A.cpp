#include <bits/stdc++.h>
using namespace std;
int a[1010], b[1010];
int main()
{
	int t;
	scanf("%d", &t);
	while(t --)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for (register int i = 1;i <= n;i ++)
		{
			int tmp;
			scanf("%d", &tmp);
			a[tmp] ++;
		}
		for (register int i = 1;i <= m;i ++)
		{
			int tmp;
			scanf("%d", &tmp);
			b[tmp] ++;
		}
		int find_ans = -1;
		for (register int i = 1;i <= 1000;i ++)
		{
			if(a[i] && b[i])
			{
				find_ans = i;
				break;
			}
		}
		if(find_ans == -1) printf("NO\n");
		else printf("YES\n1 %d\n", find_ans);
	}
}