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

struct node {
    int sum;
    int sufmax;
};

const int max_n = 300 * 1000 + 1;
node tree[4 * max_n];

void incr(int no, int nl, int nr, int i, int x) {
    if (nl == nr - 1) {
        tree[no].sum += x;
        tree[no].sufmax += x;
        return;
    }

    int mi = nl + (nr - nl) / 2;
    if (i < mi)
        incr(2 * no + 1, nl, mi, i, x);
    else
        incr(2 * no + 2, mi, nr, i, x);

    tree[no].sum += x;
    tree[no].sufmax = max(tree[2 * no + 2].sufmax,
                          tree[2 * no + 2].sum + tree[2 * no + 1].sufmax);
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n = input<int>();
    vector<int> vals(n);
    vector<int> bombs(n);

    for (int i = 0; i < n; ++i)
        vals[i] = input<int>();

    for (int i = 0; i < n; ++i)
        bombs[i] = input<int>() - 1;

    vector<int> ans(n);
    vector<int> where(n + 1, -1);
    for (int i = 0; i < n; ++i)
        where[vals[i]] = i;

    auto incr = [&](int i, int x) {
        ::incr(0, 0, n, i, x);
    };
        
    for (int i = 0; i < n; ++i)
        incr(bombs[i], -1);
    for (int i = 0; i < n; ++i)
        incr(i, +1);
    
    int cur_ans = 1;
    for (int pos = n - 1; pos >= 0; --pos) {
        incr(bombs[pos], +1);

        while (cur_ans != n) {
            cur_ans += 1;

            incr(where[cur_ans - 1], -1);
            if (tree[0].sufmax > 0) {}
            else {
                incr(where[cur_ans - 1], +1);
                --cur_ans;
                break;
            }
        }

        ans[pos] = cur_ans;
    }

    for (int elem: ans)
        cout << elem << " ";
    cout << "\n";

    return 0;
}