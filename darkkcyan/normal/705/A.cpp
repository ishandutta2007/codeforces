#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cout << "I ";
		if (i & 1) cout << "hate ";
		else cout << "love ";
		if (i == n) cout << "it";
		else cout << "that ";
	}
	return 0;
}