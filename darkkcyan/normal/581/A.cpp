#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int x = min(a, b);
	int y = (max(a, b) - x) / 2;
	cout << x << ' ' << y;
	return 0;
}