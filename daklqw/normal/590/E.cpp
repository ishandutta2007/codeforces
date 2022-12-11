#include <bits/stdc++.h>

const int MAXN = 800;
const int MAXP = 10000010;
int nxt[MAXP][2], fail[MAXP], tot = 1, end[MAXP];
void insert(int ed, const char * buf) {
	int now = 1;
	while (*buf) {
		int & x = nxt[now][*buf++ - 'a'];
		if (!x) x = ++tot; now = x;
	}
	end[now] = ed;
}
typedef std::bitset<MAXN> B;
B mat[MAXN];
void build() {
	std::queue<int> q;
	for (int i = 0; i != 2; ++i)
		if (nxt[1][i])
			q.push(nxt[1][i]), fail[nxt[1][i]] = 1;
		else nxt[1][i] = 1;
	while (!q.empty()) {
		int t = q.front(); q.pop();
		for (int i = 0; i != 2; ++i)
			if (nxt[t][i])
				q.push(nxt[t][i]), fail[nxt[t][i]] = nxt[fail[t]][i];
			else nxt[t][i] = nxt[fail[t]][i];
		if (!end[t]) end[t] = end[fail[t]];
	}
}
void match(int u, const char * buf) {
	int now = 1;
	do {
		now = nxt[now][*buf++ - 'a'];
		mat[u][end[now]] = true;
		mat[u][end[fail[now]]] = true;
	} while (*buf);
}
int n;
int L[MAXN], R[MAXN];
bool vis[MAXN];
int match(int x) {
	for (int i = mat[x]._Find_first(); i != MAXN; i = mat[x]._Find_next(i))
		if (!vis[i]) {
			vis[i] = true;
			if (!L[i] || match(L[i]))
				return L[i] = x, R[x] = i, true;
		}
	return false;
}
int cl[MAXN], cr[MAXN];
void konig(int x) {
	for (int i = mat[x]._Find_first(); i != MAXN; i = mat[x]._Find_next(i))
		if (!cr[i]) cr[i] = true, konig(L[i]);
}
std::vector<std::string> V;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::string buf;
		std::cin >> buf, insert(i, buf.c_str());
		V.push_back(buf);
	}
	build();
	for (int i = 0; i < n; ++i) match(i + 1, V[i].c_str());
	for (int i = 1; i <= n; ++i) mat[i][i] = 0;
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			if (mat[i][k])
				mat[i] |= mat[k];
	for (int i = 1; i <= n; ++i) if (!R[i])
		memset(vis, 0, n + 1), match(i);
	for (int i = 1; i <= n; ++i) if (!R[i]) konig(i);
	for (int i = 1; i <= n; ++i) if (R[i] && !cr[R[i]]) cl[i] = true;
	std::vector<int> ansl;
	for (int i = 1; i <= n; ++i)
		if (!cl[i] && !cr[i])
			ansl.push_back(i);
	std::cout << ansl.size() << std::endl;
	for (auto t : ansl) std::cout << t << ' ';
	return 0;
}