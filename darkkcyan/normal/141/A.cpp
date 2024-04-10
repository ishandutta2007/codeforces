#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string a, b, c;
	cin >> a >> ws >> b >> ws >> c;
	a += b;
	sort(a.begin(), a.end());
	sort(c.begin(), c.end());
	cout << (a == c ? "YES" : "NO");
	return 0;
}