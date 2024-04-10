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

long long n, a[100009], minx = (1LL << 62); vector<long long>V;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		minx = min(minx, a[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (minx == a[i]) V.push_back(i);
	}
	long long maxn = (1LL << 62);
	for (int i = 0; i < (int)V.size() - 1; i++)maxn = min(maxn, V[i + 1] - V[i]);
	cout << maxn << endl;
	return 0;
}