#include<iostream>
using namespace std;
int n, k;
int main() {
	cin >> n >> k;
	if (k == n - 1) {
		cout << "2" << endl;
		for (int i = 2; i <= n; i++)cout << "1 " << i << endl;
	}
	else if (k == n - 2) {
		cout << "3" << endl;
		cout << "1 2" << endl;
		cout << "2 3" << endl;
		for (int i = 4; i <= n; i++)cout << "1 " << i << endl;
	}
	else {
		if (n%k == 2 % k)cout << 2 * ((n + k - 2) / k) - 1 << endl;
		else cout << 2 * ((n + k - 2) / k) << endl;
		for (int i = 2; i <= k + 1; i++)cout << "1 " << i << endl;
		for (int i = k + 2; i <= n; i++)cout << i - k << ' ' << i << endl;
	}
	return 0;
}