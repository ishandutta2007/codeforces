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

#define int int64_t

struct tree_t {
    vector<int> tmin;
    vector<int> modif;

    void recalc(int v, int nl, int nr) {
        tmin[v] = min(tmin[2 * v + 1] + modif[2 * v + 1],
                      tmin[2 * v + 2] + modif[2 * v + 2]);
    }

    void incr(int v, int nl, int nr, int l, int r, int x) {
        if (r <= nl or nr <= l)
            return;
        
        if (l <= nl and nr <= r) {
            modif[v] += x;
            return;
        }

        int mi = nl + (nr - nl) / 2;
        incr(2 * v + 1, nl, mi, l, r, x);
        incr(2 * v + 2, mi, nr, l, r, x);
        recalc(v, nl, nr);
    }

    int get_min(int v, int nl, int nr) {
        while (nl != nr - 1) {
            int mi = nl + (nr - nl) / 2;

            if (tmin[2 * v + 1] + modif[2 * v + 1] < tmin[2 * v + 2] + modif[2 * v + 2]) {
                v = 2 * v + 1;
                nr = mi;
            } else {
                v = 2 * v + 2;
                nl = mi;
            }
        }

        return nl;
    }
};

int32_t main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n = input<int>();

    tree_t tree;
    tree.tmin.resize(4 * n);
    tree.modif.resize(4 * n);

    for (int i = 0; i != n; ++i)
        tree.incr(0, 0, n, i, i + 1, input<int>());
    
    vector<int> perm(n, -1);
    for (int i = 1; i <= n; ++i) {
        int pmin = tree.get_min(0, 0, n);
        perm[pmin] = i;

        tree.incr(0, 0, n, pmin + 1, n, -i);
        tree.incr(0, 0, n, pmin, pmin + 1, TYPEMAX(int64_t) / 10);
    }

    for (int elem: perm)
        cout << elem << " ";
    cout << "\n";
    
    return 0;
}