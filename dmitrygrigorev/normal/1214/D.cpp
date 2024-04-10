#include <bits/stdc++.h>
#define ll long long
#define db long double

using namespace std;
main(){
#ifdef LOCAL
	freopen("H_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	char matrix[n][m];
	bool vis[n][m];
	int sum[n][m];
	for (int i=0; i < n; i++) for (int j=0; j < m; j++) cin >> matrix[i][j];
	vis[n-1][m-1] = true;
	for (int i=n-1; i >= 0; i--){
		for (int j=m-1; j >= 0; j--){
			if (i==n-1 && j==m-1) continue;
			vis[i][j] = false;
			if (matrix[i][j] == '#') continue;
			if (i != n-1 && vis[i+1][j]) vis[i][j] = true;
			if (j != m-1 && vis[i][j+1]) vis[i][j] = true;
		}
	}
	if (!vis[0][0]){
		cout << 0;
		return 0;
	}
	for (int i=0;i<n;++i) for (int j=0; j < m; ++j) sum[i][j] = 0;
	int x = 0, y = 0;
	while (x != n-1 || y != m-1){
		if (x+1 == n || !vis[x+1][y]){
			y++;
		}
		else x++;
		sum[x][y]++;
	}
	x = 0, y = 0;
	while (x != n-1 || y != m-1){
		if (y+1 == m || !vis[x][y+1]){
			x++;
		}
		else y++;
		sum[x][y]++;
	}
	sum[n-1][m-1]--;
	for (int i=0;i<n;i++) for (int j=0;j<m;j++){
		if (sum[i][j] == 2){
			cout << 1;
			return 0;
		}
	}
	cout << 2;
}