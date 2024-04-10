#include <iostream>
using namespace std;
typedef long long ll;
const int N = 3e5 + 10, M = 30, SZ = M * N;
int t[SZ][2], f[SZ][2], tot;
int newnode()
{
	++tot;
	t[tot][0] = t[tot][1] = 0;
	f[tot][0] = f[tot][1] = 0;
	return tot;
}
 
int a[N];
void solve()
{
	tot = 0, newnode();
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) {
		int mx = 0;
		for (int k = M, u = 1; k >= 0 && u; k--) {
			int x = (a[i] ^ i) >> k & 1;
			int y = a[i] >> k & 1;
			//  a[j] ^ j a[j]   k   i  k 
			mx = max(mx, f[t[u][x ^ 1]][y ^ 1]);
			u = t[u][x];
		}
		ans = max(ans, mx + 1);
		for (int k = M, u = 1; k >= 0; k--) {
			int x = (a[i] ^ i) >> k & 1;
			int y = i >> k & 1;
			if (!t[u][x]) t[u][x] = newnode();
			u = t[u][x], f[u][y] = max(f[u][y], mx + 1);
		}
	}
	printf("%d\n", ans);
}
 
int main()
{
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}