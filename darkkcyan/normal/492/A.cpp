#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	int ans = 1;
	for (int i = 1; n >= 0; ans ++, i += ans) {
		n -= i;
	}
	cout << (ans - 2);
	return 0;
}