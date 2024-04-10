#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

vector<long long>vec; long long n, m, a[100009], b[100009], cnt, rem;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld", &a[i], &b[i]); vec.push_back(a[i] - b[i]); cnt += a[i];
	}
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++) {
		if (cnt > m) { cnt -= vec[i]; rem = i + 1; }
	}
	if (cnt > m) { cout << "-1" << endl; }
	else { cout << rem << endl; }
	return 0;
}