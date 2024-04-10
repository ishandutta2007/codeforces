#include <bits/stdc++.h>
using namespace std;

int N, A[1 << 18], s = 0, ret = 0, maxn = 0;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) { cin >> A[i]; maxn = max(maxn, A[i]); }
	for (int i = 1; i <= N; i++) {
		if (A[i] == maxn) s++; else s = 0;
		ret = max(ret, s);
	}
	cout << ret << endl;
	return 0;
}