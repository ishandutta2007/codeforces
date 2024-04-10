#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int N, K, T[1 << 18], ret = 0, c = 0; vector<int>vec;

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; i++) scanf("%d", &T[i]);

	c = -1000000;
	for (int i = 1; i <= N; i++) {
		if (T[i] < 0) { if (c >= 1) vec.push_back(c); c = 0; ret++; }
		else { c++; }
	}

	int last = c;

	// 
	int ans1 = (1 << 30), ans2 = (1 << 30);
	
	if (true) {
		int cnt1 = 0, ret1 = ret;
		for (int i = 1; i <= N; i++) {
			bool I1 = false; if (T[i - 1] >= 0) I1 = true;
			bool I2 = false; if (T[i] >= 0) I2 = true;
			if (I1 != I2) cnt1++;
		}
		sort(vec.begin(), vec.end());
		for (int i = 0; i < vec.size(); i++) {
			if (ret1 + vec[i] <= K) { ret1 += vec[i]; cnt1 -= 2; }
		}
		if (ret1 > K) cnt1 = (1 << 30);
		ans1 = cnt1;
	}

	// 
	if (last >= 1) {
		int cnt1 = 0, ret1 = ret + last;
		for (int i = 1; i <= N - last; i++) {
			bool I1 = false; if (T[i - 1] >= 0) I1 = true;
			bool I2 = false; if (T[i] >= 0) I2 = true;
			if (I1 != I2) cnt1++;
		}
		sort(vec.begin(), vec.end());
		for (int i = 0; i < vec.size(); i++) {
			if (ret1 + vec[i] <= K) { ret1 += vec[i]; cnt1 -= 2; }
		}
		if (ret1 > K) cnt1 = (1 << 30);
		ans2 = cnt1;
	}
	if (min(ans1, ans2) == (1 << 30)) cout << "-1" << endl;
	else cout << min(ans1, ans2) << endl;
	return 0;
}