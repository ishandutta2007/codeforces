#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cstring>
#include <cmath>
#include <complex>
#include <cstdio>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector> 
#include <tuple>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> II;
typedef pair<int, LL> ILL;
typedef pair<LL, int> LLI;
typedef pair<LL, LL> LLLL;


// Generic iterables

template<typename I>
class iter_type {
    const I b, e;
    size_t sz;
public:
    iter_type(I b, I e, const size_t& sz) : b(b), e(e), sz(sz) { }
    I begin() const {
        return b;
    }
    I end() const {
        return e;
    }
    size_t size() const {
        return sz;
    }
};

template<typename I>
iter_type<I> iter(I b, I e, const size_t& sz) {
    return iter_type<I>(b, e, sz);
}

template<typename I>
iter_type<I> iter(I b, I e) {
    return iter_type<I>(b, e, e - b);
}

template<typename T>
auto iter(T& v) -> iter_type<decltype(begin(v))> {
    return iter_type<decltype(begin(v))>(begin(v), end(v), end(v) - begin(v));
}


// Range iterator

template<typename T>
class range_iterator;

template<typename T>
iter_type<range_iterator<T>> range(const T& end) {
    return iter(range_iterator<T>(0), range_iterator<T>(end), end - 0);
}

template<typename T>
iter_type<range_iterator<T>> range(const T& begin, const T& end) {
    return iter(range_iterator<T>(begin), range_iterator<T>(end), end - begin);
}

template<typename T>
iter_type<range_iterator<T>> to_infinity(const T& begin = T(0)) {
    return iter(range_iterator<T>(begin), range_iterator<T>(T(-1)), -1);
}

template<typename T>
class range_iterator {
public:
    explicit range_iterator(const T& start) :
        i_(start) { }
    T operator * () const {
        return i_;
    }
    const range_iterator& operator ++ () {
        ++i_;
        return *this;
    }
    range_iterator operator ++ (int) {
        range_iterator copy(*this);
        ++i_;
        return copy;
    }
    bool operator == (const range_iterator& other) const {
        return i_ == other.i_;
    }
    bool operator != (const range_iterator& other) const {
        return i_ != other.i_;
    }
private:
    T i_;
};


// I/O for pairs and iterables

template<typename S, typename T>
ostream& operator << (ostream& out, const pair<S, T>& p) {
    return out << "{" << p.first << ", " << p.second << "}";
}

template<typename S, typename T>
istream& operator >> (istream& in, pair<S, T>& p) {
    return in >> p.first >> p.second;
}

template<typename I>
ostream& operator << (ostream& out, const iter_type<I>& x) {
    out << "[";
    for(auto it = x.begin(); it != x.end(); ++it) {
        out << *it;
        if(next(it) != x.end()) {
            out << ", ";
        }
    }
    return out << "]";
}

template<typename I>
istream& operator >> (istream& in, const iter_type<I>& x) {
    for(I it = x.begin(); it != x.end(); ++it) {
        in >> *it;
    }
    return in;
}

template<typename T>
ostream& operator << (ostream& out, const vector<T>& v) {
    return out << iter(v);
}

template<typename T>
istream& operator >> (istream& in, vector<T>& v) {
    return in >> iter(v);
}

template<typename T>
ostream& operator << (ostream& out, const set<T>& v) {
    return out << iter(v);
}

template<typename S, typename T>
ostream& operator << (ostream& out, const map<S, T>& v) {
    return out << iter(v);
}

template<typename T>
ostream& operator << (ostream& out, const unordered_set<T>& v) {
    return out << iter(v);
}

template<typename S, typename T>
ostream& operator << (ostream& out, const unordered_map<S, T>& v) {
    return out << iter(v);
}


// Fenwick tree

template<typename T, typename Op = plus<T>>
class fenwick_tree {
    const int N, max_pow2;
    vector<T> ft;
    const Op op;
public:
    explicit fenwick_tree(int N, const T& val = T(), const Op& op = Op()) :
        N(N), max_pow2(log2(N)), ft(N, val), op(op) { }
    template<typename I>
    fenwick_tree(const iter_type<I>& it, const Op& op = Op()) :
        fenwick_tree(it.size(), T(), op) {
        int p = 0, q;
        for(auto x : it) {
            q = p | (p + 1);
            ft[p] = op(ft[p], x);
            if(q < N) {
                ft[q] = op(ft[q], ft[p]);
            }
            ++p;
        }
    }
    void update(int p, const T& v) {
        for(; p < N; p |= p + 1) {
            ft[p] = op(ft[p], v);
        }
    }
    T get_prefix(int r) {   // [0, r)
        --r;
        T ans = T();
        for(; r >= 0; r = (r & (r + 1)) - 1) {
            ans = op(ans, ft[r]);
        }
        return ans;
    }
    T get_range(int l, int r) { // [l, r)
        return get_prefix(r) - get_prefix(l);
    }
    T get(int p) {
        return get_range(p, p + 1);
    }
    int lower_bound(const T& x) {   // min{p : get_prefix(p) >= x}, assuming get_prefix(p) is an increasing function of p
        T total = T();
        int ans = 0;
        for(int i = 1 << max_pow2; i > 0; i >>= 1) {
            if(ans + i - 1 < int(N) and op(total, ft[ans + i - 1]) <= x) {
                total = op(total, ft[ans + i - 1]);
                ans += i;
            }
        }
        return ans;
    }
};


// Range tree

template<typename Idx>
struct interval_t {
    Idx l, r;
    interval_t(const Idx l, const Idx r) :
        l(l), r(r) { }
    Idx size() const {
        return r - l;
    }
};

template<typename Idx>
inline bool disjoint_interval(const interval_t<Idx>& a, const interval_t<Idx>& b) {
    return a.r <= b.l or b.r <= a.l;
}

template<typename Idx>
inline bool contained_interval(const interval_t<Idx>& a, const interval_t<Idx>& b) {
    return b.l <= a.l and a.r <= b.r;
}

template<typename Idx>
inline void left(interval_t<Idx>& a) {
    a.r = 2 * a.l - a.r;
    swap(a.l, a.r);
}

template<typename Idx>
inline void right(interval_t<Idx>& a) {
    a.l = 2 * a.r - a.l;
    swap(a.l, a.r);
}

template<typename Idx>
inline void left_half(interval_t<Idx>& a) {
    a.r = (a.r + a.l) / 2;
}

template<typename Idx>
inline void right_half(interval_t<Idx>& a) {
    a.l = (a.r + a.l) / 2;
}

template<typename Idx>
inline void left_double(interval_t<Idx>& a) {
    a.l = 2 * a.l - a.r;
}

template<typename Idx>
inline void right_double(interval_t<Idx>& a) {
    a.r = 2 * a.r - a.l;
}

template<typename Idx, typename T>
class contiguous_binary_tree {
    const Idx size;
    vector<T> tree;
public:
    class iterator {
        contiguous_binary_tree<Idx, T>* my_tree;
        Idx i;
        interval_t<Idx> interval;
    public:
        explicit iterator(contiguous_binary_tree<Idx, T>* t) :
            my_tree(t), i(1), interval(0, t->size) { }
        iterator(contiguous_binary_tree<Idx, T>* t, Idx leaf_index) :
            my_tree(t), i(t->size + leaf_index), interval(leaf_index, leaf_index + 1) { }
        void go_up() {
            if(i & 1) {
                left_double(interval);
            } else {
                right_double(interval);
            }
            i /= 2;
        }
        inline void go_left() {
            left_half(interval);
            i *= 2;
        }
        inline void go_right() {
            right_half(interval);
            i = i * 2 + 1;
        }
        iterator father_node() const {
            iterator other = *this;
            other.go_up();
            return other;
        }
        iterator left_child() const {
            iterator other = *this;
            other.go_left();
            return other;
        }
        iterator right_child() const {
            iterator other = *this;
            other.go_right();
            return other;
        }
        void modify() {
            
        }
        iterator& operator ++ () {
            ++i;
            if(i & (i - 1)) {
                left(interval);
            } else {
                interval = interval_t<Idx>(0, interval.size() / 2);
            }
            return *this;
        }
        iterator operator ++ (int) {
            iterator other = *this;
            operator ++ ();
            return other;
        }
        iterator& operator -- () {
            --i;
            if(i & (i + 1)) {
                right(interval);
            } else {
                interval = interval_t<Idx>(my_tree->size - interval.size() / 2, my_tree->size);
            }
            return *this;
        }
        iterator operator -- (int) {
            iterator other = *this;
            operator -- ();
            return other;
        }
        inline T& operator * () {
            return my_tree->tree[i];
        }
        inline T* operator -> () {
            return &(my_tree->tree[i]);
        }
        inline bool is_root() const {
            return i == 1;
        }
        inline bool is_leaf() const {
            return i >= my_tree->size;
        }
        inline Idx get_index() const {
            return i;
        }
        inline Idx get_leaf_index() const {
            return i - my_tree->size;
        }
        inline Idx left_index() const {
            return interval.l;
        }
        inline Idx right_index() const {
            return interval.r;
        }
        inline interval_t<Idx> get_interval() const {
            return interval;
        }
        inline bool is_end() const {
            return interval.size() == 0;
        }
    };
    
    explicit contiguous_binary_tree(Idx size) :
        size(size), tree(size * 2) { }
    inline iterator get_root() {
        return iterator(this);
    }
    inline iterator get_leaf(Idx i) {
        return iterator(this, i);
    }
};

template<
    typename Idx,
    typename T,
    template<typename, typename> class BinaryTree,
    typename Merge,
    typename Operation>
class range_tree {
    class vertex {
        bool pending_operation;
        Operation op;
    public:
        T val;
        
        vertex() :
            pending_operation(false) { }
        inline bool no_op() const {
            return not pending_operation;
        }
        inline const Operation& get_operation() const {
            return op;
        }
        void new_operation(const Operation& new_op, Idx size) {
            if(no_op()) {
                pending_operation = true;
                op = new_op;
            } else {
                op.append(new_op);
            }
            new_op.apply(val, size);
        }
        inline void delete_operation() {
            pending_operation = false;
        }
    };
    typedef typename BinaryTree<Idx, vertex>:: iterator iterator;
    
    static Idx get_pow2_size(Idx sz) {
        Idx ans = 1;
        while(ans < sz) {
            ans *= 2;
        }
        return ans;
    }
    
    const Merge merge;
    mutable BinaryTree<Idx, vertex> tree;
    
    void propagate_operation(iterator it) const {
        if(it->no_op()) {
            return;
        }
        Idx l = it.left_index(), r = it.right_index();
        Idx m = (l + r) / 2, half_size = (r - l) / 2;
        it.left_child()->new_operation(it->get_operation().restrict(l, m, l, r), half_size);
        it.right_child()->new_operation(it->get_operation().restrict(m, r, l, r), half_size);
        it->delete_operation();
    }
    iterator _apply_range_operation(iterator it, const interval_t<Idx>& interval, const Operation& op) {
        if(disjoint_interval(it.get_interval(), interval)) {
            return it;
        }
        it.modify();
        if(contained_interval(it.get_interval(), interval)) {
            auto restr = op.restrict(it.left_index(), it.right_index(), interval.l, interval.r);
            it->new_operation(restr, it.get_interval().size());
            return it;
        }
        propagate_operation(it);
        _apply_range_operation(it.left_child(), interval, op);
        _apply_range_operation(it.right_child(), interval, op);
        it->val = merge(it.left_child()->val, it.right_child()->val);
        return it;
    }
    T _get_range(iterator it, const interval_t<Idx>& interval) const {
        if(contained_interval(it.get_interval(), interval)) {
            return it->val;
        }
        propagate_operation(it);
        if(disjoint_interval(it.left_child().get_interval(), interval)) {
            return _get_range(it.right_child(), interval);
        }
        if(disjoint_interval(it.right_child().get_interval(), interval)) {
            return _get_range(it.left_child(), interval);
        }
        return merge(_get_range(it.left_child(), interval), _get_range(it.right_child(), interval));
    }
public:
    range_tree(Idx size, const Merge& merge) :
        merge(merge), tree(get_pow2_size(size)) { }
    range_tree(Idx size, const T& initial_value, const Merge& merge) :
        range_tree(size, merge) {
        auto it = tree.get_leaf(0);
        for(Idx i = 0; i < size; ++i) {
            it->val = initial_value;
            ++it;
        }
        it = tree.get_leaf(0);
        while(not it.is_root()) {
            --it;
            it->val = merge(it.left_child()->val, it.right_child()->val);
        }
    }
    template<typename I>
    range_tree(Idx size, iter_type<I> initial_values, const Merge& merge) :
        range_tree(size, merge) {
        auto it = tree.get_leaf(0);
        for(const T& v : initial_values) {
            it->val = v;
            ++it;
        }
        it = tree.get_leaf(0);
        while(not it.is_root()) {
            --it;
            it->val = merge(it.left_child()->val, it.right_child()->val);
        }
    }
    T get_range(Idx l, Idx r) const {
        return get_range(l, r, tree.get_root());
    }
    T get_range(Idx l, Idx r, iterator root) const {
        interval_t<Idx> interval(l, r);
        
        assert(contained_interval(interval, root.get_interval()));
        if(interval.size() < 0 or disjoint_interval(root.get_interval(), interval)) {
            return Operation::get_identity();
        }
        return _get_range(root, interval);
    }
    inline T get_value(Idx i) const {
        return _get_range(tree.get_root(), interval_t<Idx>(i, i + 1));
    }
    inline T get_value(Idx i, iterator root) const {
        return _get_range(root, interval_t<Idx>(i, i + 1));
    }
    inline iterator apply_range_operation(Idx l, Idx r, const Operation& op) {
        return _apply_range_operation(tree.get_root(), interval_t<Idx>(l, r), op);
    }
    inline iterator apply_range_operation(Idx l, Idx r, const Operation& op, iterator root) {
        return _apply_range_operation(root, interval_t<Idx>(l, r), op);
    }
    inline iterator apply_operation(Idx i, const Operation& op) {
        return _apply_range_operation(tree.get_root(), interval_t<Idx>(i, i + 1), op);
    }
    inline iterator apply_operation(Idx i, const Operation& op, iterator root) {
        return _apply_range_operation(root, interval_t<Idx>(i, i + 1), op);
    }
};

template<
    typename T,
    template<typename, typename> class BinaryTree,
    typename Operation,
    typename Idx,
    typename Merge>
auto make_range_tree(Idx size, const Merge& merge) {
    return range_tree<Idx, T, BinaryTree, Merge, Operation>(size, merge);
}
template<
    typename T,
    template<typename, typename> class BinaryTree,
    typename Operation,
    typename Idx,
    typename Merge,
    typename I>
auto make_range_tree(Idx size, iter_type<I> initial_values, const Merge& merge) {
    return range_tree<Idx, T, BinaryTree, Merge, Operation>(size, initial_values, merge);
}
template<
    typename T,
    template<typename, typename> class BinaryTree,
    typename Operation,
    typename Idx,
    typename Merge>
auto make_range_tree(Idx size, const T& initial_value, const Merge& merge) {
    return range_tree<Idx, T, BinaryTree, Merge, Operation>(size, initial_value, merge);
}



//////////////////////
// HAPPY CODING  :) //
//////////////////////

template<typename T>
struct my_op {
    static T get_identity() {
        return 1LL << 60;
    }
    T v;
    my_op<T> restrict(int, int, int, int) const {
        return *this;
    }
    void append(const my_op& other) {
        v += other.v;
    }
    void apply(T& x, int) const {
        x += v;
    }
};

int main() {
    // remove in interactive problems
    #ifdef DEBUG
    //freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //

    int N;
    cin >> N;
    vector<LL> A(N);
    cin >> A;
    auto rt = make_range_tree<LL, contiguous_binary_tree, my_op<LL>>(N, iter(A), [](LL i, LL j) { return min(i, j); });
    int M;
    cin >> M;
    while(M--) {
        string str;
    	while(str.length() < 2) {
            getline(cin, str);
    	}
        stringstream stream(str);
        int b1, e1, v, b2, e2;
        stream >> b1 >> e1 >> v;
        ++e1;
        if(e1 <= b1) {
            e2 = e1;
            e1 = N;
            b2 = 0;
        } else {
            b2 = e2 = 0;
        }
        if(stream) {
            rt.apply_range_operation(b1, e1, my_op<LL>{v});
            rt.apply_range_operation(b2, e2, my_op<LL>{v});
        } else {
            cout << min(rt.get_range(b1, e1), rt.get_range(b2, e2)) << "\n";
        }
    }
}