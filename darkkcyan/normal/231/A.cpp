#include <iostream>
using namespace std;

int main() {
	int n, a, b, c;
	cin >> n;
	int cnt = 0;
	while (n --) {
		cin >> a >> b >> c;
		cnt += (a + b + c) >= 2;
	}
	cout << cnt;
	return 0;
}