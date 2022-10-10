#include <iostream>
using namespace std;

int main() {
	long long n, a, b; cin >> n >> a >> b;
	cout << ((((a + b - 1) % n + n) % n) + 1);
	return 0;
}