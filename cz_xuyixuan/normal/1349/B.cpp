#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int a[MAXN];
int main() {
	int T; read(T);
	while (T--) {
		int n, k; read(n), read(k);
		bool found = false, ans = false;
		for (int i = 1; i <= n; i++) {
			read(a[i]);
			if (a[i] == k) found = true;
		}
		if (!found) {
			puts("No");
			continue;
		}
		if (n == 1) {
			puts("Yes");
			continue;
		}
		for (int i = 1; i <= n; i++)
			if (a[i] >= k) {
				int j = i + 1;
				while (j <= n && a[j] < k) j++;
				if (j <= n && j - i <= 2) ans = true;
			}
		if (ans) puts("Yes");
		else puts("No");
	}
	return 0;
}