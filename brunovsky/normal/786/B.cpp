#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename Treap>
struct basic_treap {
    using uniform_priod = uniform_int_distribution<uint32_t>;
    static inline mt19937 rng = mt19937(random_device{}());
    static inline uniform_priod priod = uniform_priod(0, UINT32_MAX);

    Treap* kids[2] = {};
    uint32_t priority = priod(rng);

    static int get_size(const Treap* x) { return x ? x->size : 0; }
    static const auto& get_key(const Treap* x) { return x->key; }

  protected:
    basic_treap() : priority(priod(rng)) {}
    inline void pushdown() {}
    inline void pushup() {}

    Treap* self() { return static_cast<Treap*>(this); }
    const Treap* self() const { return static_cast<const Treap*>(this); }

  private:
    using TwoTreaps = pair<Treap*, Treap*>;
    using ThreeTreaps = tuple<Treap*, Treap*, Treap*>;

  public:
    Treap* clone() const {
        auto node = new Treap(*self());
        node->priority = priod(rng), node->kids[0] = node->kids[1] = nullptr;
        return node;
    }

    friend void delete_all(Treap* u) {
        if (u) {
            delete_all(u->kids[0]);
            delete_all(u->kids[1]);
            delete u;
        }
    }

    // Merge two treaps in order, returns the new root
    friend Treap* join(Treap* a, Treap* b) {
        if (!a || !b) {
            return !b ? a : b;
        }
        if (a->priority >= b->priority) {
            a->pushdown();
            a->kids[1] = join(a->kids[1], b);
            a->pushup();
            return a;
        } else {
            b->pushdown();
            b->kids[0] = join(a, b->kids[0]);
            b->pushup();
            return b;
        }
    }

    // Merge three treaps in order, returns the new root
    friend Treap* join(Treap* a, Treap* b, Treap* c) { return join(join(a, b), c); }

    friend Treap* push_back(Treap* root, Treap* item) {
        if (!root) {
            return item;
        }
        root->pushdown();
        if (root->priority < item->priority) {
            item->kids[0] = join(root, item->kids[0]);
            item->pushup();
            return item;
        } else {
            root->kids[1] = push_back(root->kids[1], item);
            root->pushup();
            return root;
        }
    }

    friend Treap* push_front(Treap*& root, Treap* item) {
        if (!root) {
            return item;
        }
        root->pushdown();
        if (root->priority < item->priority) {
            item->kids[1] = join(item->kids[1], root);
            item->pushup();
            return item;
        } else {
            root->kids[0] = push_front(root->kids[0], item);
            root->pushup();
            return root;
        }
    }

    // Pop element from the back of the treap. Returns {new root, popped element}
    friend TwoTreaps pop_back(Treap* root) {
        if (!root) {
            return {};
        }
        root->pushdown();
        if (!root->kids[1]) {
            Treap* kid = root->kids[0];
            root->kids[0] = nullptr;
            return {kid, root};
        } else {
            Treap* back;
            tie(root->kids[1], back) = pop_back(root->kids[1]);
            root->pushup();
            return {root, back};
        }
    }

    // Pop element from the front of the treap. Returns {new root, popped element}
    friend TwoTreaps pop_front(Treap* root) {
        if (!root) {
            return {};
        }
        root->pushdown();
        if (!root->kids[0]) {
            Treap* kid = root->kids[1];
            root->kids[1] = nullptr;
            return {kid, root};
        } else {
            Treap* front;
            tie(root->kids[0], front) = pop_front(root->kids[0]);
            root->pushup();
            return {root, front};
        }
    }

    friend Treap* delete_back(Treap* root) {
        auto [ans, last] = pop_back(root);
        delete last;
        return ans;
    }

    friend Treap* delete_front(Treap* root) {
        auto [ans, first] = pop_front(root);
        delete first;
        return ans;
    }

    template <typename Vis>
    friend void beats_visit(Treap* root, Vis&& vis) {
        if (!root || vis(root)) {
            return;
        }
        root->pushdown();
        beats_visit(root->kids[0], vis);
        beats_visit(root->kids[1], vis);
        root->pushup();
    }

    // ***** Order operations

    // Find the item with this exact order, or nullptr if order is out of bounds
    friend Treap* find_order(Treap* root, int order) {
        if (!root) {
            return nullptr;
        }
        root->pushdown();
        int rorder = get_size(root->kids[0]);
        if (rorder > order) {
            return find_order(root->kids[0], order);
        } else if (rorder < order) {
            return find_order(root->kids[1], order - rorder - 1);
        } else {
            return root;
        }
    }

    // Insert item just before the given order (accepts out of bounds orders)
    friend Treap* insert_order(Treap* root, Treap* item, int order) {
        if (!root) {
            return item;
        }
        root->pushdown();
        int rorder = get_size(root->kids[0]);
        if (root->priority < item->priority) {
            auto [a, b] = split_order(root, order);
            item->pushdown();
            item->kids[0] = join(a, item->kids[0]);
            item->kids[1] = join(item->kids[1], b);
            item->pushup();
            return item;
        } else if (rorder >= order) {
            root->kids[0] = insert_order(root->kids[0], item, order);
            root->pushup();
            return root;
        } else {
            root->kids[1] = insert_order(root->kids[1], item, order - rorder - 1);
            root->pushup();
            return root;
        }
    }

    // Split into two treaps: {node<order} {order<=node}
    friend TwoTreaps split_order(Treap* root, int order) {
        if (!root || order <= 0) {
            return {nullptr, root};
        }
        root->pushdown();
        int rorder = get_size(root->kids[0]);
        Treap* a = {};
        if (rorder >= order) {
            tie(a, root->kids[0]) = split_order(root->kids[0], order);
            root->pushup();
            return {a, root};
        } else {
            tie(root->kids[1], a) = split_order(root->kids[1], order - rorder - 1);
            root->pushup();
            return {root, a};
        }
    }

    // Split into three treaps: {node<start} {start<=node<end} {end<=node}
    friend ThreeTreaps split_order_range(Treap* root, int start, int end) {
        auto [mid, c] = split_order(root, end);
        auto [a, b] = split_order(mid, start);
        return make_tuple(a, b, c);
    }

    // Splice (remove but not delete) item with given order. Returns {new root, spliced}
    friend TwoTreaps splice_order(Treap* root, int order) {
        if (!root) {
            return {};
        }
        root->pushdown();
        int rorder = get_size(root->kids[0]);
        Treap* ans;
        if (rorder > order) {
            tie(root->kids[0], ans) = splice_order(root->kids[0], order);
            root->pushup();
        } else if (rorder < order) {
            tie(root->kids[1], ans) = splice_order(root->kids[1], order - rorder - 1);
            root->pushup();
        } else {
            ans = root, root = join(root->kids[0], root->kids[1]);
            ans->kids[0] = ans->kids[1] = nullptr;
            ans->pushup();
        }
        return {root, ans};
    }

    friend Treap* delete_order(Treap* root, int order) {
        auto [new_root, ans] = splice_order(root, order);
        delete ans;
        return new_root;
    }

    friend Treap* delete_order_range(Treap* root, int start, int end) {
        auto [a, b, c] = split_order_range(root, start, end);
        delete_all(b);
        return join(a, c);
    }

    template <typename Vis>
    friend void beats_visit_order(Treap* root, Vis&& vis, int order = 0) {
        if (!root || vis(root, order, order + get_size(root))) {
            return;
        }
        root->pushdown();
        beats_visit(root->kids[0], vis, order);
        beats_visit(root->kids[1], vis, order + get_size(root->kids[0]) + 1);
        root->pushup();
    }

    // ***** Key operations

    template <typename Key>
    friend int order_of_key(Treap* root, const Key& key) {
        if (!root) {
            return 0;
        }
        root->pushdown();
        int rorder = get_size(root->kids[0]);
        if (get_key(root) < key) {
            return order_of_key(root->kids[1], key) + rorder + 1;
        } else if (key < get_key(root)) {
            return order_of_key(root->kids[0], key);
        } else {
            return rorder;
        }
    }

    // Find first item s.t. item->key >= key, or nullptr for end (lower_bound)
    template <typename Key>
    friend Treap* after(Treap* root, const Key& key) {
        Treap* ahead = nullptr;
        while (root) {
            root->pushdown();
            if (!(get_key(root) < key)) {
                ahead = root;
                root = root->kids[0];
            } else {
                root = root->kids[1];
            }
        }
        return ahead;
    }

    // Find first item s.t. item->key > key, or nullptr for end (upper_bound)
    template <typename Key>
    friend Treap* strict_after(Treap* root, const Key& key) {
        Treap* ahead = nullptr;
        while (root) {
            root->pushdown();
            if (key < get_key(root)) {
                ahead = root, root = root->kids[0];
            } else {
                root = root->kids[1];
            }
        }
        return ahead;
    }

    // Find last item s.t. item->key <= key, or nullptr for end (reverse lower_bound)
    template <typename Key>
    friend Treap* before(Treap* root, const Key& key) {
        Treap* ahead = nullptr;
        while (root) {
            root->pushdown();
            if (!(key < get_key(root))) {
                ahead = root, root = root->kids[1];
            } else {
                root = root->kids[0];
            }
        }
        return ahead;
    }

    // Find last item s.t. item->key < key, or nullptr for end (reverse upper_bound)
    template <typename Key>
    friend Treap* strict_before(Treap* root, const Key& key) {
        Treap* ahead = nullptr;
        while (root) {
            root->pushdown();
            if (get_key(root) < key) {
                ahead = root, root = root->kids[1];
            } else {
                root = root->kids[0];
            }
        }
        return ahead;
    }

    // Find first item s.t. item->key = key
    template <typename Key>
    friend Treap* find_key(Treap* root, const Key& key) {
        while (root) {
            root->pushdown();
            if (key < get_key(root)) {
                root = root->kids[0];
            } else if (get_key(root) < key) {
                root = root->kids[1];
            } else {
                return root;
            }
        }
        return nullptr;
    }

    // Insert item(s) in search position, returning the item splayed
    friend Treap* insert_key(Treap* root, Treap* item) {
        if (!root) {
            return item;
        }
        root->pushdown();
        if (root->priority < item->priority) {
            auto [a, b] = split_key(root, get_key(item));
            item->pushdown();
            item->kids[0] = join(a, item->kids[0]);
            item->kids[1] = join(item->kids[1], b);
            item->pushup();
            return item;
        } else if (get_key(root) < get_key(item)) {
            root->kids[1] = insert_key(root->kids[1], item);
            root->pushup();
            return root;
        } else {
            root->kids[0] = insert_key(root->kids[0], item);
            root->pushup();
            return root;
        }
    }

    template <typename Key>
    friend TwoTreaps split_key(Treap* root, const Key& key) {
        if (!root) {
            return {nullptr, nullptr};
        }
        root->pushdown();
        Treap* a = {};
        if (get_key(root) < key) {
            tie(root->kids[1], a) = split_key(root->kids[1], key);
            root->pushup();
            return {root, a};
        } else {
            tie(a, root->kids[0]) = split_key(root->kids[0], key);
            root->pushup();
            return {a, root};
        }
    }

    template <typename Key>
    friend ThreeTreaps split_key_range(Treap* root, const Key& L, const Key& R) {
        auto [mid, c] = split_key(root, R);
        auto [a, b] = split_key(mid, L);
        return make_tuple(a, b, c);
    }

    // Splice (remove but not delete) item with given key. Returns {new root, spliced}
    template <typename Key>
    friend TwoTreaps splice_key(Treap* root, const Key& key) {
        if (!root) {
            return {};
        }
        root->pushdown();
        Treap* ans;
        if (key < get_key(root)) {
            tie(root->kids[0], ans) = splice_key(root->kids[0], key);
            root->pushup();
        } else if (get_key(root) < key) {
            tie(root->kids[1], ans) = splice_key(root->kids[1], key);
            root->pushup();
        } else {
            ans = root, root = join(root->kids[0], root->kids[1]);
            ans->kids[0] = ans->kids[1] = nullptr;
            ans->pushup();
        }
        return {root, ans};
    }

    template <typename Key>
    friend Treap* delete_key(Treap* root, const Key& key) {
        auto [new_root, ans] = splice_key(root, key);
        delete ans;
        return new_root;
    }

    template <typename Key>
    friend Treap* delete_key_range(Treap* root, const Key& L, const Key& R) {
        auto [a, b, c] = split_key_range(root, L, R);
        delete_all(b);
        return join(a, c);
    }

    // Meld two treaps, smaller into larger. O(B log A) if |A| >= |B|
    friend Treap* meld(Treap* A, Treap* B) {
        if (!A || !B) {
            return A ? A : B;
        }
        if (get_size(A) < get_size(B)) {
            swap(A, B);
        }
        visit_inorder(B, [&A](Treap* item) {
            item->kids[0] = item->kids[1] = nullptr;
            item->pushup();
            insert_key(A, item);
        });
        meld_dfs(A, B);
        return A;
    }

    friend Treap* meld(Treap* A, Treap* B, Treap* C) { return meld(meld(A, B), C); }

    friend Treap* delete_root(Treap* root) {
        if (!root) {
            return nullptr;
        }
        auto [L, R] = root->kids;
        delete root;
        return join(L, R);
    }

    // ***** Debugging/auxiliary

    template <typename Fn>
    friend void visit_inorder(Treap* node, Fn&& fn) {
        if (node) {
            node->pushdown();
            auto [a, b] = node->kids;
            visit_inorder(a, fn);
            fn(node);
            visit_inorder(b, fn);
        }
    }

    friend string format_inorder(Treap* node) {
        int id = 0;
        string s;
        visit_inorder(node, [&](Treap* child) {
            s += " [" + to_string(id++) + "] " + child->format() + '\n';
        });
        return s;
    }
};

// Remember: updates should generally maintain that the current node is up-to-date (does
// not need pushup) but may need pushdown.
struct Range {
    int L, R;

    bool operator<(Range o) const { return make_pair(L, R) < make_pair(o.L, o.R); }
    bool within(int i) const { return L <= i && i < R; }
};

struct Treap : basic_treap<Treap> {
    Range key, value;
    int weight = 0;
    int max_right = 0;

    explicit Treap(Range key, Range value, int w)
        : key(key), value(value), weight(w), max_right(key.R) {}

    void pushdown() {}

    void pushup() { max_right = max({key.R, get_right(kids[0]), get_right(kids[1])}); }

    static vector<tuple<int, int, int>> stab_query(Treap*& root, int i) {
        vector<tuple<int, int, int>> rs;
        root = stab_query_dfs(root, i, rs);
        return rs;
    }

    static Treap* stab_query_dfs(Treap* x, int i, vector<tuple<int, int, int>>& rs) {
        while (x && x->key.within(i)) {
            rs.emplace_back(x->value.L, x->value.R, x->weight);
            x = delete_root(x);
        }
        if (x && get_right(x->kids[0]) > i) {
            x->kids[0] = stab_query_dfs(x->kids[0], i, rs);
            x->pushup();
        }
        if (x && get_right(x->kids[1]) > i && x->key.L <= i) {
            x->kids[1] = stab_query_dfs(x->kids[1], i, rs);
            x->pushup();
        }
        return x;
    }

    static int get_right(const Treap* x) { return x ? x->max_right : 0; }
};

struct SetminTreap : basic_treap<SetminTreap> {
    static constexpr int64_t MAX = numeric_limits<int64_t>::max() / 2;

    int key;
    int64_t dist = MAX;
    int64_t minimum = MAX;
    int64_t set_lazy = MAX;

    explicit SetminTreap(int key, int64_t dist) : key(key), dist(dist), minimum(dist) {}

    void apply_setmin(int64_t setmin) {
        dist = min(dist, setmin);
        minimum = min(minimum, setmin);
        set_lazy = min(set_lazy, setmin);
    }

    void pushdown() {
        if (kids[0])
            kids[0]->apply_setmin(set_lazy);
        if (kids[1])
            kids[1]->apply_setmin(set_lazy);
        set_lazy = MAX;
    }

    void pushup() { minimum = min({dist, get_min(kids[0]), get_min(kids[1])}); }

    static SetminTreap* query_remove_min(SetminTreap* x, SetminTreap*& node) {
        x->pushdown();
        if (x->dist == x->minimum) {
            node = x;
            x = join(x->kids[0], x->kids[1]);
            node->kids[0] = node->kids[1] = nullptr, node->pushup();
        } else if (get_min(x->kids[0]) == x->minimum) {
            x->kids[0] = query_remove_min(x->kids[0], node);
            x->pushup();
        } else if (get_min(x->kids[1]) == x->minimum) {
            x->kids[1] = query_remove_min(x->kids[1], node);
            x->pushup();
        } else {
            assert(false);
        }
        return x;
    }

    static int64_t get_min(SetminTreap* x) { return x ? x->minimum : MAX; }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, Q, S;
    cin >> N >> Q >> S, S--;

    Treap* plans = nullptr;
    for (int i = 0; i < Q; i++) {
        if (int t; cin >> t, t == 1) {
            int u, v, w;
            cin >> u >> v >> w, u--, v--;
            plans = insert_key(plans, new Treap({u, u + 1}, {v, v + 1}, w));
        } else if (t == 2) {
            int u, L, R, w;
            cin >> u >> L >> R >> w, u--, L--, R--;
            plans = insert_key(plans, new Treap({u, u + 1}, {L, R + 1}, w));
        } else if (t == 3) {
            int L, R, v, w;
            cin >> v >> L >> R >> w, L--, R--, v--;
            plans = insert_key(plans, new Treap({L, R + 1}, {v, v + 1}, w));
        } else {
            assert(false);
        }
    }

    SetminTreap* nodes = nullptr;
    for (int i = 0; i < N; i++) {
        nodes = insert_key(nodes, new SetminTreap(i, i == S ? 0 : SetminTreap::MAX));
    }

    vector<int64_t> dist(N, SetminTreap::MAX);
    while (true) {
        SetminTreap* node;
        nodes = SetminTreap::query_remove_min(nodes, node);

        int i = node->key;
        dist[i] = node->dist;
        delete node;

        if (!nodes || dist[i] == SetminTreap::MAX) {
            break;
        }
        for (auto [L, R, w] : Treap::stab_query(plans, i)) {
            auto [a, b, c] = split_key_range(nodes, L, R);
            if (b) {
                b->apply_setmin(dist[i] + w);
            }
            nodes = join(a, b, c);
        }
    }

    for (int i = 0; i < N; i++) {
        cout << (dist[i] == SetminTreap::MAX ? -1 : dist[i]) << " \n"[i + 1 == N];
    }
    return 0;
}