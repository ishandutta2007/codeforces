#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << _yellow << _bold << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7, M = 1e9 + 7;

int inv100;

int inv(int x) {
	if(x == 1)
		return 1;
	return M - 1LL * M / x * inv(M % x) % M;
}

void add(int& a, int b) {
	a += b;
	if(a >= M) a -= M;
}

void mul(int& a, int b) {
	a = int(1LL * a * b % M);
}

void solve() {
	int n, m, rb, cb, rd, cd, p;
	cin >> n >> m >> rb >> cb >> rd >> cd >> p;

	int q = 1;
	mul(p, inv100);
	add(q, M - p);

	auto trans = [&] (array<int, 4> s) {
		if(s[0] + s[2] > n) s[2] *= -1;		
		else if(s[0] + s[2] < 1) s[2] *= -1;
		if(s[1] + s[3] > m) s[3] *= -1;		
		else if(s[1] + s[3] < 1) s[3] *= -1;
		s[0] += s[2];
		s[1] += s[3];
		return s;
	};
	array<int, 4> s = {rb, cb, 1, 1};
	array<array<bool, 2>, 2> zero = {0, 0, 0, 0};
	V<V<array<array<bool, 2>, 2>>> _vis(n + 1, V<array<array<bool, 2>, 2>>(m + 1, zero));
	auto vis = [&] (array<int, 4> s) -> bool& {
		return _vis[s[0]][s[1]][(s[2] + 1) / 2][(s[3] + 1) / 2];
	};
	vi aux, aux2;
	while(!vis(s)) {
		vis(s) = true;
		aux.PB(s[0] == rd || s[1] == cd);
		s = trans(s);
	}
	array<int, 4> ss = {rb, cb, 1, 1};
	while(ss != s) {
		aux2.PB(ss[0] == rd || ss[1] == cd);
		ss = trans(ss);
	}
	int a = 1, b = 0;
	while(aux.size() > aux2.size()) {
		int k = aux.back(); aux.pop_back();
		if(k) {
			add(b, 1);
			mul(a, q), mul(b, q);
		} else {
			add(b, 1);
		}
	}
	add(a, M - 1);
	b = M - b;
	mul(b, inv(a));


	while(aux2.size()) {
		int k = aux2.back(); aux2.pop_back();
		add(b, 1);
		if(k) mul(b, q);
	}
	cout << b << '\n';
}

signed main()
{
	IO_OP;

	inv100 = inv(100);

	int t;
	cin >> t;
	while(t--) solve();

}