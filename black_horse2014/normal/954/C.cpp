#include <bits/stdc++.h>
using namespace std;

int a[220000];
int ax[220000];
int ay[220000];

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int maxy = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i] == a[i-1]) return puts("NO"), 0;
		maxy = max(maxy, abs(a[i] - a[i-1]));
	}
	int x = 1000000000, y = maxy;
	for (int i = 1; i <= n; i++) ay[i] = (a[i]-1) % y + 1, ax[i] = (a[i]-1) / y + 1;
	for (int i = 2; i <= n; i++) if (abs(ax[i] - ax[i-1]) + abs(ay[i] - ay[i-1]) != 1) return puts("NO"), 0;
	puts("YES");
	cout << x << ' ' << y << endl;
	return 0;
}