#include<bits/stdc++.h>
using namespace std;
#define MAXN	505
#define INF	2e9
int n, R, C, x[MAXN], y[MAXN];
struct info {int l, r; };
bool cmp(info x, info y) {
	return x.l < y.l;
}
bool checkx(int pos, int value) {
	static info tmp[MAXN];
	for (int i = 1; i <= n; i++)
		if (x[i] - value <= pos && x[i] + value >= pos) tmp[i].l = y[i] - value, tmp[i].r = y[i] + value;
		else tmp[i].l = INF, tmp[i].r = INF;
	sort(tmp + 1, tmp + n + 1, cmp);
	int last = 0;
	for (int i = 1; i <= n; i++) {
		if (tmp[i].l == INF) break;
		if (tmp[i].l > last + 1) return true;
		last = tmp[i].r;
	}
	return last < C;
}
bool checky(int pos, int value) {
	static info tmp[MAXN];
	for (int i = 1; i <= n; i++)
		if (y[i] - value <= pos && y[i] + value >= pos) tmp[i].l = x[i] - value, tmp[i].r = x[i] + value;
		else tmp[i].l = INF, tmp[i].r = INF;
	sort(tmp + 1, tmp + n + 1, cmp);
	int last = 0;
	for (int i = 1; i <= n; i++) {
		if (tmp[i].l == INF) break;
		if (tmp[i].l > last + 1) return true;
		last = tmp[i].r;
	}
	return last < R;
}
bool check(int value) {
	int lft = INF, rit = 0, down = INF, up = 0;
	if (checkx(1, value)) lft = 1;
	for (int i = 1; i <= n; i++)
		if (checkx(x[i] + value + 1, value)) lft = min(lft, x[i] + value + 1);
	if (checkx(R, value)) rit = R;
	for (int i = 1; i <= n; i++)
		if (checkx(x[i] - value - 1, value)) rit = max(rit, x[i] - value - 1);
	if (checky(1, value)) down = 1;
	for (int i = 1; i <= n; i++)
		if (checky(y[i] + value + 1, value)) down = min(down, y[i] + value + 1);
	if (checky(C, value)) up = C;
	for (int i = 1; i <= n; i++)
		if (checky(y[i] - value - 1, value)) up = max(up, y[i] - value - 1);
	return (rit - lft <= 2 * value) && (up - down <= 2 * value);
}
int main() {
	ios::sync_with_stdio(false);
	cin >> R >> C >> n;
	for (int i = 1; i <= n; i++)
		cin >> x[i] >> y[i];
	int l = 0, r = max(R, C);
	while (l < r) {
		int mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << endl;
	return 0;
}