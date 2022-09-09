#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
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
struct edge {int x, y, val; } e[MAXN];
int n, m, tot, num[MAXN], ans[MAXN];
int root, weight[MAXN], size[MAXN];
int nxt[MAXN], home[MAXN];
bool vis[MAXN];
vector <int> a[MAXN], nodes[MAXN];
map <int, int> behind[MAXN];
bool cmp(edge x, edge y) {
	return x.val < y.val;
}
bool cnp(int x, int y) {
	return nodes[x] < nodes[y];
}
void getroot(int pos, int fa, int tot) {
	size[pos] = 1; weight[pos] = 0;
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i] != fa && !vis[a[pos][i]]) {
			getroot(a[pos][i], pos, tot);
			size[pos] += size[a[pos][i]];
			chkmax(weight[pos], size[a[pos][i]]);
		}
	chkmax(weight[pos], tot - size[pos]);
	if (weight[pos] < weight[root]) root = pos;
}
void calcsize(int pos, int fa) {
	size[pos] = 1;
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i] != fa && !vis[a[pos][i]]) {
			calcsize(a[pos][i], pos);
			size[pos] += size[a[pos][i]];
		}
}
void work(int pos, int depth) {
	vis[pos] = true;
	ans[num[pos]] = depth;
	calcsize(pos, 0);
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (!vis[a[pos][i]]) {
			root = 0;
			getroot(a[pos][i], pos, size[a[pos][i]]);
			work(root, depth + 1);
		}
}
void debug(int pos) {
	printf("%d:\n", pos);
	printf("  Vertex:");
	for (unsigned i = 0; i < nodes[pos].size(); i++)
		printf(" %d", nodes[pos][i]);
	printf("\n");
	printf("  Edge:");
	for (unsigned i = 0; i < a[pos].size(); i++)
		printf(" %d", a[pos][i]);
	printf("\n");
	printf(" Number: %d\n", num[pos]);
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		read(e[i].x), read(e[i].y);
		if (e[i].x > e[i].y) swap(e[i].x, e[i].y);
		e[i].val = e[i].y - e[i].x - 1;
		chkmin(e[i].val, n - 2 - e[i].val);
	}
	sort(e + 1, e + m + 1, cmp);
	for (int i = 1; i <= n; i++)
		if (i == n) nxt[n] = 1;
		else nxt[i] = i + 1;
	for (int i = 1; i <= m; i++) {
		int now = ++tot, s = e[i].y, t = e[i].x;
		if (e[i].y - e[i].x - 1 == e[i].val) swap(s, t);
		nodes[now].push_back(s);
		nodes[now].push_back(t);
		int p = s;
		while (nxt[s] != t) {
			int q = nxt[s];
			nodes[now].push_back(q);
			if (behind[p][q] != 0) {
				int tmp = behind[p][q];
				a[tmp].push_back(now);
				a[now].push_back(tmp);
			}
			nxt[s] = nxt[p = q];
		}
		if (behind[p][t] != 0) {
			int tmp = behind[p][t];
			a[tmp].push_back(now);
			a[now].push_back(tmp);
		}
		behind[s][t] = now;
		if (i != m) continue;
		now = ++tot; swap(s, t);
		a[now].push_back(now - 1);
		a[now - 1].push_back(now);
		nodes[now].push_back(s);
		nodes[now].push_back(t);
		p = s;
		while (nxt[s] != t) {
			int q = nxt[s];
			nodes[now].push_back(q);
			if (behind[p][q] != 0) {
				int tmp = behind[p][q];
				a[tmp].push_back(now);
				a[now].push_back(tmp);
			}
			nxt[s] = nxt[p = q];
		}
		if (behind[p][t] != 0) {
			int tmp = behind[p][t];
			a[tmp].push_back(now);
			a[now].push_back(tmp);
		}
		behind[s][t] = now;
	}
	if (m == 0) tot++;
	for (int i = 1; i <= tot; i++) {
		sort(nodes[i].begin(), nodes[i].end());
		reverse(nodes[i].begin(), nodes[i].end());
		home[i] = i;
	}
	sort(home + 1, home + tot + 1, cnp);
	for (int i = 1; i <= tot; i++)
		num[home[i]] = i;
	weight[root = 0] = n + 1;
	getroot(1, 0, n);
	work(root, 1);
	for (int i = 1; i <= tot; i++)
		printf("%d ", ans[i]);
	return 0;
}