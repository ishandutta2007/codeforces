#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/**
 * Rationale: all indices <= floor(n/2) must be less than or equal to the
 * median, all >= floor(n/2) must be greater than or equal to the median. Never
 * move indices across the median, since if you need to increase the number on
 * the right of the median, the elements already on the right are closer to the
 * median than those on the left of the median, and vice versa.
 */

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	int S;
	cin >> S;
	vector<int> v(n);
	for(auto& x : v) cin >> x;

	sort(v.begin(), v.end());

	ll ans = 0;
	ans += abs(v[n/2]-S);
	for(int i=0;i<n/2;++i) {
		if(v[i] > S) ans += v[i]-S;
	}
	for(int j=n/2+1;j<n;++j) {
		if(v[j] < S) ans += S-v[j];
	}
	cout << ans << endl;

	return 0;
}