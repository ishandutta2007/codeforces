#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <deque>

using namespace std;

void solve() {
	int n; cin >> n;
	deque<int> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
	deque<int> b(n); for (int i = 0; i < n; ++i) cin >> b[i];
	sort(a.begin(), a.end()); reverse(a.begin(), a.end());
	sort(b.begin(), b.end()); reverse(b.begin(), b.end());

	int score_a = 0;
	int score_b = 0;
	for (int i = 0; i < a.size() - (a.size() / 4); ++i) score_a += a[i];
	for (int i = 0; i < b.size() - (b.size() / 4); ++i) score_b += b[i];

	int res = 0;
	int pa = n - n / 4;
	while (score_a < score_b) {
		++n;
		++res;
		a.push_front(100); score_a += 100; 
		b.push_back(0); score_b += b[pa++];
		if (n % 4 == 0) {
			--pa;
			score_a -= a[pa];
			score_b -= b[pa];
		}
	}
	cout << res << endl;
}

int main() {
	cin.sync_with_stdio(false);
	int t; cin >> t;
	while (t-- > 0)
		solve();
	return 0;
}