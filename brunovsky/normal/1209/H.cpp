#define NDEBUG
#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename Splay>
struct basic_splay {
    Splay* parent = nullptr;
    Splay* kids[2] = {};

  protected:
    basic_splay() = default;
    inline void pushdown() {}
    inline void pushup() {}

    Splay* self() { return static_cast<Splay*>(this); }
    const Splay* self() const { return static_cast<const Splay*>(this); }

  private:
    using TwoSplays = pair<Splay*, Splay*>;
    using ThreeSplays = tuple<Splay*, Splay*, Splay*>;

    static int get_size(const Splay* x) { return Splay::get_size(x); }
    static auto get_key(const Splay* x) { return Splay::get_key(x); }

    bool is_root() const { return !parent; }
    bool is_left() const { return parent && self() == parent->kids[0]; }
    bool is_right() const { return !parent && self() == parent->kids[1]; }

    static void adopt_node(Splay* parent, Splay* kid, int8_t side) {
        if (side >= 0)
            parent->kids[side] = kid;
        if (kid)
            kid->parent = parent;
    }

    static void attach_node(Splay* u, Splay* kid, int8_t side) {
        if (kid) {
            adopt_node(u, kid, side);
            u->pushup();
        }
    }

    static void rotate(Splay* u) {
        Splay *p = u->parent, *g = p->parent;
        int8_t u_side = u == p->kids[1];
        int8_t p_side = g ? p == g->kids[1] : -1;
        adopt_node(p, u->kids[!u_side], u_side);
        adopt_node(g, u, p_side);
        adopt_node(u, p, !u_side);
        p->pushup();
    }

    // Cut the edge from u to u->kids[side] and return the kid
    static Splay* detach_kid(Splay* u, int8_t side) {
        Splay* kid = u->kids[side];
        if (kid) {
            kid->parent = u->kids[side] = nullptr;
            u->pushup();
        }
        return kid;
    }

    // Cut the edge from u to its parent and return the parent
    static Splay* detach_parent(Splay* u) {
        Splay* parent = u->parent;
        if (parent) {
            parent->kids[u == parent->kids[1]] = u->parent = nullptr;
            parent->pushup();
        }
        return parent;
    }

    static Splay* min_node(Splay* u) {
        u->pushdown();
        while (u->kids[0])
            u = u->kids[0], u->pushdown();
        return u;
    }

    static Splay* max_node(Splay* u) {
        u->pushdown();
        while (u->kids[1])
            u = u->kids[1], u->pushdown();
        return u;
    }

    static Splay* findroot(Splay* u) {
        while (u->parent)
            u = u->parent, u->pushdown();
        return u;
    }

    static Splay* splay_unsafe(Splay* u) {
        if (!u->parent) {
            return u;
        }
        while (u->parent && u->parent->parent) {
            u->parent->parent->pushdown(), u->parent->pushdown(), u->pushdown();
            bool zigzig = u->is_right() == u->parent->is_right();
            rotate(zigzig ? u->parent : u), rotate(u);
        }
        if (u->parent) {
            u->parent->pushdown(), u->pushdown(), rotate(u);
        }
        u->pushdown(), u->pushup();
        return u;
    }

  public:
    Splay* clone() const {
        Splay* node = new Splay(*self());
        node = node->parent = node->kids[0] = node->kids[1] = nullptr;
        return node;
    }

    friend Splay* splay(Splay* u) {
        return u ? !u->parent ? u->pushdown(), u->pushup(), u : splay_unsafe(u) : nullptr;
    }

    friend void delete_all(Splay* u) {
        if (u) {
            delete_all(u->kids[0]);
            delete_all(u->kids[1]);
            delete u;
        }
    }

    friend Splay* predecessor(Splay*& tree, Splay* index) {
        if (!index) {
            return back(tree);
        } else if (index->kids[0]) {
            return tree = splay(max_node(index->kids[0]));
        } else {
            tree = splay(index);
            return index->kids[0] ? tree = splay(max_node(index->kids[0])) : nullptr;
        }
    }

    friend Splay* successor(Splay*& tree, Splay* index) {
        if (!index) {
            return front(tree);
        } else if (index->kids[1]) {
            return tree = splay(min_node(index->kids[1]));
        } else {
            tree = splay(index);
            return index->kids[1] ? tree = splay(min_node(index->kids[1])) : nullptr;
        }
    }

    friend Splay* insert_before(Splay*& tree, Splay* index, Splay* item) {
        if (!item) {
            return item;
        } else if (index) {
            if (!index->kids[0]) {
                attach_node(index, item, 0);
            } else {
                attach_node(max_node(index->kids[0]), item, 1);
            }
            return tree = splay(item);
        } else {
            return push_back(tree, item);
        }
    }

    friend Splay* insert_after(Splay*& tree, Splay* index, Splay* item) {
        if (!item) {
            return item;
        } else if (index) {
            if (!index->kids[1]) {
                attach_node(index, item, 1);
            } else {
                attach_node(min_node(index->kids[1]), item, 0);
            }
            return tree = splay(item);
        } else {
            return push_front(tree, item);
        }
    }

    friend Splay* back(Splay*& tree) {
        return tree ? tree = splay(max_node(tree)) : nullptr;
    }

    friend Splay* front(Splay*& tree) {
        return tree ? tree = splay(min_node(tree)) : nullptr;
    }

    friend Splay* push_back(Splay*& tree, Splay* item) {
        if (item) {
            return tree = tree ? attach_node(max_node(tree), item, 1), splay(item) : item;
        }
        return item;
    }

    friend Splay* push_front(Splay*& tree, Splay* item) {
        if (item) {
            tree = tree ? attach_node(min_node(tree), item, 0), splay(item) : item;
        }
        return item;
    }

    friend Splay* pop_back(Splay*& tree) {
        if (tree) {
            Splay* item = splay(max_node(tree));
            tree = detach_kid(item, 0);
            return item;
        }
        return nullptr;
    }

    friend Splay* pop_front(Splay*& tree) {
        if (tree) {
            Splay* item = splay(min_node(tree));
            tree = detach_kid(item, 1);
            return item;
        }
        return nullptr;
    }

    friend void delete_back(Splay*& tree) {
        if (tree) {
            Splay* item = pop_back(tree);
            delete item;
        }
    }

    friend void delete_front(Splay*& tree) {
        if (tree) {
            Splay* item = pop_front(tree);
            delete item;
        }
    }

    // Access the range (L...R). If L,R are both null it accesses everything
    friend Splay* access_exclusive(Splay*& tree, Splay* L, Splay* R) {
        Splay* S = nullptr;
        if (L && R) {
            splay(R), splay(L);
            if (R->parent != L) {
                R->parent->pushdown();
                R->pushdown();
                rotate(R);
                R->pushup();
            }
            assert(R->parent == L);
            S = R->kids[R->is_left()];
        } else if (L) {
            S = splay(L)->kids[1];
        } else if (R) {
            S = splay(R)->kids[0];
        } else {
            return tree;
        }
        if (S) {
            S->pushdown(), S->pushup();
        }
        tree = L ? L : R;
        return S;
    }

    friend Splay* access_inclusive(Splay*& tree, Splay* L, Splay* R) {
        return access_exclusive(tree, predecessor(tree, L), successor(tree, R));
    }

    friend Splay* access_range(Splay*& tree, Splay* L, Splay* R) {
        return access_exclusive(tree, predecessor(tree, L), R);
    }

    // Splice the range (L...R). If L,R are both null it splices everything
    friend Splay* splice_exclusive(Splay*& tree, Splay* L, Splay* R) {
        Splay* M = access_exclusive(tree, L, R);
        if (M && M->parent) {
            tree = splay(detach_parent(M));
        } else if (M) {
            tree = nullptr;
        }
        return M;
    }

    friend Splay* splice_inclusive(Splay*& tree, Splay* L, Splay* R) {
        Splay* M = access_inclusive(tree, L, R);
        if (M && M->parent) {
            tree = splay(detach_parent(M));
        } else if (M) {
            tree = nullptr;
        }
        return M;
    }

    friend Splay* splice_range(Splay*& tree, Splay* L, Splay* R) {
        Splay* M = access_range(tree, L, R);
        if (M && M->parent) {
            tree = splay(detach_parent(M));
        } else if (M) {
            tree = nullptr;
        }
        return M;
    }

    // Delete the range (L...R). If L,R are both null it deletes everything
    friend void delete_exclusive(Splay*& tree, Splay* L, Splay* R) {
        delete_all(splice_exclusive(tree, L, R));
    }

    friend void delete_inclusive(Splay*& tree, Splay* L, Splay* R) {
        delete_all(splice_inclusive(tree, L, R));
    }

    friend void delete_range(Splay*& tree, Splay* L, Splay* R) {
        delete_all(splice_range(tree, L, R));
    }

    // Splice (remove but not delete) one item from the sequence
    friend Splay* splice_item(Splay*& tree, Splay* item) {
        return splice_inclusive(tree, item, item);
    }

    friend void delete_item(Splay*& tree, Splay* item) { delete splice_item(tree, item); }

    // Split into two sequences: [...A)[A...)
    friend TwoSplays split_before(Splay*& tree, Splay* node) {
        if (node) {
            splay(node);
            return {detach_kid(node, 0), node};
        } else {
            return {tree, nullptr};
        }
    }

    // Split into two sequences: [...A](A...)
    friend TwoSplays split_after(Splay*& tree, Splay* node) {
        if (node) {
            splay(node);
            return {node, detach_kid(node, 1)};
        } else {
            return {nullptr, tree};
        }
    }

    // Split into three sequences: [...A)[A...B)[B...)
    friend ThreeSplays split_range(Splay*& tree, Splay* A, Splay* B) {
        auto [mid, c] = split_before(tree, B);
        auto [a, b] = split_before(mid, A);
        return {a, b, c};
    }

    friend Splay* join(Splay* A, Splay* B) {
        if (!A || !B) {
            return A ? A : B;
        }
        splay(A), splay(B), assert(A->is_root() && A != B);
        Splay* root = splay(max_node(A));
        attach_node(root, B, 1);
        return root;
    }

    friend Splay* join(Splay* A, Splay* B, Splay* C) { return join(join(A, B), C); }

    friend Splay* join_if_disjoint(Splay* A, Splay* B) {
        if (!A || !B || A == B) {
            return A ? A : B;
        }
        splay(A), splay(B);
        if (A->is_root()) {
            Splay* root = splay(max_node(A));
            attach_node(root, B, 1);
            return root;
        } else {
            return B;
        }
    }

    friend Splay* join_if_disjoint(Splay* A, Splay* B, Splay* C) {
        return join_if_disjoint(join_if_disjoint(A, B), C);
    }

    template <typename... Args>
    [[nodiscard]] static Splay* construct(int N, Args&&... args) {
        if (N == 0) {
            return nullptr;
        } else {
            Splay* node = new Splay(args...);
            attach_node(node, construct(N / 2, args...), 0);
            attach_node(node, construct((N - 1) / 2, args...), 1);
            return node;
        }
    }

    template <typename T>
    [[nodiscard]] static Splay* construct_array(int N, const vector<T>& arr, int s = 0) {
        if (N == 0) {
            return nullptr;
        } else {
            int L = N / 2, R = (N - 1) / 2;
            Splay* node = new Splay(arr[s + L]);
            attach_node(node, construct_array(L, arr, s), 0);
            attach_node(node, construct_array(R, arr, s + 1 + L), 1);
            return node;
        }
    }

    // ***** Order operations

    // Find order of an item (0-indexed)
    friend int order_of_node(Splay*& tree, Splay* item) {
        if (item) {
            tree = splay(item);
            return tree ? get_size(tree->kids[0]) : 0;
        } else {
            return get_size(tree);
        }
    }

    // Find the item with this exact order, or nullptr if order is out of bounds
    friend Splay* find_order(Splay*& tree, int order) {
        if (!tree || order < 0 || order >= get_size(tree)) {
            return nullptr;
        }
        while (true) {
            tree->pushdown();
            int left = get_size(tree->kids[0]);
            if (order < left) {
                tree = tree->kids[0];
            } else if (order > left) {
                order -= left + 1;
                tree = tree->kids[1];
            } else {
                return splay(tree);
            }
        }
    }

    // Insert item just before the given order (accepts out of bounds orders)
    friend Splay* insert_order(Splay*& tree, Splay* item, int order) {
        if (!tree) {
            return tree = item;
        } else if (order <= 0) {
            return push_front(tree, item);
        } else if (order >= get_size(tree)) {
            return push_back(tree, item);
        } else {
            return insert_before(tree, find_order(tree, order), item);
        }
    }

    // Access the nodes s.t. L < order(u) < R. If L<0 and R>=size that's everything
    friend Splay* access_order_exclusive(Splay*& tree, int L, int R) {
        assert(L <= R);
        if (!tree || R <= 0 || L >= get_size(tree) || L + 1 >= R) {
            return nullptr;
        } else {
            auto A = find_order(tree, L);
            auto B = find_order(tree, R);
            return access_exclusive(tree, A, B);
        }
    }

    friend Splay* access_order_inclusive(Splay*& tree, int L, int R) {
        return access_order_exclusive(tree, L - 1, R + 1);
    }

    friend Splay* access_order_range(Splay*& tree, int L, int R) {
        return access_order_exclusive(tree, L - 1, R);
    }

    // Splice the nodes s.t. L < order(u) < R. If L<0 and R>=size that's everything
    friend Splay* splice_order_exclusive(Splay*& tree, int L, int R) {
        assert(L <= R);
        if (!tree || R <= 0 || L >= get_size(tree) - 1 || L + 1 >= R) {
            return nullptr;
        } else {
            auto A = find_order(tree, L);
            auto B = find_order(tree, R);
            return splice_exclusive(tree, A, B);
        }
    }

    friend Splay* splice_order_inclusive(Splay*& tree, int L, int R) {
        return splice_order_exclusive(tree, L - 1, R + 1);
    }

    friend Splay* splice_order_range(Splay*& tree, int L, int R) {
        return splice_order_exclusive(tree, L - 1, R);
    }

    // Delete the nodes s.t. L < order(u) < R. If L<0 and R>=size that's everything
    friend void delete_order_exclusive(Splay*& tree, int L, int R) {
        assert(L <= R);
        if (!tree || R <= 0 || L >= get_size(tree) - 1 || L + 1 >= R) {
            return;
        } else {
            auto A = find_order(tree, L);
            auto B = find_order(tree, R);
            delete_exclusive(tree, A, B);
        }
    }

    friend void delete_order_inclusive(Splay*& tree, int L, int R) {
        delete_order_exclusive(tree, L - 1, R + 1);
    }

    friend void delete_order_range(Splay*& tree, int L, int R) {
        delete_order_exclusive(tree, L - 1, R);
    }

    // Splice (remove but not delete) one item from the sequence
    friend Splay* splice_order(Splay*& tree, int order) {
        auto node = find_order(tree, order);
        if (node) {
            tree = join(detach_kid(tree, 0), detach_kid(tree, 1));
            return node;
        } else {
            return nullptr;
        }
    }

    friend void delete_order(Splay*& tree, int order) {
        delete splice_order(tree, order);
    }

    // Split into two sequences: {order(u)<order} {order<=order(u)}
    friend TwoSplays split_order(Splay*& tree, int order) {
        if (order >= 1) {
            return split_before(tree, find_order(tree, order));
        } else {
            return {nullptr, tree};
        }
    }

    // Split into three sequences: {order(u)<L} {L<=order(u)<R} {R<=order(u)}
    friend ThreeSplays split_order_range(Splay*& tree, int L, int R) {
        auto [mid, c] = split_order(tree, R);
        auto [a, b] = split_order(mid, L);
        return {a, b, c};
    }

    // ***** Key operations

    // Find first item s.t. item->key >= key, or nullptr for end (lower_bound)
    template <typename Key>
    friend Splay* after(Splay*& tree, const Key& key) {
        Splay *valid = nullptr, *last = tree;
        while (tree) {
            last = tree, tree->pushdown();
            if (!(get_key(tree) < key)) {
                valid = tree, tree = tree->kids[0];
            } else {
                tree = tree->kids[1];
            }
        }
        tree = splay(last);
        return valid;
    }

    // Find first item s.t. item->key > key, or nullptr for end (upper_bound)
    template <typename Key>
    friend Splay* strict_after(Splay*& tree, const Key& key) {
        Splay *valid = nullptr, *last = tree;
        while (tree) {
            last = tree, tree->pushdown();
            if (key < get_key(tree)) {
                valid = tree, tree = tree->kids[0];
            } else {
                tree = tree->kids[1];
            }
        }
        tree = splay(last);
        return valid;
    }

    // Find last item s.t. item->key <= key, or nullptr for end (reverse lower_bound)
    template <typename Key>
    friend Splay* before(Splay*& tree, const Key& key) {
        Splay *valid = nullptr, *last = nullptr;
        while (tree) {
            last = tree, tree->pushdown();
            if (!(key < get_key(tree))) {
                valid = tree, tree = tree->kids[1];
            } else {
                tree = tree->kids[0];
            }
        }
        tree = splay(last);
        return valid;
    }

    // Find last item s.t. item->key < key, or nullptr for end (reverse upper_bound)
    template <typename Key>
    friend Splay* strict_before(Splay*& tree, const Key& key) {
        Splay *valid = nullptr, *last = nullptr;
        while (tree) {
            last = tree, tree->pushdown();
            if (get_key(tree) < key) {
                valid = tree, tree = tree->kids[1];
            } else {
                tree = tree->kids[0];
            }
        }
        tree = splay(last);
        return valid;
    }

    // Find first item s.t. item->key = key
    template <typename Key>
    friend Splay* find_key(Splay*& tree, const Key& key) {
        Splay* last = nullptr;
        while (tree) {
            last = tree, tree->pushdown();
            if (key < get_key(tree)) {
                tree = tree->kids[0];
            } else if (get_key(tree) < key) {
                tree = tree->kids[1];
            } else {
                return splay(tree);
            }
        }
        tree = splay(last);
        return nullptr;
    }

    // Insert item(s) in search position, returning the item splayed
    friend Splay* insert_key(Splay*& tree, Splay* item) {
        if (!item) {
            return tree;
        } else if (!tree) {
            return tree = item;
        } else if (Splay* ahead = after(tree, get_key(item))) {
            return insert_before(tree, ahead, item);
        } else {
            return push_back(tree, item);
        }
    }

    // Access the nodes s.t. L < node->key < R, possibly nullptr if none
    template <typename Key>
    friend Splay* access_key_exclusive(Splay*& tree, const Key& L, const Key& R) {
        assert(!(R < L));
        auto A = before(tree, L);
        auto B = after(tree, R);
        return access_exclusive(tree, A, B);
    }

    template <typename Key>
    friend Splay* access_key_inclusive(Splay*& tree, const Key& L, const Key& R) {
        assert(!(R < L));
        auto A = strict_before(tree, L);
        auto B = strict_after(tree, R);
        return access_exclusive(tree, A, B);
    }

    template <typename Key>
    friend Splay* access_key_range(Splay*& tree, const Key& L, const Key& R) {
        assert(!(R < L));
        auto A = strict_before(tree, L);
        auto B = after(tree, R);
        return access_exclusive(tree, A, B);
    }

    // Splice the range of nodes s.t. L < node->key < R
    template <typename Key>
    friend Splay* splice_key_exclusive(Splay*& tree, const Key& L, const Key& R) {
        assert(!(R < L));
        auto A = before(tree, L);
        auto B = after(tree, R);
        return splice_exclusive(tree, A, B);
    }

    template <typename Key>
    friend Splay* splice_key_inclusive(Splay*& tree, const Key& L, const Key& R) {
        assert(!(R < L));
        auto A = strict_before(tree, L);
        auto B = strict_after(tree, R);
        return splice_exclusive(tree, A, B);
    }

    template <typename Key>
    friend Splay* splice_key_range(Splay*& tree, const Key& L, const Key& R) {
        assert(!(R < L));
        auto A = strict_before(tree, L);
        auto B = after(tree, R);
        return splice_exclusive(tree, A, B);
    }

    // Delete the range of nodes s.t. L < node->key < R
    template <typename Key>
    friend void delete_key_exclusive(Splay*& tree, const Key& L, const Key& R) {
        assert(!(R < L));
        auto A = before(tree, L);
        auto B = after(tree, R);
        delete_exclusive(tree, A, B);
    }

    template <typename Key>
    friend void delete_key_inclusive(Splay*& tree, const Key& L, const Key& R) {
        assert(!(R < L));
        auto A = strict_before(tree, L);
        auto B = strict_after(tree, R);
        delete_exclusive(tree, A, B);
    }

    template <typename Key>
    friend void delete_key_range(Splay*& tree, const Key& L, const Key& R) {
        assert(!(R < L));
        auto A = strict_before(tree, L);
        auto B = after(tree, R);
        delete_exclusive(tree, A, B);
    }

    // Splice the first item with exact given key
    template <typename Key>
    friend Splay* splice_key(Splay*& tree, const Key& key) {
        if (auto item = find_key(tree, key)) {
            return splice_item(tree, item);
        } else {
            return nullptr;
        }
    }

    template <typename Key>
    friend void delete_key(Splay*& tree, const Key& key) {
        delete splice_key(tree, key);
    }

    // Split into two sequences: {node<key} {key<=node}
    template <typename Key>
    friend TwoSplays split_key(Splay*& tree, const Key& key) {
        if (auto succ = after(tree, key)) {
            return split_before(tree, succ);
        } else {
            return {tree, nullptr};
        }
    }

    // Split into three sequences: {node<L} {L<=node<R} {R<=node}
    template <typename Key>
    friend ThreeSplays split_key_range(Splay*& tree, const Key& L, const Key& R) {
        auto [mid, c] = split_key(tree, R);
        auto [a, b] = split_key(mid, L);
        return {a, b, c};
    }

    // Meld two splay trees, smaller into larger. O(B log A) if |A| >= |B|
    friend Splay* meld(Splay* A, Splay* B) {
        if (!A || !B) {
            return A ? A : B;
        }
        if (get_size(A) < get_size(B)) {
            swap(A, B);
        }
        visit_inorder(B, [&A](Splay* item) {
            item->kids[0] = item->kids[1] = item->parent = nullptr;
            item->pushup();
            insert_key(A, item);
        });
        return A;
    }

    friend Splay* meld(Splay* A, Splay* B, Splay* C) { return meld(meld(A, B), C); }

    // ***** Debugging

    friend vector<Splay*> get_inorder_vector(Splay* node) {
        vector<Splay*> vec;
        visit_inorder(node, [&vec](Splay* x) { vec.push_back(x); });
        return vec;
    }

    template <typename Fn>
    friend void visit_inorder(Splay* node, Fn&& fn) {
        if (node) {
            node->pushdown();
            auto [a, b] = node->kids;
            visit_inorder(a, fn);
            fn(node);
            visit_inorder(b, fn);
        }
    }

    friend string format_inorder(Splay* node) {
        int id = 0;
        string s;
        visit_inorder(node, [&](Splay* child) {
            s += " [" + to_string(id++) + "] " + child->format() + '\n';
        });
        return s;
    }
};

constexpr double eps = 1e-9;

// Splay tree that represents the branches of a bounded convex piecewise linear function
// with integer slopes, dangling on an implicit vertex. Supports pointwise addition and
// minplus convolution (small to large), inversion and evaluation in O(log n)
struct Branch : basic_splay<Branch> {
    using V = double;
    int size = 1, flip = 0;
    V slope = 0, width = 0, sum = 0, height = 0, lazy = 0;

    explicit Branch(V slope, V len)
        : slope(slope), width(len), sum(len), height(slope * len) {}

    static int get_size(const Branch* x) { return x ? x->size : 0; }
    static V get_key(const Branch* x) { return x->slope; }
    static V get_sum(const Branch* x) { return x ? x->sum : 0; }
    static V get_height(const Branch* x) { return x ? x->height : 0; }

    inline V val() const { return width * slope; }
    void adjust_width(V add) { width += add, sum += add, height += add * slope; }
    void update_range(V add) { slope += add, lazy += add, height += add * sum; }
    void invert_range() { flip ^= 1, slope = -slope, height = -height, lazy = -lazy; }

    void pushdown() {
        if (flip) {
            if (kids[0])
                kids[0]->invert_range();
            if (kids[1])
                kids[1]->invert_range();
            swap(kids[0], kids[1]);
            flip = 0;
        }
        if (lazy) {
            if (kids[0])
                kids[0]->update_range(lazy);
            if (kids[1])
                kids[1]->update_range(lazy);
            lazy = 0;
        }
    }

    void pushup() {
        sum = width + get_sum(kids[0]) + get_sum(kids[1]);
        size = 1 + get_size(kids[0]) + get_size(kids[1]);
        height = val() + get_height(kids[0]) + get_height(kids[1]);
    }

    static void insert_segment(Branch*& tree, V slope, V width) {
        if (width <= 0) {
            return;
        } else if (auto pos = after(tree, slope); pos && pos->slope <= slope) {
            pos->adjust_width(width), tree = splay(pos);
        } else {
            insert_before(tree, pos, new Branch(slope, width));
        }
    }

    // Find the node responsible for x=rank. If this lies at the beginning of a node
    // x, it returns x, otherwise it cuts x and returns its successor node
    static auto find_by_rank(Branch*& tree, V rank) -> Branch* {
        if (!tree || get_sum(tree) <= rank) {
            return nullptr;
        } else if (rank <= 0) {
            auto a = new Branch(front(tree)->slope, 0);
            return push_front(tree, a);
        }
        assert(rank >= 0);
        Branch* node = tree;
        while (node) {
            node->pushdown();
            if (rank < get_sum(node->kids[0])) {
                node = node->kids[0];
            } else if (rank -= get_sum(node->kids[0]); rank < node->width) {
                V rest = node->width - rank;
                node->adjust_width(rank - node->width);
                tree = splay(node);
                return insert_after(tree, node, new Branch(node->slope, rest));
            } else {
                rank -= node->width;
                node = node->kids[1];
            }
        }
        auto b = new Branch(back(tree)->slope, 0);
        return push_back(tree, b);
    }

    // Find the earliest x for which slope after x is >= to given slope
    static V slope_rank(Branch*& tree, V slope) {
        auto node = after(tree, slope);
        return node ? get_sum(node->kids[0]) : get_sum(tree);
    }

    // Find the range [L,R] of ranks where function attains values <=ceiling.
    // If no range satisfies this it returns {-1,-1}. O(log n)
    static auto ceiling_range(Branch*& tree, V ceiling) {
        auto [left, zero, right] = split_key_range(tree, 0, 1);
        auto bottom = get_height(left);
        pair<V, V> ans = {-1, -1};

        if (ceiling < bottom) {
            tree = join(left, zero, right);
            return ans;
        }

        ans = {get_sum(left), get_sum(left) + get_sum(zero)};
        V prefix = bottom - ceiling, suffix = ceiling - bottom;
        Branch *node, *previous;

        node = previous = left;
        while (node) {
            previous = node, node->pushdown();
            if (prefix > get_height(node->kids[1])) {
                node = node->kids[1];
            } else if (prefix -= get_height(node->kids[1]); prefix > node->val()) {
                ans.first -= get_sum(node->kids[1]) + (prefix / node->slope);
                break;
            } else {
                prefix -= node->val();
                ans.first -= get_sum(node->kids[1]) + node->width;
                node = node->kids[0];
            }
        }
        left = splay(previous);

        node = previous = right;
        while (node) {
            previous = node, node->pushdown();
            if (suffix < get_height(node->kids[0])) {
                node = node->kids[0];
            } else if (suffix -= get_height(node->kids[0]); suffix < node->val()) {
                ans.second += get_sum(node->kids[0]) + (suffix / node->slope);
                break;
            } else {
                suffix -= node->val();
                ans.second += get_sum(node->kids[0]) + node->width;
                node = node->kids[1];
            }
        }
        right = splay(previous);

        tree = join(left, zero, right);
        return ans;
    }

    // Split the tree into two branches [0,rank) and [rank,...)
    static auto split_rank_range(Branch*& tree, V rank) {
        rank = max<V>(0, min<V>(rank, get_sum(tree)));
        auto A = find_by_rank(tree, rank);
        return split_before(tree, A);
    }

    // Split the tree into three branches [0,L) and [L,R) and [R,...)
    static auto access_rank_range(Branch*& tree, V L, V R) {
        L = max<V>(0, min<V>(L, get_sum(tree)));
        R = max<V>(L, min<V>(R, get_sum(tree)));
        auto B = find_by_rank(tree, R);
        auto A = find_by_rank(tree, L);
        return split_range(tree, A, B);
    }

    // Query height at given rank. O(log n)
    static V query(Branch*& tree, V rank) {
        if (rank <= 0) {
            return 0;
        } else if (get_sum(tree) <= rank) {
            return get_height(tree);
        }
        V prefix = 0;
        Branch* previous = tree;
        Branch* node = tree;
        while (node) {
            previous = node;
            node->pushdown();
            if (rank < get_sum(node->kids[0])) {
                node = node->kids[0];
            } else if (rank -= get_sum(node->kids[0]); rank < node->width) {
                prefix += get_height(node->kids[0]) + node->slope * rank;
                break;
            } else {
                prefix += get_height(node->kids[0]) + node->slope * node->width;
                rank -= node->width;
                node = node->kids[1];
            }
        }
        tree = splay(previous);
        return prefix;
    }

    // Minplus convolution of two branches, the caller tracks the vertex shift.
    // Small to large merge. O(min(a,b) log max(a,b))
    static void minplus(Branch*& a, Branch*& b) {
        if (get_size(a) < get_size(b)) {
            swap(a, b);
        }
        while (b) {
            auto x = pop_front(b);
            if (auto pos = after(a, x->slope); !pos) {
                push_back(a, x);
                push_back(a, b);
                break;
            } else {
                insert_before(a, pos, x);
            }
        }
    }

    // Pointwise addition of two branches, the caller tracks the vertex shift.
    // Small to large. O(min(a,b) log max(a,b)). Restricts to common domain.
    static void pointwise(Branch*& a, Branch*& b, V av, V bv) {
        V A = get_sum(a), ar = av + A;
        V B = get_sum(b), br = bv + B;
        trim_front(a, max<V>(0, bv - av));
        trim_front(b, max<V>(0, av - bv));
        trim_back(a, max<V>(0, ar - br));
        trim_back(b, max<V>(0, br - ar));
        if (get_size(a) < get_size(b)) {
            swap(a, b);
        }
        V rank = 0;
        while (b) {
            auto node = pop_front(b);
            auto [x, y, z] = access_rank_range(a, rank, rank + node->width);
            rank += node->width;
            y->update_range(node->slope);
            if (Branch* c = back(x), *d = front(y); c && c->slope >= d->slope) {
                d->adjust_width(c->width), y = splay(d), delete_back(x);
            }
            a = join(x, y, z);
            delete node;
        }
    }

    // Trim the left end of the tree by given length
    static void trim_front(Branch*& tree, V amount) {
        if (amount <= 0) {
            return;
        } else if (amount >= get_sum(tree)) {
            delete_all(tree), tree = nullptr;
        } else {
            auto node = find_by_rank(tree, amount);
            delete_exclusive(tree, nullptr, node);
        }
    }

    // Trim the right end of the tree by given length
    static void trim_back(Branch*& tree, V amount) {
        if (amount <= 0) {
            return;
        } else if (amount >= get_sum(tree)) {
            delete_all(tree), tree = nullptr;
        } else {
            auto node = find_by_rank(tree, get_sum(tree) - amount);
            delete_range(tree, node, nullptr);
        }
    }

    // Trim branch to [L,R) of current domain
    static void trimto(Branch*& tree, V L, V R) {
        L = max<V>(L, 0), R = min<V>(R, get_sum(tree));
        trim_back(tree, get_sum(tree) - R), trim_front(tree, L);
    }

#ifdef LOCAL
    string format() const { return fmt::format("({},{})", slope, width); }
#endif
};

// Branch wrapper that represents the complete function, tracking vertex and value there
struct Slopy {
    using V = Branch::V;
    static constexpr V inf = numeric_limits<V>::max() / 4;
    Branch* tree = nullptr;
    V v = 0, y = 0; // vertex, y value there

    // f(x) = {0 for x=0}
    Slopy() = default;

    void clear() { delete_all(tree), tree = nullptr, v = y = 0; }

    static Slopy point(V x, V y) {
        Slopy fn;
        fn.v = x, fn.y = y;
        return fn;
    }

    // f(x) = {y for L<=x<=R}
    static Slopy constant(V L, V R, V y) {
        assert(L <= R);
        Slopy fn;
        fn.v = L, fn.y = y;
        Branch::insert_segment(fn.tree, 0, R - L);
        return fn;
    }

    // f(x) = {a(x-L)+y for L<=x<=R}
    static Slopy slope(V a, V L, V R, V y) {
        assert(L <= R);
        Slopy fn;
        fn.v = L, fn.y = y;
        Branch::insert_segment(fn.tree, a, R - L);
        return fn;
    }

    // f(x) = ax+b for L<=x<=R
    static Slopy linear(V a, V b, V L, V R) {
        assert(L <= R);
        Slopy fn;
        fn.v = L, fn.y = a * L + b;
        Branch::insert_segment(fn.tree, a, R - L);
        return fn;
    }

    // f(x) = {a(A-x)+y if L<=x<=A | y if A<=x<=B | b(x-B) if B<=x<=R | for L<=x<=R}
    static Slopy valley(V a, V b, V L, V A, V B, V R, V y) {
        assert(a >= 0 && b >= 0 && L <= A && A <= B && B <= R);
        Slopy fn;
        fn.v = L, fn.y = a * (A - L) + y;
        Branch::insert_segment(fn.tree, -a, A - L);
        Branch::insert_segment(fn.tree, 0, B - A);
        Branch::insert_segment(fn.tree, b, R - B);
        return fn;
    }

    // f(x) = {a(M-x)+y if x<=M | b(x-M)+y if M<=x | for L<=x<=R}
    static Slopy vee(V a, V b, V L, V M, V R, V y) {
        assert(a + b >= 0 && L <= R); // convexity requirements
        Slopy fn;
        fn.v = L;
        if (L <= M && M <= R) {
            fn.y = a * (M - L) + y;
            Branch::insert_segment(fn.tree, -a, M - L);
            Branch::insert_segment(fn.tree, +b, R - M);
        } else if (M < L) {
            fn.y = b * (L - M) + y;
            Branch::insert_segment(fn.tree, +b, R - L);
        } else /* R < M */ {
            fn.y = a * (M - L) + y;
            Branch::insert_segment(fn.tree, -a, R - L);
        }
        return fn;
    }

    // merge g into f. f(x)=min{y+z=x}(a(y)+b(z))
    static void minplus(Slopy& fn, Slopy& gn) {
        fn.y += gn.y, fn.v += gn.v, Branch::minplus(fn.tree, gn.tree);
    }

    // merge g into f. f(x)=g(x)+h(x) restricted to the intersected domain
    static void pointwise(Slopy& fn, Slopy& gn) {
        V vertex = max(fn.v, gn.v);
        V right = min(fn.right(), gn.right());
        assert(vertex <= right); // function domain is not empty
        fn.y = fn.query(vertex) + gn.query(vertex);
        Branch::pointwise(fn.tree, gn.tree, fn.v, gn.v);
        fn.v = vertex;
    }

    // f(x) := g(x+c)
    void shift(V c) { v -= c; }

    // f(x) := g(x)+c
    void add_constant(V c) { y += c; }

    // f(x) := min{a+x<=y<=b+x} g(y)
    void range_min(V a, V b) { Branch::insert_segment(tree, 0, b - a), v -= b; }

    // f(x) := min{x<=y} g(y). Clears the left branch.
    void suffix_min() {
        auto [a, b] = split_key(tree, 0);
        auto len = Branch::get_sum(a);
        tree = b;
        delete_all(a);
        Branch::insert_segment(tree, 0, len);
    }

    // f(x) := min{y<=x} g(y). Clears the right branch.
    void prefix_min() {
        auto [a, b] = split_key(tree, 1);
        auto len = Branch::get_sum(b);
        tree = a;
        delete_all(b);
        Branch::insert_segment(tree, 0, len);
    }

    void trimto(V L, V R) {
        L = max(L, left()), R = min(R, right());
        assert(L <= R);
        y = query(L);
        Branch::trimto(tree, L - v, R - v);
        v = L;
    }

    V minimum() { return y + Branch::query(tree, Branch::slope_rank(tree, 0)); }
    V left_argmin() { return v + Branch::slope_rank(tree, 0); }
    V right_argmin() { return v + Branch::slope_rank(tree, 1); }
    V left() const { return v; }
    V right() const { return v + Branch::get_sum(tree); }
    auto ceiling_range(V ceil) { return Branch::ceiling_range(tree, ceil - v); }

    bool within_domain(V x) const { return v <= x && x <= v + Branch::get_sum(tree); }

    V query(V x) { return within_domain(x) ? y + Branch::query(tree, x - v) : inf; }
};

#ifdef LOCAL
#include "code/random.hpp"
void generate() {
    int N = rand_unif<int>(10000, 50000);
    int L = rand_unif<int>(500'000'000, 900'000'000);
    auto is = int_sample<int>(2 * N + 2, 0, L);
    auto take = int_sample<int>(N, 0, 2 * N);
    vector<int> x(N), y(N);
    vector<double> s(N);
    for (int i = 0; i < N; i++) {
        x[i] = is[take[i]], y[i] = is[take[i] + 1];
        s[i] = rand_unif<double>(0.1, 10);
        assert((i ? (y[i - 1] <= x[i]) : (0 <= x[i])) && x[i] < y[i] && y[i] <= L);
    }
    putln(N, L);
    for (int i = 0; i < N; i++) {
        putln(x[i], y[i], s[i]);
    }
}
#endif

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, L;
    cin >> N >> L;
    vector<int> x(N), y(N);
    vector<double> s(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i] >> s[i];
    }
    vector<pair<int, double>> segs;
    for (int i = 0, R = 0; i < N; i++) {
        if (R < x[i]) {
            segs.push_back({x[i] - R, 0});
        }
        segs.push_back({y[i] - x[i], s[i]}), R = y[i];
    }
    if (y[N - 1] < L) {
        segs.push_back({L - y[N - 1], 0});
    }
    Slopy fn;
    for (auto [d, s] : segs) {
        double time = d / (1.0 + s);
        double slope = 1 / (1.0 + s);
        double L = -d / (2.0 + s);
        double R = s <= 0 ? 0 : d / (0.0 + s); // for s=0, v>=1 is optimal
        Slopy lin = Slopy::linear(slope, time, L, R);
        Slopy::minplus(fn, lin);
        fn.trimto(0, fn.right());
    }
    cout << setprecision(9) << showpoint << fixed;
    cout << fn.minimum() << '\n';
    return 0;
}