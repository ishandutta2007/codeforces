#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int MAXLOG = 20;
const int INF = 1e9 + 5;
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
struct info {int x, home; } b[MAXN];
bool operator < (info a, info b) {return a.x > b.x; }
int n, w, q, k1, k2, a[MAXN];
int cnt[MAXN], jump[MAXN], ans[MAXN];
int nxt[MAXN], nowMax[MAXN], nowMin[MAXN];
int Min[MAXN][MAXLOG], Max[MAXN][MAXLOG];
priority_queue <info> Heap;
bool cmp(info a, info b) {
	return a.x < b.x;
}
void update(int pos, int x) {
	while (nxt[pos] <= n && nxt[pos] - pos <= k2 && nowMax[pos] - nowMin[pos] <= x) {
		nxt[pos]++;
		chkmax(nowMax[pos], a[nxt[pos]]);
		chkmin(nowMin[pos], a[nxt[pos]]);
	}
	if (nxt[pos] <= n && nxt[pos] - pos <= k1) Heap.push((info) {nowMax[pos] - nowMin[pos], pos});
	static int q[MAXN]; int top = 0;
	jump[pos] = pos, cnt[pos] = 0, q[++top] = pos;
	while (jump[pos] != n + 1 && nxt[jump[pos]] - pos <= k1) {
		jump[pos] = nxt[jump[pos]];
		cnt[pos]++, q[++top] = jump[pos];
	}
	static int tmp[MAXN]; tmp[pos] = top;
	static bool updated[MAXN]; updated[pos] = true;
	for (int i = pos - 1; i >= 1 && i >= pos - k1; i--) {
		if (!updated[nxt[i]]) continue;
		while (q[top] - i > k1) top--;
		jump[i] = q[top], cnt[i] = cnt[nxt[i]] + 1 - tmp[nxt[i]] + top;
		tmp[i] = top, updated[i] = true;
	}
	for (int i = pos; i >= 1 && i >= pos - k1; i--) updated[i] = false;
}
int query(int x) {
	static int tmp[MAXN]; int tot = 0;
	while (!Heap.empty() && Heap.top().x <= x) {
		tmp[++tot] = Heap.top().home;
		Heap.pop();
	}
	sort(tmp + 1, tmp + tot + 1);
	for (int i = 1; i <= tot; i++)
		update(tmp[i], x);
	int ans = 0, pos = 1;
	while (pos != n + 1) {
		int dist = nxt[pos] - pos;
		if (dist <= k1) {
			ans += cnt[pos];
			pos = jump[pos];
		} else {
			while (nxt[pos] <= n && nxt[pos] - pos <= k2 && nowMax[pos] - nowMin[pos] <= x) {
				nxt[pos]++;
				chkmax(nowMax[pos], a[nxt[pos]]);
				chkmin(nowMin[pos], a[nxt[pos]]);
			}
			dist = nxt[pos] - pos;
			if (dist <= k2) {
				ans += 1;
				pos = nxt[pos];
			} else {
				ans += 1;
				int nMax = a[pos], nMin = a[pos];
				for (int i = MAXLOG - 1; i >= 0; i--) {
					if (pos + (1 << i) - 1 <= n) {
						int tMax = max(nMax, Max[pos][i]);
						int tMin = min(nMin, Min[pos][i]);
						if (tMax - tMin <= x) {
							pos += 1 << i;
							nMax = tMax;
							nMin = tMin;
						}
					}
				}
			}
		}
	}
	return ans;
}
void init() {
	a[n + 1] = -INF;
	for (int p = 1; p < MAXLOG; p++)
	for (int i = 1, j = (1 << (p - 1)) + 1; j <= n; i++, j++) {
		Max[i][p] = max(Max[i][p - 1], Max[j][p - 1]);
		Min[i][p] = min(Min[i][p - 1], Min[j][p - 1]);
	}
	k1 = pow(n, 1.0 / 3.0), k2 = pow(n, 2.0 / 3.0);
	for (int i = 1; i <= n; i++) {
		nxt[i] = i + 1;
		nowMin[i] = min(a[i], a[i + 1]);
		nowMax[i] = max(a[i], a[i + 1]);
		Heap.push((info) {nowMax[i] - nowMin[i], i});
		jump[i] = min(i + k1, n + 1);
		cnt[i] = jump[i] - i;
	}
}
int main() {
	read(n), read(w), read(q);
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		Max[i][0] = Min[i][0] = a[i];
	}
	init();
	for (int i = 1; i <= q; i++) {
		int x; read(x);
		b[i] = (info) {w - x, i};
	}
	sort(b + 1, b + q + 1, cmp);
	for (int i = 1; i <= q; i++)
		ans[b[i].home] = query(b[i].x);
	for (int i = 1; i <= q; i++)
		writeln(ans[i] - 1);
	return 0;
}