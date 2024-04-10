#include <bits/stdc++.h>
    /** Interface */

inline int readChar();
template <class T = int> inline T getInt(); 

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
inline T getInt() {
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

using namespace std;
 
#define re return
#define sz(a) (int)a.size()
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef double ld;
 
const int mod = int(1e9) + 7, szz = 2 * 1024 * 1024;
 
int get_int() {
	int k;
	scanf("%d", &k);
	re k;
}

ll n, k[szz];
string s;

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> n;
	forn (i, n) {
		char c;
		cin >> c;
		if (c == '+' || c == '-') {
			ll pp;
			cin >> pp;
			ll kk = 0;
			forn (i, 19) {
				kk = kk * 2LL + pp % 2LL;
				pp /= 10;
			}
			if (c == '+') k[kk]++;
			else
				k[kk]--;
		}
		else {
			string s;
			cin >> s;
			reverse(s.begin(), s.end());
			while (sz(s) < 19) s += "0";
			int kk = 0;
			forn (i, 19)
				kk = kk * 2LL + ll(s[i] - '0');
			cout << k[kk] << "\n";
		}
	}
	re 0;
}