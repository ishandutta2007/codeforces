#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, k, h = 0;
		cin >> n >> k;
		while (n--) {
			cin >> k;
			h |= k;
		}
		cout << (h ? "YES\n" : "NO\n");
	}
	return 0;
}