#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
bool lucky(int x) {
	int sa = 0, sb = 0;
	for (int i = 1; i <= 3; i++) {
		sa += x % 10;
		x /= 10;
	}
	for (int i = 1; i <= 3; i++) {
		sb += x % 10;
		x /= 10;
	}
	return sa == sb;
}
int dist(int x, int y) {
	int ans = 0;
	while (x || y) {
		ans += x % 10 != y % 10;
		x /= 10; y /= 10;
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	int ans = 6, value;
	cin >> value;
	for (int i = 0; i <= 999999; i++) {
		if (!lucky(i)) continue;
		ans = min(ans, dist(i, value));
	}
	cout << ans << endl;
	return 0;
}