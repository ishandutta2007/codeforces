#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string a, b;
	cin >> ws >> a >> ws >> b;
	reverse(b.begin(), b.end());
	cout << (a == b ? "YES":"NO");
	return 0;
}