#include <bits/stdc++.h>

using namespace std;

int Sum[2000005];

int main() {
	int n, k;
	cin >> n >> k;

	for(int i = 1; i <= n; ++i) {
		int val;
		cin >> val;
		Sum[val + 1] += 1;
	}

	for(int i = 1; i <= 2000001; ++i)
		Sum[i] += Sum[i - 1];

	for(int d = 1000000; d >= 1; --d) {
		int cnt = 0;
		for(int i = d; i <= 1000000; i += d) {
			cnt += Sum[min(i + k + 1, i + d)] - Sum[i];
		}
		if(cnt >= n) {
			cout << d << endl;
			return 0;
		}
	}

	return 0;
}