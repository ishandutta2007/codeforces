#include <bits/stdc++.h>
using namespace std;

struct Node {
    int sum;
    Node *lc, *rc;

    Node(int val) : sum(val), lc(nullptr), rc(nullptr) {}
    Node(Node *l, Node *r)
        : sum((l ? l->sum : 0) + (r ? r->sum : 0)), lc(l), rc(r) {}

    Node *upd(int pos, int v, int l, int r) {
        if (pos >= r or pos < l)
            return this;
        if (r - l == 1) {
            return new Node(v);
        }
        int mid = (l + r) / 2;
        return new Node(lc->upd(pos, v, l, mid), rc->upd(pos, v, mid, r));
    }

    int get(int from, int to, int l, int r) const {
        if (from >= r or l >= to)
            return 0;
        if (from <= l and r <= to)
            return sum;
        int mid = (l + r) / 2;
        return lc->get(from, to, l, mid) + rc->get(from, to, mid, r);
    }

    static Node *build(int len) {
        if (len == 1)
            return new Node(0);
        return new Node(build(len / 2), build((len + 1) / 2));
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& i: a) {
        cin >> i;
        --i;
    }
    
    int const lim_val = *max_element(a.begin(), a.end()) + 1;
    
    vector<queue<int>> pos_queue(lim_val);
    
    Node* cur = Node::build(n);
    vector<Node*> events(n);
    
    for (int i = n; i--; ) {
        int v = a[i];
        if ((int)pos_queue[v].size() == k) {
            cur = cur->upd(pos_queue[v].front(), 0, 0, n);
            pos_queue[v].pop();
        }
        pos_queue[v].push(i);
        cur = cur->upd(i, 1, 0, n);
        events[i] = cur;
    }
    
    int last = 0;
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l = (l + last) % n + 1;
        r = (r + last) % n + 1;
        if (l > r) swap(l, r);
        --l;
        last = events[l]->get(l, r, 0, n);
        cout << last << '\n';
    }

    return 0;
}