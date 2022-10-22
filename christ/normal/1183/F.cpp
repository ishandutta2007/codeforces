#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 200005;
 
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int q;
	scanf("%i", &q);
	while (q--)
	{
		int n;
		scanf("%i", &n);
        vector<int> a(n);
		for (int x = 0; x < n; x++)
			scanf("%i", &a[x]);
		sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        n = a.size();
		int ans = 0;
		for (int x = 0; x < n; x++)
		{
			int y = x - 1, z = n - 1;
			while (y >= 0 && a[x] % a[y] == 0)
				y--;
			y = y < 0 ? 0 : a[y];
			while (z > x && (a[z] % a[x] == 0 || (y != 0 && a[z] % y == 0)))
				z--;
			z = z <= x ? 0 : a[z];
			ans = max(ans, a[x] + y + z);
			y = x - 1, z = n - 1;
			while (z > x && a[z] % a[x] == 0)
				z--;
			z = z <= x ? 0 : a[z];
			while (y >= 0 && (a[x] % a[y] == 0 || (z != 0 && z % a[y] == 0)))
				y--;
			y = y < 0 ? 0 : a[y];
			ans = max(ans, a[x] + y + z);
		}
		cout << ans << '\n';
	}
}