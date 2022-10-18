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
		string s;
		int x;
		cin >> s >> x;
		auto get = [&](string s) {
			return (s[0] - '0') * 10 + (s[1] - '0');
		};
		int now = get(s.substr(0, 2)) * 60 + get(s.substr(3));
		set <int> S;
		while (!S.count(now)) {
			S.insert(now);
			now += x;
			now %= 1440;
		}
		auto get2 = [&](int x) {
			string s;
			s += x / 10 + '0';
			s += x % 10 + '0';
			return s;
		};
		int ans = 0;
		for (int x : S) {
			string s = get2(x / 60), t = get2(x % 60);
			reverse(all(s));
			if (s == t) ans++;
		}
		cout << ans << endl;
	}
}