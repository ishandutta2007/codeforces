#include<bits/stdc++.h>
using namespace std;
const int MAXN = 300005;
const int MAXC = 26;
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
struct edge {int dest; char val; };
vector <edge> a[MAXN];
vector <int> p[MAXN];
int n, benifit[MAXN];
int child[MAXN][MAXC], depth[MAXN];
int calc(int depth) {
	if (p[depth].size() <= 1) return 0;
	int ans = 0;
	for (int j = 0; j < 26; j++) {
		p[depth + 1].clear();
		int cnt = 0;
		for (unsigned i = 0; i < p[depth].size(); i++)
			if (child[p[depth][i]][j]) {
				cnt++;
				p[depth + 1].push_back(child[p[depth][i]][j]);
			}
		ans += max(cnt - 1, 0) + calc(depth + 1);
	}
	return ans;
}
void dfs(int pos, int fa) {
	depth[pos] = depth[fa] + 1;
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i].dest != fa) {
			child[pos][a[pos][i].val - 'a'] = a[pos][i].dest;
			dfs(a[pos][i].dest, pos);
		}
}
int main() {
	read(n);
	for (int i = 1; i <= n - 1; i++) {
		int x, y; char z;
		scanf("%d%d %c", &x, &y, &z);
		a[x].push_back((edge) {y, z});
		a[y].push_back((edge) {x, z});
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) {
		p[0].clear();
		for (int j = 0; j < MAXC; j++)
			if (child[i][j]) {
				benifit[depth[i]]++;
				p[0].push_back(child[i][j]);
			}
		benifit[depth[i]] += calc(0);
	}
	int ans = 1;
	for (int i = 1; i <= n; i++)
		if (benifit[i] > benifit[ans]) ans = i;
	writeln(n - benifit[ans]);
	writeln(ans);
	return 0;
}