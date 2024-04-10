#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <functional>
#include <cmath>
#include <map>
#include <vector>
using namespace std;

long long n, k, a[100009], c[100009], s[100009], sum, maxn;

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		if (c[i] == 1) sum += a[i];
		else s[i] += a[i];
	}
	for (int i = 1; i <= n; i++) s[i] += s[i - 1];
	for (int i = 0; i <= n; i++) {
		maxn = max(maxn, sum + s[i + k] - s[i]);
	}
	cout << maxn << endl;
	return 0;
}