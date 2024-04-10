/**
 *  created: 28/11/2021, 16:53:59
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 1111, inf = 1000111222;

struct dsu {
    int p_or_sz[max_n];
    multiset<int> q;

    void init(int n) {
        for (int i = 0; i < n; ++i) {
            p_or_sz[i] = -1;
            q.insert(-1);
        }
    }

    int find_set(int v) {
        if (p_or_sz[v] < 0) {
            return v;
        }
        return p_or_sz[v] = find_set(p_or_sz[v]);
    }

    bool union_set(int v1, int v2) {
        v1 = find_set(v1);
        v2 = find_set(v2);
        if (v1 == v2) {
            return false;
        }
        if (-p_or_sz[v1] > -p_or_sz[v2]) {
            swap(v1, v2);
        }
        q.erase(q.find(p_or_sz[v1]));
        q.erase(q.find(p_or_sz[v2]));
        p_or_sz[v2] += p_or_sz[v1];
        q.insert(p_or_sz[v2]);
        p_or_sz[v1] = v2;
        return true;
    }
};

int n, k;
dsu d;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    d.init(n);
    int top = 1;
    for (int i = 0; i < k; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        top += (!d.union_set(u, v));
        int cnt = 0, ans = -1;
        for (auto x : d.q) {
            ans -= x;
            ++cnt;
            if (cnt == top) {
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}