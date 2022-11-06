#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#define my_abs(x) ((x) < 0 ? -(x) : (x))
#define mp std::make_pair
#define pb push_back
#define X first
#define Y second
typedef long long ll; 
int fa[400005][25], nxt[400005][25], cnt[400005][25]; 
ll mx[400005][25], sum[400005][25]; 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("932D.in", "r", stdin); 
#endif
	int t, lst = 0, n = 1; 
	scanf("%d", &t);
	memset(fa, -1, sizeof(fa)); 
	memset(nxt, -1, sizeof(nxt)); 
	for (int i = 0; i < 20; i++)
		cnt[0][i] = 1; 
	while (t--)
	{
		int tp; 
		ll p, q; 
		scanf("%d%lld%lld", &tp, &p, &q); 
		p ^= lst; 
		q ^= lst; 
		if (tp == 1)
		{
			p--; 
			fa[n][0] = p; 
			for (int i = 19; i >= 0; i--)
			{
				if (~p && mx[p][i] < q)
					p = fa[p][i]; 
			}
			nxt[n][0] = p; 
			mx[n][0] = q; 
			sum[n][0] = q; 
			cnt[n][0] = 1; 
			for (int i = 1; i < 20; i++)
			{
				fa[n][i] = fa[n][i - 1] == -1 ? -1 : fa[fa[n][i - 1]][i - 1]; 
				mx[n][i] = fa[n][i - 1] == -1 ? mx[n][i - 1] : std::max(mx[n][i - 1], mx[fa[n][i - 1]][i - 1]); 
				nxt[n][i] = nxt[n][i - 1] == -1 ? -1 : nxt[nxt[n][i - 1]][i - 1]; 
				sum[n][i] = nxt[n][i - 1] == -1 ? sum[n][i - 1] : sum[n][i - 1] + sum[nxt[n][i - 1]][i - 1]; 
				cnt[n][i] = nxt[n][i - 1] == -1 ? cnt[n][i - 1] : cnt[n][i - 1] + cnt[nxt[n][i - 1]][i - 1]; 
			}
			n++; 
		}
		else
		{
			p--; 
			int ans = 0; 
			for (int i = 19; i >= 0; i--)
			{
				if (~p && cnt[p][i] >= (1 << i) && sum[p][i] <= q)
				{
					q -= sum[p][i]; 
					p = nxt[p][i]; 
					ans += 1 << i; 
				}
			}
			printf("%d\n", lst = ans);
		}
	}
	return 0; 
}