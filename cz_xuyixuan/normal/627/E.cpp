#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3005;
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
int r, c, n, k, home[MAXN];
int x[MAXN], y[MAXN], pre[MAXN], nxt[MAXN];
vector <int> a[MAXN];
bool cmp(int a, int b) {
	return y[a] < y[b];
}
int main() {
	read(r), read(c), read(n), read(k);
	for (int i = 1; i <= n; i++) {
		read(x[i]), read(y[i]), home[i] = i;
		a[x[i]].push_back(i);
	}
	y[n + 1] = 0, y[n + 2] = c + 1;
	sort(home + 1, home + n + 1, cmp);
	home[0] = n + 1, home[n + 1] = n + 2;
	ll ans = r * (r + 1ll) * c * (c + 1ll) / 4;
	for (int p = 1; p <= r; p++) {
		for (int i = 1; i <= n + 1; i++) {
			pre[home[i]] = home[i - 1];
			nxt[home[i - 1]] = home[i];
		}
		ll sum = 0;
		for (int i = n + 1; i != n + 2; i = nxt[i]) {
			int len = y[nxt[i]] - y[i];
			sum += (len - 1ll) * len / 2;
			for (int j = nxt[i], cnt = 1; j != n + 2 && cnt <= k - 1; j = nxt[j], cnt++)
				sum += len * (y[nxt[j]] - y[j]);
		}
		pre[n + 1] = n + 1, nxt[n + 2] = n + 2;
		for (int i = 1; i <= p - 1; i++) {
			for (auto x : a[i]) {
				int pos = x;
				for (int j = 1; j <= k; j++)
					pos = pre[pos];
				int qos = pos;
				for (int j = 1; j <= k; j++)
					qos = nxt[qos];
				while (pos != x && qos != n + 2) {
					sum += (y[nxt[pos]] - y[pos]) * (y[nxt[qos]] - y[qos]);
					pos = nxt[pos];
					qos = nxt[qos];
				}
				int p = pre[x], s = nxt[x];
				nxt[p] = s, pre[s] = p;
			}
		}
		for (int i = r; i >= p; i--) {
			ans -= sum;
			for (auto x : a[i]) {
				int pos = x;
				for (int j = 1; j <= k; j++)
					pos = pre[pos];
				int qos = pos;
				for (int j = 1; j <= k; j++)
					qos = nxt[qos];
				while (pos != x && qos != n + 2) {
					sum += (y[nxt[pos]] - y[pos]) * (y[nxt[qos]] - y[qos]);
					pos = nxt[pos];
					qos = nxt[qos];
				}
				int p = pre[x], s = nxt[x];
				nxt[p] = s, pre[s] = p;
			}
		}
	}
	cout << ans << endl;
	return 0;
}