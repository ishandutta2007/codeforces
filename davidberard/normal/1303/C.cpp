#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

void dfs(char u, char p, string& t, set<char>& seen, set<char> adj[256]) {
    t += u;
    assert(!seen.count(u));
    seen.insert(u);
    for (auto& v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, t, seen, adj);
    }
}

void solve() {
    set<char> adj[256];
    string s;
    cin >> s;
    for (int i=0; i<s.size()-1; ++i) {
        adj[s[i]].insert(s[i+1]);
        adj[s[i+1]].insert(s[i]);
        //cerr << " :: " << s[i] << " <-> " << s[i+1] << endl;
    }
    set<char> twice;
    for (char c='a'; c<='z'; ++c) {
        if (adj[c].size() > 2) {
            cout << "NO" << "\n";
            return;
        }
        if (adj[c].size() == 2) twice.insert(c);
    }
    string t;
    set<char> seen;
    for (char c='a'; c<='z'; ++c) {
        if (seen.count(c)) continue;
        if (twice.count(c)) continue;
        dfs(c, 0, t, seen, adj);
    }
    if (t.size() != 26) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << t << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int TT;
    cin >> TT;
    while (TT--) {
        solve();
    }
    return 0;
}