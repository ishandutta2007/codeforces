// 2018, Sayutin Dmitry.

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

#define pb push_back
#define eb emplace_back

std::mt19937 rnd(31031999);

struct node;
int sz(node* a);

struct node {
    node(int x_ = -228, node* left_ = NULL, node* right_ = NULL) {
        x = x_;
        left = left_;
        right = right_;

        sz = 1 + ::sz(left) + ::sz(right);
    }

    int x;
    int sz;
    node* left;
    node* right;
};

int sz(node* a) {
    if (a == NULL)
        return 0;
    return a->sz;
}

const int num_nodes = 5e7;
const int threshold = 5e3;
node pool[num_nodes];
int p_node = 0;

node* new_node(int x_, node* left_ = NULL, node* right_ = NULL) {
    assert(p_node != num_nodes);
    pool[p_node] = node(x_, left_, right_);
    return &pool[p_node++];
}

pair<node*, node*> split(node* a, int cnt) {
    if (a == NULL)
        return make_pair<node*, node*>(NULL, NULL);

    if (sz(a->left) >= cnt) {
        auto spl = split(a->left, cnt);
        return make_pair(spl.first,
                         new_node(a->x, spl.second, a->right));
    } else {
        auto spl = split(a->right, cnt - 1 - sz(a->left));
        return make_pair(new_node(a->x, a->left, spl.first),
                         spl.second);
    }
}

node* merge(node* a, node* b) {
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    if (rnd() % uint32_t(a->sz + b->sz) < uint32_t(a->sz)) {
        return new_node(a->x, a->left, merge(a->right, b));
    } else {
        return new_node(b->x, merge(a, b->left), b->right);
    }
}

void print(node* a, vector<int>& res) {
    if (a == NULL)
        return;

    print(a->left, res);
    res.push_back(a->x);
    print(a->right, res);
}

// perform [n - 1, ... 1].
vector<int> get_kukarek(int n, int m) {
    node* cur = NULL;

    for (int i = 0; i != n; ++i)
        cur = merge(cur, new_node(i, NULL, NULL));

    auto circ_segment = [&](int l, int r) {
        l %= n;
        r %= n;

        if (l < 0)
            l += n;
        if (r < 0)
            r += n;

        if (l <= r) {
            auto spl = split(cur, r + 1);
            return split(spl.first, l).second;
        } else {
            return merge(split(cur, l).second,
                         split(cur, r + 1).first);
        }
    };

    auto rebuild = [&]() {
        vector<int> res;
        print(cur, res);
        
        cur = NULL;
        p_node = 0;

        for (int i = 0; i != n; ++i)
            cur = merge(cur, new_node(res[i], NULL, NULL));
    };
    
    for (int step = 1; step <= n; ++step) {
        // [0; m - 1] goes to [step, step + m - 1]
        // [m; n - 1] goes to [m - step, n - 1 - step]

        if (num_nodes - p_node < threshold) {
            rebuild();
        }
        
        node* A = circ_segment(step, step + m - 1);
        node* B = circ_segment(m - step, n - 1 - step);
        cur = merge(A, B);
    }

    vector<int> res;
    print(cur, res);
    return res;
}

int32_t main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n = input<int>();
    int m = input<int>();

    int s = input<int>() - 1;
    int64_t t = input<int64_t>();

    vector<int> go = get_kukarek(n, m);
    
    int64_t full = t / n;
    t %= n;

    for (; t > 0; --t) {
        if (s < m)
            s = (s + t) % n;
        else {
            s = (s - t) % n;
            if (s < 0)
                s += n;
        }
    }

    if (1) {        
        vector<int> id(n, -1);

        int cur_id = 0;
        int pos = s;
        for (; true ; pos = go[pos], cur_id += 1) {
            if (id[pos] == -1)
                id[pos] = cur_id;
            else
                break;
        }

        int predperiod = id[pos];
        int period = cur_id - id[pos];

        full -= predperiod;
        full %= period;
        full += predperiod;
    }

    for (; full > 0; --full)
        s = go[s];

    cout << s + 1 << "\n";
    
    return 0;
}