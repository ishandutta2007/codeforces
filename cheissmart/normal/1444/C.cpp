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

void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
	cerr << to_string(h);
	if(sizeof...(t)) cerr << ", ";
	DBG(t...);
}
#define debug(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)

const int INF = 1e9 + 7, N = 2e6 + 7;

int c[N], isbi[N], cur[N], vis[N], which[N];
vi who[N], G[N], tt, g[N];

bool dfs(int u, int color = 1) {
	tt.PB(u);
	vis[u] = color;
	for(int v:G[u]) if(cur[v]) {
		if(vis[v] == 0) {
			if(!dfs(v, color ^ 3)) return false;
		} if(vis[v] == vis[u]) return false;
	}
	return true;
}

signed main()
{
	IO_OP;

	int n, m, k;
	cin >> n >> m >>k;
	for(int i = 1; i <= n; i++) {
		cin >> c[i];
		who[c[i]].PB(i);
	}
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}
	int cnt = 0;
	for(int i = 1; i <= k; i++) {
		isbi[i] = 1;
		for(int u:who[i]) cur[u] = 1;
		for(int u:who[i]) {
			if(!vis[u]) {
				tt.clear();
				if(!dfs(u)) {
					isbi[i] = 0;
					break;
				}
				for(int v:tt) {
					if(vis[v] == 1) which[v] = cnt;
				}
				cnt++;
				for(int v:tt) {
					if(vis[v] == 2) which[v] = cnt;
				}
				cnt++;
			}
		}
		for(int u:who[i]) cur[u] = 0, vis[u] = 0;
	}
	for(int i = 0; i < cnt; i++) g[i].PB(i ^ 1);
	int no_cnt = 0;
	set<pi> no;
	for(int i = 1; i <= k; i++) {
		if(!isbi[i]) {
			no_cnt++;
			continue;
		}
		unordered_map<int, V<pi>> mp;
		for(int u:who[i]) {
			for(int v:G[u]) if(c[v] != c[u] && isbi[c[v]]) {
				mp[c[v]].EB(which[v], which[u]);
			}
		}
		for(auto& p:mp) {
			for(pi e:p.S) {
				g[e.F].PB(e.S);
				g[e.S].PB(e.F);
			}
			vi undo;
			for(pi e:p.S) {
				if(!vis[e.F]) {
					function<bool(int, int)> dfs2 = [&](int u, int color) {
						undo.PB(u);
						vis[u] = color;
						for(int v:g[u]) {
							if(vis[v] == 0) {
								if(!dfs2(v, color ^ 3)) return false;
							} if(vis[v] == vis[u]) return false;
						}
						return true;
					};
					if(!dfs2(e.F, 1)) {
						int sa = i, na = p.F;
						if(sa > na) swap(sa, na);
						no.insert({sa, na});
						break;
					}
				}
			}
			for(pi e:p.S) {
				g[e.F].pop_back();
				g[e.S].pop_back();
			}
			for(int u:undo) vis[u] = 0;
		}
	}
	cout << (ll) k * (k - 1) / 2 - (int) no.size() - (no_cnt * (no_cnt - 1) / 2 + no_cnt * (k - no_cnt)) << endl;
}