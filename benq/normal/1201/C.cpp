#include <bits/stdc++.h>
using namespace std;

int lastTrue(int lo, int hi, function<bool(int)> f) {
	for (--lo; lo < hi; ) {
		int mid = lo+(hi-lo+1)/2;
		if (f(mid)) lo = mid;
		else hi = mid-1;
	}
	return lo;
}

int main() {
	size_t n; int k; cin >> n >> k;
	vector<int> a(n);
	for (int& t: a) cin >> t;
	sort(a.begin(), a.end());
	cout << lastTrue(1, 2e9,[&](int x){
		// returns true if median can be raised to x
		long long operationsNeeded = 0;
		for (size_t i = (n-1)/2; i < n; ++i)
			operationsNeeded += max(0, x-a[i]);
		return operationsNeeded <= k;
	});
}