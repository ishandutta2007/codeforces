#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
int main() {
	ios::sync_with_stdio(false);
	int n, k, t;
	cin >> n >> k >> t;
	int x = t - k + 1, y = t;
	if (x < 1) x = 1;
	if (y > n) y = n;
	cout << y - x + 1 << endl;
	return 0;
}