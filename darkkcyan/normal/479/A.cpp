#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int vals[] = {
		a + b + c,
		a * b + c,
		a + b * c,
		(a + b) * c,
		a * (b + c),
		a * b * c
	};
	cout << *max_element(vals, vals + 6);
	return 0;
}