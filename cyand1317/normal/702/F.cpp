#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
static const int MAXN = 2e5 + 10;
static const int MAXK = 2e5 + 4;

int n, k;
#define quality first
#define cost    second
std::pair<int, int> t[MAXN];
#define query_val   first
#define query_id    second
std::pair<int, int> q[MAXK];
int ans[MAXK];

// A split-merge treap
namespace sm_treap {
int lch[MAXN], rch[MAXN], prio[MAXN], key[MAXN], key_tag[MAXN], val[MAXN], val_tag[MAXN];
int sz = 0;

inline void push(int idx) {
    if (lch[idx] != -1) {
        key_tag[lch[idx]] += key_tag[idx]; key[lch[idx]] += key_tag[idx];
        val_tag[lch[idx]] += val_tag[idx]; val[lch[idx]] += val_tag[idx];
    }
    if (rch[idx] != -1) {
        key_tag[rch[idx]] += key_tag[idx]; key[rch[idx]] += key_tag[idx];
        val_tag[rch[idx]] += val_tag[idx]; val[rch[idx]] += val_tag[idx];
    }
    key_tag[idx] = val_tag[idx] = 0;
}
inline void update(int idx) {
    puts("(?)");
}

inline int new_node(int K, int V) {
    lch[sz] = rch[sz] = -1;
    key[sz] = K; key_tag[sz] = 0;
    val[sz] = V; val_tag[sz] = 0;
    prio[sz] = (rand() << 16) | (rand() & ((1 << 16) - 1));
    return sz++;
}

// th is the threshold of key
// returns: root_lt, root_gte
std::pair<int, int> split(int idx, int th) {
    if (idx == -1) return std::make_pair(-1, -1);
    push(idx);
    if (key[idx] >= th) {
        std::pair<int, int> t = split(lch[idx], th);
        lch[idx] = t.second;
        //update(idx);
        return std::make_pair(t.first, idx);
    } else {
        std::pair<int, int> t = split(rch[idx], th);
        rch[idx] = t.first;
        //update(idx);
        return std::make_pair(idx, t.second);
    }
}
// returns: new_root
int merge(int u, int v) {
    if (u == -1) return v;
    if (v == -1) return u;
    push(u); push(v);
    if (prio[u] > prio[v]) {
        rch[u] = merge(rch[u], v);
        //update(u);
        return u;
    } else {
        lch[v] = merge(u, lch[v]);
        //update(v);
        return v;
    }
}

// returns: new_root
inline int insert(int idx, int w) {
    if (idx == -1) return w;
    std::pair<int, int> t = split(idx, key[w]);
    return merge(t.first, merge(w, t.second));
}
inline int insert(int idx, int K, int V) {
    return insert(idx, new_node(K, V));
}
// returns: new_root, orphaned_id
/*inline std::pair<int, int> remove(int idx, int th) {
    std::pair<int, int> t = split(idx, th - 1);
    std::pair<int, int> s = split(t.second, 1);
    return std::make_pair(merge(t.first, s.second), s.first);
}*/
}

// insert vertices in v into u one by one
int delta_cost;
int disassemble_and_insert(int u, int v) {
    using namespace sm_treap;
    if (v == -1) return u;
    push(v);
    int _l = lch[v], _r = rch[v];
    lch[v] = rch[v] = -1;
    key[v] -= delta_cost;
    val[v] += 1;
    u = insert(u, v);
    if (_l != -1) u = disassemble_and_insert(u, _l);
    if (_r != -1) u = disassemble_and_insert(u, _r);
    return u;
}
void traverse_push(int idx) {
    using namespace sm_treap;
    push(idx);
    if (lch[idx] != -1) traverse_push(lch[idx]);
    if (rch[idx] != -1) traverse_push(rch[idx]);
}

int main()
{
    srand(114514);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &t[i].cost, &t[i].quality);
        t[i].quality = -t[i].quality;
    }
    std::sort(t, t + n);
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        q[i].query_id = i;
        scanf("%d", &q[i].query_val);
    }

    int root = sm_treap::new_node(q[0].query_val, 0);
    for (int i = 1; i < k; ++i) {
        root = sm_treap::insert(root, q[i].query_val, 0);
    }
    std::pair<int, int> r;
    for (int i = 0; i < n; ++i) {
        int cur = t[i].cost;
        int t1, t2, t3; // t1 - [0, c); t2 - [c, 2c); t3 - [2c, +INF)
        r = sm_treap::split(root, cur);
        t1 = r.first;
        r = sm_treap::split(r.second, cur * 2);
        t2 = r.first; t3 = r.second;
        // Disassemble t2 and insert into t1
        delta_cost = cur;
        t1 = disassemble_and_insert(t1, t2);
        // Place lazy tags on t3
        if (t3 != -1) {
            sm_treap::key[t3] -= cur;
            sm_treap::key_tag[t3] -= cur;
            sm_treap::val[t3] += 1;
            sm_treap::val_tag[t3] += 1;
        }
        // Bring back together
        root = sm_treap::merge(t1, t3);
    }

    traverse_push(root);
    for (int i = 0; i < k; ++i) ans[q[i].query_id] = sm_treap::val[i];
    for (int i = 0; i < k; ++i) printf("%d%c", ans[i], i == k - 1 ? '\n' : ' ');

    return 0;
}