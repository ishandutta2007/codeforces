#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

struct TNode {
    ll sz, y;
    TNode *left, *right;
    ll sum, x, pos;
};

TNode *new_node(ll x, ll pos) {
    return new TNode({1, rand(), nullptr, nullptr, x, x, pos});
}

ll safe_sz(TNode *root) {
    return (root ? root->sz : 0);
}

ll safe_sum(TNode *root) {
    return (root ? root->sum : 0);
}

void relax(TNode *root) {
    if (!root) return;
    root->sum = safe_sum(root->left) + safe_sum(root->right) + root->x;
    root->sz = safe_sz(root->left) + safe_sz(root->right) + 1;
}

TNode *merge(TNode *left, TNode *right) {
    if (!left) {
        return right;
    }
    if (!right) {
        return left;
    }
    if (left->y > right->y) {
        left->right = merge(left->right, right);
        relax(left);
        return left;
    } else {
        right->left = merge(left, right->left);
        relax(right);
        return right;
    }
}

pair <TNode*, TNode*> split(TNode *root, ll sz) {
    if (!root || !sz) {
        return {nullptr, root};
    }
    if (safe_sz(root->left) >= sz) {
        auto t = split(root->left, sz);
        root->left = t.second;
        relax(root);
        return {t.first, root};
    } else {
        sz -= safe_sz(root->left) + 1;
        auto t = split(root->right, sz);
        root->right = t.first;
        relax(root);
        return {root, t.second};
    }
}

TNode *insert(TNode *root, ll sz, ll x, ll pos) {
    auto t = split(root, sz);
    return merge(t.first, merge(new_node(x, pos), t.second));
}

TNode *erase_last(TNode *root) {
    auto t = split(root, safe_sz(root) - 1);
    return t.first;
}

ll find_pos(TNode *root) {
    if (!root) return -1;
    if (!root->right) {
        return root->pos;
    }
    return find_pos(root->right);
}

struct Tree {
    ll n;
    vector <ll> t;
    Tree(ll n) : n(n), t(2 * n, 0) {}
    void add(ll p, ll x) {
        p += n;
        while (p) {
            t[p] += x;
            p /= 2;
        }
    }
    ll get(ll l, ll r) {
        ll res = 0;
        for (l += n, r += n; l <= r; l /= 2, r /= 2) {
            if (l % 2) res += t[l++];
            if (r % 2 == 0) res += t[r--];
        }
        return res;
    }
};

ll n, m, T;

ll find_time(TNode *root) {
    if (!root) return 0;
    ll tm = 2 * safe_sum(root);
    ll x = safe_sz(root) % m;
    if (!x) {
        x = m;
    }
    auto t = split(root, safe_sz(root) - x);
    tm -= safe_sum(t.second);
    root = merge(t.first, t.second);
    return tm;
}

void solve() {
    cin >> n >> m >> T;
    vector <pair <ll, ll> > a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    ll rt = n;
    Tree t(n);
    TNode *root = nullptr;
    ll res = 0, d = 1;
    for (ll lt = 0; lt < (ll) a.size(); lt++) {
        ll cnt = t.get(0, a[lt].second);
        if (a[lt].second <= rt) {
            root = insert(root, cnt, a[lt].first, a[lt].second);
            t.add(a[lt].second, 1);
        }
        while (lt + 1 < a.size() && a[lt + 1].first == a[lt].first) {
            lt++;
            ll cnt = t.get(0, a[lt].second);
            if (a[lt].second <= rt) {
                root = insert(root, cnt, a[lt].first, a[lt].second);
                t.add(a[lt].second, 1);
            }
        }
        while (find_time(root) > T) {
            rt--;
            ll pos = find_pos(root);
            while (pos > rt) {
                root = erase_last(root);
                pos = find_pos(root);
                t.add(pos, -1);
            }
        }
        if (safe_sz(root) > res) {
            res = safe_sz(root);
            d = a[lt].first;
        }
    }
    cout << res << " " << d << "\n";
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int c;
    cin >> c;
    for (int i = 0; i < c; i++) {
        solve();
    }
}