#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

struct AhoCorasick {
    vector<int> order, link, sz = {0};
    vector<map<int, int>> leg = {{}};

    void Add(string s, int del) {
        int node = 0;
        for (auto c : s) {
            int& nxt = leg[node][c];
            if (nxt == 0) {
                nxt = leg.size();
                leg.emplace_back();
                sz.push_back(0);
            }
            node = nxt;
        }
        sz[node] += del;
    }
    int Go(int node, char c) {
        while (node != -1 && !leg[node].count(c))
            node = link[node];
        if (node == -1) return 0;
        return leg[node][c];
    }
    void Build() {
        int n = leg.size();
        link.assign(n, -1);
        order = {0};
        for (int i = 0; i < n; ++i) {
            int node = order[i];
            for (auto vec : leg[node]) {
                link[vec.second] = Go(link[node], vec.first);
                sz[vec.second] += sz[link[vec.second]];
                order.push_back(vec.second);
            }
        }
    }
    int Query(string str) {
        if (link.empty()) return 0;
        int node = 0, ans = 0;
        for (auto c : str) {
            node = Go(node, c);
            ans += sz[node];
        }
        return ans;
    }
};

vector<AhoCorasick> ahos;
vector<vector<pair<string, int>>> strings;
void Insert(string s, int del) {
    vector<pair<string, int>> accum = {{s, del}};
    for (int i = 0; i < 20; ++i) {
        if (strings[i].empty()) {
            strings[i] = accum;
            for (auto str : accum)
                ahos[i].Add(str.first, str.second);
            ahos[i].Build();
            break;
        }
        ahos[i] = AhoCorasick();
        accum.insert(accum.end(), strings[i].begin(), strings[i].end());
        strings[i].clear();
    }
}

int Query(string s) {
    int ans = 0;
    for (auto& aho : ahos)
        ans += aho.Query(s);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ahos.resize(20); strings.resize(20);

    int q; cin >> q;
    while (q--) {
        int t; string s; cin >> t >> s;
        if (t == 1) Insert(s, +1);
        if (t == 2) Insert(s, -1);
        if (t == 3) cout << Query(s) << endl;
    }

    return 0;
}