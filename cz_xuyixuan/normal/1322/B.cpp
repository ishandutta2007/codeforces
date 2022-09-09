#include<bits/stdc++.h>
using namespace std;
const int MAXN = 4e5 + 5;
const int MAXV = 1 << 25;
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
int n, a[MAXN];
bool getans(int p) {
	static int sum[MAXV];
	int bit = (1 << (p + 1)) - 1, goal = 1 << p;
	for (int i = 0; i <= bit; i++)
		sum[i] = 0;
	for (int i = 1; i <= n; i++)
		sum[a[i] & bit]++;
	for (int i = 1; i <= bit; i++)
		sum[i] += sum[i - 1];
	bool ans = false; int last = 0;
	for (int i = 0; i <= bit; i++) {
		int cnt = sum[i] - last;
		if (cnt != 0) {
			if (((i + i) & bit) >= goal) ans ^= 1ll * cnt * (cnt - 1) / 2 % 2 == 1;
			int l = (goal - i + bit + 1) & bit, r = bit - i, tmp = 0;
			if (cnt & 1) {
				if (l <= r) {
					if (r > i) tmp = sum[r] - sum[max(l - 1, i)];
				} else {
					tmp = sum[bit] - sum[max(l - 1, i)]; 
					if (r > i) tmp += sum[r] - sum[i];
				}
			}
			if (tmp & 1) ans ^= true;
		}
		last = sum[i];
	}
	return ans;
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	int ans = 0;
	for (int p = 0; p <= 24; p++) {
		bool flg = getans(p);
		if (flg) ans ^= 1 << p;
	}
	cout << ans << endl;
	return 0;
}