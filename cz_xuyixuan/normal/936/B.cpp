#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
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
int l, r, q[MAXN], t[MAXN];
vector <int> a[MAXN], b[MAXN];
int n, m, d[MAXN], sodd[MAXN], seven[MAXN];
bool found, vis[MAXN], ins[MAXN], odd[MAXN], even[MAXN];
void work(int pos) {
	if (ins[pos]) {
		found = true;
		return;
	}
	if (vis[pos]) return;
	vis[pos] = ins[pos] = true;
	for (unsigned i = 0; i < b[pos].size(); i++)
		work(b[pos][i]);
	ins[pos] = false;
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++) {
		int cnt; read(cnt);
		d[i] = cnt;
		while (cnt--) {
			int x; read(x);
			a[x].push_back(i);
			b[i].push_back(x);
		}
	}
	l = 0, r = -1;
	for (int i = 1; i <= n; i++)
		if (d[i] == 0) {
			r++;
			t[r] = 0;
			q[r] = i;
			even[i] = true;
			seven[i] = 1;
		}
	while (l <= r) {
		int tmp = q[l], type = t[l++];
		if (type) {
			for (unsigned i = 0; i < a[tmp].size(); i++)
				if (!even[a[tmp][i]]) {
					r++;
					t[r] = 0;
					q[r] = a[tmp][i];
					even[a[tmp][i]] = true;
					seven[a[tmp][i]] = sodd[tmp] + 1;
				}
		} else {
			for (unsigned i = 0; i < a[tmp].size(); i++)
				if (!odd[a[tmp][i]]) {
					r++;
					t[r] = 1;
					q[r] = a[tmp][i];
					odd[a[tmp][i]] = true;
					sodd[a[tmp][i]] = seven[tmp] + 1;
				}
		}
	}
	int pos; read(pos);
	if (odd[pos]) {
		printf("Win\n");
		printf("%d ", pos);
		while (true) {
			for (unsigned i = 0; i < b[pos].size(); i++)
				if (even[b[pos][i]] && seven[b[pos][i]] == sodd[pos] - 1) {
					pos = b[pos][i];
					break;
				}
			printf("%d ", pos);
			if (b[pos].size() == 0) return 0;
			for (unsigned i = 0; i < b[pos].size(); i++)
				if (odd[b[pos][i]] && sodd[b[pos][i]] == seven[pos] - 1) {
					pos = b[pos][i];
					break;
				}
			printf("%d ", pos);
		}
	}
	work(pos);
	if (found) printf("Draw\n");
	else printf("Lose\n");
	return 0;
}