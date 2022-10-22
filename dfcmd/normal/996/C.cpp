#include <bits/stdc++.h>

const int N = 55, M = ::N << 1;

struct Node {
	int x, y;
	
	Node() { x = 0, y = 0; }
	Node(int _x, int _y) : x(_x), y(_y) {}
	
	Node operator + (const Node &rhs) const {
		return Node(x + rhs.x, y + rhs.y);
	}
	
	bool operator == (const Node &rhs) const {
		return x == rhs.x && y == rhs.y;
	}
};

const Node delta[4] = {Node(-1, 0), Node(1, 0), Node(0, -1), Node(0, 1)};

int n, m;
Node s[M], t[M];
bool finished[M];
int id[2][N];
std::vector<std::pair<int, Node>> ans;

bool work(Node now, int dir) {
	Node st = now + delta[dir];
	static bool vis[2][N];
	static Node lst[2][N];
	for (int i = 0; i < n; ++i) {
		vis[0][i] = vis[1][i] = 0;
	}
	vis[now.x][now.y] = 1;
	std::vector<Node> Q;
	Q.push_back(st);
	vis[st.x][st.y] = 1;
	lst[st.x][st.y] = now;
	Node ed(-1, -1);
	for (int i = 0; i < (int)Q.size(); ++i) {
		Node u = Q[i];
		if (id[u.x][u.y] == -1) {
			ed = u;
			break;
		}
		for (int j = 0; j < 4; ++j) {
			Node v = u + delta[j];
			if (0 <= v.x && v.x < 2 && 0 <= v.y && v.y < n && !vis[v.x][v.y]) {
				vis[v.x][v.y] = 1;
				lst[v.x][v.y] = u;
				Q.push_back(v);
			}
		}
	}
	if (ed.x == -1) {
		return false;
	}
	while (!(ed == now)) {
		Node u = lst[ed.x][ed.y];
		ans.push_back({id[u.x][u.y], ed});
		id[ed.x][ed.y] = id[u.x][u.y];
		s[id[u.x][u.y]] = ed;
		id[u.x][u.y] = -1;
		ed = u;
	}
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int x;
		std::cin >> x;
		--x;
		if (x != -1) {
			t[x] = Node(0, i);
		}
	}
	for (int i = 0; i < n; ++i) {
		int x;
		std::cin >> x;
		--x;
		if (x != -1) {
			s[x] = Node(0, i);
		}
		id[0][i] = x;
	}
	for (int i = 0; i < n; ++i) {
		int x;
		std::cin >> x;
		--x;
		if (x != -1) {
			s[x] = Node(1, i);
		}
		id[1][i] = x;
	}
	for (int i = 0; i < n; ++i) {
		int x;
		std::cin >> x;
		--x;
		if (x != -1) {
			t[x] = Node(1, i);
		}
	}
	
	int cnt = m;
	while (cnt) {
		bool has_moved = false;
		for (int i = 0; i < m; ++i) {
			if (finished[i]) {
				continue;
			}
			bool ok = true;
			while (s[i].y != t[i].y && ok) {
				if (!work(Node(s[i].x, s[i].y), 2 + (s[i].y < t[i].y))) {
					ok = false;
				}
			}
			while (s[i].x != t[i].x && ok) {
				if (!work(Node(s[i].x, s[i].y), s[i].x < t[i].x)) {
					ok = false;
				}
			}
			if (!ok) {
				continue;
			}
			finished[i] = true;
			has_moved = true;
			--cnt;
			if (t[i].x == 0) {
				ans.push_back({i, Node(-1, t[i].y)});
			} else {
				ans.push_back({i, Node(2, t[i].y)});
			}
			id[t[i].x][t[i].y] = -1;
		}
		if (!has_moved && cnt) {
			std::cout << -1 << "\n";
			return 0;
		}
	}
	std::cout << ans.size() << "\n";
	for (auto v : ans) {
		std::cout << v.first + 1 << " " << v.second.x + 2 << " " << v.second.y + 1 << "\n";
	}
}