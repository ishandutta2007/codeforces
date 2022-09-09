#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
int n, m;
ll ans[4], b[MAXN]; int a[MAXN];
void solve(int sum) {
	if (sum % 2 == 0) {
		int tmp = sum / 2, cnt = 0;
		for (int i = 1; i <= n; i++)
			cnt += a[i] / tmp;
		if (cnt & 1) ans[2]++;
		else ans[3]++;
	}
	int Min = max(1, sum - m), Max = (sum - 1) / 2;
	vector <pair<int, int>> res;
	for (int i = 1; i <= n; i++) {
		if (a[i] + 1 <= Max) {
			res.emplace_back(max(a[i] + 1, Min), 1);
			res.emplace_back(Max + 1, -1);
		}
		int tmp = min(a[i], sum - a[i] - 1);
		if (tmp >= Min) {
			res.emplace_back(Min, 2);
			res.emplace_back(min(tmp, Max) + 1, -2);
		}
		tmp = max(sum - a[i], a[i] / 2 + 1);
		if (tmp <= Max) {
			res.emplace_back(max(tmp, Min), 3);
			res.emplace_back(Max + 1, -3);
		}
	}
	res.emplace_back(Min, 0);
	res.emplace_back(Max + 1, 0);
	sort(res.begin(), res.end());
	int now[5] = {0, 0, 0, 0, 0};
	for (unsigned i = 1; i < res.size(); i++) {
		int delta = res[i].first - res[i - 1].first;
		if (res[i - 1].second < 0) now[-res[i - 1].second]--;
		else now[res[i - 1].second]++;
		now[4] = n - now[1] - now[2] - now[3];
		if (now[2] != 0 || now[4] >= 2) ans[0] += delta, ans[1] += delta;
		else if (now[4] == 0) {
			if (now[3] & 1) ans[2] += delta * 2;
			else ans[3] += delta * 2;
		} else {
			if (now[3] & 1) ans[0] += delta, ans[1] += delta;
			else ans[2] += delta * 2;
		}
	}
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(b[i]);
	for (int i = 2; i <= 2 * m; i++) {
		for (int j = 1; j <= n; j++)
			a[j] = b[j] % i;
		solve(i);
	}
	cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << ' ' << ans[3] << endl;
	return 0;
}