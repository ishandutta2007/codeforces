#include <bits/stdc++.h>

using namespace std;

struct Node{
    int maxi, d = 0;
    Node() {}
    Node(int val): maxi(val), d(0) {}
};

const int N = 1 << 19;
Node t[2 * N];

void relax(int pos) {
    t[pos].maxi = max(t[2 * pos].maxi, t[2 * pos + 1].maxi);
}

void full(int pos, int d) {
    t[pos].d += d;
    t[pos].maxi += d;
}

void push(int pos) {
    full(2 * pos, t[pos].d);
    full(2 * pos + 1, t[pos].d);
    t[pos].d = 0;
}

void upd(int pos, int l, int r, int a, int b, int d) {
    if (a > b || l > b || a > r) return;
    if (a <= l && r <= b) {
        full(pos, d);
        return;
    }
    int m = (l + r) / 2;
    push(pos);
    upd(2 * pos, l, m, a, b, d);
    upd(2 * pos + 1, m + 1, r, a, b, d);
    relax(pos);
}

int get(int pos, int l, int r, int a, int b) {
    if (a > b || l > b || a > r) return 0;
    if (a <= l && r <= b) return t[pos].maxi;
    push(pos);
    int m = (l + r) / 2;
    return max(get(2 * pos, l, m, a, b), get(2 * pos + 1, m + 1, r, a, b));
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, m;
    cin >> n >> k >> m;
    for (int i = 1; i <= N; i++) t[N + i - 1].maxi = i - n;
    for (int i = N - 1; i >= 1; i--) relax(i);
    set <pair <int, int>> s;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        y += abs(x - k);
        if (s.find({y, x}) == s.end()) {
            s.insert({y, x});
            upd(1, 1, N, 1, y - 1, 1);
        } else {
            s.erase({y, x});
            upd(1, 1, N, 1, y - 1, -1);
        }
        if (s.empty()) {
            cout << 0 << "\n";
            continue;
        }
        auto uk = s.end();
        int yy = (*(--uk)).first;
        cout << get(1, 1, N, 1, yy) << "\n";
    }
    return 0;
}