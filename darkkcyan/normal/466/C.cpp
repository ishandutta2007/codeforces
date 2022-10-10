#include <bits/stdc++.h>
using namespace std;

#define long long long
#define ii pair<int, int>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	static vector<int> a;
	a.resize(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	long sum = accumulate(a.begin(), a.end(), (long) 0);
	if (sum % 3 != 0) return cout << 0, 0;
	sum /= 3;
	static vector<int> r;
	r.resize(n);
	
	long curSum = a[n - 1];
	r[n - 1]= curSum == sum;
	for (int i = n - 2; i >= 0; --i) {
		curSum += a[i];
		r[i] = r[i + 1] + (curSum == sum);
	}
	
	long ans = 0;
	curSum = 0;
	for (int i = 1; i < n - 1; ++i) {
		curSum += a[i - 1];
		if (curSum != sum) continue;
		ans += (long) r[i + 1];
	}
	cout << ans;
	return 0;
}