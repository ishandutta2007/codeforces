#include <iostream>
#include <string>
using namespace std;
#pragma warning (disable: 4996)

int n, cnt, ret; string S;

int main() {
	cin >> n >> S;
	int p = (n - 11) / 2;
	for (int i = 0; i < n; i++) {
		if (S[i] == '8') {
			if (cnt == p) {
				if (ret > p) cout << "NO" << endl;
				else cout << "YES" << endl;
				return 0;
			}
			cnt++;
		}
		else ret++;
	}
	if (cnt <= p) {
		cout << "NO" << endl;
	}
	return 0;
}