/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

// #define _GLIBCXX_DEBUG
// #define DEBUG 1
#include <bits/stdc++.h>

// #define err(...) fprintf(stderr, "%.2f : ", 1. * clock() / CLOCKS_PER_SEC), fprintf(stderr, __VA_ARGS__), fflush(stderr)

// #define DEBUG

/** Begin fast allocation */
// const int MAX_MEM = 1e8;
// int mpos = 0;
// char mem[MAX_MEM];
// inline void * operator new ( size_t n ) {
// 	assert((mpos += n) <= MAX_MEM);
// 	return (void *)(mem + mpos - n);
// }
// inline void operator delete ( void * ) { } // must have!
/** End fast allocation */

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
typedef pair<int, int> pii;

const ll INF = 1e18;

// int cnt1 = 0, cnt2 = 0;

inline int readChar();
template <class T = int> inline T readInt(); 
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x ); 
inline void writeWord( const char *s );

const int MAX = 1e6 + 10;

int pos, qnext[MAX], qhead[MAX], qv[MAX];

int main() {
	int n, m, queries;
	#ifdef DEBUG
	n = 0.5e5, m = 1e5, queries = 2000;
	#else
	n = readInt();
	m = readInt();
	queries = readInt();
	#endif

	int head[n], next[m], to[m], w[m];
	memset(head, -1, sizeof(head));
	// puts("start");
	forn(i, m) {
		#ifdef DEBUG
		int a = rand() % n, b = rand() % n, c = rand() % 10000;
		#else
		int a = readInt();
		int b = readInt();
		int c = readInt();
		a--, b--;
		#endif
		w[i] = c, to[i] = b, next[i] = head[a], head[a] = i;
	}
	ll d[n];
	auto Dijkstra = [&]() {
		set<pii> s;
		fill(d, d + n, INF);
		s.insert(pii(d[0] = 0, 0));
		while (s.size()) {
			int v = s.begin()->second;
			s.erase(s.begin());
			for (int i = head[v]; i != -1; i = next[i]) {
				if (d[to[i]] > d[v] + w[i]) {
					s.erase(pii(d[to[i]], to[i]));
					s.insert(pii(d[to[i]] = d[v] + w[i], to[i]));
				}
			}
		}
	};
	// puts("0 OK");
	Dijkstra();
	// puts("1 OK");
	// err("=)\n");

	int k = 0, res[n];
	// puts("!");
	auto bfs = [&]() {
		// puts("bfs!");
		memset(qhead, -1, sizeof(qhead[0]) * (k + 1));
		pos = 0;
		fill(res, res + n, 1e9);
		res[0] = 0;
		auto addq = [&]( int i, int v ) {
			qnext[pos] = qhead[i], qv[pos] = v, qhead[i] = pos++;
		};
		addq(0, 0);
		// int cnt1 = 0, cnt2 = 0;
		// printf("k = %d\n", k);
		forn(dist, k + 1) 
			while (qhead[dist] != -1) {
				int p = qhead[dist];
				int v = qv[p];
				qhead[dist] = qnext[p];
				// printf("v = %d : dist = %d\n", v, dist);
				if (res[v] != dist)
					continue;
				// assert(++cnt1 <= n);
				for (int i = head[v]; i != -1; i = next[i]) {
					// assert(++cnt2 <= m);
					int tmp;
					if (res[to[i]] > (tmp = d[v] + res[v] + w[i] - d[to[i]])) {
						// printf("to[i] = %d, tmp = %d of %d [%lld + %d + %d - %lld]\n", to[i], tmp, k, d[v], res[v], w[i], d[to[i]]);
						if (tmp > k) continue;
						// assert(0 <= tmp && tmp <= k);
						res[to[i]] = tmp, addq(tmp, to[i]);
					}
				}
			}
		// forn(i, n)
		// 	printf("%d ", res[i]);
		// puts("");
		forn(i, n)
			if (d[i] != INF)
				d[i] += res[i];
	};

	while (queries--) {
		int type;
		#ifdef DEBUG
		type = 2;
		#else
		type = readInt();
		#endif
		if (type == 1) {
			int v = readInt();
			if (d[v - 1] == INF)
				puts("-1");
			else {
				if (k > 0)
					bfs(), k = 0;
				printf("%lld\n", d[v - 1]);
			}
		} else {
			int cnt, i;
			#ifdef DEBUG
			cnt = 2000;
			#else
			cnt = readInt();
			#endif
			forn(_, cnt) {
				#ifdef DEBUG
				i = rand() % m;
				#else
				i = readInt() - 1;
				#endif
				w[i]++;
			}
			k += cnt;
			// Dijkstra();
			// continue;
			// bfs();
		}
	}
	// err("cnt1 = %g\n", (double)cnt1);
	// err("cnt2 = %g\n", (double)cnt2);
}

/** Read */

static const int buf_size = 4096;

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