//vsp
#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b) - 1; (a) <= i; i--)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define sz(x) int(x.size())
using ll = long long;
using namespace std;

template<class T>
struct RMinQ {
	vector<vector<T>> t;
	void init(vector<T> a) {
		int n = a.size();
		int m = __lg(n) + 1;
		t = vector<vector<T>> (n, vector<T>(m));
		FOR(i, n) t[i][0] = a[i];
		FOR(j, m - 1)
			FOR(i, n - (1 << j)) {
				t[i][j + 1] = min(t[i][j], t[i + (1 << j)][j]);
			}
	}
	int level(int x) {
		return 31 - __builtin_clz(x);
	}
	T query(int l, int r) {
		int d = level(r - l + 1);
		return min(t[l][d], t[r - (1 << d) + 1][d]);
	}
};

/*complexity: O(n log n)
* x[k] - rank of the k-th suffix
* sa[k] - position of the k-th smallest suffix
* numeration [0, n)
*/
struct SuffixArray {
	int n;
	vector<int> sa, x, lcp;
	RMinQ<int> T;

	void init (string s) {
		n = s.size();
		int m = 26;
		vector<int> y(n), cnt(max(n, m));
		sa.resize(n);
		x.resize(n);
		lcp.resize(n);
		rep(i, 0, m) cnt[i] = 0;
		rep(i, 0, n) cnt[x[i] = s[i] - 'a']++;
		rep(i, 1, m) cnt[i] += cnt[i - 1];
		per(i, 0, n) sa[--cnt[x[i]]] = i;

		for (int k = 1; k < n; k *= 2) {
			int p = 0;
			rep(i, n - k, n) y[p++] = i;
			rep(i, 0, n) if (sa[i] >= k) y[p++] = sa[i] - k;
			rep(i, 0, m) cnt[i] = 0;
			rep(i, 0, n) cnt[x[i]]++;
			rep(i, 1, m) cnt[i] += cnt[i - 1];
			per(i, 0, n) sa[--cnt[x[y[i]]]] = y[i];
			swap(x, y);
			m = x[sa[0]] = 0;
			auto dif = [&](int a, int b) -> int {
				return y[a] != y[b] || (a + k < n ? y[a + k] : -1) != (b + k < n ? y[b + k] : -1);
			};
			rep(i, 1, n)
				x[sa[i]] = (m += dif(sa[i - 1], sa[i]));
			if (++m == n) break;
		}

		int i = 0;
		rep(a, 0, n) {
			if (x[a] + 1 == n) 
				continue;
			int b = sa[x[a] + 1];
			while (max(a, b) + i < n && s[a + i] == s[b + i]) i++;
			lcp[x[a]] = i;
			if (i) i--;
		}

		T.init(lcp);
	}

	int LCP(int a, int b) {
		if (a == b)
			return n - a;
		a = x[a]; b = x[b];
		if (a > b) swap(a, b);
		return T.query(a, b - 1);
	}

	bool same(int a, int b, int len) {
		assert(a + len <= n);
		assert(b + len <= n);
		return LCP(a, b) >= len;
	}
};

string s, t;
SuffixArray SA;

bool check(vector<int> len) {
	int last[2] = {-1, -1};
		
	int n = s.size();
	int p = 0;
	FOR(i, n) {
		int d = s[i] - '0';
		if (last[d] != -1)
			if (SA.same(last[d], p, len[d]) == 0)
				return false;
		last[d] = p;
		p += len[d];
	}
	return (len[0] != len[1] || SA.same(last[0], last[1], len[0]) == 0);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> s >> t;
	SA.init(t);

	int c0 = count(s.begin(), s.end(), '0');
	int c1 = count(s.begin(), s.end(), '1');

	int n = t.size();
	int res = 0;

	rep(i, 1, n + 1) {
		int j = n - i * c1;
		if (j <= 0)
			break;
		if (j % c0)
			continue;
		j /= c0;
		res += check({j, i});
	}
	cout << res << '\n';
	return 0;
}