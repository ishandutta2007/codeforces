#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

int main() {
	int T, N;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N;
		cout << (N + 1) / 2 << endl;
	}
	return 0;
}