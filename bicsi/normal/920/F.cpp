#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

vector<int> divc;

struct SegTree {
    struct Node {
        int maxx; long long sum;
    };
    vector<Node> T;

    void Init(int node, int b, int e, vector<int>& V) {
        if (b == e) {
            T[node].maxx = T[node].sum = V[b];
        } else {
            int m = (b + e) / 2;
            Init(node * 2, b, m, V);
            Init(node * 2 + 1, m + 1, e, V);
            Pull(node);
        }
    }

    SegTree(vector<int> V) : T(4 * V.size()) {
        Init(1, 0, V.size() - 1, V);
    } 

    void Pull(int node) { 
        T[node].maxx = max(T[node * 2].maxx, T[node * 2 + 1].maxx);
        T[node].sum = T[node * 2].sum + T[node * 2 + 1].sum;
    }

    void Update(int node, int b, int e, int l, int r) {
        if (l > r or T[node].maxx <= 2) {
            return;
        }        
        if (b == e) {
            T[node].maxx = T[node].sum = divc[T[node].sum];
            return;
        }
        int m = (b + e) / 2;
        Update(node * 2, b, m, l, min(m, r));
        Update(node * 2 + 1, m + 1, e, max(m + 1, l), r);
        Pull(node);
    }

    long long Query(int node, int b, int e, int l, int r) {
        if (l > r) return 0;
        if (b == l && e == r) return T[node].sum;

        int m = (b + e) / 2;
        return Query(node * 2, b, m, l, min(r, m)) 
             + Query(node * 2 + 1, m + 1, e, max(l, m + 1), r);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    divc.resize(1000005);
    for (int i = 1; i < (int)divc.size(); ++i) {
        for (int j = i; j < (int)divc.size(); j += i) {
            divc[j] += 1;
        }
    }
    
    int n, m; cin >> n >> m;
    vector<int> V(n);
    for (int i = 0; i < n; ++i)
        cin >> V[i];
    SegTree st(V);
    
    cerr << "INIT DONE" << endl;
    while (m--) {
        int t, l, r; cin >> t >> l >> r;
        if (t == 1) st.Update(1, 0, n - 1, l - 1, r - 1);
        else cout << st.Query(1, 0, n - 1, l - 1, r - 1) << '\n';
    }


    return 0;
}