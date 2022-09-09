#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
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
int n, m, k, q, b[MAXN];
vector <int> a[MAXN];
int dist[MAXN], cnt[MAXN];
void work(int pos) {
	static int q[MAXN];
	int l = 0, r = 0; q[0] = pos, dist[pos] = 1, cnt[pos] = 1;
	while (l <= r) {
		int tmp = q[l++];
		for (auto x : a[tmp]) {
			if (dist[x] == 0) {
				dist[x] = dist[tmp] + 1;
				q[++r] = x;
			}
			if (dist[x] == dist[tmp] + 1) {
				cnt[x] = min(2, cnt[x] + 1);
			}
		}
	}
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		int x, y; read(x), read(y);
		a[y].push_back(x);
	}
	read(q);
	for (int i = 1; i <= q; i++)
		read(b[i]);
	work(b[q]);
	int Min = 0, Max = 0;
	for (int i = 1; i <= q - 1; i++) {
		if (dist[b[i]] != dist[b[i + 1]] + 1) Min++, Max++;
		else Max += cnt[b[i]] == 2;
	}
	cout << Min << ' ' << Max << endl;
	return 0;
}