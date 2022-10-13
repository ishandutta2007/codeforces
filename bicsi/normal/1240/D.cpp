#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

struct SegTree {
    struct Node {
        int l, r, val;
    };
    
    int n;
    vector<Node> data;

    SegTree(int n) : n(n) {
        data.push_back(Node{0, 0, -1});
    }

    int get(int node, int b, int e, int pos) {
        if (b == e) return data[node].val;
        int m = (b + e) / 2;
        if (pos <= m) return get(data[node].l, b, m, pos);
        else return get(data[node].r, m + 1, e, pos);
    }
    int Get(int node, int pos) { return get(node, 0, n - 1, pos); }


    int set(int node, int b, int e, int pos, int val) {
        data.push_back(data[node]);
        node = data.size() - 1;
        if (b == e) {
            data[node].val = val;
        } else {
            int m = (b + e) / 2;
            if (pos <= m) {
                int aux = set(data[node].l, b, m, pos, val);
                data[node].l = aux;
            } else {
                int aux = set(data[node].r, m + 1, e, pos, val);
                data[node].r = aux;
            }
        }
        return node;
    }
    int Set(int node, int pos, int val) { return set(node, 0, n - 1, pos, val); }
};

int main() {
    srand(time(0));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int q; cin >> q;
    while (q--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; --a[i];
        }
        
        vector<int> dp(n + 1, 0);
        vector<int> maps(n + 1, 0);
        SegTree st(n);

        long long total = 0;
        for (int i = n - 1; i >= 0; --i) {
            int j;
            if (i + 1 < n && a[i + 1] == a[i]) {
                j = i + 1;
            } else j = st.Get(maps[i + 1], a[i]);
            
            if (j != -1) {
                dp[i] = 1 + dp[j + 1];
                if (j + 1 < n)
                    maps[i] = st.Set(maps[j + 1], a[j + 1], j + 1);
                else maps[i] = maps[j + 1];
                total += dp[i];
            }
        }

        cout << total << '\n';
    }


    return 0;
}