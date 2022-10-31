#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; string s; cin >> n >> s;
	int tot = count(s.begin(), s.end(), '?');
	vector<int> L(n + 1), R(n + 1);
	vector<int> A(n + 1), C(n + 1);
	for (int i = 0; i < n; i++) {
		L[i + 1] = L[i] + (s[i] == '?');
		A[i + 1] = A[i] + (s[i] == 'a');
		R[i + 1] = R[i] + (s[n - 1 - i] == '?');
		C[i + 1] = C[i] + (s[n - 1 - i] == 'c');
	}
	const int P = 1e9 + 7;
	vector<int> pw(n + 1, 1);
	for (int i = 1; i <= n; i++) {
		pw[i] = pw[i - 1] * 3LL % P;
	}
	int ans = 0;
	for (int i = 1; i < n - 1; i++) {
		if (s[i] == 'b' || s[i] == '?') {
			int l = (A[i] * 1LL * pw[L[i]] + (L[i] ? L[i] * 1LL * pw[L[i] - 1] : 0)) % P;
			int r = (C[n - 1 - i] * 1LL * pw[R[n - 1 - i]] + (R[n - 1 - i] ? R[n - 1 - i] * 1LL * pw[R[n - 1 - i] - 1] : 0)) % P;
			ans = (ans + 1LL * l * r) % P;
		}
	}
	cout << ans << '\n';
	return 0;
}