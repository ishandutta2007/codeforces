#include <bits/stdc++.h>
using namespace std;

// #define constexpr(...) (__VA_ARGS__)  
using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (int)(a); i < (int)(b); ++i) 
#define all(a) (a).begin(), (a).end()
#define print_op(type) ostream& operator<<(ostream& out, const type& u)
// DEBUGING TEMPLETE ////////////////////////////////////////////////////////////////////////{{{
#define db(val) "["#val" = "<<(val)<<"] "
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
#   define clog cerr << flush << string(__db_level * 2, ' ')
#   define DB() debug_block CONCAT(dbbl, __LINE__)
    int __db_level = 0;
    struct debug_block {
        debug_block() { clog << "{" << endl; ++__db_level; }
        ~debug_block() { --__db_level; clog << "}" << endl; }
    };
#else
#   define clog if (0) cerr
#   define DB(...)
#endif

template<class U, class V> ostream& operator<<(ostream& out, const pair<U, V>& p) {
    return out << "(" << p.first << ", " << p.second << ")";
}

template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")"; 
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup); 
}

template<class ...U> ostream& operator<<(ostream& out, const tuple<U...>& tup) {
    return print_tuple_utils<0, tuple<U...>>(out, tup);
}

template<class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream&>::type
operator<<(ostream& out, const Con& container) { 
    out << "{";
    for (auto it = container.begin(); it != container.end(); ++it)
        out << (it == container.begin() ? "" : ", ") << *it;
    return out << "}";
}
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////}}}

struct Line {
    int x, y;
    Line(): x(INT_MIN), y(INT_MIN) {}
    Line(int x_, int y_): x(x_), y(y_) {}
    
    ll operator()(ll q) const {
        if (x == INT_MIN and y == INT_MIN) return LLONG_MIN;
        return x * q + y;
    }
};

template<class T>
int scmp(const T& u, const T& v) {
    if (u < v) return -1;
    else return u > v;
}

// spare Li-Chao segment tree with rollback
struct DS {
    struct Node {
        Line inner;
        Node *left, *right;
        Node(Line ln = Line()): inner(ln), left(0), right(0) {}
        ~Node() {
            if (left) delete left;
            if (right) delete right;
        }
    };
    
    vector<pair<Node*, Line>> history;
    void save_his(Node* n) {
        history.emplace_back(n, n->inner);
    }
    Node* root;
    
    int low, hi;
    DS(int l, int r): root(0), low(l), hi(r) {}
    ~DS() {
        if (root) delete root;
    }
    
    void add(const Line& ln) {
        root = add(root, ln, low, hi);
    }
    
    Node* add(Node* node, Line ln, int l, int r) {
        if (!node) {
            auto ans = new Node();
            save_his(ans);
            ans->inner = ln;
            return ans;
        }
        int mid = (l + r) / 2;
        int mid_diff = scmp(node->inner(mid), ln(mid));
        if (mid_diff < 0) {
            save_his(node);
            swap(node->inner, ln);
        }
        if (r - l == 1) return node;
        int l_diff = scmp(node->inner(l), ln(l));
        int r_diff = scmp(node->inner(r - 1), ln(r - 1));
        if (l_diff >= 0 and r_diff >= 0) return node;
        if (l_diff < 0) {
            node->left = add(node->left, ln, l, mid);
        }
        if (r_diff < 0) {
            node->right = add(node->right, ln, mid, r);
        }
        return node;
    }
    
    ll query(ll q) {
        return query(root, q, low, hi);
    }
    
    ll query(Node* node, ll q, int l, int r) {
        if (!node) return LLONG_MIN;
        ll ans = node->inner(q);
        int mid = (l + r) / 2;
        return max(ans, q < mid ? query(node->left, q, l, mid) : query(node->right, q, mid, r));
    }
    
    int time_stamp() const {
        return sz(history);
    }
    
    void restore(int stamp) {
        while (sz(history) > stamp) {
            auto [n, l] = history.back();
            history.pop_back();
            n->inner = l;
        }
    }
};

const int maxn = 300010;
const int max_range = 1e9 + 10;
int n;
ll query[maxn];
vector<Line> updates[maxn * 4];
Line added[maxn];

void add_update(int from, int to, Line ln, int i, int l, int r) {
    if (from >= r or l >= to) return ;
    if (from <= l and r <= to) {
        updates[i].push_back(ln);
        return ;
    }
    int mid = (l + r) / 2;
    add_update(from, to, ln, 2 * i, l, mid);
    add_update(from, to, ln, 2 * i + 1, mid, r);
}

DS ds(-max_range, max_range);
void process(int i, int l, int r) {
    int mid = (l + r) / 2;
    int st = ds.time_stamp();
    for (auto ln: updates[i]) ds.add(ln);
    if (r - l == 1) {
        if (query[l] != LLONG_MIN) {
            DB();
            auto ans = ds.query(query[l]);
            if (ans == LLONG_MIN) cout << "EMPTY SET\n";
            else cout << ans << '\n';
        }
    } else {
        process(2 * i, l, mid);
        process(2 * i + 1, mid, r);
    }
    ds.restore(st);
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    rep(i, 0, n) {
        query[i] = LLONG_MIN;
        int t; cin >> t;
        if (t == 1) {
            int a, b; cin >> a >> b;
            added[i] = Line(a, b);
        } else if (t == 2) {
            int id; cin >> id;
            --id;
            add_update(id, i, added[id], 1, 0, n);
            added[id] = Line();
        } else {
            cin >> query[i];
        }
    }
    
    rep(i, 0, n) {
        if (added[i].y == LLONG_MIN) continue;
        add_update(i, n, added[i], 1, 0, n);
    }
    
    process(1, 0, n);
    
    return 0;
}

// vim: foldmethod=marker