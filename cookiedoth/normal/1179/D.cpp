/*

Code for problem longest-path by cookiedoth
Generated 21 Jun 2019 at 06.15 P


  !











o_O
^_^
~_^

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
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int)a.size()

using namespace std;

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

class hull_optimizer {
    /**
     * Line y=a*x+b represented by 2 coefficients a and b
     * and xLeft which is intersection with previous/next line in hull(first line has -INF)
     */
public:
    enum Type {line, maxQuery, minQuery};

    struct Line {
        long long a, b;
        double xLeft;
        long long val;
        Type type;

        explicit Line( long long aa = 0, long long bb = 0 ) : a( aa ), b( bb ), xLeft( -1e16 ), type( line ), val( 0 ) {}
        long long valueAt( long long x ) const { return a * x + b; }
        friend bool areParallel( const Line& l1, const Line& l2 ) { return l1.a == l2.a; }
        friend double intersectX( const Line& l1, const Line& l2 ) { return areParallel( l1, l2 ) ? 1e16 : 1.0 * ( l2.b - l1.b ) / ( l1.a - l2.a ); }
        bool operator<( const Line& l2 ) const {
            if ( l2.type == line )
                return this->a < l2.a;
            if ( l2.type == maxQuery )
                return this->xLeft < l2.val;
            if ( l2.type == minQuery )
                return this->xLeft > l2.val;
        }

        void show() const {
            cout << " [M = " << a << ", C = " << b << ", Type = " << type << ", xLeft = " << xLeft << "] ";
        }
    };

    bool isMax; //whether or not saved envelope is Upper/Max(search of max value) or Lower/Min(search of lower)
    std::set<Line> hull;  //envelope/Hull itself

    std::set<Line>::iterator next( std::set<Line>::iterator it ) { return ++it; }
    std::set<Line>::iterator prev( std::set<Line>::iterator it ) { return --it; }
    bool hasPrev( std::set<Line>::iterator it ) { return it != hull.begin(); }
    bool hasNext( std::set<Line>::iterator it ) { return it != hull.end() && next( it ) != hull.end(); }

    bool irrelevant( const Line& l1, const Line& l2, const Line& l3 ) { return intersectX( l1, l3 ) <= intersectX( l1, l2 ); }
    bool irrelevant( std::set<Line>::iterator it ) {
        return ( ( hasPrev( it ) && hasNext( it ) )
                 && ( ( isMax && irrelevant( *prev( it ), *it, *next( it ) ) )
                      || ( !isMax && irrelevant( *next( it ), *it, *prev( it ) ) ) ) );
    }

    /**
     *Updates intersectionX of line pointed by iterator 'it'
     */
    std::set<Line>::iterator updateLeftBorder( std::set<Line>::iterator it ) {
        if ( ( isMax && !hasPrev( it ) ) || ( !isMax && !hasNext( it ) ) )
            return it;

        double val = intersectX( *it, isMax ? *prev( it ) : *next( it ) );
        Line ModifiedLine( *it );
        __typeof( hull.begin() ) temp_it = it;
        it++;
        hull.erase( temp_it );
        ModifiedLine.xLeft = val;
        it = hull.insert( it, ModifiedLine );
        return it;
    }

    hull_optimizer( bool isMax ): isMax( isMax ) {}
    hull_optimizer(): isMax( false ) {} /**set false for by-default MinHull/LowerHull/LowerEnvelope/BestMin and true for UpperHull */

    /**
     * Adding line to the envelope/Hull
     * Line is of type y=a*x+b represented by 2 coefficients a and b
     */
    void addLine( long long a, long long b ) {
        //find the place where line will be inserted in set
        Line l3 = Line( a, b );
        __typeof( hull.begin() ) it = hull.lower_bound( l3 );
        //if parallel line is already in set, one of them becomes irrelevant
        if ( it != hull.end() && areParallel( *it, l3 ) ) {
            if ( ( isMax && it->b < b ) || ( !isMax && it->b > b ) ) {
                __typeof( hull.begin() ) temp_it = it;
                it++;
                hull.erase( temp_it );
            }
            else return;
        }
        //try to insert
        it = hull.insert( it, l3 );
        if ( irrelevant( it ) ) { hull.erase( it ); return; }
        //remove lines which became irrelevant after inserting line
        while ( hasPrev( it ) && irrelevant( prev( it ) ) ) hull.erase( prev( it ) );
        while ( hasNext( it ) && irrelevant( next( it ) ) ) hull.erase( next( it ) );
        //update the intersectionX of current line with next/prev line
        it = updateLeftBorder( it );
        if ( hasPrev( it ) )
            updateLeftBorder( prev( it ) );
        if ( hasNext( it ) )
            updateLeftBorder( next( it ) );
    }

    long long getBest( long long x ) const {
        Line q;
        q.val = x;
        q.type = isMax ? maxQuery : minQuery;
        __typeof( hull.begin() ) bestLine = hull.lower_bound( q );
        if ( isMax ) --bestLine;
        if( bestLine == hull.end() ) {
            return 1e16;
        }
        return bestLine->valueAt( x );
    }

    void show() const {
        puts( "Now Hull:" );
        for( __typeof( hull.begin() ) it = hull.begin(); it != hull.end(); it++ ) {
            it->show();
        }
        puts( "\n" );
    }
};


const int mx = 5e5 + 228;
const ll INF = 1e18;
ll n;
ll sz[mx], dp[mx], ways0, sum_sq = INF;
vector<vector<int> > g, children;

void hang(int v, int pv) {
	sz[v] = 1;
	for (auto v1 : g[v]) {
		if (v1 != pv) {
			children[v].push_back(v1);
			hang(v1, v);
			sz[v] += sz[v1];
		}
	}
}

ll sqr(ll x) {
	return x * x;
}

void dfs(int v) {
	dp[v] = sz[v] * sz[v];
	for (auto v1 : children[v]) {
		dfs(v1);
		chkmin(dp[v], (sz[v] - sz[v1]) * (sz[v] - sz[v1]) + dp[v1]);
	}
	if (children[v].empty()) {
		return;
	}
	hull_optimizer H;
	for (int i = 0; i < children[v].size(); ++i) {
		int v1 = children[v][i];
		if (i) {
			chkmin(sum_sq, n * n + dp[v1] - 2 * n * sz[v1] + sz[v1] * sz[v1] + H.getBest(2 * sz[v1] - 2 * n));
		}
		H.addLine(sz[v1], dp[v1] + sz[v1] * sz[v1]);
	}
	for (auto v1 : children[v]) {
		chkmin(sum_sq, dp[v1] + sqr((ll)n - sz[v1]));
	}
}

void read() {
	n = readInt();
	g.resize(n);
	children.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		u = readInt();
		v = readInt();
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

void solve() {
	hang(0, 0);
	ways0 = (ll)n * (ll)(n - 1) / 2;
	dfs(0);
	writeInt(ways0 + ((ll)n * (ll)n - sum_sq) / 2);
	writeChar('\n');
}

signed main() {
	fast_io();
	read();
	solve();
}