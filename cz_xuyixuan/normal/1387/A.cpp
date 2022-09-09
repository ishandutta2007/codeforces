#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
vector <int> points;
bool vis[MAXN], sure;
int n, m, x, ans[MAXN], k[MAXN], b[MAXN];
vector <pair <int, int>> a[MAXN];
void work(int pos) {
	vis[pos] = true;
	points.push_back(pos);
	for (auto p : a[pos])
		if (!vis[p.first]) {
			k[p.first] = -k[pos];
			b[p.first] = p.second - b[pos];
			work(p.first);
		} else {
			int tk = k[pos] + k[p.first];
			int tb = b[pos] + b[p.first];
			if (sure) tb += tk * x, tk = 0;
			if (tk == 0) {
				if (tb != p.second) {
					puts("NO");
					exit(0);
				}
			} else {
				int tx = (p.second - tb) / tk;
				if (sure && tx != x) {
					puts("NO");
					exit(0);
				}
				sure = true;
				x = tx;
			}
		}
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		int x, y, z; read(x), read(y), read(z);
		a[x].emplace_back(y, z * 2);
		a[y].emplace_back(x, z * 2);
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			sure = false, points.clear();
			k[i] = 1, b[i] = 0, work(i);
			if (!sure) {
				vector <int> values;
				for (auto p : points)
					values.push_back(-b[p] / k[p]);
				sort(values.begin(), values.end());
				x = values[values.size() / 2];
			}
			for (auto p : points)
				ans[p] = k[p] * x + b[p];
		}
	puts("YES");
	for (int i = 1; i <= n; i++)
		printf("%.1lf ", ans[i] * 0.5);
	printf("\n");
	return 0;
}