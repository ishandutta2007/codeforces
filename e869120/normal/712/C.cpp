#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
long long x, y, a, b, c;
int main() {
	cin >> x >> y;
	a = y; b = y; c = y; int cnt = 0;
	while (a < x || b < x || c < x) {
		if (cnt % 3 == 0)a = b + c - 1;
		if (cnt % 3 == 1)b = a + c - 1;
		if (cnt % 3 == 2)c = a + b - 1;
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}