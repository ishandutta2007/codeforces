#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll seg1[3 * 100000];
ll seg2[3 * 100000];

void build(int* arr, int n, int i, int j, ll* to_build) {
	if (i == j) {
		to_build[n] = arr[i];
		return;
	}

	build(arr, n * 2 + 1, i, (i + j) / 2, to_build);
	build(arr, n * 2 + 2, (i + j) / 2 + 1, j, to_build);
	to_build[n] = to_build[2 * n + 1] + to_build[2 * n + 2];
}

ll get_sum(ll* seg, int n, int i, int j, int s, int e) {

	if (i > e || j < s)
		return 0;
	else if (i >= s && j <= e)
		return seg[n];
	ll ans = get_sum(seg, 2 * n + 1, i, (i + j) / 2, s, e) + get_sum(seg, 2 * n + 2, (i + j) / 2 + 1, j, s, e);

	return ans;
}

int main() {
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	int stones[n];
	for (int i = 0; i < n; ++i)
		cin >> stones[i];

	build(stones, 0, 0, n - 1, seg1);
	sort(stones, stones + n);
	build(stones, 0, 0, n - 1, seg2);

	int m;
	cin >> m;

	for (int i = 0; i < m; ++i) {
		int type, l, r;
		cin >> type >> l >> r;
		if (type == 1) {
			cout << get_sum(seg1, 0, 0, n - 1, l - 1, r - 1) << "\n";
		} else {
			cout << get_sum(seg2, 0, 0, n - 1, l - 1, r - 1) << "\n";
		}
	}

	return 0;
}