#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#include <cassert>
#include <iostream>
#include <queue>

using namespace std;

struct Node {
    Node *l, *r;
    int sum;
};

typedef Node* pNode;
Node nodes[5000000];
int cursor = 0;
pNode nill;

pNode alloc(pNode from = nill) {
    pNode ret = &(nodes[++cursor]);
    memcpy(ret, from, sizeof(Node));
    return ret;
}

void init() {
    nill = nodes;
    nill->l = nill->r = nill;
    nill->sum = 0;
}

pNode add(pNode root, int b, int e, int pos, int val) {
    root = alloc(root);
    
    root->sum += val;
    if (b == e) { assert(b == pos); return root; }
    int m = (b + e) / 2;

    if (pos <= m) root->l = add(root->l, b, m, pos, val);
    else root->r = add(root->r, m + 1, e, pos, val);
    return root;
}

int query(pNode root, int b, int e, int l) {
    if (b == e) return root->sum;

    int m = (b + e) / 2;
    if (l <= m) return root->r->sum + query(root->l, b, m, l);
    return query(root->r, m + 1, e, l);
}


deque<int> positions[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k; cin >> n >> k;
   
    //cerr << "n = " << n << endl;
    //return 0;
    
    init();
    pNode root = nill;
    vector<pNode> nodes(n);

    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        //cerr << i << ": " << x << endl;
        positions[x].push_back(i);
    
        root = add(root, 0, n - 1, i, 1);
        if (positions[x].size() > k) {
            int first = positions[x].front();
            positions[x].pop_front();
            root = add(root, 0, n - 1, first, -1);
        }
        nodes[i] = root;
    }

    //cerr << "Done step #1" << endl;

    int q; cin >> q;
    int ans = 0;
    while (q--) {
        int l, r; cin >> l >> r;
        l = 1 + (l + ans) % n;
        r = 1 + (r + ans) % n;
        if (l > r) swap(l, r);
        --l; --r;

        //cerr << "Real: " << l << " " << r << endl;

        ans = query(nodes[r], 0, n - 1, l);
        cout << ans << '\n';
    }
    

    return 0;
}