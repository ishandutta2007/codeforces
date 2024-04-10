#include <bits/stdc++.h>
using namespace std;


int n;
int mx = -1, my = -1;

int main() {
	scanf("%d", &n);
	while (n--) {
		char s[6];
		scanf("%s", s);
		int x, y; scanf("%d %d", &x, &y);
		if (x > y) swap(x, y);
		if (s[0] == '+') {
			if (mx == -1) mx = x, my = y;
			else {
				mx = max(mx, x);
				my = max(my, y);
			}
		}
		else {
			if (mx > x || my > y) puts("NO");
			else puts("YES");
		}
	}
	return 0;
}