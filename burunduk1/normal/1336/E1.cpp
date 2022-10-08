// #define _GLIBCXX_DEBUG

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,tune=native")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (n); i++)
#define IS(a, i) (((a) >> (i)) & 1)
#define err(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

const int BUF_SIZE = 4096;
int readChar() {
	static unsigned char buf[BUF_SIZE];
	static int buf_pos = 0, buf_len = 0;
	if (buf_pos == buf_len) {
		buf_pos = 0;
		buf_len = fread(buf, 1, BUF_SIZE, stdin);
		if (!buf_len)
			return -1;
	}
	return buf[buf_pos++];
}

template<class T = int>
T readInt() {
	T x = 0;
	int c;
	while ((c = readChar()) <= 32)
		;
	while (c > 32)
		x = x * 10 + c - '0', c = readChar();
	return x;
}

const int MOD = 998244353;

int mul(int a, int b) {
	return (int64_t)a * b % MOD;
}
void add(int &a, int b) {
	if ((a += b) >= MOD)
		a -= MOD;
}

int dp[36][1 << 16];

int main() {
	ios_base::sync_with_stdio(0);
	int n = readInt();
	int m = readInt();
	int k = 0;
	vector<int64_t> a(m + 1), b(m);
	vector<int> p(m), u(m);
	forn(i, n) {
		a[k] = readInt<int64_t>();
		forn(j, k)
			if (IS(a[k], p[j]))
				a[k] ^= a[j];
		if (a[k]) {
			p[k] = 0;
			while (!IS(a[k], p[k]))
				p[k]++;
			u[p[k]] = 1;
			forn(j, k)
				if (IS(a[j], p[k]))
					a[j] ^= a[k];
			k++;
		}
	}
	forn(i, k) {
		int pos = 0;
		forn(j, m)
			if (!u[j])
				b[i] |= IS(a[i], j) << pos++;
		assert(pos == m - k);
	}

	vector<int> ans(m + 1);
	int ma = min(k, 18);
	err("k=%d m=%d ma=%d\n", k, m, ma);
	if (k <= ma) {
		err("case 1\n");
		if (m - k <= 31) {
			int x = 0, cnt = 0;
			ans[0]++;
			for (int i = 1; i < (1 << k); i++) {
				int j = 0;
				while (!IS(i, j))
					cnt--, x ^= b[j], j++;
				cnt++, x ^= b[j];
				ans[cnt + __builtin_popcount(x)]++;
			}
		} else {
			forn(i, 1 << k) {
				int64_t x = 0;
				forn(j, k)
					if (IS(i, j))
						x ^= a[j];
				ans[__builtin_popcountll(x)]++;
			}
		}
	} else {
		err("case 2\n");
		int x = 0, cnt = 0;
		dp[0][0]++;
		for (int i = 1; i < (1 << ma); i++) {
			int j = 0;
			while (!IS(i, j))
				cnt--, x ^= b[j], j++;
			cnt++, x ^= b[j];
			dp[cnt][x]++;
		}
		for (int i = ma; i < k; i++)
			for (int j = i; j >= 0; j--)
				forn(mask, 1 << (m - k))
					add(dp[j + 1][mask ^ b[i]], dp[j][mask]);
		forn(j, k + 1)
			forn(mask, 1 << (m - k))
				add(ans[j + __builtin_popcount(mask)], dp[j][mask]);
	}

	int pow = 1;
	forn(i, n - k)
		pow = mul(pow, 2);
	for (int x : ans)
		cout << mul(x, pow) << " ";
	cout << endl;
}