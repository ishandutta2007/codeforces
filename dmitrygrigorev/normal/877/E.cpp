#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <deque>
#include <algorithm>
#include <math.h>
#include <random>
#define int long long

using namespace std;

typedef long long ll;

struct Node {
    int cnt;
    bool push;
    Node(int _cnt, bool _push) : cnt(_cnt), push(_push) {}
    Node() : cnt(0), push(false) {}
};

struct Point {
    int l, r;
    Point(int _l, int _r) : l(_l), r(_r) {}
    Point() : l(0), r(0) {}
};

int n, m, len = 1, idx;
vector<Point> scan;
vector<Node> tree;
vector<vector<int> > gr;
vector<int> color;

void dfs(int u, int pr) {
    tree[idx] = Node(color[u], false); scan[u].l = idx++;
    for (auto v : gr[u]) {
        if (v != pr)
            dfs(v, u);
    }
    tree[idx] = Node(color[u], false); scan[u].r = idx++;
}

void build() {
    for (int i = len - 2; i >= 0; --i) {
        tree[i] = Node(tree[i * 2 + 1].cnt + tree[i * 2 + 2].cnt, false);
    }
}

void push_ver(int l, int r, int root) {
    if (tree[root].push) {
        tree[root] = Node((r - l + 1) - tree[root].cnt, false);
        if (l != r) {
            tree[root * 2 + 1].push ^= 1;
            tree[root * 2 + 2].push ^= 1;
        }
    }
}

int get(int l, int r, int l1, int r1, int root) {
    push_ver(l, r, root);
    if (l >= l1 && r <= r1) {
        push_ver(l, r, root);
        return tree[root].cnt;
    } else if (max(l, l1) > min(r, r1)) {
        push_ver(l, r, root);
        return 0;
    } else {
        push_ver(l, r, root);
        return get(l,  (l + r) / 2, l1, r1, root * 2 + 1) + get((l + r) / 2 + 1, r, l1, r1, root * 2 + 2);
    }
}

void upd(int l, int r, int l1, int r1, int root) {
    push_ver(l, r, root);
    if (l >= l1 && r <= r1) {
        tree[root].push = true;
        push_ver(l, r, root);
    } else if (max(l, l1) > min(r, r1)) {
        push_ver(l, r, root);
    } else {
        push_ver(l, r, root);
        upd(l, (l + r) / 2, l1, r1, root * 2 + 1);
        upd((l + r) / 2 + 1, r, l1, r1, root * 2 + 2);
        if (l != r) {
            tree[root] = Node(tree[root * 2 + 1].cnt + tree[root * 2 + 2].cnt, false);
        }
    }
}

void solve() {
    cin >> n;
    while (len < n * 2) {
        len *= 2;
    }
    idx = len - 1;
    scan.resize(n);
    tree.resize(len + len - 1, Node(0, false));
    gr.resize(n);
    color.resize(n);
    for (int i = 1; i <= n - 1; ++i) {
        int tmp;
        cin >> tmp;
        gr[tmp - 1].push_back(i);
        gr[i].push_back(tmp - 1);
    }
    for (int i = 0; i < n; ++i) {
        cin >> color[i];
    }
    dfs(0, 0);
    build();
    cin >> m;
    for (int i = 0; i < m; ++i) {
        string req; int u;
        cin >> req >> u; --u;
        if (req == "get") {
            cout << get(len - 1, tree.size() - 1, scan[u].l, scan[u].r, 0) / 2 << '\n';
        } else {
            upd(len - 1, tree.size() - 1, scan[u].l, scan[u].r, 0);
        }
    }
}

signed main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
    return 0;
}