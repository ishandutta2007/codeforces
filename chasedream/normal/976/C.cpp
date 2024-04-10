#include <bits/stdc++.h>
using namespace std;
struct node
{
	int l, r, num;
}s[300005];
int n, ans, Max;
bool cmp(node a, node b)
{
	if (a.l < b.l) return true;
	else if (a.l > b.l) return false;
	return a.r > b.r;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		s[i].num = i;
		scanf("%d%d", &s[i].l, &s[i].r);
	}
	sort(s + 1, s + n + 1, cmp);
	for (int i = 1; i <= n; i++)
		if (ans >= s[i].r)
		{
			printf("%d %d\n", s[i].num, Max);
			return 0;
		}
		else ans = s[i].r, Max = s[i].num;
	printf("-1 -1\n");
	return 0;
}