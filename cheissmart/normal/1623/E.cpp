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

const int INF = 1e9 + 7, N = 2e5 + 7;

int l[N], r[N], good[N], yes[N];
int n, k;
string s, t;
vi who;

void dfs(int u) {
	if(l[u]) dfs(l[u]);
	debug(u);
	t.PB(s[u]), who.PB(u);
	if(r[u]) dfs(r[u]);
}

bool dfs2(int u, int need = 0) {
	if(need + 1 > k) return false;
	if(l[u] && dfs2(l[u], need + 1)) {
		yes[u] = 1;
		if(r[u]) dfs2(r[u], 0);
		return true;
	} else {
		if(good[u]) {
			yes[u] = 1;
			k -= need + 1;
			if(r[u]) dfs2(r[u], 0);
			return true;
		} else {
			return false;
		}
	}
}


string ans;

void dfs3(int u) {
	if(l[u]) dfs3(l[u]);
	ans.PB(s[u]);
	if(yes[u])
		ans.PB(s[u]);
	if(r[u]) dfs3(r[u]);
}

signed main()
{
	IO_OP;

	cin >> n >> k >> s;
	s = ' ' + s;
	for(int i = 1; i <= n; i++)
		cin >> l[i] >> r[i];
	who.PB(0);
	t = " ";
	dfs(1);
	char c = 'A';
	for(int i = n; i >= 1;) {
		int j = i;
		while(i >= 1 && t[i] == t[j]) {
			if(t[i] < c) {
				debug(who[i]);
				good[who[i]] = 1;
			}
			i--;
		}
		c = t[j];
	}
	dfs2(1);
	dfs3(1);
	cout << ans << '\n';
}