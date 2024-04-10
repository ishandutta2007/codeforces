#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;

const int maxn = 100005;
int x[maxn], y[maxn], tx[maxn], ty[maxn];
int n, dx, dy, A, C, has, mx, my;
long long ans;

int main() {
	cin >> n;
	rep (i, 1, n) {
		cin >> x[i] >> y[i];
		tx[i] = x[i]; ty[i] = y[i];
	}
	int mid = (n + 1) / 2;
	sort(x + 1, x + n + 1);
	sort(y + 1, y + n + 1);
	dx = x[mid + 1] - x[mid];
	dy = y[mid + 1] - y[mid];
	mx = x[mid + 1] + x[mid];
	my = y[mid + 1] + y[mid];
	if (n & 1) {
		dx = min(dx, x[mid] - x[mid - 1]);
		dy = min(dy, y[mid] - y[mid - 1]);
		mx = x[mid] + x[mid];
		my = y[mid] + y[mid];
	}
	rep (i, 1, n) {
		int cost = abs(tx[i] - x[mid]) + abs(ty[i] - y[mid]);
		ans += cost;
		if (!cost) has = 1;
		if (2 * tx[i] < mx) {
			A |= (2 * ty[i]) > my;
			C |= (2 * ty[i]) < my;
		}
	}
	if (((~n & 1) || has) && A && C)
		ans -= min(dx, dy);
	cout << ans * 2;
	return 0;
}