#include <iostream>

using namespace std;

typedef long long ll;

int arr[100005];
int opt[100005];

int ofs = 0;
int best;

int main() {
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	arr[0] = 0;
	for (int i = 1; i <= n; ++i)
		cin >> arr[i];
	arr[n + 1] = 0;
	best = 0;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		best = min(best + 1, arr[i]);
		opt[i] = best;
	}

	best = 0;
	for (int i = n; i >= 1; --i) {
		best = min(best + 1, arr[i]);
		ans = max(min(best, opt[i]), ans);
	}

	cout << ans << endl;

	return 0;
}