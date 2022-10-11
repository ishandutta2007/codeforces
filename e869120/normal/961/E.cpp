#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <functional>
#include <cmath>
#include <map>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

long long n, a[200009], bit[200009], sums; vector<pair<int, int>>vec;

void add(int p, int x) {
	while (p <= 200008) { bit[p] += x; p += (p&-p); }
}
int sum(int p) {
	int s = 0;
	while (p >= 1) { s += bit[p]; p -= (p&-p); }
	return s;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) { scanf("%lld", &a[i]); vec.push_back(make_pair(a[i], i)); }
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());

	int cx = 0;
	for (int i = n; i >= 1; i--) {
		while (cx < vec.size() && vec[cx].first >= i) { add(vec[cx].second, 1); cx++; }
		if (a[i] >= i) add(i, -1);
		sums += 1LL * sum(min(200005LL, a[i]));
		if (a[i] >= i) add(i, 1);
	}
	sums /= 2;
	cout << sums << endl;
	return 0;
}