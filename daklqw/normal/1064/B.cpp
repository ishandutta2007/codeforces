#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int T, n;
int main() {
	cin >> T;
	while (T --> 0) {
		cin >> n;
		cout << (1 << __builtin_popcount(n)) << endl;
	}
	return 0;
}