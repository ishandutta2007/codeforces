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
struct RMaxQ {
	vector<vector<T>> t;
	void init(vector<T> a) {
		int n = a.size();
		int m = __lg(n) + 1;
		t = vector<vector<T>> (n, vector<T>(m));
		FOR(i, n) t[i][0] = a[i];
		FOR(j, m - 1)
			FOR(i, n - (1 << j)) {
				t[i][j + 1] = max(t[i][j], t[i + (1 << j)][j]);
			}
	}
	int level(int x) {
		return 31 - __builtin_clz(x);
	}
	T query(int l, int r) {
		int d = level(r - l + 1);
		return max(t[l][d], t[r - (1 << d) + 1][d]);
	}
};

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

const int N = 321321;
int n, q;
ll a[N], b[N];
RMinQ<ll> Min;
RMaxQ<ll> Max;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> q;
	FOR(i, n)
		cin >> a[i];
	FOR(i, n)
		cin >> b[i];

	vector<ll> s(n + 1);
	FOR(i, n)
		s[i + 1] = s[i] + a[i] - b[i];

	Min.init(s);
	Max.init(s);

	while (q--) {
		int l, r;
		cin >> l >> r;
		l--;
		if (s[l] != s[r] || s[l] < Max.query(l, r))
			cout << "-1\n";
		else
			cout << s[l] - Min.query(l, r) << "\n";
	}
	return 0;
}