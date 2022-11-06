// Dmitry _kun_ Sayutin (2019)

#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;

using std::vector;
using std::map;
using std::array;
using std::set;
using std::string;

using std::pair;
using std::make_pair;

using std::tuple;
using std::make_tuple;
using std::get;

using std::min;
using std::abs;
using std::max;
using std::swap;

using std::unique;
using std::sort;
using std::generate;
using std::reverse;
using std::min_element;
using std::max_element;

#ifdef LOCAL
#define LASSERT(X) assert(X)
#else
#define LASSERT(X) {}
#endif

template <typename T>
T input() {
    T res;
    cin >> res;
    LASSERT(cin);
    return res;
}

template <typename IT>
void input_seq(IT b, IT e) {
    std::generate(b, e, input<typename std::remove_reference<decltype(*b)>::type>);
}

#define SZ(vec)         int((vec).size())
#define ALL(data)       data.begin(),data.end()
#define RALL(data)      data.rbegin(),data.rend()
#define TYPEMAX(type)   std::numeric_limits<type>::max()
#define TYPEMIN(type)   std::numeric_limits<type>::min()

template <typename A, typename B>
bool cmp_first(const pair<A, B>& x, const pair<A, B>& y) {
    return x.first < y.first;
}

template <typename T>
struct object_t {
    object_t(int* cur_time, T val) {
        this->cur_time = cur_time;

        log = {{*cur_time, val}};
    };

    T get(int tm) {
        return get2(tm).second;
    }

    T get() {
        return get2().second;
    }

    pair<int, T> get2(int tm) {
        auto it = std::upper_bound(ALL(log), make_pair(tm, T()), cmp_first<int, T>);
        --it;
        return *it;
    }

    pair<int, T> get2() {
        return log.back();
    }
    
    void set(T val) {
        if (log.back().first == *cur_time)
            log.back().second = val;
        else
            log.emplace_back(*cur_time, val);
    }

    
    int* cur_time;
    vector<pair<int, T>> log;
};

struct rmq_t {
    rmq_t(vector<int>& arr) {
        tree.resize(4 * SZ(arr));
        n = SZ(arr);

        build(0, 0, n, arr);
    }

    void build(int v, int nl, int nr, vector<int>& arr) {
        if (nl == nr - 1)
            tree[v] = arr[nl];
        else {
            int mi = nl + (nr - nl) / 2;

            build(2 * v + 1, nl, mi, arr);
            build(2 * v + 2, mi, nr, arr);
            tree[v] = min(tree[2 * v + 1], tree[2 * v + 2]);
        }
    }

    void sett(int v, int nl, int nr, int i, int x) {
        if (nr - nl == 1) {
            tree[v] = x;
        } else {
            int mi = nl + (nr - nl) / 2;

            if (i < mi)
                sett(2 * v + 1, nl, mi, i, x);
            else
                sett(2 * v + 2, mi, nr, i, x);

            tree[v] = min(tree[2 * v + 1], tree[2 * v + 2]);
        }
    }

    void change(int i, int x) {
        sett(0, 0, n, i, x);
    }
    
    int prefix_ge_than(int val) { // returns last element of that prefix
        return go_down(0, 0, n, val);
    }

    int go_down(int v, int nl, int nr, int val) {
        if (nr - nl == 1) {
            if (tree[v] >= val)
                return nl;
            else
                return nl - 1;
        } else {
            int mi = nl + (nr - nl) / 2;
            
            if (tree[2 * v + 1] >= val)
                return go_down(2 * v + 2, mi, nr, val);
            else
                return go_down(2 * v + 1, nl, mi, val);
        }
    }
    
    int n;
    vector<int> tree;
};

struct node_t;
node_t* new_node_t();
node_t* copy(node_t* a);

struct node_t {
    node_t() {
    }
    
    int64_t sum = 0;
    int modif = 0;
    node_t* left = nullptr;
    node_t* right = nullptr;

    int64_t get(int nl, int nr, int l, int r) {
        if (l <= nl and nr <= r)
            return sum + modif * 1ll * (nr - nl);

        if (nr <= l or r <= nl)
            return 0;

        int64_t ans = modif * 1ll * (min(nr, r) - max(nl, l));
        int mi = nl + (nr - nl) / 2;
        
        if (left)
            ans += left->get(nl, mi, l, r);
        if (right)
            ans += right->get(mi, nr, l, r);

        return ans;
    }

    void op(int nl, int nr, int l, int r, int64_t delta) {
        if (nr <= l or r <= nl)
            return;

        if (l <= nl and nr <= r) {
            // forked hence safe.
            modif += delta;
            return;
        }
        
        if (not left)
            left = new_node_t();
        else
            left = copy(left);
        
        if (not right)
            right = new_node_t();
        else
            right = copy(right);

        int mi = nl + (nr - nl) / 2;
        left->op(nl, mi, l, r, delta);
        right->op(mi, nr, l, r, delta);

        sum += delta * (min(nr, r) - max(nl, l));
    }
};

node_t* new_node_t() {
    return new node_t();
}

node_t* copy(node_t* a) {
    node_t* nw = new node_t();
    *nw = *a;

    return nw;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n = input<int>();

    vector<int> arr;
    vector<int> last(n + 5, -1);

    rmq_t rmq(last);
    
    int cur_time = -1;
    vector<object_t<pair<int, int>>> segms;

    for (int i = 0; i != n + 5; ++i)
        segms.push_back(object_t<pair<int, int>>(&cur_time, make_pair(-1, -2)));

    set<int> alive;

    vector<object_t<node_t*>> trees;
    for (int i = 0; i != n + 5; ++i) {
        trees.push_back(object_t<node_t*>(&cur_time, new_node_t()));
    }

    auto apply_op = [&](int k, pair<int, int> seg, int delta) {
        if (seg == make_pair(-2, -1))
            return;
        
        node_t* tr = trees[k].get();

        node_t* nw = copy(tr);

        nw->op(0, n + 3, seg.first, seg.second + 1, delta);

        trees[k].set(nw);
    };
    
    auto assign = [&](int k, pair<int, int> seg) {
        auto old = segms[k].get2();

        apply_op(k, old.second, cur_time - old.first);

        segms[k].set(seg);
    };
    
    auto append = [&](int elem) {
        ++cur_time;

        arr.push_back(elem);
        last[elem] = SZ(arr) - 1;
        rmq.change(elem, SZ(arr) - 1);
        
        if (not alive.count(0)) {
            alive.insert(0);
            assign(0, make_pair(SZ(arr) - 1, SZ(arr) - 1));
        } else {
            assign(0, make_pair(segms[0].get().first, SZ(arr) - 1));
        }

        if (not alive.count(elem))
            return;

        int pos = segms[elem].get().second;
        int p2 =  segms[elem].get().first;

        alive.erase(elem);
        assign(elem, make_pair(-1, -2));

        while (p2 <= pos) {
            // calc mex(pos..r).

            int mex = 1 + rmq.prefix_ge_than(pos);
            // int lo = elem + 1; // yes
            // int hi = n + 1;

            
            // while (hi - lo > 1) {
            //     int mi = lo + (hi - lo) / 2;

            //     if (rmq(0, mi - 1) >= pos)
            //         lo = mi;
            //     else
            //         hi = mi;
            // }

            // // mex is lo
            // int mex = lo;

            int L = max(p2, last[mex] + 1);
            alive.insert(mex);

            if (segms[mex].get().second == L - 1)
                assign(mex, make_pair(segms[mex].get().first, pos));
            else
                assign(mex, make_pair(L, pos));
            pos = L - 1;
        }
    };
        
    auto get = [&](int l, int r, int k) {        
        int64_t ans = 0;

        for (int iter = 0; iter != 2; ++iter) {
            int pos = (iter == 0 ? r : l - 1);
            int sgn = (iter == 0 ? +1 : -1);

            if (pos == -1)
                continue;

            node_t* nd = trees[k].get(pos);
            auto segg = segms[k].get2(pos);
            auto seg = segg.second;
            
            int64_t delta = nd->get(0, n + 3, l, r + 1);
            if (max(seg.first, l) <= min(seg.second, r))
                delta += (pos + 1 - segg.first) * int64_t(min(seg.second, r) - max(seg.first, l) + 1);
            
            ans += sgn * delta;
        }

        return ans;
    };
    
    int64_t lans = 0;
    for (int i = 0; i != n; ++i) {
        int ap, lp, rp, kp;
        cin >> ap >> lp >> rp >> kp;

        ap = (ap + lans) % (n + 1);
        lp = (lp + lans) % (i + 1);
        rp = (rp + lans) % (i + 1);
        kp = (kp + lans) % (n + 1);

        if (lp > rp)
            swap(lp, rp);

        append(ap);

        lans = get(lp, rp, kp);
        cout << lans << std::endl;
    }
    
    return 0;
}