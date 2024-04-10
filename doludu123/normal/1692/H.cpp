#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    if (a.empty()) return o << "{}";
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
template <typename T> struct vv : vector <vector <T>> {
    vv(int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv() {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv(int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo void(0)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 300005, logN = 20, K = 111;

int main () {
	owo;
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		vector <int> v = a;
		sort(all(v)), v.resize(unique(all(v)) - v.begin());
		for (int i = 0; i < n; ++i) a[i] = lower_bound(all(v), a[i]) - v.begin();
		int m = v.size();
		vector <vector <int>> pt(m);
		for (int i = 0; i < n; ++i) pt[a[i]].pb(i);
		int ans = 1, ansl = 0, ansr = 0;
		auto solve = [&](vector <int> a) {
			int n = a.size();
			// (j - i + 1) * 2 - (a[j] - a[i] + 1) = (j * 2 - a[j]) - (i * 2 - a[i]) + 1
			int mn = 0 * 2 - a[0], p = 0;
			for (int i = 1; i < n; ++i) {
				int now = i * 2 - a[i];
				if (now - mn + 1 > ans) ans = now - mn + 1, ansl = a[p], ansr = a[i];
				if (mn > now) mn = now, p = i;
			}
		};
		for (int x = 0; x < m; ++x) {
			solve(pt[x]);
		}
		cout << v[a[ansl]] << ' ' << ansl + 1 << ' ' << ansr + 1 << '\n';
	}
}