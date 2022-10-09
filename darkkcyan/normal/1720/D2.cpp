#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

typedef long long ll;
const ll inf = (ll)1e16;

ll max(ll u, ll v) {
    return u < v ? v : u;
}

void upd_max(ll* u, ll v) {
    *u = max(*u, v);
}

struct Trie;
typedef struct Trie *ptrie;
struct Trie {
    ptrie c[2];
    ll mx_val[2][2];
};

ptrie new_trie() {
    ptrie res = (ptrie)malloc(sizeof(struct Trie));
    memset(res->c, 0, sizeof(res->c));
    for (int i = 0; i < 2; ++i)
        for (int f = 0; f < 2; ++f)
            res->mx_val[i][f] = -inf;
    return res;
}

void free_trie(ptrie root) {
    if (!root) return ;
    free_trie(root->c[0]);
    free_trie(root->c[1]);
    free(root);
}

const int maxbit = 31;

void insert(ptrie root, int num, int pos, ll val) {
    int path = num ^ pos;
    for (int bit = maxbit; bit--; ) {
        upd_max(&root->mx_val[(num >> bit) & 1][(pos >> bit) & 1], val);
        int b = (path >> bit) & 1;
        if (!root->c[b]) {
            root->c[b] = new_trie();
        }
        root = root->c[b];
    }
    upd_max(&root->mx_val[num & 1][pos & 1], val);
}

ll get_mx(ptrie root, int num, int pos) {
    int path = num ^ pos;
    ll ans = 0;
    for (int bit = maxbit; bit--; ) {
        int nb = (num >> bit) & 1;
        int pb = (pos >> bit) & 1;
        
        for (int onb = 0; onb < 2; ++onb) {
            for (int opb = 0; opb < 2; ++opb) {
                if ((nb ^ opb) > (onb ^ pb)) {
                    ans = max(ans, root->mx_val[onb][opb]);
                }
            }
        }
        int b = (path >> bit) & 1;
        if (!root->c[b]) break;
        root = root->c[b];
    }
    return ans;
}

int main() {
    int ntest;
    scanf("%d", &ntest);
    while (ntest--) {
        int n;
        scanf("%d", &n);
        ptrie root = new_trie();
        
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            int a;
            scanf("%d", &a);
            ll t = get_mx(root, a, i) + 1;
            ans = max(ans, t);
            insert(root, a, i, t);
        }
        printf("%lld\n", ans);
    }
}