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
#include <valarray>
#include <vector>
#include <type_traits>
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
public:
    iter_type(I b, I e) : b(b), e(e) { }
    I begin() const {
        return b;
    }
    I end() const {
        return e;
    }
};

template<typename I>
iter_type<I> iter(I b, I e) {
    return iter_type<I>(b, e);
}

template<typename T>
auto iter(T& v) -> iter_type<decltype(begin(v))> {
    return iter_type<decltype(begin(v))>(begin(v), end(v));
}

template<typename T>
auto iter(const T& v) -> iter_type<decltype(begin(v))> {
    return iter_type<decltype(begin(v))>(begin(v), end(v));
}

template<typename T, typename I> T from_iter(const iter_type<I>& it) {
    return T(it.begin(), it.end());
}


// Apply iterator

template<typename I, typename F>
class apply_iterator;

template<typename I, typename F>
iter_type<apply_iterator<I, F>> apply(const F& f, const iter_type<I>& it) {
    return iter(apply_iterator<I, F>(f, it.begin()), apply_iterator<I, F>(f, it.end()));
}

template<typename I, typename F>
class apply_iterator {
    friend iter_type<apply_iterator<I, F>> apply<>(const F&, const iter_type<I>&);
    
    const F f;
    I it;
    
    using T = decltype(f(*it));
public:
    T operator * () const {
        return f(*it);
    }
    apply_iterator& operator ++ () {
        ++it;
        return *this;
    }
    apply_iterator operator ++ (int) {
        apply_iterator other = *this;
        operator ++ ();
        return other;
    }
    bool operator == (const apply_iterator& other) const {
        return it == other.it;
    }
    bool operator != (const apply_iterator& other) const {
        return it != other.it;
    }
protected:
    apply_iterator(const F& f, I it) :
        f(f), it(it) { }
};


// Convert iterator

template<typename I, typename T>
class convert_iterator;

template<typename T, typename I>
iter_type<convert_iterator<I, T>> convert(const iter_type<I>& it) {
    return iter(convert_iterator<I, T>(it.begin()), convert_iterator<I, T>(it.end()));
}

template<typename I, typename T>
class convert_iterator {
    friend iter_type<convert_iterator<I, T>> convert<>(const iter_type<I>&);
    
    I it;
public:
    T operator * () const {
        return *it;
    }
    convert_iterator& operator ++ () {
        ++it;
        return *this;
    }
    convert_iterator operator ++ (int) {
        convert_iterator other = *this;
        operator ++ ();
        return other;
    }
    bool operator == (const convert_iterator& other) const {
        return it == other.it;
    }
    bool operator != (const convert_iterator& other) const {
        return it != other.it;
    }
protected:
    convert_iterator(I it) :
        it(it) { }
};


// Join iterator

template<typename I, typename J>
class join_iterator;

template<typename I, typename J>
iter_type<join_iterator<I, J>> operator + (const iter_type<I>& it1, const iter_type<J>& it2) {
    return iter(join_iterator<I, J>(it1, it2, it1.begin(), it2.begin()), join_iterator<I, J>(it1, it2, it1.end(), it2.end()));
}

template<typename I, typename J>
class join_iterator {
    friend iter_type<join_iterator<I, J>> operator + <>(const iter_type<I>&, const iter_type<J>&);
    
    iter_type<I> it1;
    iter_type<J> it2;
    I i1;
    J i2;
    
    using T1 = decltype(*i1);
    using T2 = decltype(*i2);
    static_assert(is_convertible<T2, typename remove_reference<T1>::type>::value, "Joining iterators with incompatible value types");
public:
    typename conditional<is_same<T1, T2>::value, T1, typename remove_reference<T1>::type>::type operator * () const {
        if(i1 == it1.end()) {
            return *i2;
        } else {
            return *i1;
        }
    }
    join_iterator& operator ++ () {
        if(i1 == it1.end()) {
            ++i2;
        } else {
            ++i1;
        }
        return *this;
    }
    join_iterator operator ++ (int) {
        join_iterator other = *this;
        operator ++ ();
        return other;
    }
    bool operator == (const join_iterator& other) const {
        return i1 == other.i1 and i2 == other.i2;
    }
    bool operator != (const join_iterator& other) const {
        return (i1 != other.i1) or (i2 != other.i2);
    }
protected:
    join_iterator(const iter_type<I>& it1, const iter_type<J>& it2, I i1, J i2) :
        it1(it1), it2(it2), i1(i1), i2(i2) { }
};


// Repeat iterator

template<typename T>
class repeat_iterator;

template<typename T>
iter_type<repeat_iterator<T>> repeat(const T& v) {
    return iter(repeat_iterator<T>(v), repeat_iterator<T>());
}

template<typename T>
class repeat_iterator {
    friend iter_type<repeat_iterator<T>> repeat<>(const T&);
    
    const T v;
public:
    T operator * () {
        return v;
    }
    const T& operator * () const {
        return v;
    }
    repeat_iterator& operator ++ () {
        return *this;
    }
    repeat_iterator operator ++ (int) {
        return *this;
    }
    bool operator == (const repeat_iterator&) const {
        return false;
    }
    bool operator != (const repeat_iterator&) const {
        return true;
    }
protected:
    repeat_iterator(const T& v = T()) :
        v(v) { }
};


// Range iterator

template<typename T>
class range_iterator;

template<typename T>
iter_type<range_iterator<T>> range(const T& e) {
    return iter(range_iterator<T>(0, e, 1), range_iterator<T>());
}

template<typename T>
iter_type<range_iterator<T>> range(const T& b, const T& e, const T& step = T(1)) {
    return iter(range_iterator<T>(b, e, step), range_iterator<T>());
}

template<typename T>
iter_type<range_iterator<T>> to_infinity(const T& b = T(0), const T& step = T(1)) {
    return iter(range_iterator<T>(b, -step, step), range_iterator<T>());
}

template<typename T>
class range_iterator {
    friend iter_type<range_iterator> range<>(const T&);
    friend iter_type<range_iterator> range<>(const T&, const T&, const T&);
    friend iter_type<range_iterator> to_infinity<>(const T& b, const T&);
    
    T b, e, step;
    bool is_end;
public:
    T operator * () const {
        return b;
    }
    range_iterator& operator ++ () {
        b += step;
        if((step >= 0 and b >= e) or (step <= 0 and b <= e)) {
            is_end = true;
        }
        return *this;
    }
    range_iterator operator ++ (int) {
        range_iterator other(*this);
        operator ++ ();
        return other;
    }
    bool operator == (const range_iterator& other) const {
        return is_end and other.is_end;
    }
    bool operator != (const range_iterator& other) const {
        return (not is_end) or (not other.is_end);
    }
protected:
    range_iterator() :
        is_end(true) { }
    explicit range_iterator(const T& b, const T& e, const T& step) :
        b(b), e(e), step(step), is_end(false) { }
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
    for(auto it = x.begin(); it != x.end();) {
        out << *it;
        if(++it != x.end()) {
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
bool disjoint_interval(const interval_t<Idx>& a, const interval_t<Idx>& b) {
    return a.r <= b.l or b.r <= a.l;
}

template<typename Idx>
bool contained_interval(const interval_t<Idx>& a, const interval_t<Idx>& b) {
    return b.l <= a.l and a.r <= b.r;
}

template<typename Idx>
void left(interval_t<Idx>& a) {
    a.r = 2 * a.l - a.r;
    swap(a.l, a.r);
}

template<typename Idx>
void right(interval_t<Idx>& a) {
    a.l = 2 * a.r - a.l;
    swap(a.l, a.r);
}

template<typename Idx>
void left_half(interval_t<Idx>& a) {
    a.r = (a.r + a.l) / 2;
}

template<typename Idx>
void right_half(interval_t<Idx>& a) {
    a.l = (a.r + a.l) / 2;
}

template<typename Idx>
void left_double(interval_t<Idx>& a) {
    a.l = 2 * a.l - a.r;
}

template<typename Idx>
void right_double(interval_t<Idx>& a) {
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
        void go_left() {
            left_half(interval);
            i *= 2;
        }
        void go_right() {
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
        T& operator * () {
            return my_tree->tree[i];
        }
        T* operator -> () {
            return &(my_tree->tree[i]);
        }
        bool is_root() const {
            return i == 1;
        }
        bool is_leaf() const {
            return i >= my_tree->size;
        }
        Idx get_index() const {
            return i;
        }
        Idx get_leaf_index() const {
            return i - my_tree->size;
        }
        Idx left_index() const {
            return interval.l;
        }
        Idx right_index() const {
            return interval.r;
        }
        interval_t<Idx> get_interval() const {
            return interval;
        }
        bool is_end() const {
            return interval.size() == 0;
        }
    };
    
    explicit contiguous_binary_tree(Idx size) :
        size(size), tree(size * 2) { }
    iterator get_root() {
        return iterator(this);
    }
    iterator get_leaf(Idx i) {
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
        bool no_op() const {
            return not pending_operation;
        }
        const Operation& get_operation() const {
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
        void delete_operation() {
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
    template<typename I>
    range_tree(Idx size, iter_type<I> initial_values, const Merge& merge) :
        range_tree(size, merge) {
        auto it = tree.get_leaf(0);
        auto j = (initial_values + repeat(Operation::get_identity())).begin();
        for(; not it.is_end(); ++it) {
            it->val = *j++;
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
        if(l > r or disjoint_interval(root.get_interval(), interval)) {
            return Operation::get_identity();
        }
        return _get_range(root, interval);
    }
    T get_value(Idx i) const {
        return get_value(i, tree.get_root());
    }
    T get_value(Idx i, iterator root) const {
        return _get_range(root, interval_t<Idx>(i, i + 1));
    }
    iterator apply_range_operation(Idx l, Idx r, const Operation& op) {
        return apply_range_operation(l, r, op, tree.get_root());
    }
    iterator apply_range_operation(Idx l, Idx r, const Operation& op, iterator root) {
        return _apply_range_operation(root, interval_t<Idx>(l, r), op);
    }
    iterator apply_operation(Idx i, const Operation& op) {
        return apply_operation(i, op, tree.get_root());
    }
    iterator apply_operation(Idx i, const Operation& op, iterator root) {
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
    return range_tree<Idx, T, BinaryTree, Merge, Operation>(size, repeat(initial_value), merge);
}



//////////////////////
// HAPPY CODING  :) //
//////////////////////

typedef valarray<int> arr;

struct my_op {
    static arr get_identity() {
        return arr(0, 26);
    }
    int i;
    my_op(int i = -1) : i(i) { }
    my_op restrict(int, int, int, int) const {
        return *this;
    }
    void append(const my_op& other) {
        i = other.i;
    }
    void apply(arr& x, int sz) const {
        x = 0;
        x[i] = sz;
    }
};

int main() {
    // remove in interactive problems
    #ifdef DEBUG
    freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //

    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    vector<arr> initial_values(N, arr(0, 26));
    for(int n : range(N)) {
        initial_values[n][S[n] - 'a'] = 1;
    }
    auto rt = make_range_tree<arr, contiguous_binary_tree, my_op>(N, iter(initial_values), [](const arr& i, const arr& j) { return i + j; });
    while(Q--) {
        int l, r, k;
        cin >> l >> r >> k;
        --l;
        auto cnt = rt.get_range(l, r);
        if(k) {
            int i = l;
            for(int j = 0; j < 26; ++j) {
                rt.apply_range_operation(i, i + cnt[j], my_op(j));
                i += cnt[j];
            }
        } else {
            int i = l;
            for(int j = 25; j >= 0; --j) {
                rt.apply_range_operation(i, i + cnt[j], my_op(j));
                i += cnt[j];
            }
        }
    }
    for(int n : range(N)) {
        auto c = rt.get_value(n);
        for(int i = 0; i < 26; ++i) {
            if(c[i]) {
                S[n] = 'a' + i;
            }
        }
    }
    cout << S << "\n";
    return 0;
}