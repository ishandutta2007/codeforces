#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n * k);
	for (auto& i : a)
		cin >> i, i--;
	vector<pair<int, int>> ans(n);
	vector<int> done(n);
	int cnt = 0;
	int x = 0;
	map<int, int> lst;

	auto go = [&]() {
		x = (x + 1) % (n * k);
		if (x == 0)
			lst.clear();
	};

	while (cnt < n) {
		if (done[a[x]]) {
			go();
			continue;
		}
		if (!lst.count(a[x])) {
			lst[a[x]] = x;
			go();
			continue;
		}
		cnt++;
		ans[a[x]] = {lst[a[x]], x};
		done[a[x]] = 1;
		lst.clear();
		go();
	}

	for (auto [l, r] : ans)
		cout << l + 1 << " " << r + 1 << endl;
	return 0;
}