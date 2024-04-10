#pragma GCC optimize(2,3,"Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= int(b); i++)
#define per(i, a, b) for (int i = (a); i >= int(b); i--)
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
int T, f[70][3], bin[5][5] = { { 1 }, { 1, 1 }, { 1, 2, 1 }, { 1, 3, 3, 1 } };
ll m;

inline void reduce(int &x) {
	x += x >> 31 & mod;
}

template<int LIM>
struct fast_io {
	char ib[LIM], ob[LIM], *p1, *p2, *q1, *q2;
	fast_io() {
		p1 = p2 = ib;
		q1 = ob;
		q2 = ob + LIM;
	}
	inline char gc() {
		return p1 == p2 && (p2 = (p1 = ib) + fread(ib, 1, LIM, stdin), p1 == p2) ? EOF : *p1++;
	}
	inline void pc(char ch) {
		if (q1 == q2) q2 = (q1 = ob) + fwrite(ob, 1, LIM, stdout);
		*q1++ = ch;
	}
	~fast_io() {
		fwrite(ob, 1, q1 - ob, stdout);
	}
};

fast_io<1000000> io;

ll read() {
	ll x = 0;
	char ch;
	do ch = io.gc(); while (ch < '0' || ch > '9');
	do x = 10 * x + (ch & 15), ch = io.gc(); while (ch >= '0' && ch <= '9');
	return x;
}

void write(int x) {
	if (x / 10) write(x / 10);
	io.pc('0' + x % 10);
}

int main() {
	T = read();
	while (T --> 0) {
		m = read();
		memset(f, 0, sizeof(f));
		f[0][0] = 1;
		rep(i, 0, 59) rep(j, 0, 2) rep(k, 0, min(i + 1, 3)) if (((j + k) & 1) == (m >> i & 1)) {
			reduce(f[i + 1][(j + k) >> 1] += 1ll * bin[min(i + 1, 3)][k] * f[i][j] % mod - mod);
		}
		write(f[60][0]), io.pc('\n');
	}
	return 0;
}