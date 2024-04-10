#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node *left, *right;
    int one;
    int l, r;
    int lazyVal;
    
    Node(){};
    Node(int l, int r) {
        this->l = l;
        this->r = r;
        this->lazyVal = -1;
    }
    int getLength() {
        return this->r - this->l + 1;
    }
    void lazy() {
        if (this->lazyVal != -1) {
            if (this->l != this->r) {
                left->lazyVal = this->lazyVal;
                left->one = left->lazyVal ? left->getLength() : 0;

                right->lazyVal = this->lazyVal;
                right->one = right->lazyVal ? right->getLength() : 0;
            }
            this->lazyVal = -1;
        }
    }
    int get(int l, int r) {
        if (l > this->r or r < this->l) return 0;
        if (l <= this->l and this->r <= r) return this->one;

        lazy();
        return left->get(l, r) + right->get(l, r);
    }
    void update(int l, int r, int lazyVal) {
        // cerr << l << ' ' << r << ' ' << this->l << ' ' << this->r << ' ' << lazyVal << '\n';
        if (this->r < l || r < this->l) return;
        if (l <= this->l && this->r <= r) {
            this->lazyVal = lazyVal;
            this->one = lazyVal == 1 ? getLength() : 0;
            return;
        }
        lazy();

        left->update(l, r, lazyVal);
        right->update(l, r, lazyVal);
        this->one = left->one + right->one;
    }
};
Node* init(int l, int r, const string& s) {
    Node *p = new Node(l, r);
    if (l == r) {
        p->one = (s[l] == '1');
        return p;
    }
    int mid = (l + r) >> 1;
    p->left = init(l, mid, s);
    p->right = init(mid+1, r, s);
    p->one = p->left->one + p->right->one;
    return p;
}
int n, q;
string s, f;
Node* root;
bool solve() {
    cin >> n >> q >> s >> f;
    s = ' ' + s;
    f = ' ' + f;
    vector<tuple<int, int>> queries;
    for(int i = 0; i < q; ++i) {
        int li, ri; cin >> li >> ri;
        queries.emplace_back(li, ri);
    }
    reverse(queries.begin(), queries.end());
    root = init(1, n, f);
    for(auto query: queries) {
        int li, ri;
        tie(li, ri) = query;
        int one = root->get(li, ri);
        if (!one || one == ri-li+1) continue; 
        if (2 * one == ri - li  + 1) return false;
        if (2 * one > ri - li + 1) root->update(li, ri, 1);
        else root->update(li, ri, 0);
    }
    for(int i = 1; i <= n; ++i) {
        // cout << i << ' ' << i << ' ' << root->get(i, i) << '\n';
        if (root->get(i, i) != s[i] - '0') return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int ntest; cin >> ntest;
    for(; ntest; ntest --) {
        cout << (solve() ? "YES\n" : "NO\n");
    }
}