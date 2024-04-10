#include <iostream>
#include <climits>

using namespace std;

#define fff(i, a, b) for (i = a; i != b; ++i)
#define ff(i, n) fff(i, 0, n)

#define MAX_M 40
#define MAX_K 60
int cachedResult[MAX_M][MAX_M][MAX_K] = {0};

int setCachedResult(int m, int n, int k, int result) {
	return (cachedResult[m][n][k] = cachedResult[n][m][k] = result);
}

int process(int m, int n, int k) {
	if (k == 0 || k == m * n) return setCachedResult(m, n, k, 0);
	if (cachedResult[m][n][k] != 0) return cachedResult[m][n][k];

	if (k > m * n) {
		return setCachedResult(m, n, k, -1);
	}

	if (m == 1 || n == 1) {
		return setCachedResult(m, n, k, 1);
	}

	int result = INT_MAX;

	int i, h, g;
	g = n * n;

	fff (i, 1, m) {
		ff (h, k) {
			int a = process(i, n, h);
			int b = process(m - i, n, k - h);
			if (a == -1 || b == -1) continue;
			if (a + b + g < result) result = a + b + g;
		}
	}

	g = m * m;
	fff (i, 1, n) {
		ff (h, k) {
			int a = process(m, i, h);
			int b = process(m, n - i, k - h);
			if (a == -1 || b == -1) continue;
			if (a + b + g < result) result = a + b + g;
		}
	}

	if (result == INT_MAX) result = -1;
	return setCachedResult(m, n, k, result);
}

int main (void) {
	ios_base::sync_with_stdio(0);

	int t;
	cin >> t;

	int i, h, g;

	ff (i, t) {
		int m, n, k;
		cin >> m >> n >> k;
		cout << process(m, n, k) << '\n';
	}

	return 0;
}