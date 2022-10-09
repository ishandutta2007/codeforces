#include <bits/stdc++.h>

using namespace std;

#define long long long 
#define ve vector
#define vi ve<int>
#define sz(v) ((int)v.size())
#define ii pair<int, int>
#define xx first
#define yy second
#define inf(t) numeric_limits<t>::max()

namespace Solution {

void quit() { cout << "NO"; exit(0); }

int n;
ve<ve<string> > choises;
map<string, vi> a;
ve<string> ans;

struct cmp {
    bool operator() (int u, int v) {
        if (sz(choises[u]) == sz(choises[v])) return u < v;
        return sz(choises[u]) < sz(choises[v]);
    }
};
set<int, cmp> pq;

void erase(ve<string>& a, const string& s) {
    a.resize(remove(a.begin(), a.end(), s) - a.begin());
}

int main() {
    cin >> n;
    choises.resize(n);
    for (int i = -1; ++i < n; ) {
        string u, v; cin >> u >> v;
        u = u.substr(0, 3);
        v = u.substr(0, 2) + v[0];
        choises[i].push_back(u);
        if (u != v) choises[i].push_back(v);
        a[u].push_back(i);
    }

    ans.resize(n);

    for (auto i : a) {
        if (sz(i.yy) == 1) continue;
        for (auto f : i.yy) {
            if (sz(choises[f]) == 2) erase(choises[f], i.xx);
        }
    }

    for (int i = -1; ++ i < n; ) pq.insert(i);

    while (sz(pq)) {
        int u = *pq.begin();
        pq.erase(pq.begin());
        assert(ans[u].size() == 0);
        if (sz(choises[u]) == 0) {
            quit();
        }
        ans[u] = choises[u][0];
        for (int i = -1; ++i < n;) {
            if (sz(ans[i])) continue;
            pq.erase(i);
            erase(choises[i], ans[u]);
            pq.insert(i);
        }
    }

    cout << "YES\n";
    for (int i = -1; ++i < n; ) cout << ans[i] << '\n';
    sort(ans.begin(), ans.end());
    for (int i = 0; ++i < n; ) assert(ans[i - 1] != ans[i]);

    return 0;
}}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    return Solution::main();
}