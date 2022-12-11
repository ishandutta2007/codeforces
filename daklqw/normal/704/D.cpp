#include <bits/stdc++.h>

const int MAXN = 400010;
const int MAXM = MAXN * 20;
const int INF = 0x3f3f3f3f;
int head[MAXN], nxt[MAXM], to[MAXM], val[MAXM], tot = 1;
void addedge(int b, int e, int v) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e; val[tot] = v;
	nxt[++tot] = head[e]; to[head[e] = tot] = b; val[tot] = 0;
}
int S, T, SS, TT, idx;
int _S, _T, dis[MAXN];
std::queue<int> q;
bool bfs() {
	memset(dis, 0, idx + 1 << 2);
	q.push(_S); dis[_S] = 1;
	while (!q.empty()) {
		int t = q.front(); q.pop();
		for (int i = head[t]; i; i = nxt[i])
			if (!dis[to[i]] && val[i]) {
				q.push(to[i]);
				dis[to[i]] = dis[t] + 1;
			}
	}
	return dis[_T] > 0;
}
int dinic(int u, int minv) {
	if (u == _T || !minv) return minv;
	int t, res = 0;
	for (int & i = head[u]; i; i = nxt[i])
		if (val[i] && dis[to[i]] == dis[u] + 1 && (t = dinic(to[i], std::min(minv, val[i])))) {
			val[i] -= t;
			val[i ^ 1] += t;
			res += t;
			minv -= t;
			if (!minv) break;
		}
	if (!res) dis[u] = -1;
	return res;
}
int df = 0;
void _adde(int b, int e, int l, int r) {
	if (l > r) { std::cout << -1 << std::endl; exit(0); }
	l = std::max(l, 0);
	if (r - l) addedge(b, e, r - l);
	if (l) {
		addedge(SS, e, l);
		addedge(b, TT, l);
	}
	df += l;
}
std::map<int, int> col, row, lcol, lrow, hc, hr;
int n, m, R, B, al[MAXN];
inline int get(std::map<int, int> & t, int x) {
	if (!t.count(x)) t[x] = ++idx;
	return t[x];
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m >> R >> B;
	for (int i = 1, x, y; i <= n; ++i) {
		std::cin >> x >> y;
		addedge(get(col, x), get(row, y), 1);
		al[i] = tot;
		++hc[x], ++hr[y];
	}
	for (int i = 1; i <= m; ++i) {
		int opt, x, y;
		std::cin >> opt >> x >> y;
		if (opt == 1) {
			if (!lcol.count(x)) lcol[x] = y;
			else lcol[x] = std::min(lcol[x], y);
		} else {
			if (!lrow.count(x)) lrow[x] = y;
			else lrow[x] = std::min(lrow[x], y);
		}
	}
	S = ++idx, T = ++idx, SS = ++idx, TT = ++idx;
	addedge(T, S, INF); int imp = tot;
	for (auto t : col) {
		int i = t.first, u = t.second;
		int lim = lcol.count(i) ? lcol[i] : hc[i];
		_adde(S, u, (hc[i] - lim + 1) / 2, hc[i] + lim >> 1);
	}
	for (auto t : row) {
		int i = t.first, u = t.second;
		int lim = lrow.count(i) ? lrow[i] : hr[i];
		_adde(u, T, (hr[i] - lim + 1) / 2, hr[i] + lim >> 1);
	}
	_S = SS, _T = TT;
	int td = 0;
	static int te[MAXN];
	memcpy(te, head, idx + 1 << 2);
	while (bfs()) {
		td += dinic(_S, INF);
		memcpy(head, te, idx + 1 << 2);
	}
	if (df != td) return std::cout << "-1" << std::endl, 0;
	_S = S, _T = T; td = val[imp];
	val[imp] = val[imp ^ 1] = 0;
	while (bfs()) {
		td += dinic(_S, INF);
		memcpy(head, te, idx + 1 << 2);
	}
	char buf[2] = {'b', 'r'};
	if (R > B) std::swap(R, B), std::swap(buf[0], buf[1]);
	std::cout << (long long) td * R + (long long) (n - td) * B << std::endl;
	for (int i = 1; i <= n; ++i)
		std::cout << buf[val[al[i]]];
	std::cout << std::endl;
	return 0;
}