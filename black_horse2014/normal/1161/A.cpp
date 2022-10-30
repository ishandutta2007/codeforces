#include <bits/stdc++.h>
using namespace std;

const int N = 110000;

int vis[N];
int used[N][3];

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
        int x; cin >> x;
		used[x][0] = 1;
		if (vis[x+1] == 1) used[x][1] = 1;
		if (vis[x-1] == 1) used[x][2] = 1;
		vis[x] = 1;
	}
	int ans = 3 * n - 2;
    for (int i = 1; i <= n; i++) ans -= used[i][0] + used[i][1] + used[i][2];
	cout << ans << endl;
	return 0;
}