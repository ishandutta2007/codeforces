#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int arr[100005];

int gcd(int a, int b) {
	return (b == 0) ? a : gcd(b, a % b);
}

bool sm3(int n) {
	while (n % 2 == 0)
		n /= 2;
	while (n % 3 == 0)
		n /= 3;
	return n == 1;
}

int main() {
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	int g = 0;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		g = gcd(g, arr[i]);
	}
	bool ok = true;
	for (int i = 0; ok && i < n; ++i) {
		arr[i] /= g;
		if (!sm3(arr[i]))
			ok = false;
	}
	if (ok)
		cout << "Yes\n";
	else
		cout << "No\n";

	return 0;
}