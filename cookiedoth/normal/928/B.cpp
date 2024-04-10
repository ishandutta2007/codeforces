#include <bits/stdc++.h>
#define right right228

using namespace std;

const int mx = 3e5;
int n, k, a[mx], sum[mx], right[mx];

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i]--;
	}
	for (int i = 0; i < n; ++i) {
		int l, r;
		if (a[i] == -1) {
			int l = max(i - k, 0);
			int r = min(i + k, n - 1);
			right[i] = r;
			sum[i] = r - l + 1;
		}
		else {
			int l = max(i - k, right[a[i]] + 1);
			int r = min(i + k, n - 1);
			if (r >= l) {
				sum[i] = sum[a[i]] + r - l + 1;
			}
			else
				sum[i] = sum[a[i]];
			right[i] = r;
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << sum[i] << " ";
	}
	cout << endl;
}