#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <int k>
struct Trie {
    static_assert(k >= 0);
    using Self = Trie<k>;
    using Subt = Trie<k - 1>;
    int mask[2] = {}, leaves = 0, lazy = 0;
    Subt *L = nullptr, *R = nullptr;

    Trie(Subt* L, Subt* R) : L(L), R(R) { pushup(); }

    void pushup() {
        assert(L || R);
        leaves = get_leaves(L) + get_leaves(R);
        mask[0] = get_mask(L, 0, 1) | get_mask(R, 0, 0);
        mask[1] = get_mask(L, 1, 0) | get_mask(R, 1, 1);
    }

    void pushdown() {
        if (L && lazy) {
            L->apply_xor(lazy);
        }
        if (R && lazy) {
            R->apply_xor(lazy);
        }
        lazy = 0;
    }

    void apply_xor(int flip) {
        int m0 = mask[0] & flip;
        int m1 = mask[1] & flip;
        mask[0] = (mask[0] & ~flip) | m1;
        mask[1] = (mask[1] & ~flip) | m0;
        if (flip >> k & 1) {
            swap(L, R);
        }
        lazy ^= flip & ((2 << k) - 1);
    }

    auto kids() const { return array<Subt*, 2>{L, R}; }
    friend int get_mask(Self* x, int d, int v) {
        return x ? x->mask[d] | (v << (k + 1)) : 0;
    }
    friend int get_leaves(Self* x) { return x ? x->leaves : 0; }
};

template <>
struct Trie<-1> {
    using Self = Trie<-1>;
    void pushdown() { assert(false); }
    void apply_xor(int) const {}
    friend int get_mask(Self* x, int, int v) { return x ? v : 0; }
    friend int get_leaves(Self* x) { return x ? 1 : 0; }
};
Trie<-1>* null = new Trie<-1>();

template <int k>
auto build_trie(int mask) {
    if (mask >> k & 1) {
        return new Trie<k>(nullptr, build_trie<k - 1>(mask));
    } else {
        return new Trie<k>(build_trie<k - 1>(mask), nullptr);
    }
}

template <>
auto build_trie<-1>(int) {
    return null;
}

template <int k>
array<Trie<k - 1>*, 2> cut(Trie<k>* a) {
    a->pushdown();
    auto kids = a->kids();
    delete a;
    return kids;
}

template <int k>
auto join(Trie<k - 1>* a, Trie<k - 1>* b) {
    return a || b ? new Trie<k>(a, b) : nullptr;
}

template <int k>
auto meld(Trie<k>* a, Trie<k>* b) {
    if (!a || !b) {
        return a ? a : b;
    }
    auto [la, ra] = cut(a);
    auto [lb, rb] = cut(b);
    return join<k>(meld<k - 1>(la, lb), meld<k - 1>(ra, rb));
}

template <>
auto meld(Trie<-1>* a, Trie<-1>* b) {
    return a || b ? null : nullptr;
}

template <int k>
auto meld(Trie<k>* a, Trie<k>* b, Trie<k>* c) {
    return meld<k>(a, meld<k>(b, c));
}

template <int k>
array<Trie<k>*, 2> access(Trie<k>* a, int bound) {
    if (!a) {
        return {nullptr, nullptr};
    } else if (bound <= 0) {
        return {nullptr, a};
    } else if (bound >= (2 << k)) {
        return {a, nullptr};
    }
    assert(0 <= bound && bound < (2 << k));
    auto [la, ra] = cut(a);
    if (bound == (1 << k)) { // handle k=0
        return {join<k>(la, nullptr), join<k>(nullptr, ra)};
    } else if (bound < (1 << k)) {
        auto [xa, ya] = access(la, bound);
        return {join<k>(xa, nullptr), join<k>(ya, ra)};
    } else {
        auto [xa, ya] = access(ra, bound - (1 << k));
        return {join<k>(la, xa), join<k>(nullptr, ya)};
    }
}

template <>
array<Trie<-1>*, 2> access(Trie<-1>*, int) {
    assert(false);
}

template <int k>
array<Trie<k>*, 3> access(Trie<k>* tree, int L, int R) {
    auto [mid, c] = access(tree, R);
    auto [a, b] = access(mid, L);
    return {a, b, c};
}

template <int k>
auto apply_beats_or(Trie<k>* a, int mask) {
    if (!a) {
        return a;
    }
    a->pushdown();
    if (mask & a->mask[0] & a->mask[1]) {
        // We got some messy bit, recurse
        auto [la, ra] = cut(a);
        la = apply_beats_or(la, mask);
        ra = apply_beats_or(ra, mask);
        return (mask >> k & 1) ? join<k>(nullptr, meld(la, ra)) : join<k>(la, ra);
    } else {
        // No messy bit
        a->apply_xor(mask & a->mask[0]);
        return a;
    }
}

template <>
auto apply_beats_or(Trie<-1>* a, int) {
    return a;
}

template <int k>
auto apply_beats_and(Trie<k>* a, int mask) {
    if (!a) {
        return a;
    }
    a->pushdown();
    if (~mask & a->mask[0] & a->mask[1]) {
        // We got some messy bit, recurse
        auto [la, ra] = cut(a);
        la = apply_beats_and(la, mask);
        ra = apply_beats_and(ra, mask);
        return (mask >> k & 1) ? join<k>(la, ra) : join<k>(meld(la, ra), nullptr);
    } else {
        // No messy bit
        a->apply_xor(~mask & a->mask[1]);
        return a;
    }
}

template <>
auto apply_beats_and(Trie<-1>* a, int) {
    return a;
}

template <int k>
auto apply_xor(Trie<k>* a, int mask) {
    if (a) {
        a->apply_xor(mask);
    }
    return a;
}

constexpr int M = 20;
using Tree = Trie<M>*;

template <int k>
void debug_tree(Trie<k>* a, int v) {
    if (a) {
        debug_tree(a->L, v);
        debug_tree(a->R, v + (1 << k));
    }
}

template <>
void debug_tree(Trie<-1>* a, int v) {
    if (a) {
        cerr << ' ' << v;
    }
}

template <int k>
void debug_tree(Trie<k>* a) {
    debug_tree(a, 0);
    cerr << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(begin(arr), end(arr));
    arr.erase(unique(begin(arr), end(arr)), end(arr));

    Tree tree = nullptr;
    for (int a : arr) {
        tree = meld(tree, build_trie<M>(a));
    }

    while (Q--) {
        int t, l, r;
        cin >> t >> l >> r, r++;
        assert(0 <= l && l < r && r <= (1 << M));
        auto [a, b, c] = access(tree, l, r);
        if (t == 1) {
            int x;
            cin >> x;
            b = apply_beats_and(b, x);
        } else if (t == 2) {
            int x;
            cin >> x;
            b = apply_beats_or(b, x);
        } else if (t == 3) {
            int x;
            cin >> x;
            b = apply_xor(b, x);
        } else if (t == 4) {
            cout << get_leaves(b) << '\n';
        } else {
            assert(false);
        }
        tree = meld(a, b, c);
    }

    return 0;
}