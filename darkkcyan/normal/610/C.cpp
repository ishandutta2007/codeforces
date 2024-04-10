#include <iostream>
#include <vector>

using namespace std;
bool arr[513][513];

void process (int rowSource, int rowDest1, int rowDest2, int sourceLength) {
	int destLength = 2 * sourceLength;
	for (int i = sourceLength - 1, k = destLength - 2; i >= 0; --i, k -= 2) {
		bool t = arr[rowSource][i];
		arr[rowDest1][k + 1] = t;
		arr[rowDest1][k] = t;
		arr[rowDest2][k] = t;
		arr[rowDest2][k + 1] = !t;
	}
}

int main (void) {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;

	//arr.resize(1 << n, vector<bool>(1 << n));
	arr[0][0] = false;


	int len = 1;

	for (int i = 0; i < n; ++i) {
		for (int k = len - 1; k >= 0; --k) {
			process(k, 2 * k, 2 * k + 1, len);
		}
		len *= 2;
	}

	for (int i = 0; i < len; ++i) {
		for (int k = 0; k < len; ++k) {
			cout << (arr[i][k] ? '+' : '*');
		}

		cout << '\n';
	}

	return 0;
}