#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#define int long long 

using namespace std;

const int kMod = 1e9 + 7;

long long GCD(long long a, long long b) {
    while (b) {
        long long r = a % b;
        a = b; b = r;
    }
    return a;
}

struct SegTree {
    int n;
    vector<long long> data;

    SegTree(int n) : n(n), data(4 * n) {}

    void Update(int pos, long long val) {
        //cerr << "Update: " << pos << " " << val << endl;
        update(1, 0, n - 1, pos, val);
    }

    int Query(int pos) {
        //cerr << "Query: " << pos << endl;
        int ret = query(1, 0, n - 1, pos, 0LL).first;
        //cerr << " > " << ret << endl;
        return ret;
    }

    void update(int node, int b, int e, int pos, long long val) {
        if (b == e) {
            data[node] = val;
        } else {
            int m = (b + e) / 2;
            if (pos <= m) update(node * 2, b, m, pos, val);
            else update(node * 2 + 1, m + 1, e, pos, val);
            data[node] = GCD(data[node * 2], data[node * 2 + 1]);
        }
    }

    pair<int, long long> query(int node, int b, int e, int pos, long long val) {
        if (b > pos) 
            return make_pair(0, 0LL);
        
        if (b == e) {
            val = GCD(val, data[node]);
            return make_pair(val % kMod, val);    
        } else if (GCD(val, data[node]) == val) {
            return make_pair(val % kMod * (e - b + 1) % kMod, val);
        } else {
            int m = (b + e) / 2;
            int sum1; tie(sum1, val) = query(node * 2 + 1, m + 1, e, pos, val); 
            int sum2; tie(sum2, val) = query(node * 2, b, m, pos, val);
            return make_pair((sum1 + sum2) % kMod, val);
        }
    }
};

int DFS(const vector<vector<int>>& graph, 
        const vector<long long>& vals, 
        SegTree& st, 
        int node, int par, int dep) 
{
    st.Update(dep, vals[node]); 
    int ret = st.Query(dep);
    for (auto vec : graph[node]) {
        if (vec == par) continue;
        ret += DFS(graph, vals, st, vec, node, dep + 1);
        ret %= kMod;
    }
    return ret;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<long long> vals(n);
    for (int i = 0; i < n; ++i) {
        cin >> vals[i];
    }

    vector<vector<int>> graph(n);
    for (int i = 1; i < n; ++i) {
        int a, b; cin >> a >> b; --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    SegTree st(n);
    int ret = DFS(graph, vals, st, 0, -1, 0);
    cout << ret << endl;
    
    return 0;
}