#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

const int MAXN = 1005;

int n, m;
int col[MAXN], row[MAXN];

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		row[x]++;
		col[y]++;
	}
	int ans = 0;
	for(int i = 2; i <= (n + 1) / 2; i++) {
		if (n % 2 == 1 && i == (n + 1) / 2) {
			if (row[i] == 0 || col[i] == 0)
				ans++;
			continue;
		}
		int tmp = 0;
		if (row[i] == 0) tmp++;
		if (col[i] == 0) tmp++;
		if (row[n - i + 1] == 0) tmp++;
		if (col[n - i + 1] == 0) tmp++;
		ans += tmp;
	}
	cout << ans << endl;
	return 0;
}