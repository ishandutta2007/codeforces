#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n; string s;
	cin >> n;
	long long x = 0;
	while (n -- ) {
		cin >> s;
		if (count(s.begin(), s.end(), '+') > 0) ++x;
		else --x;
	}
	cout << x;
	return 0;
}