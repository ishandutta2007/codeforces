#include <bits/stdc++.h>
using namespace std;

const int N = 1100000;

int L[N], R[N], sum[N];
string s;
int main() {
	ios::sync_with_stdio(0);
	int n; cin >> n;
	cin >> s;
	L[0] = 1e9;
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + (s[i - 1] == '(' ? 1 : -1);
		L[i] = min(L[i - 1], sum[i]);
	}
	R[n + 1] = 1e9;
	for (int i = n; i >= 1; i--) {
		R[i] = min(R[i + 1], sum[i]);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i - 1] == '(' && sum[n] == 2) {
			if (L[i - 1] >= 0 && R[i] >= 2) ans++;
		}
		if (s[i - 1] == ')' && sum[n] == -2) {
			if (L[i - 1] >= 0 && R[i] >= -2) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}