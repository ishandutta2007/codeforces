#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
const long long Range = 1e18;
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
int n, cnt, a[MAXN]; ll L, b[MAXN], c[MAXN];
pair <ll, ll> ans[MAXN];
ll locate(int i, ll x, ll l, ll r) {
	while (l < r) {
		ll mid = (l + r) / 2, res;
		cout << '?' << ' ' << i << ' ' << mid << endl;
		read(res); if (res == x) return mid;
		if (res > x) r = mid - 1;
		else l = mid + 1;
	}
	return l;
}
void findkth(int l, int r, int k, ll x, ll pl, ll pr) {
	random_shuffle(a + l, a + r + 1);
	b[a[l]] = locate(a[l], x, pl, pr);
	ll pos = b[a[l]];
	for (int i = l; i <= r; i++) {
		cout << '?' << ' ' << a[i] << ' ' << pos << endl;
		read(c[a[i]]); if (c[a[i]] == x) b[a[i]] = pos;
	}
	sort(a + l, a + r + 1, [&] (int x, int y) {return c[x] > c[y]; });
	if (c[a[k]] == x) return;
	if (c[a[k]] < x) {
		while (c[a[l]] >= x) l++;
		findkth(l, r, k, x, pl, pr);
	} else {
		while (c[a[r]] <= x) r--;
		findkth(l, r, k, x, pl, pr);
	}
}
void solve(int l, int r, ll vl, ll vr, ll pl, ll pr) {
	if (l == r) {
		ans[a[l]] = make_pair(pl, pr);
		return;
	}
	assert((vr - vl) % (r - l + 1) == 0);
	ll d = (vr - vl) / (r - l + 1), k = (r - l + 1) / 2;
	findkth(l, r, l + k - 1, vl + k * d, pl, pr);
	ll mid = b[a[l + k - 1]];
	solve(l, l + k - 1, vl, vl + k * d, pl, mid);
	solve(l + k, r, vl + k * d, vr, mid, pr);
}
int main() {
	read(n), read(L);
	for (int i = 1; i <= n; i++)
		a[i] = i;
	solve(1, n, 0, L, 0, Range);
	cout << '!' << endl;
	for (int i = 1; i <= n; i++)
		cout << ans[i].first << ' ' << ans[i].second << endl;
	return 0;
}