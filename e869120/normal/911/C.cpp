#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
#include <map>
#include <cmath>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

int a[3];

int main() {
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	if (a[0] == 1) { cout << "YES" << endl; }
	else if (a[0] == 2) {
		if (a[1] == 2) { cout << "YES" << endl; }
		else if (a[1] == 4 && a[2] == 4) { cout << "YES" << endl; }
		else { cout << "NO" << endl; }
	}
	else if (a[0] == 3) {
		if (a[0] == 3 && a[1] == 3 && a[2] == 3) { cout << "YES" << endl; }
		else { cout << "NO" << endl; }
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}