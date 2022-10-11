#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int N, A[1 << 18], cnt[1 << 18], cnts[1 << 18], maxn, ans;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &A[i]);

	for (int i = 1; i <= N; i++) {
		cnt[A[i]]++;
		maxn = max(maxn, cnt[A[i]]);
		if (cnt[A[i]] >= 2) cnts[cnt[A[i]] - 1]--;
		cnts[cnt[A[i]]]++;

		bool flag = false;
		if (cnts[maxn] == 1 && cnts[maxn] * maxn + cnts[maxn - 1] * (maxn - 1) == i) flag = true;
		if (cnts[1] == 1 && cnts[1] * 1 + cnts[maxn] * maxn == i) flag = true;
		if (maxn == 1) flag = true;

		if (flag == true) ans = i;
	}
	cout << ans << endl;
	return 0;
}