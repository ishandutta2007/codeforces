#pragma GCC optimize("Ofast")
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class SegTree {
    vector<int> mod;

public:
    explicit SegTree(int n) {
        int _n = 1;
        while (_n < n) _n *= 2;
        n = _n;
        mod.resize(2 * n);
    }

    void plus_val(int l, int r, int val) {
        l += (int)mod.size() / 2, r += (int)mod.size() / 2;
        while (l < r) {
            if (l & 1) mod[l++] += val;
            if (r & 1) mod[--r] += val;
            l >>= 1, r >>= 1;
        }
    }

    void plus_all(int val) {
        mod[1] += val;
    }

    int get(int i) {
        i += (int)mod.size() / 2;
        int sum = 0;
        while (i >= 1) {
            sum += mod[i];
            i >>= 1;
        }
        return sum;
    }

//    void set(int i, int val) {
//        plus_val(i, i + 1, val - get(i));
//    }
};

int timer = 0;

void dfs(int u, const vector<vector<int>>& g, vector<int>& left, vector<int>& right) {
    left[u] = timer++;
    for (int v : g[u]) {
        dfs(v, g, left, right);
    }
    right[u] = timer;
}

bool is_parent(int u, int v, const vector<int>& left, const vector<int>& right) { // v is parent of u
    return left[v] <= left[u] && right[v] >= right[u];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> p(n, -1);
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        cin >> p[i];
        p[i]--;
        g[p[i]].push_back(i);
    }
    vector<int> left(n), right(n);
    dfs(0, g, left, right);
    int sz = timer;
    int center = 0;
    bool is2 = false;
    int x = 0;
    SegTree dist(sz);
    for (int i = 1; i < n; i++) {
        int pr = p[i];
        int d = dist.get(left[pr]);
        int old = dist.get(left[i]);
        dist.plus_val(left[i], left[i] + 1, d + 1 - old);
        if (d != x) {
            cout << 2 * x + is2 << ' ';
            continue;
        }
        if (!is2 && !is_parent(i, center, left, right)) {
            dist.plus_all(-1);
            dist.plus_val(left[center], right[center], 1);
        } else if (!is2 && is_parent(i, center, left, right)) {
            int child = *lower_bound(g[center].begin(), g[center].end(), i, [&right](int a, int b) {
                return right[a] < right[b];
            });
            dist.plus_val(left[child], right[child], -1);
            center = child;
        } else if (is2 && !is_parent(i, center, left, right)) {
            dist.plus_val(left[center], right[center], 1);
            center = p[center];
            x++;
        } else if (is2 && is_parent(i, center, left, right)) {
            dist.plus_all(1);
            dist.plus_val(left[center], right[center], -1);
            x++;
        }
        is2 ^= 1;
        cout << 2 * x + is2 << ' ';
    }
    cout << endl;
}