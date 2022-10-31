#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int nums[N] = {}, n, k;
int a[N];

inline int range(int a, int b) {
	return nums[b] - nums[a-1];
}

inline bool ok(int x, int y) {
	return 2*range(x, y) - n >= k;
}

void solve() {
	cin >> n >> k;
	fill(nums, nums+n+1, 0);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		++nums[a[i]];
	}
	for(int i = 1; i <= n; ++i)
		nums[i] += nums[i-1];
	int bx=0, by=1e9;

	for(int x = 1, y = 0; x <= n; ++x) {
		while(y <= n && !ok(x, y)) ++y;
		if(y > n) break;
		if(y-x < by-bx)
			bx=x, by=y;
	}
	cout << bx << " " << by << "\n";
	int bal = 0;
	int last_start = 0;
	int tot = 0;
	for(int i = 0; i < n; ++i) {
		if(bx <= a[i] && a[i] <= by)
			++bal;
		else
			--bal;
		if(bal > 0 && tot < k-1) {
			cout << last_start+1 << " " << i+1 << '\n';
			last_start=i+1;
			++tot;
			bal = 0;
		}
	}
	cout << last_start+1 << " " << n << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}