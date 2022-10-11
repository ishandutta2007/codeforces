#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<functional>
using namespace std;
long long n, k, c, d;
int main() {
	cin >> n >> k; c = n; d = k;
	while (c % 10 == 0 && k >= 1) { c /= 10; k--; }
	while (c % 5 == 0 && k >= 1) { c /= 5; k--; }
	while (c % 2 == 0 && k >= 1) { c /= 2; k--; }
	for (int i = 0; i < d; i++)c *= 10;
	cout << c << endl;
	return 0;
}