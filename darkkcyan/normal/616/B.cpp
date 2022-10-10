#include <iostream>

using namespace std;

#define fff(i, a, b) for (i = a; i != b; ++i)
#define ff(i, n) fff(i, 0, n)

int main (void) {
	ios_base::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;

	long long arr[n][m];
	int i, j, k;

	ff (i, n) {
		ff (j, m) {
			cin >> arr[i][j];
		}
	}

	long long int max = -1;

	ff (i, n) {
		long long int min = arr[i][0];
		fff (j, 1, m) {
			if (arr[i][j] < min) {
				min = arr[i][j];
			}
		}
		if (min > max) {
			max = min;
		}
	}

	cout << max << '\n';

	return 0;
}