#define FAST_ALLOCATOR_MEMORY 1e8

/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#define VERSION "0.1.1"

#include <cassert>
#include <cstdio>
#include <algorithm>

/** Fast allocation */

#ifdef FAST_ALLOCATOR_MEMORY
	int allocator_pos = 0;
	char allocator_memory[(int)FAST_ALLOCATOR_MEMORY];
	inline void * operator new ( size_t n ) {
		char *res = allocator_memory + allocator_pos;
		allocator_pos += n;
		assert(allocator_pos <= (int)FAST_ALLOCATOR_MEMORY);
		return (void *)res;
	}
	inline void operator delete ( void * ) { }
	inline void * operator new [] ( size_t ) { assert(0); }
	inline void operator delete [] ( void * ) { assert(0); }
#endif

/** Fast input-output */

template <class T = int> inline T readInt();
inline double readDouble();
inline int readUInt();
inline int readChar();
inline void readWord( char *s );
inline bool readLine( char *s ); // do not save '\n'
inline bool isEof();
inline int peekChar();
inline bool seekEof();

template <class T> inline void writeInt( T x, char end = 0, int len = -1 );
inline void writeChar( int x );
inline void writeWord( const char *s );
inline void writeDouble( double x, int len = 0 );
inline void flush();

static struct buffer_flusher_t {
	~buffer_flusher_t() {
		flush();
	}
} buffer_flusher;

/** Read */

static const int buf_size = 4096;

static char buf[buf_size];
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

inline void readWord( char *s ) {
	int c = readChar();
	while (c > 32)
		*s++ = c, c = getChar();
	*s = 0;
}

inline bool readLine( char *s ) {
	int c = getChar();
	while (c != '\n' && c != -1)
		*s++ = c, c = getChar();
	*s = 0;
	return c != -1;
}

/** Write */

static int write_buf_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
	if (write_buf_pos == buf_size)
		fwrite(write_buf, 1, buf_size, stdout), write_buf_pos = 0;
	write_buf[write_buf_pos++] = x;
}

inline void flush() {
	if (write_buf_pos)
		fwrite(write_buf, 1, write_buf_pos, stdout), write_buf_pos = 0;
}

template <class T>
inline void writeInt( T x, char end, int output_len ) {
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

inline void writeWord( const char *s ) {
	while (*s)
		writeChar(*s++);
}

inline void writeDouble( double x, int output_len ) {
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


#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 1e5 + 7;

string s;
int h, mid, a[1000];

char ans[300][1000];

void draw(int pos, int cnt, int dir){
    for (int i = 0; i < cnt; i++)
        ans[mid + i][pos] = ans[mid - i][pos] = '|';
    ans[mid + cnt][pos] = ans[mid - cnt][pos] = '+';
    ans[mid + cnt][pos + dir] = ans[mid - cnt][pos + dir] = '-';
}


int main(){
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    //freopen("next.out", "w", stdout);
    int n, balance = 0, max_bal = 0;
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++){
        balance += (s[i]=='[' ? 1 : -1);
        a[i] = balance + (s[i]=='[' ? -1 : 0);
        max_bal = max(max_bal, balance);
    }

    h = max_bal * 2 + 1;
    mid = max_bal;

    for (int i = 0; i < n * 5; i++)
        for (int j = 0; j < h; j++)
            ans[j][i] = ' ';
    int pos = 0;
    for (int i = 0; i < n; i++){
        a[i] = max_bal - a[i];
        if (i > 0 && s[i - 1] == '[' && s[i] == ']')
            pos += 3;               // cause '+-_-' and next is to draw on
        draw(pos++, a[i], s[i] == '[' ? 1 : -1);
    }

    for (int i = 0; i < h; i++){
        for (int j = 0; j < pos; j++)
            writeChar(ans[i][j]);
        writeChar('\n');
    }
}