// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define fi first
#define se second
#define pb push_back
 
#define ll long long
#define pii pair<int, int>
#define endl '\n'
//#define int ll
const int MOD = 1000000007;

namespace Tarjan {
	const int maxn = 1000006;
	struct graph {
		int n; vector<int> inc; vector<int> e[maxn];
		void ae(int u, int v) { e[u].pb(v); }
		void clr(int _n) {
			inc.clear();
			rep(i,_n+2) e[i].clear();
			n = _n;
		}
	};
    int tot, color, l[maxn], t[maxn], findSCC[maxn];
    bool r[maxn]; stack<int> S; graph pre, shr;
    
    void DFS(int u) {
        l[u] = t[u] = ++tot; S.push(u); r[u] = true;
        for(int& v:pre.e[u]) {
            if(r[v] && t[v]) l[u] = min(l[u], t[v]);
            if(!r[v] && !t[v]) { DFS(v); l[u] = min(l[u], l[v]); }
        }
        if(l[u] != t[u]) return;
        color++;
        while(1) {
            int c = S.top(); S.pop(); r[c] = false;
            findSCC[c] = color; if(c == u) return;
        }
    }
    void shrinkSCC() {
    	rep(i, pre.n+2) { l[i] = t[i] = r[i] = 0; }
    	color = 0; tot = 0;
        tot = color = 0; rep1(u, pre.n) { if(t[u]) { continue; } DFS(u); }
        shr.clr(color+1);
        shr.n = color; shr.inc.resize(color+1);
        rep1(u, pre.n) {
            for(int& v:pre.e[u]) if(findSCC[u] != findSCC[v]) {
            	shr.ae(findSCC[u], findSCC[v]);
            	shr.inc[findSCC[v]]++;
            }
        }
    }
}

// using namespace Tarjan;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) {
    	int n, m; cin >> n >> m;
    	Tarjan::pre.clr(n);
    	rep(i, m) {
    		int u, v; cin >> u >> v;
    		if(u == v) continue;
    		Tarjan::pre.ae(u, v);
    	}
    	Tarjan::shrinkSCC();
    	if(Tarjan::color == 1) cout << "No" << endl;
    	else {
    		cout << "Yes" << endl;
    		vector<int> a, b;
    		int start = 0;
    		rep1(i, Tarjan::color) if(!Tarjan::shr.inc[i]) start = i;
    		rep1(i, n) {
    			if(Tarjan::findSCC[i] == start) a.pb(i);
    			else b.pb(i);
    		}
    		swap(a, b);
    		cout << a.size() << ' ' << b.size() << endl;
    		for(int& k:a) cout << k << ' ';
    		cout << endl; for(int& k:b) cout << k << ' ';
    		cout << endl;
    	}
    }
}