#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
int n, k, a, s, c, d;
int main() {
	cin >> n >> k; d = n;
	for (int i = 0; i < n; i++)cin >> a, s += a;
	while (s * 2 / d < (k * 2 - 1)) { d++; s += k; c++; }
	cout << c << endl;
	return 0;
}