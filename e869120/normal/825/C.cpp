#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<functional>
#pragma warning(disable:4996)
using namespace std;
long long n, k, c, a[100009];
int main() {
	cin >> n >> k; for (int i = 0; i < n; i++)cin >> a[i];
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		while (k * 2 < a[i]) { k *= 2; c++; }
		k = max(k, a[i]);
	}
	cout << c << endl;
	return 0;
}