#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300005;

vector<int> premx(MAXN), sufmx(MAXN), premn(MAXN, INT_MAX / 2), sufmn(MAXN, INT_MAX / 2), lft(MAXN), rht(MAXN);

int main()
{
	int n;
	scanf("%i", &n);
	for (int x = 0; x < n; x++)
	{
		scanf("%i%i", &lft[x], &rht[x]);
		premx[x + 1] = max(premx[x], lft[x]);
		premn[x + 1] = min(premn[x], rht[x]);
	}
	for (int x = n - 2; x >= 0; x--)
	{
		sufmx[x] = max(sufmx[x + 1], lft[x + 1]);
		sufmn[x] = min(sufmn[x + 1], rht[x + 1]);
	}
	int ans = 0;
	for (int x = 0; x < n; x++)
		ans = max(ans, min(premn[x], sufmn[x]) - max(premx[x], sufmx[x]));
	printf("%i\n", ans);
}