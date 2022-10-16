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

const int INF = 1e9 + 7, N = 1e5 + 7;

set<int> g1, g2;
int p1[N], p2[N];
vi who1[N], who2[N];
map<int, set<int>> mp1[N], mp2[N];

void upd(int sa, int na, int i, int op) {
	if(op == -1) {
		mp1[sa][na].erase(i);
		if(mp1[sa][na].empty())
			mp1[sa].erase(na);
		mp2[na][sa].erase(i);
		if(mp2[na][sa].empty())
			mp2[na].erase(sa);
	} else {
		mp1[sa][na].insert(i);
		mp2[na][sa].insert(i);
	}
}

void unite1(int u, int v) {
	debug("unite1", u, v);
	u = p1[u], v = p1[v];
	assert(u != v);
	if(who1[u].size() > who1[v].size())
		swap(u, v);
	for(int i:who1[u]) {
		upd(p1[i], p2[i], i, -1);
		p1[i] = v;
		upd(p1[i], p2[i], i, 1);
		who1[v].PB(i);
	}
	who1[u].clear();
	g1.erase(u);
}

void unite2(int u, int v) {
	debug("unite2", u, v);
	u = p2[u], v = p2[v];
	assert(u != v);
	if(who2[u].size() > who2[v].size())
		swap(u, v);
	for(int i:who2[u]) {
		upd(p1[i], p2[i], i, -1);
		p2[i] = v;
		upd(p1[i], p2[i], i, 1);
		who2[v].PB(i);
	}
	who2[u].clear();
	g2.erase(u);
}

void unite(int u, int v) {
	cout << u + 1 << ' ' << v + 1 << '\n';
	unite1(u, v);
	unite2(u, v);
}

signed main()
{
	IO_OP;

	int n, m1, m2;
	cin >> n >> m1 >> m2;

	for(int i = 0; i < n; i++) {
		g1.insert(i);
		g2.insert(i);
		p1[i] = p2[i] = i;
		who1[i].PB(i);
		who2[i].PB(i);
		mp1[i][i].insert(i);
		mp2[i][i].insert(i);
	}

	for(int i = 0; i < m1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		unite1(u, v);
	}

	for(int i = 0; i < m2; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		unite2(u, v);
	}

	cout << n - 1 - max(m1, m2) << '\n';
	while(g1.size() > 1 && g2.size() > 1) {
		int a1 = *g1.begin(), a2 = *next(g1.begin());
		int b1 = mp1[a1].begin() -> F;
		assert(mp1[a1][b1].size());
		int u = *mp1[a1][b1].begin();
		int bt = mp1[a2].begin() -> F;
		if(bt == b1 && (mp1[a2].size()) > 1) {
			bt = next(mp1[a2].begin()) -> F;
			assert(bt != b1);
		}
		if(bt != b1) {
			assert(mp1[a2][bt].size());
			int v = *mp1[a2][bt].begin();
			debug("type1");
			unite(u, v);
			continue;
		}
		int v = *mp1[a2][bt].begin();
		int bsa = *g2.begin(), bna = *next(g2.begin());
		int b2 = bsa;
		if(b2 == b1) b2 = bna;
		int aa = mp2[b2].begin() -> F;
		assert(aa != a2);
		assert(mp2[b2][aa].size());
		int w = *mp2[b2][aa].begin();
		debug("type1");
		unite(v, w);
	}

}