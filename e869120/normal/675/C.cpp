#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<long long>D; long long n, a[100000], s;
long long solve() {
	D.clear();
	for (int i = 0; i < n; i++) { D.push_back(s); s += a[i]; }
	sort(D.begin(), D.end());
	long long maxn = 0;
	for (int i = 0; i < n; i++) {
		long long pos1 = lower_bound(D.begin(), D.end(), s) - D.begin();
		long long pos2 = lower_bound(D.begin(), D.end(), s + 1) - D.begin();
		maxn = max(maxn, pos2 - pos1); s += a[i];
	}
	return n - maxn;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) { cin >> a[i]; D.push_back(s); s += a[i]; }
	long long minx = solve();
	reverse(a, a + n);
	minx = min(minx, solve());
	cout << minx << endl;
	return 0;
}