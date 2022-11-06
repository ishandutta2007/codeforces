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

struct walkway_t {
    int len;
    double speed;
    bool is_feet;
};

struct rsq_t {
    vector<double> tree;
    vector<double> modif;
    
    rsq_t(int n) {
        tree.resize(4 * n);
        modif.resize(4 * n);
    }

    double get_min(int no, int nl, int nr, int l, int r) {
        if (l <= nl and nr <= r)
            return tree[no] + modif[no];

        if (nr <= l or r <= nl)
            return +1e100;

        int mi = nl + (nr - nl) / 2;
        return modif[no] + min(get_min(2 * no + 1, nl, mi, l, r),
                              get_min(2 * no + 2, mi, nr, l, r));
    }

    void increase(int no, int nl, int nr, int l, int r, double delta) {
        if (l <= nl and nr <= r) {
            modif[no] += delta;
            return;
        }

        if (nr <= l or r <= nl)
            return;

        int mi = nl + (nr - nl) / 2;
        increase(2 * no + 1, nl, mi, l, r, delta);
        increase(2 * no + 2, mi, nr, l, r, delta);

        tree[no] = min(tree[2 * no + 1] + modif[2 * no + 1],
                       tree[2 * no + 2] + modif[2 * no + 2]);
    }
};

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n = input<int>();
    int l = input<int>();

    vector<walkway_t> walks;
    
    if (1) {
        int start = 0;
        for (int i = 0; i < n; ++i) {
            int x, y;
            double s;
            cin >> x >> y >> s;

            if (x != start)
                walks.push_back(walkway_t {x - start, 0, true});

            walks.push_back(walkway_t {y - x, s, false});
            start = y;
        }

        if (start != l)
            walks.push_back(walkway_t {l - start, 0, true});
    }

    n = SZ(walks);
    vector<int> order(n);
    std::iota(ALL(order), 0);

    sort(ALL(order), [&](int i, int j) {return walks[i].speed + 1e-10 < walks[j].speed;});

    rsq_t rsq(n);
    for (int i = 0; i < n; ++i)
        if (not walks[i].is_feet)
            rsq.increase(0, 0, n, i, n, walks[i].len / walks[i].speed);
    
    double ans = 0;
    for (int i: order) {
        if (not walks[i].is_feet)
            rsq.increase(0, 0, n, i, n, -(walks[i].len / walks[i].speed));
        
        walks[i].speed += 1;
        double energy_lim = /* speed */ 1.0 * walks[i].len / (walks[i].speed + 1.0);

        double suf_min = rsq.get_min(0, 0, n, i, n);

        energy_lim = min(energy_lim, suf_min);
        rsq.increase(0, 0, n, i, n, -energy_lim);
        
        ans += (walks[i].len - energy_lim) / walks[i].speed;
    }

    cout << std::fixed;
    cout.precision(10);
    cout << ans << "\n";

    return 0;
}