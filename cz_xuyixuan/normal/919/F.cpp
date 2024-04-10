#include<bits/stdc++.h>
using namespace std;
const int MAXM = 1 << 25;
const int MAXN = 490055;
const int MAXS = 1 << 12;
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
struct info {int cnt[5]; };
int hash(info a) {
	int ans = 0, now = -1;
	for (int i = 0; i <= 3; i++) {
		now += 1 + a.cnt[i];
		ans |= 1 << now;
	}
	return ans;
}
info decode(int x) {
	info ans;
	int now = 0, pos = 0;
	for (int i = 1, j = 1; i <= 12; i++, j <<= 1)
		if (x & j) ans.cnt[pos++] = now, now = 0;
		else now++;
	ans.cnt[pos] = now;
	return ans;
}
int cnt, num[MAXM];
int d[MAXN], bits[MAXS];
bool vis[MAXN], win[MAXN];
vector <int> a[MAXN];
int l, r, q[MAXN];
int main() {
	for (int i = 0; i < MAXS; i++) {
		int ans = 0, tmp = i;
		while (tmp) {
			ans += tmp & 1;
			tmp >>= 1;
		}
		bits[i] = ans;
	}
	for (int t = 0; t <= 1; t++)
	for (int i = 0; i < MAXS; i++) {
		if (bits[i] != 4) continue;
		for (int j = 0; j < MAXS; j++) {
			if (bits[j] != 4) continue;
			int S = (t << 24) + (i << 12) + j;
			num[S] = ++cnt;
		}
	}
	for (int t = 0; t <= 1; t++)
	for (int i = 0; i < MAXS; i++) {
		if (bits[i] != 4) continue;
		info fi = decode(i);
		for (int j = 0; j < MAXS; j++) {
			if (bits[j] != 4) continue;
			info fj = decode(j);
			int S = num[(t << 24) + (i << 12) + j];
			if (t == 0) {
				for (int ti = 1; ti <= 4; ti++) {
					if (fi.cnt[ti] == 0) continue;
					for (int tj = 1; tj <= 4; tj++) {
						if (fj.cnt[tj] == 0) continue;
						int res = (ti + tj) % 5;
						fi.cnt[ti]--, fi.cnt[res]++;
						int T = num[((t ^ 1) << 24) + (hash(fi) << 12) + j];
						d[S]++, a[T].push_back(S);
						fi.cnt[ti]++, fi.cnt[res]--;
					}
				}
			} else {
				for (int ti = 1; ti <= 4; ti++) {
					if (fi.cnt[ti] == 0) continue;
					for (int tj = 1; tj <= 4; tj++) {
						if (fj.cnt[tj] == 0) continue;
						int res = (ti + tj) % 5;
						fj.cnt[tj]--, fj.cnt[res]++;
						int T = num[((t ^ 1) << 24) + (i << 12) + hash(fj)];
						d[S]++, a[T].push_back(S);
						fj.cnt[tj]++, fj.cnt[res]--;
					}
				}
			}
		}
	}
	l = 0, r = -1;
	for (int t = 0; t <= 1; t++)
	for (int i = 0; i < MAXS; i++) {
		if (bits[i] != 4) continue;
		for (int j = 0; j < MAXS; j++) {
			if (bits[j] != 4) continue;
			int S = num[(t << 24) + (i << 12) + j];
			if (i == 3840) {
				vis[S] = true;
				win[S] = t ^ 1;
				q[++r] = S;
			} else if (j == 3840) {
				vis[S] = true;
				win[S] = t;
				q[++r] = S;
			}
		}
	}
	while (l <= r) {
		int tmp = q[l++];
		if (win[tmp]) {
			for (unsigned i = 0; i < a[tmp].size(); i++) {
				d[a[tmp][i]]--;
				if (!vis[a[tmp][i]] && d[a[tmp][i]] == 0) {
					vis[a[tmp][i]] = true;
					win[a[tmp][i]] = false;
					q[++r] = a[tmp][i];
				}
			}
		} else {
			for (unsigned i = 0; i < a[tmp].size(); i++) {
				if (!vis[a[tmp][i]]) {
					vis[a[tmp][i]] = true;
					win[a[tmp][i]] = true;
					q[++r] = a[tmp][i];
				}
			}
		}
	}
	int T; read(T);
	while (T--) {
		int s, tmp; read(s);
		tmp = s; info a, b;
		memset(a.cnt, 0, sizeof(a.cnt));
		memset(b.cnt, 0, sizeof(b.cnt));
		for (int i = 1; i <= 8; i++) {
			int x; read(x);
			a.cnt[x]++;
		}
		for (int i = 1; i <= 8; i++) {
			int x; read(x);
			b.cnt[x]++;
		}
		s <<= 12; s += hash(a);
		s <<= 12; s += hash(b);
		s = num[s];
		if (vis[s]) {
			if (win[s] ^ tmp) printf("Alice\n");
			else printf("Bob\n");
		} else printf("Deal\n");
	}
	return 0;
}