#include <iostream>

using namespace std;

#define loop(i, f, t) for (i = f; i < t; ++i)

int main (void) {
	ios_base::sync_with_stdio(0);

	int i, k;

	int n, m;
	cin >> n >> m;

	int arr[m + 10] = {0};

	loop(i, 0, n) {
		int t;
		cin >> t;
		++arr[t - 1];
	}

	long long int result = 0;
	loop(i, 0, m) {
		result += arr[i] * (n - arr[i]);
	}

	result /= 2;
	cout << result;


	return 0;
}