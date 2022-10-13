#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 2000005;

vector<tuple<int, int, int>> queries[kMaxN];
vector<tuple<int, int, int>> updates[kMaxN];
int answer[kMaxN];

struct DSU {

    vector<int> link, dp, rank;
    DSU(int n) : link(n, -1), dp(n, 0), rank(n, 0) {}

    int Find(int& x) {
        int ret = 0;
        while (link[x] != -1) {
            ret ^= dp[x];
            x = link[x];
        }
        return ret;
    }

    vector<pair<int, int>> stk;
    int Union(int a, int b, int c) {
        c ^= Find(a);
        c ^= Find(b);
        if (a == b) return 0;
        
        if (rank[a] > rank[b]) 
            swap(a, b);
        
        link[a] = b;
        dp[a] = c;
        rank[b] += (rank[a] == rank[b]);

        stk.emplace_back(a, b);

        return 1;
    }
   
    void Undo() {
        int a, b; tie(a, b) = stk.back();
        stk.pop_back();
        link[a] = -1;
        dp[a] = 0;
    }
};

void Add(int node, int b, int e, int l, int r, int x, int y, int c) {
    if (l > r) return;
    if (b == l && e == r) {
        updates[node].emplace_back(x, y, c);
        return;
    }
    int m = (b + e) / 2;
    Add(node * 2, b, m, l, min(m, r), x, y, c);
    Add(node * 2 + 1, m + 1, e, max(m + 1, l), r, x, y, c);
}


vector<int> ComputeBase(vector<int> V) {
    int at = 0, n = V.size();
    for (int bit = 29; bit >= 0; --bit) {
        if (at >= n) break;    
        for (int i = at; i < n; ++i) {
            if (V[i] & 1 << bit) {
                swap(V[i], V[at]);
                break;
            }
        }
        if (V[at] & 1 << bit) {
            for (int i = 0; i < n; ++i) {
                if (i != at && (V[i] & 1 << bit))
                    V[i] ^= V[at];
            }
            at += 1;
        }
    }
    V.resize(at);
    return V;
}

int ComputeAnswer(vector<int> V, int val) {
    while (true) {
        int nxt = val, n = V.size();
        for (int i = 0; i < n; ++i) {
            nxt = min(nxt, val ^ V[i]);
        }
        if (nxt == val) break;
        val = nxt;
    }
    return val; 
}

void Solve(int node, int b, int e, vector<int> base, DSU& dsu) {
//    cerr << "[" << node << " " << b+1 << " " << e+1 << "]" << endl;

    int uc = 0; 
    for (auto itr : updates[node]) {
        int a, b, c; tie(a, b, c) = itr;
//        cerr << "UPDATING: " << a+1 << " " << b+1 << " " << c << endl;
        if (dsu.Union(a, b, c)) uc += 1;
        else base.push_back(c ^ dsu.Find(a) ^ dsu.Find(b));
    }

    base = ComputeBase(base);

    if (b == e) {
        for (auto itr : queries[b]) {
            int a, b, idx; tie(a, b, idx) = itr;
//            cerr << "ANSWERING: " << a+1 << " " << b+1 << endl;
            answer[idx] = ComputeAnswer(base, dsu.Find(a) ^ dsu.Find(b));
        }    
    } else {
        int m = (b + e) / 2;
        Solve(node * 2, b, m, base, dsu);
        Solve(node * 2 + 1, m + 1, e, base, dsu);
    }

    for (int i = 0; i < uc; ++i)
        dsu.Undo();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    map<pair<int, int>, pair<int, int>> edge_set;

    for (int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c; --a; --b;
        if (a > b) swap(a, b);
        edge_set[make_pair(a, b)] = make_pair(0, c);
    }
    
    int qc = 0;    
    queries[1].emplace_back(0, n - 1, qc++); 
    int q = qc;

    for (auto itr : edge_set) {
        int a, b, c, i;
        tie(a, b) = itr.first;
        tie(i, c) = itr.second;
        Add(1, 0, q, i, q, a, b, c);
    }    
    DSU dsu(n);    
    Solve(1, 0, q, {}, dsu);

    for (int i = 0; i < qc; ++i) {
        cout << answer[i] << '\n';
    }

    return 0;
}