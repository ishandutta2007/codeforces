#include <bits/stdc++.h>
using namespace std;
#define LL long long
struct node
{
	LL h, d, p;
}s[200005];
LL sum, t, ans;
int n, a, b;
bool cmp(node a, node b) { return a.p > b.p; }
int main()
{
	scanf("%d%d%d", &n, &a, &b);
	b = min(n, b);
	for (int i = 1; i <= n; i++)
	{
		scanf("%I64d%I64d", &s[i].h, &s[i].d);
		s[i].p = max(s[i].h - s[i].d, 0LL);
		sum += s[i].d;
	}
	if (b == 0)
	{
		printf("%I64d\n", sum);
		return 0;
	}
	sort(s + 1, s + n + 1, cmp);
	for (int i = 1; i <= b; i++) t += s[i].p;
	for (int i = 1; i <= b; i++) ans = max(ans, t - s[i].p + (s[i].h << a) - s[i].d);
	for (int i = b + 1; i <= n; i++) ans = max(ans, t - s[b].p + (s[i].h << a) - s[i].d);
	printf("%I64d\n", ans + sum);
	return 0;
}