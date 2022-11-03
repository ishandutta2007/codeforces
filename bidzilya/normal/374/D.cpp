#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdlib>
using namespace std;

typedef long long ll;

const int max_n = 1e6 + 100;

int t[4 * max_n];
int a[max_n], b[max_n];
int n, m;

void update_from_index(int v, int tl, int tr, int p, int d) {
    t[v] += d;
    if (tl != tr) {
        int m = (tl + tr) >> 1;
        if (p <= t[2 * v])
            update_from_index(2 * v, tl, m, p, d);
        else
            update_from_index(2 * v + 1, m + 1, tr, p - t[2 * v], d);
    }
}

void update(int v, int tl, int tr, int p, int d) {
    t[v] += d;
    if (tl != tr) {
        int m = (tl + tr) >> 1;
        if (p <= m)
            update(2 * v, tl, m, p, d);
        else
            update(2 * v + 1, m + 1, tr, p, d);
    }
}

int get(int v, int tl, int tr, int p) {
    if (tl == tr)
        return t[v];
    else {
        int m = (tl + tr) >> 1;
        if (p <= m)
            return get(2 * v, tl, m, p);
        else
            return get(2 * v + 1, m + 1, tr, p);
    }
}

int main() {
   // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
        cin >> a[i];
    int sz = 0;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        if (b[i] == -1) {
            for (int j = 0; j < m && a[j] - j <= sz; ++j, --sz) {
                update_from_index(1, 0, n - 1, a[j] - j, -1);
            }
        } else {
            ++sz;
            update(1, 0, n - 1, i, 1);
        }
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i)
        if (get(1, 0, n - 1, i))
            ans.push_back(b[i]);
    if (ans.empty()) {
        cout << "Poor stack!" << endl;
    } else {
        for (int i = 0; i < (int) ans.size(); ++i)
            cout << ans[i];
        cout << endl;
    }
    return 0;
}