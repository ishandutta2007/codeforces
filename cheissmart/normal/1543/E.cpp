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

string to_string(char c) { return string(1, c); }
string to_string(bool b) { return b?"true":"false"; }
string to_string(const char* s) { return string(s); }
string to_string(string s) { return s; }
string to_string(V<bool> v) {
	string res;
	for(int i=0;i<(int)v.size();i++) res+=char('0'+v[i]);
	return res;
}
template<class T1, class T2> string to_string(pair<T1, T2> p) {return "(" + to_string(p.F) + ", " + to_string(p.S) + ")";}
template<size_t S> string to_string(bitset<S> b) {
	string res;
	for(int i=0;i<S;i++) res+=char('0'+b[i]);
	return res;
}
template<class T> string to_string(T v) {
    bool f=1;
    string res;
    for(auto x:v){
		if(!f) res+=' ';
		f=0; res+=to_string(x);
	}
    return res;
}


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

const int INF = 1e9 + 7;

void solve() {
	int n, N;
	cin >> n;
	N = n;
	V<set<int>> G(1 << n);
	for(int i = 0; i < (n << (n - 1)); i++) {
		int u, v;
		cin >> u >> v;
		G[u].insert(v);
		G[v].insert(u);
	}
	vi s;
	for(int i = 0; i < (1 << n); i++)
		s.PB(i);
	function<vi(vi, int)> solve = [&] (vi s, int n) -> vi {
		assert(int(s.size()) == (1 << n));
		if(n == 0)
			return s;
		vi vis(1 << N);
		int a = s[0], b = *G[a].begin();
		vis[a] = 1, vis[b] = 2;
		queue<int> qa({a}), qb({b});
		vi who(1 << N);
		while(qa.size()) {
			assert(qa.size() == qb.size());
			int aa = qa.front(), bb = qb.front();
			qa.pop(), qb.pop();
			for(int v:G[aa]) {
				if(vis[v] == 0) {
					qa.push(v);
					vis[v] = 1;
				} else if(vis[v] == 2) {
					who[aa] = v;
				}
			}
			G[aa].erase(who[aa]);
			for(int v:G[bb]) if(vis[v] == 0) {
				qb.push(v);
				vis[v] = 2;
			}
		}
		vi sa;
		for(int i:s) if(vis[i] == 1)
			sa.PB(i);
		vi tt = solve(sa, n - 1);
		vi res = tt;
		for(int i:tt) res.PB(who[i]);
		return res;
	};
	vi order = solve(s, n);
	for(int i:order) {
		cout << i << " ";
	}
	cout << '\n';
	if((1 << n) % n == 0) {
		vi ans(1 << n);
		for(int i = 0; i < (1 << n); i++) {
			ans[order[i]] = 0;
			for(int j = 0; j < n; j++) if(i >> j & 1)
				ans[order[i]] ^= j;	
		}
		for(int i = 0; i < (1 << n); i++)
			cout << ans[i] << ' ';
		cout << '\n';
	}
	else cout << "-1" << '\n';
}


signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) solve();
	
}