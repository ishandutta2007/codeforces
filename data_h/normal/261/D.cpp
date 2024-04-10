#include <cstdio>
#include <cstdlib>
#include <iostream> 
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 300000;

int k, n, maxb, t;
int b[MAXN], ans[MAXN], cnt[MAXN];

int main()
{

	scanf("%d %d %d %d", &k, &n, &maxb, &t);
	
	while(k--)
	{		
		for(int i = 1; i <= n; i++)
			scanf("%d", &b[i]);
		for(int i = 1; i <= max(n, maxb) + 10; i++)
			ans[i] = maxb + 1, cnt[i] = 0;
		//printf("%d\n", len);
		int res = 0;
		for(int i = 1; i <= t && i <= maxb; i++)
			for(int j = 1; j <= n; j++)
			{
				int x = b[j];
				while(ans[cnt[x]] < x) cnt[x]++;
				if (cnt[x] > res)
					res = cnt[x];
				ans[cnt[x]] = x;
			}
		printf("%d\n", res);
		//return 0;
	}
	//printf("k = %d\n", k);
	return 0;
}