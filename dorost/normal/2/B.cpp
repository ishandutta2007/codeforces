/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012;
int dp2[N][N];
int dp5[N][N];
int a[N][N];
bool par2[N][N];
bool par5[N][N];

int32_t main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	}
	bool f = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x = 0, y = 0;
			if (a[i][j] == 0) {
				f = true;
				x = N * 51;
				y = N * 51;
			} else {
				while (a[i][j] % 2 == 0)
					a[i][j] /= 2, x++;
				while (a[i][j] % 5 == 0)
					a[i][j] /= 5, y++;
			}
			dp2[i][j] = N * 51;
			if (i == 0 && j == 0) {
				dp5[i][j] = y;
				dp2[i][j] = x;
				continue;
			}
			dp2[i][j] = N * 51;
			if (i != 0) {
				dp2[i][j] = dp2[i - 1][j] + x;
				par2[i][j] = true;
			}
			if (j != 0 && dp2[i][j] > dp2[i][j - 1] + x) {
				dp2[i][j] = dp2[i][j - 1] + x;
				par2[i][j] = false;
			}
			dp5[i][j] = N * 51;
			if (i != 0) {
				dp5[i][j] = dp5[i - 1][j] + y;
				par5[i][j] = true;
			}
			if (j != 0 && dp5[i][j] > dp5[i][j - 1] + y) {
				dp5[i][j] = dp5[i][j - 1] + y;
				par5[i][j] = false;
			}
		}
	}
	if (f) {
		cout << min(min(dp2[n - 1][n - 1], dp5[n - 1][n - 1]), 1) << '\n';
		if (min(dp2[n - 1][n - 1], dp5[n - 1][n - 1]) == 0) {
			if (dp2[n - 1][n - 1] < dp5[n - 1][n - 1]) {
				int x = n - 1, y = n - 1;
				string s;
				for (int i = 0; i < 2 * n - 2; i++) {
					bool c = par2[x][y];
					if (c)
						s += 'D', x--;
					else
						s += 'R', y--;
				}
				reverse(s.begin(), s.end());
				for (char c : s)
					printf("%c", c);
			} else {
				int x = n - 1, y = n - 1;
				string s;
				for (int i = 0; i < 2 * n - 2; i++) {
					bool c = par5[x][y];
					if (c)
						s += 'D', x--;
					else
						s += 'R', y--;
				}
				reverse(s.begin(), s.end());
				for (char c : s)
					printf("%c", c);
			}
		} else {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (a[i][j] == 0) {
						for (int k = 0; k < i; k++) {
							cout << 'R';
						}
						for (int k = 0; k < j; k++) {
							cout << 'D';
						}
						for (int k = i + 1; k < n; k++)
							cout << 'R';
						for (int k = j + 1; k < n; k++)
							cout << 'R';
						return 0;
					}
				}
			}
		}
		return 0;
	}
	printf("%d\n", min(dp2[n - 1][n - 1], dp5[n - 1][n - 1]));
	if (dp2[n - 1][n - 1] < dp5[n - 1][n - 1]) {
		int x = n - 1, y = n - 1;
		string s;
		for (int i = 0; i < 2 * n - 2; i++) {
			bool c = par2[x][y];
			if (c)
				s += 'D', x--;
			else
				s += 'R', y--;
		}
		reverse(s.begin(), s.end());
		for (char c : s)
			printf("%c", c);
	} else {
		int x = n - 1, y = n - 1;
		string s;
		for (int i = 0; i < 2 * n - 2; i++) {
			bool c = par5[x][y];
			if (c)
				s += 'D', x--;
			else
				s += 'R', y--;
		}
		reverse(s.begin(), s.end());
		for (char c : s)
			printf("%c", c);
	}
}