/*

Code for problem C by cookiedoth
Generated 26 Mar 2020 at 11.45 AM


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

>_<
o_O
^_^

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#include <random>
#include <cstring>
#include <numeric>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

template<class T> int chkmax(T &a, T b) {
	if (b > a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class T> int chkmin(T &a, T b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class iterator> void output(iterator begin, iterator end, ostream& out = cerr) {
	while (begin != end) {
		out << (*begin) << " ";
		begin++;
	}
	out << endl;
}

template<class T> void output(T x, ostream& out = cerr) {
	output(x.begin(), x.end(), out);
}

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

/** Fast input-output */

template <class T = int> inline T readInt();						
inline double readDouble();
inline int readUInt();					 
inline int readChar(); // first non-blank character
inline void readWord(char *s); 
inline bool readLine(char *s); // do not save '\n'
inline bool isEof();
inline int getChar(); 
inline int peekChar();
inline bool seekEof();
inline void skipBlanks();

template <class T> inline void writeInt(T x, char end = 0, int len = -1);
inline void writeChar(int x); 
inline void writeWord(const char *s);
inline void writeDouble(double x, int len = 0);
inline void flush();

static struct buffer_flusher_t {
	~buffer_flusher_t() {
		flush();
	}
} buffer_flusher;

/** Read */

static const int buf_size = 4096;

static unsigned char buf[buf_size];
static int buf_len = 0, buf_pos = 0;

inline bool isEof() {
	if (buf_pos == buf_len) {
		buf_pos = 0, buf_len = fread(buf, 1, buf_size, stdin);
		if (buf_pos == buf_len)
			return 1;
	}
	return 0;
}

inline int getChar() { 
	return isEof() ? -1 : buf[buf_pos++];
}

inline int peekChar() { 
	return isEof() ? -1 : buf[buf_pos];
}

inline bool seekEof() { 
	int c;
	while ((c = peekChar()) != -1 && c <= 32)
		buf_pos++;
	return c == -1;
}

inline void skipBlanks() {
	while (!isEof() && buf[buf_pos] <= 32U)
		buf_pos++;
}

inline int readChar() {
	int c = getChar();
	while (c != -1 && c <= 32)
		c = getChar();
	return c;
}

inline int readUInt() {
	int c = readChar(), x = 0;
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return x;
}

template <class T>
inline T readInt() {
	int s = 1, c = readChar();
	T x = 0;
	if (c == '-')
		s = -1, c = getChar();
	else if (c == '+')
		c = getChar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return s == 1 ? x : -x;
}

inline double readDouble() {
	int s = 1, c = readChar();
	double x = 0;
	if (c == '-')
		s = -1, c = getChar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	if (c == '.') {
		c = getChar();
		double coef = 1;
		while ('0' <= c && c <= '9')
			x += (c - '0') * (coef *= 1e-1), c = getChar();
	}
	return s == 1 ? x : -x;
}

inline void readWord(char *s) { 
	int c = readChar();
	while (c > 32)
		*s++ = c, c = getChar();
	*s = 0;
}

inline bool readLine(char *s) { 
	int c = getChar();
	while (c != '\n' && c != -1)
		*s++ = c, c = getChar();
	*s = 0;
	return c != -1;
}

/** Write */

static int write_buf_pos = 0;
static char write_buf[buf_size];

inline void writeChar(int x) {
	if (write_buf_pos == buf_size)
		fwrite(write_buf, 1, buf_size, stdout), write_buf_pos = 0;
	write_buf[write_buf_pos++] = x;
}

inline void flush() {
	if (write_buf_pos) {
		fwrite(write_buf, 1, write_buf_pos, stdout), write_buf_pos = 0;
		fflush(stdout);
	}
}

template <class T> 
inline void writeInt(T x, char end, int output_len) {
	if (x < 0)
		writeChar('-'), x = -x;

	char s[24];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n < output_len)
		s[n++] = '0';
	while (n--)
		writeChar(s[n]);
	if (end)
		writeChar(end);
}

inline void writeWord(const char *s) {
	while (*s)
		writeChar(*s++);
}

inline void writeDouble(double x, int output_len) {
	if (x < 0)
		writeChar('-'), x = -x;
	int t = (int)x;
	writeInt(t), x -= t;
	writeChar('.');
	for (int i = output_len - 1; i > 0; i--) {
		x *= 10;
		t = std::min(9, (int)x);
		writeChar('0' + t), x -= t;
	}
	x *= 10;
	t = std::min(9, (int)(x + 0.5));
	writeChar('0' + t);
}

const int lg = 19;
const int mx = 3e5 + 228;

namespace treeX {
	vector<int> cmp;
	vector<vector<int> > *g1, *g2, g;
	int n, cmp_cnt = 0;

	void dfs1(int v) {
		cmp[v] = cmp_cnt;
		for (auto v1 : (*g1)[v]) {
			if (cmp[v1] == -1) {
				dfs1(v1);
			}
		}
	}

	set<pair<int, int> > tree_edges;

	void add_edge(int u, int v) {
		if (u > v) {
			swap(u, v);
		}
		if (tree_edges.find({u, v}) != tree_edges.end()) {
			return;
		}
		g[u].push_back(v);
		g[v].push_back(u);
		tree_edges.insert({u, v});
	}

	int level[mx], sz[mx], par[mx][lg], dist[mx][lg];

	void calc_sz(int v, int pv) {
		sz[v] = 1;
		for (auto v1 : g[v]) {
			if (level[v1] == -1 && v1 != pv) {
				calc_sz(v1, v);
				sz[v] += sz[v1];
			}
		}
	}

	int find_centroid(int v) {
		int pv = v, all_sz = sz[v];
		while (true) {
			int found = 0;
			for (auto v1 : g[v]) {
				if (v1 != pv && level[v1] == -1 && 2 * sz[v1] >= all_sz) {
					pv = v;
					v = v1;
					found = 1;
					break;
				}
			}
			if (!found) {
				break;
			}
		}
		return v;
	}

	int base_level;

	void dist_dfs(int v, int pv, int d) {
		dist[v][base_level] = d;
		for (auto v1 : g[v]) {
			if (level[v1] == -1 && pv != v1) {
				dist_dfs(v1, v, d + 1);
			}
		}
	}

	void build_decomposition(int v, int pc, int cur_level) {
		calc_sz(v, v);
		int c = find_centroid(v);
		level[c] = cur_level;
		for (int i = 0; i < level[c]; ++i) {
			par[c][i] = par[pc][i];
		}
		par[c][cur_level] = c;
		base_level = level[c];
		dist_dfs(c, c, 0);
		for (auto v1 : g[c]) {
			if (level[v1] == -1) {
				build_decomposition(v1, c, cur_level + 1);
			}
		}
	}

	void init(int _n, vector<vector<int> > *_g1, vector<vector<int> > *_g2) {
		g1 = _g1;
		g2 = _g2;
		n = _n;
		cmp.resize(n, -1);
		for (int i = 0; i < n; ++i) {
			if (cmp[i] == -1) {
				dfs1(i);
				cmp_cnt++;
			}
		}
		g.resize(cmp_cnt);
		for (int i = 0; i < n; ++i) {
			for (auto v : (*g2)[i]) {
				if (cmp[i] != cmp[v]) {
					add_edge(cmp[i], cmp[v]);
				}
			}
		}

		fill(level, level + cmp_cnt, -1);
		build_decomposition(0, -1, 0);

		// cerr << "decomposition: " << endl;
		// cerr << "level" << endl;
		// output(level, level + cmp_cnt);
	}
};

namespace treeY {
	vector<int> cmp;
	vector<vector<int> > *g1, *g2, g;
	int n, cmp_cnt = 0;

	void dfs1(int v) {
		cmp[v] = cmp_cnt;
		for (auto v1 : (*g1)[v]) {
			if (cmp[v1] == -1) {
				dfs1(v1);
			}
		}
	}

	set<pair<int, int> > tree_edges;

	void add_edge(int u, int v) {
		if (u > v) {
			swap(u, v);
		}
		if (tree_edges.find({u, v}) != tree_edges.end()) {
			return;
		}
		g[u].push_back(v);
		g[v].push_back(u);
		tree_edges.insert({u, v});
	}

	int level[mx], sz[mx], par[mx][lg], dist[mx][lg];

	void calc_sz(int v, int pv) {
		sz[v] = 1;
		for (auto v1 : g[v]) {
			if (level[v1] == -1 && v1 != pv) {
				calc_sz(v1, v);
				sz[v] += sz[v1];
			}
		}
	}

	int find_centroid(int v) {
		int pv = v, all_sz = sz[v];
		while (true) {
			int found = 0;
			for (auto v1 : g[v]) {
				if (v1 != pv && level[v1] == -1 && 2 * sz[v1] >= all_sz) {
					pv = v;
					v = v1;
					found = 1;
					break;
				}
			}
			if (!found) {
				break;
			}
		}
		return v;
	}

	int base_level;

	void dist_dfs(int v, int pv, int d) {
		dist[v][base_level] = d;
		for (auto v1 : g[v]) {
			if (level[v1] == -1 && pv != v1) {
				dist_dfs(v1, v, d + 1);
			}
		}
	}

	void build_decomposition(int v, int pc, int cur_level) {
		calc_sz(v, v);
		int c = find_centroid(v);
		level[c] = cur_level;
		for (int i = 0; i < level[c]; ++i) {
			par[c][i] = par[pc][i];
		}
		par[c][cur_level] = c;
		base_level = level[c];
		dist_dfs(c, c, 0);
		for (auto v1 : g[c]) {
			if (level[v1] == -1) {
				build_decomposition(v1, c, cur_level + 1);
			}
		}
	}

	void init(int _n, vector<vector<int> > *_g1, vector<vector<int> > *_g2) {
		g1 = _g1;
		g2 = _g2;
		n = _n;
		cmp.resize(n, -1);
		for (int i = 0; i < n; ++i) {
			if (cmp[i] == -1) {
				dfs1(i);
				cmp_cnt++;
			}
		}
		g.resize(cmp_cnt);
		for (int i = 0; i < n; ++i) {
			for (auto v : (*g2)[i]) {
				if (cmp[i] != cmp[v]) {
					add_edge(cmp[i], cmp[v]);
				}
			}
		}

		fill(level, level + cmp_cnt, -1);
		build_decomposition(0, -1, 0);

		// cerr << "decomposition: " << endl;
		// cerr << "level" << endl;
		// output(level, level + cmp_cnt);
	}
};

int n, X[mx], Y[mx];
map<pair<int, int>, int> cells;

void read_cells() {
	n = readInt();
	for (int i = 0; i < n; ++i) {
		X[i] = readInt();
		Y[i] = readInt();
		cells[{X[i], Y[i]}] = i;
	}
}

vector<vector<int> > hor_g, vert_g, g;
vector<int> deltas = {-1, 1};

void build_graphs() {
	hor_g.resize(n);
	vert_g.resize(n);
	g.resize(n);
	for (int i = 0; i < n; ++i) {
		for (auto dy : deltas) {
			if (cells.find({X[i], Y[i] + dy}) != cells.end()) {
				int v = cells[{X[i], Y[i] + dy}];
				vert_g[i].push_back(v);
				g[i].push_back(v);
			}
		}
		for (auto dx : deltas) {
			if (cells.find({X[i] + dx, Y[i]}) != cells.end()) {
				int v = cells[{X[i] + dx, Y[i]}];
				hor_g[i].push_back(v);
				g[i].push_back(v);
			}
		}
	}
}

const int INF = 1e9 + 228;
int q, ans[mx];
vector<pair<int, int> > queries;

void read_queries() {
	q = readInt();
	queries.resize(q);
	for (int i = 0; i < q; ++i) {
		int t, x, y;
		t = readInt();
		x = readInt();
		y = readInt();
		queries[i].first = t;
		queries[i].second = cells[{x, y}];
	}
}

vector<vector<int> > vv;
int min_path[mx], du[mx], du_ptr;

ld t0 = clock();

ld watch() {
	return ((ld)clock() - t0) / CLOCKS_PER_SEC;
}

void solve() {
	treeX::init(n, &hor_g, &vert_g);
	treeY::init(n, &vert_g, &hor_g);
	vv.resize(n);
	fill(ans, ans + q, INF);
	for (int L1 = 0; L1 < lg; ++L1) {
		for (int i = 0; i < n; ++i) {
			vv[i].clear();
		}
		for (int i = 0; i < q; ++i) {
			int vx = treeX::cmp[queries[i].second];
			if (treeX::level[vx] >= L1) {
				vv[treeX::par[vx][L1]].push_back(i);
			}
		}
		for (auto v : vv) {
			du_ptr++;
			for (auto id : v) {
				int vx = treeX::cmp[queries[id].second];
				int vy = treeY::cmp[queries[id].second];
				int dist0 = treeX::dist[vx][L1];
				for (int i = 0; i <= treeY::level[vy]; ++i) {
					int cur = dist0 + treeY::dist[vy][i], pc = treeY::par[vy][i];
					if (queries[id].first == 1) {
						if (du[pc] != du_ptr) {
							min_path[pc] = cur;
							du[pc] = du_ptr;
						} else {
							chkmin(min_path[pc], cur);
						}
					} else {
						if (du[pc] == du_ptr) {
							chkmin(ans[id], cur + min_path[pc]);
						}
					}
				}
			}
		}
	}
}

void print_ans() {
	for (int i = 0; i < q; ++i) {
		if (queries[i].first == 2) {
			if (ans[i] == INF) {
				writeInt(-1, '\n');
			} else {
				writeInt(ans[i], '\n');
			}
		}
	}
}

signed main() {
	fast_io();
	read_cells();
	build_graphs();
	read_queries();
	solve();
	print_ans();
}