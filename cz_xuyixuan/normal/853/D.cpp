#include<bits/stdc++.h>
using namespace std;
#define MAXN	300005
#define MAXC	45
#define INF	1e9
int a[MAXN][MAXC], n, value[MAXN];
void update(int &x, int y) {
	x = min(x, y);
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> value[i];
		value[i] /= 100;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < MAXC; j++)
			a[i][j] = INF;
	a[1][value[1] / 10] = value[1];
	for (int i = 1; i < n; i++) {
		int tmp = value[i + 1];
		for (int j = 0; j < MAXC; j++) {
			int used = min(j, tmp);
			update(a[i + 1][j - used], a[i][j] + tmp - used);
			update(a[i + 1][j + tmp / 10], a[i][j] + tmp);
		}
	}
	int ans = INF;
	for (int i = 0; i < MAXC; i++)
		ans = min(ans, a[n][i]);
	cout << ans << "00" << endl;
	return 0;
}