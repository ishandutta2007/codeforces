//  Copyright 2020 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

template <class A, class B>
bool smin(A &x, B &&y) {
  if (y < x) {
    x = y;
    return true;
  }
  return false;
}

template <class A, class B>
bool smax(A &x, B &&y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}

/** Interface */

inline int readChar();
template <class T = int> inline T readInt();
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x );
inline void writeWord( const char *s );

/** Read */

static const int buf_size = 1 << 17;

inline int getChar() {
	static char buf[buf_size];
	static int len = 0, pos = 0;
	if (pos == len)
		pos = 0, len = fread(buf, 1, buf_size, stdin);
	if (pos == len)
		return -1;
	return buf[pos++];
}

inline int readChar() {
	int c = getChar();
	while (c <= 32)
		c = getChar();
	return c;
}

template <class T>
inline T readInt() {
	int s = 1, c = readChar();
	T x = 0;
	if (c == '-')
		s = -1, c = getChar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return s == 1 ? x : -x;
}

/** Write */

static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
	if (write_pos == buf_size)
		fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
	write_buf[write_pos++] = x;
}

template <class T>
inline void writeInt( T x, char end ) {
	if (x < 0)
		writeChar('-'), x = -x;

	char s[24];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n--)
		writeChar(s[n]);
	if (end)
		writeChar(end);
}

inline void writeWord( const char *s ) {
	while (*s)
		writeChar(*s++);
}

struct Flusher {
	~Flusher() {
		if (write_pos)
			fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
	}
} flusher;

struct dsu {
  int n;
  vector<int> sz;
  vector<int> p;
  int nsets;
  vector<tuple<int*, int, int>> changes;
  int cur_t = 0;

  dsu(int n_) : n(n_), sz(n), p(n), nsets(n) {
    iota(p.begin(), p.end(), 0);
    fill(sz.begin(), sz.end(), 1);
  }

  int find(int v) const {
    return p[v] == v ? v : find(p[v]);
  }

  void set(int* ptr, int val, int t) {
    changes.emplace_back(ptr, *ptr, t);
    *ptr = val;
  }

  void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
      set(&nsets, nsets - 1, cur_t);
      if (sz[u] < sz[v]) swap(u, v);
      set(&sz[u], sz[u] + sz[v], cur_t);
      set(&p[v], u, cur_t);
    }
    ++cur_t;
  }

  void rollback(int bound = 0) {
    while (!changes.empty()) {
      auto[ptr, val, t] = changes.back();
      if (t < bound) break;
      *ptr = val;
      changes.pop_back();
    }
  }
};

int const N = 1 << 19;

vector<pair<int, int>> st[N << 1];
bool is_q[N];
int ans[N];

void add(int v, int l, int r, int ql, int qr, pair<int, int> e) {
  if (l >= qr || ql >= r) return;
  if (ql <= l && r <= qr) {
    st[v].push_back(e);
    return;
  }
  int m = (l + r) / 2;
  add(2 * v, l, m, ql, qr, e);
  add(2 * v + 1, m, r, ql, qr, e);
}

int time_by_day[N];
tuple<int, int, int, int> edges[N];
int who[N];

void dfs(dsu& dsu, int v, int l, int r) {
  int tt = dsu.cur_t;
  for (auto[a, b] : st[v]) {
    dsu.unite(a, b);
  }
  if (l + 1 == r) {
    if (is_q[l]) {
      ans[l] = dsu.sz[dsu.find(who[l])];
    }
  } else {
    int m = (l + r) / 2;
    dfs(dsu, 2 * v, l, m);
    dfs(dsu, 2 * v + 1, m, r);
  }
  dsu.rollback(tt);
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif

  int n = readInt();
  int q = readInt();
  int k = readInt();

  int cur_day = 0;
  int ptr = 0;
  for (int i = 0; i < q; ++i) {
    int t = readInt();
    if (t == 1) {
      int u = readInt() - 1;
      int v = readInt() - 1;
      edges[ptr++] = make_tuple(u, v, i, cur_day + k);
    } else if (t == 2) {
      int z = readInt() - 1;
      is_q[i] = true;
      who[i] = z;
    } else {
      time_by_day[++cur_day] = i;
    }
  }
  for (int i = 0; i < ptr; ++i) {
    auto[u, v, l, d] = edges[i];
    if (d <= cur_day) {
      d = time_by_day[d];
    } else {
      d = q;
    }
    add(1, 0, N, l, d, make_pair(u, v));
  }
  dsu dsu(n);
  dfs(dsu, 1, 0, N);
  for (int i = 0; i < q; ++i) {
    if (is_q[i]) {
      writeInt(ans[i], '\n');
    }
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}