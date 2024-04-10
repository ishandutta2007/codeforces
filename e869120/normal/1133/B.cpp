#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

int n, k, a[1 << 18], c[109];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) c[a[i] % k]++;

	int sum = 0; vector<int>vec;
	for (int i = 0; i <= k / 2; i++) {
		if (i == 0 || k - i == i) vec.push_back(i);
		else {
			sum += min(c[i], c[k - i]);
		}
	}
	for (int i = 0; i < vec.size(); i++) sum += c[vec[i]] / 2;
	cout << sum * 2 << endl;
	return 0;
}