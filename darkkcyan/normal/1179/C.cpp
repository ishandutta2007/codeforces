#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (int)(a); i < (int)(b); ++i) 
#define all(a) (a).begin(), (a).end()
// #define constexpr(...) (__VA_ARGS__)  
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

struct Node {
    int dish_left, man_left;
    
    Node() = default;
    Node(int dl, int ml): dish_left(dl), man_left(ml) {}
    
    Node(const Node& left, const Node& right) {
        dish_left = left.dish_left + right.dish_left;
        man_left = left.man_left + right.man_left;
        
        int consummed = min(left.dish_left, right.man_left);
        dish_left -= consummed;
        man_left -= consummed;
    }
};

const int maxval = 1e6 + 10;
int n, m;
int cnt_dish[maxval], cnt_man[maxval];
Node it[maxval * 4];

void single_upd(int i, int l, int r) {
    it[i] = Node(Node(cnt_dish[l], 0), Node(0, cnt_man[l]));
}

// [l, r)
void build(int i, int l, int r) {
    if (r - l == 1) {
        single_upd(i, l, r);
        return ;
    }
    int mid = (l + r) / 2;
    build(2 * i, l, mid);
    build(2 * i + 1, mid, r);
    it[i] = Node(it[2 * i], it[2 * i + 1]);
}

void upd(int pos, int i, int l, int r) {
    if (pos < l or pos >= r) return ;
    if (r - l == 1) {
        single_upd(i, l, r);
        return ;
    }
    
    int mid = (l + r) / 2;
    upd(pos, 2 * i, l, mid);
    upd(pos, 2 * i + 1, mid, r);
    it[i] = Node(it[2 * i], it[2 * i + 1]);
}

int get_max_left(int man_left, int i, int l, int r) {
    if (it[i].dish_left - man_left <= 0) return r;
    
    if (r - l == 1) {
        return l;
    }
    int mid = (l + r) / 2;
    if (it[2 * i + 1].dish_left - man_left > 0) {
        return get_max_left(man_left, 2 * i + 1, mid, r);
    }
    
    man_left -= it[2 * i + 1].dish_left;
    man_left += it[2 * i + 1].man_left;
    return get_max_left(man_left, 2 * i, l, mid);
}

const int maxn = 301010;
int dish_pos[maxn], man_pos[maxn];
int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    rep(i, 0, n) {
        cin >> dish_pos[i];
        cnt_dish[dish_pos[i]]++;
    }
    
    rep(i, 0, m) {
        cin >> man_pos[i];
        cnt_man[man_pos[i]] ++;
    }
    
    build(1, 0, maxval);
    
    int q; cin >> q;
    while (q--) {
        int t, i, x;
        cin >> t >> i >> x;
        --i;
        if (t == 1) {
            --cnt_dish[dish_pos[i]];
            upd(dish_pos[i], 1, 0, maxval);
            dish_pos[i] = x;
            ++cnt_dish[dish_pos[i]];
            upd(dish_pos[i], 1, 0, maxval);
        } else {
            --cnt_man[man_pos[i]];
            upd(man_pos[i], 1, 0, maxval);
            man_pos[i] = x;
            ++cnt_man[man_pos[i]];
            upd(man_pos[i], 1, 0, maxval);
        }
        int cur_ans = get_max_left(0, 1, 0, maxval);
        if (cur_ans >= maxval) cout << "-1\n";
        else cout << cur_ans << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker