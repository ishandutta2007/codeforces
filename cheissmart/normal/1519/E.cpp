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

const int INF = 1e9 + 7, N = 4e5 + 7;

struct fc {
	ll n, d;
	fc(ll _n, ll _d) {
		n = _n, d = _d;
		ll g = __gcd(n,d); n /= g, d /= g;
		if(d < 0) n *= -1, d *= -1;
	}
	fc(ll _n) : fc(_n,1) {}
	fc() : fc(0) {}
	friend fc abs(fc F) { return fc(abs(F.n),F.d); }
	friend string to_string(const fc& a) { return to_string(a.n)+"/"+to_string(a.d); }
 
	friend bool operator<(const fc& l, const fc& r) { return l.n*r.d < r.n*l.d; }
	friend bool operator==(const fc& l, const fc& r) { return l.n == r.n && l.d == r.d; }
	friend bool operator!=(const fc& l, const fc& r) { return !(l == r); }
 
	fc operator-() const { return fc(-n,d); }
	friend fc operator+(const fc& l, const fc& r) { return fc(l.n*r.d+r.n*l.d,l.d*r.d); }
	friend fc operator-(const fc& l, const fc& r) { return fc(l.n*r.d-r.n*l.d,l.d*r.d); }
	friend fc operator*(const fc& l, const fc& r) { return fc(l.n*r.n,l.d*r.d); }
	friend fc operator*(const fc& l, int r) { return l*fc(r,1); }
	friend fc operator*(int r, const fc& l) { return l*r; }
	friend fc operator/(const fc& l, const fc& r) { return l*fc(r.d,r.n); }
	friend fc operator/(const fc& l, const int& r) { return l/fc(r,1); }
	friend fc operator/(const int& l, const fc& r) { return fc(l,1)/r; }

	friend fc& operator+=(fc& l, const fc& r) { return l = l+r; }
	friend fc& operator-=(fc& l, const fc& r) { return l = l-r; }
	template<class T> friend fc& operator*=(fc& l, const T& r) { return l = l*r; }
	template<class T> friend fc& operator/=(fc& l, const T& r) { return l = l/r; }
};

map<fc, int> mp;
int cnt = 0;

int get_id(fc f) {
	if(mp.count(f) == 0)
		mp[f] = cnt++;
	return mp[f];
}

V<pi> G[N], ans;
int d[N];
bool vis[N];

bool dfs(int u, int pe = -1, int depth = 0) {
	vis[u] = true;
	d[u] = depth;
	vi tt;
	if(pe != -1) tt.PB(pe);
	for(pi e:G[u]) {
		if(!vis[e.F]) {
			if(dfs(e.F, e.S, depth + 1))
				tt.PB(e.S);
		}
		else if(d[e.F] > d[u]) {
			tt.PB(e.S);
		}
	}
	while(tt.size() >= 2) {
		int sz = tt.size();
		ans.EB(tt[sz - 1], tt[sz - 2]);
		tt.pop_back(), tt.pop_back();
	}
	return tt.size();
}

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		fc x(a, b), y(c, d);
		fc s1 = (y + 1) / x, s2 = y / (x + 1);
		int u = get_id(s1), v = get_id(s2);
		G[u].EB(v, i);
		G[v].EB(u, i);
	}
	for(int i = 0; i < cnt; i++) {
		if(!vis[i]) {
			dfs(i);
		}
	}
	cout << ans.size() << '\n';
	for(pi p:ans)
		cout << p.F + 1 << ' ' << p.S + 1 << '\n';

}