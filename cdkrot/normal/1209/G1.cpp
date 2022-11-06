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
using std::queue;

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

struct val_t {
    int mn = 0;
    
    int global_max = 0;
    
    int sum_between = 0;
    int max_before_mn = 0;
    int max_after_mn = 0;
};

val_t combine(val_t a, int mid, val_t b) {
    val_t res;
    res.mn = min(a.mn, b.mn);
    res.global_max = max({mid, a.global_max, b.global_max});

    if (a.mn == b.mn) {
        res.max_before_mn = a.max_before_mn;
        res.max_after_mn  = b.max_after_mn;
        res.sum_between   = a.sum_between + b.sum_between + max({mid, a.max_after_mn, b.max_before_mn});
    } else if (a.mn < b.mn) {
        res.sum_between   = a.sum_between;
        res.max_before_mn = a.max_before_mn;
        res.max_after_mn  = max({a.max_after_mn, mid, b.global_max});
    } else {
        res.sum_between   = b.sum_between;
        res.max_after_mn  = b.max_after_mn;
        res.max_before_mn = max({b.max_before_mn, mid, a.global_max});
    }

    return res;
}

vector<int> values;
vector<int> modif;
vector<val_t> tree;

void push(int no, int nl, int nr) {
    tree[no].mn += modif[no];
    if (nl != nr - 1) {
        modif[2 * no + 1] += modif[no];
        modif[2 * no + 2] += modif[no];
    }

    modif[no] = 0;
}

void recalc(int no, int nl, int nr) {
    val_t v1 = tree[2 * no + 1];
    val_t v2 = tree[2 * no + 2];

    v1.mn += modif[2 * no + 1];
    v2.mn += modif[2 * no + 2];

    int mi = nl + (nr - nl) / 2;
    tree[no] = combine(v1, values[mi - 1], v2);
}

void get(int no, int nl, int nr, int l, int r, val_t& res) {
    push(no, nl, nr);
    
    if (l <= nl and nr <= r) {        
        if (res.mn == -228)
            res = tree[no];
        else
            res = combine(res, values[nl - 1], tree[no]);

        return;
    }

    if (nr <= l or r <= nl)
        return;

    int mi = nl + (nr - nl) / 2;
    get(2 * no + 1, nl, mi, l, r, res);
    get(2 * no + 2, mi, nr, l, r, res);
}

void incr_range(int no, int nl, int nr, int l, int r, int delta) {
    if (nr <= l or r <= nl)
        return;
            
    if (l <= nl and nr <= r) {
        modif[no] += delta;
        return;
    }

    push(no, nl, nr);

    int mi = nl + (nr - nl) / 2;
    incr_range(2 * no + 1, nl, mi, l, r, delta);
    incr_range(2 * no + 2, mi, nr, l, r, delta);

    recalc(no, nl, nr);
}

void recalc_pos(int no, int nl, int nr, int i) {
    if (nl == nr - 1)
        return;

    push(no, nl, nr);

    int mi = nl + (nr - nl) / 2;
    
    if (i < mi)
        recalc_pos(2 * no + 1, nl, mi, i);
    else
        recalc_pos(2 * no + 2, mi, nr, i);

    recalc(no, nl, nr);
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n = input<int>();
    int q = input<int>();
    vector<int> arr(n);
    input_seq(ALL(arr));

    std::unordered_map<int, set<int>> was;
    for (int i = 0; i != n; ++i)
        was[arr[i]].insert(i);

    modif.resize(4 * (n + 1));
    tree.resize(4 * (n + 1));
    values.resize(n);
    
    auto unsetup = [&](int val) {
        auto& cur = was[val];
                
        if (cur.empty())
            return;

        auto fst = *cur.begin();
        auto lst = *cur.rbegin();
        
        values[fst] = 0;
        recalc_pos(0, 0, (n + 1), fst);
        recalc_pos(0, 0, (n + 1), fst + 1);
        
        incr_range(0, 0, (n + 1), fst + 1, lst + 1, -1);
    };
    
    auto setup = [&](int val) {
        auto& cur = was[val];
        
        if (cur.empty())
            return;
        
        auto fst = *cur.begin();
        auto lst = *cur.rbegin();
        
        values[fst] = SZ(cur);
        recalc_pos(0, 0, (n + 1), fst);
        recalc_pos(0, 0, (n + 1), fst + 1);
        
        incr_range(0, 0, (n + 1), fst + 1, lst + 1, +1);
    };

    
    for (auto& elem: was) {
        setup(elem.first);
    }

    auto calc = [&]() {
        val_t rs;
        rs.mn = -228;
        get(0, 0, (n + 1), 0, (n + 1), rs);
        
        return n - rs.sum_between;
    };

    cout << calc() << "\n";
    
    for (int t = 0; t != q; ++t) {
        int i = input<int>() - 1;
        int x = input<int>();
        int old = arr[i];
        
        unsetup(old);
        unsetup(x);
        
        was[old].erase(i);
        was[x].insert(i);
        arr[i] = x;
        
        setup(x);
        setup(old);
        
        cout << calc() << "\n";
    }

    return 0;
}