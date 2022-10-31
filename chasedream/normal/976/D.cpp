#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
int a[maxn], f[maxn], x[maxn], y[maxn];
int n, l, r, cnt;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		f[a[i]] = true;
	}
	while (a[n] > r)
	{
		do {
			for (int i = l + 2; i <= a[n] + 1; i++) x[cnt] = l + 1, y[cnt++] = i;
			l++, r++;
		}while (!f[r]);
		n--;
	}
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++) printf("%d %d\n", x[i], y[i]);
	return 0;
}