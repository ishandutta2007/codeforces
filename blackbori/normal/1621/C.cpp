#include <bits/stdc++.h>

using namespace std;

int P[10101];
int n;

int ask(int i) {
	cout << "? " << i << "\n";
	cout.flush();
	int x; cin >> x;
	return x;
}

void tc() {
	int i, x, y, z;

	cin >> n;

	fill(P + 1, P + n + 1, 0);

	for (i = 1; i <= n; i++) {
		if (P[i]) continue;
		z = x = ask(i);
		for (; ; ) {
			y = ask(i); P[z] = y; z = y;
			if (y == x) break;
		}
	}

	cout << "!";
	for (i = 1; i <= n; i++) {
		cout << " " << P[i];
	}
	cout << "\n";
	cout.flush();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	
	cin >> t;

	for (; t--; ) {
		tc();
	}

	return 0;
}