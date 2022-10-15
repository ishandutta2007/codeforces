#include <iostream> 
#include <vector> 
#include <queue> 
#include <cstdio> 
#include <cassert> 

bool home = true;
using namespace std;

const int N = (int)1e5 + 7;
const int INF = (int)1e9 + 7;
int l, n, pivots[N], i_have[N], i_transfer[N], have[N], transfer[N];
int mn[N], mx[N]; // mn and mx is before transfer

bool is_ok(int low, int high) {
	for (int i = 1; i <= n; i++) have[i] = i_have[i];
	for (int i = 1; i < n; i++) transfer[i] = i_transfer[i];
	mn[0] = mx[0] = low;
	transfer[0] = low;
	for (int i = 1; i <= n; i++) {
		mn[i] = +INF;
		mx[i] = -INF;

		if (max(low, mn[i - 1]) <= min(high, mx[i - 1])) {
			mn[i] = min(mn[i], have[i]);
			mx[i] = max(mx[i], have[i] + min(transfer[i - 1], min(high, mx[i - 1]) - low));
		}

		if (max(high + 1, mn[i - 1]) <= min(high + transfer[i - 1], mx[i - 1])) {
			mn[i] = min(mn[i], have[i] + max(high + 1, mn[i - 1]) - high);
			mx[i] = max(mx[i], have[i] + min(transfer[i - 1], min(high + transfer[i - 1], mx[i - 1]) - low));
		}

		if (mn[i] == +INF || mn[i] == -INF) {
			return 0;
		}
	}
	if (mx[n] < low || high < mn[n]) {
		return 0;
	}
	return 1;
}

int tr[N];

void print_ok(int low, int high) {
	is_ok(low, high);
	assert(is_ok(low, high));
	for (int i = 1; i <= n; i++) have[i] = i_have[i];
	for (int i = 1; i < n; i++) transfer[i] = i_transfer[i];

	int i = n, want = max(low, mn[n]);
	assert(low <= want && mn[n] <= want && want <= high && want <= mx[n]);
	tr[n] = 0;

	while (i >= 2) {
		want -= have[i];
		tr[i - 1] = want;
		want = min(want + high, mx[i - 1]);
		i--;
	}
	for (int i = 1; i < n; i++) {
		assert(tr[i] <= min(have[i], transfer[i]));
		have[i] -= tr[i];
		have[i + 1] += tr[i];
	}
	for (int i = 1; i <= n; i++) {
		assert(low <= have[i] && have[i] <= high);
	}

	int d = 0;
	for (int i = 1; i <= n; i++) {
		cout << d << " " << d + have[i] << "\n";
		d += have[i];
	}
}

signed main() {
#ifdef ONLINE_JUDGE
	home = 0;
#endif

	if (home) {
		FILE* stream;
		freopen_s(&stream, "iron_man.txt", "r", stdin);
	}
	else {
		ios::sync_with_stdio(0); cin.tie(0);
	}

	cin >> l >> n;
	pivots[n + 1] = l;
	for (int i = 1; i <= n; i++) {
		cin >> pivots[i];
	}
	i_have[1] += pivots[1];
	for (int i = 1; i <= n; i++) {
		i_have[i] += pivots[i + 1] - pivots[i];
	}
	for (int i = 1; i < n; i++) {
		i_transfer[i] = pivots[i + 1] - pivots[i];
	}
	int low = 0, high = (int)1e9 + 7, sol = -1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (is_ok(0, mid)) {
			sol = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	assert(sol != -1);
	low = 0, high = sol;
	int sol2 = -1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (is_ok(mid, sol)) {
			sol2 = mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	assert(sol2 != -1);
	print_ok(sol2, sol);
}