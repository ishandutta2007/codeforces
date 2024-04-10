#include <bits/stdc++.h>
#define ll long long
#define null null

using namespace std;

int n, a, b, c, d, k;

void go(int l, int r, int depth) {
	int mid = (l + r) / 2;
	//cout << l << " " << r << " " << depth << " " << mid << endl;
	if (c <= mid && d > mid) {
		if (depth == 0) {
			cout << "Final!" << endl;
		}
		else
			cout << k - depth << endl;
		return;
	}
	if (c <= mid)
		go(l, mid, depth + 1);
	else
		go(mid + 1, r, depth + 1);
}

int main() {
	cin >> n >> a >> b;
	a--;
	b--;
	c = min(a, b);
	d = max(a, b);
	//cout << c << " " << d << endl;
	k = log2(n);
	go(0, n - 1, 0);
}