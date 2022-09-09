#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
int gcd(int x, int y) {
	if (y == 0) return x;
	else return gcd(y, x % y);
}
int main() {
	ios::sync_with_stdio(false);
	int n, x, y; cin >> n;
	for (int i = 1, j = n - 1; i < j; i++, j--)
		if (gcd(i, j) == 1) x = i, y = j;
	cout << x << ' ' << y << endl;
	return 0;
}