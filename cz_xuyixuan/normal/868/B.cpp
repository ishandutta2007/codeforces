#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
int h, m, s, x, y, a[MAXN];
int func(int x) {
	if (x > a[1] && x < a[2]) return 1;
	if (x > a[2] && x < a[3]) return 2;
	return 3;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> h >> m >> s;
	if (m == 0 && s == 0) a[1] = h * 2;
	else if (h == 12) a[1] = 1;
		else a[1] = h * 2 + 1;
	if (s == 0 && m % 5 == 0) {
		if (m / 5 == 0) a[2] = 24;
		else a[2] = m / 5 * 2;
	} else {
		if (m / 5 == 0) a[2] = 1;
		else a[2] = m / 5 * 2 + 1;
	}
	if (s % 5 == 0) {
		if (s / 5 == 0) a[3] = 24;
		else a[3] = s / 5 * 2;	
	} else {
		if (s / 5 == 0) a[3] = 1;
		else a[3] = s / 5 * 2 + 1;
	}
	sort(a + 1, a + 4);
	cin >> x >> y;
	if (func(x * 2) == func(y * 2)) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}