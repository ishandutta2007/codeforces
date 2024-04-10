#include <algorithm>
#include <iostream>
#include <cstdio>
#define mp make_pair
#define fi first
#define se second
#define INF 1000000000
using namespace std;
int a[1000005], dp[1000005][10][5];
int read(){
	int cnt = 0;
	char ch = getchar();
	while (ch < '0' || '9' < ch)
		ch = getchar();
	while ('0' <= ch && ch <= '9'){
		cnt = cnt * 10 + ch - '0';
		ch = getchar();
	}
	return cnt;
}
int main(){
	int n = read(), m = read();
	for (int i = 1; i <= n; ++ i)
		a[read()] ++;
	for (int i = 1; i <= n - 2; ++ i)
		for (int x = 0; x <= 6; ++ x)
			for (int y = 0; y <= 3; ++ y)
				dp[i][x][y] = -INF;
	for (int x = 0; x <= 3; ++ x)
		if (a[1] >= x && a[2] >= x && a[3] >= x)
			dp[1][x][x] = x + (a[1] - x) / 3;
	for (int i = 1; i <= m - 2; ++ i)
		for (int x = 0; x <= 6; ++ x)
			for (int y = 0; y <= 3; ++ y)
				for (int z = 0; z <= 3; ++ z)
					if (a[i + 1] >= x + z && a[i + 2] >= y + z && a[i + 3] >= z)
						dp[i + 1][y + z][z] = max(dp[i + 1][y + z][z], dp[i][x][y] + z + (a[i + 1] - z - x) / 3);
	int ans = 0;
	for (int x = 0; x <= 6; ++ x)
		for (int y = 0; y <= 3; ++ y)
			if (a[m - 1] >= x && a[m - 2] >= y)
				ans = max(ans, dp[m - 2][x][y] + (a[m - 1] - x) / 3 + (a[m] - y) / 3);
	cout << ans << endl;
}