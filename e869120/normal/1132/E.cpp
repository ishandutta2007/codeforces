#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long W, A[10], sum, minx = (1LL << 60);

void dfs(int pos, long long val) {
	if (pos == 0) {
		minx = min(minx, val);
		return;
	}

	long long B = val / pos; B = min(B, A[pos]);

	for (long long i = B; i >= B - 7; i--) {
		if (i < 0) continue;
		dfs(pos - 1, val - 1LL * i * pos);
	}
}

int main() {
	cin >> W;
	for (int i = 1; i <= 8; i++) { cin >> A[i]; }

	dfs(8, W);
	cout << W - minx << endl;
	return 0;
}