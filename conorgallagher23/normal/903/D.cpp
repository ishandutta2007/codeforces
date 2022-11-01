#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

inline int read() {
	char c = getchar(); int x = 0, f = 1;
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

int n, a[200005];
ld sum, ans;
map<ld, ld> cnt;

int main() {
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i <= n; i++) {
		ans += (ld)((ll)a[i] * (i - 1) - sum);
		ans += (ld)cnt[a[i] + 1];
		ans -= (ld)cnt[a[i] - 1];
		cnt[a[i]]++; sum += (ld)a[i];
	}
	cout << fixed << setprecision(0) << ans << endl;
	return 0;
}