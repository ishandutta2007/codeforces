#include <bits/stdc++.h>
using namespace std;

const int N = 110000;

int a[N];
char b[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; cin >> n;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	scanf("%s", b + 1);
	int L = -1e9, R = 1e9;
	for (int i = 5; i <= n; i++) {
		if (b[i] != b[i-1]) {
			if (b[i] == '1') {
				for (int j = 0; j < 5; j++) L = max(L, a[i - j] + 1);
			} else {
				for (int j = 0; j < 5; j++) R = min(R, a[i - j] - 1);
			}
		}
	}
	cout << L << ' ' << R << endl;
	return 0;
}