#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

int pos[N], a, b, c;
int n;

int main() {
	scanf("%d %d %d", &a, &b, &c);
	scanf("%d", &n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (x > b && x < c) ans++;
	}
	cout << ans << endl;
	return 0;
}