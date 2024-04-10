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

long long n, a, b; bool flag = false;

int main() {
	cin >> n >> a >> b;
	for (int i = 10000; i >= 1; i--) {
		long long I = a / i;
		long long J = b / i;
		if (I + J >= n) { cout << min(min(a, b), 1LL * i) << endl; flag = true; break; }
	}
	if (flag == false) { cout << "0" << endl; }
	return 0;
}