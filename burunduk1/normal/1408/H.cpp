#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) a.begin(), a.end()

template <class T = int> inline T readInt(); 
template <class T> inline void writeInt( T x, char end = 0 );

int solve() {
	int n = readInt();
	vector<int> zeroes, a(n);
	zeroes.reserve(n);
	forn(i, n) {
		a[i] = readInt();
		if (!a[i])
			zeroes.push_back(i);
	}
	int zn = zeroes.size();
	if (zn < 2)
		return 0;
	int mid = zeroes[zn / 2], ans = 0;
	vector<int> first(n + 1);
	priority_queue<pair<int, int>> s;
	forn(i, mid)
		first[a[i]] = i; // rightmost in left half
	for (int i = mid; i < n; i++)
		if (!a[i]) {
			if (s.size()) {
				first[s.top().second] = -1, ans++;
				s.pop();
			}
		} else if (first[a[i]] >= 0) {
			s.push({-first[a[i]], a[i]});
			first[a[i]] = -2; // pushed but not used
		}
	for (int cnt = 0, i = mid - 1; i >= 0; i--) {
		if (!a[i]) {
			if (cnt)
				cnt--, ans++;
		}
		else if (first[a[i]] != -1)
			cnt++, first[a[i]] = -1;
	}
	return min(ans, zn / 2);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int t = readInt();
	while (t--)
		writeInt(solve(), '\n');
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