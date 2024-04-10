#include <iostream>

using namespace std;

#define loop(i, f, t) for (i = f; i < t; ++i)

int main (void) {
	ios_base::sync_with_stdio(0);

	long long int i, k, m;

	long long int n;
	cin >> n;

	long long int arr[n + 10];
	long long int minInd = 0;

	loop (i, 0, n) {
		cin >> arr[i];
		if (arr[minInd] > arr[i]) {
			minInd = i;
		}
	}

	long long int min = arr[minInd];

	loop (i, 0, n) {
		arr[i] -= min;
	}

	long long int  result = min * n;

	long long int maxCount = 0;
	long long int lastCount = 0;
	loop (i, minInd, n) {
		if (arr[i] == 0) {
			if (lastCount > maxCount) {
				maxCount = lastCount;
			}

			lastCount = -1;
		}

		++ lastCount;
	}
	// cout << result << endl;
	// cout << maxCount << endl;

	for (i = n - 1; i >= 0; --i) {
		if (arr[i] == 0) break;
	}

	if (maxCount < minInd + n - i - 1) {
		maxCount = minInd + n - i - 1;
	}

	// cout << maxCount << endl;
	// cout << minInd + n - i - 1 << endl;
	// cout << minInd << ' ' << i << endl;

	result += maxCount;
	cout << result;

	return 0;
}