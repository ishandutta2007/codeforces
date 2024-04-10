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

template<class It1, class It2>
int count_unmatched(It1 beg1, It1 end1, It2 beg2, It2 end2) {
    int ans = 0;
    for (; beg1 != end1; ++beg1) {
        while (beg2 != end2 and *beg2 < *beg1) ++beg2;
        if (beg2 == end2) ++ans;
        else ans += *beg1 != *beg2;
    }
    return ans;
}

using pt = pair<int, int>;
#define xx first
#define yy second

const int maxn = 201010;
int n, k;
pt a[maxn];

bool can_be_center(const pt& cen_2) {
    DB();
    static pt b[maxn];
    int f = n; 
    rep(i, 0, n) {
        --f;
        b[f].xx = cen_2.xx - a[i].xx;
        b[f].yy = cen_2.yy - a[i].yy;
    }
    assert(is_sorted(b, b + n));
    
    int cur_count = count_unmatched(a, a + n, b, b + n);
    clog << db(cen_2) << db(cur_count) << endl;
    clog << db(vector<pt>(a, a + n)) << endl;
    clog << db(vector<pt>(b, b + n)) << endl;
    return cur_count <= k;
}

void print_half(int x) {
    if (x < 0) {
        cout << "-";
        print_half(-x);
        return ;
    }
    cout << x / 2 << "." << (x % 2) * 5;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> k;
    rep(i, 0, n) {
        cin >> a[i].xx >> a[i].yy;
        clog << a[i] << endl;
    }
    
    sort(a, a + n);
    
    if (k >= n) {
        cout << "-1\n";
        return 0;
    }
    
    set<pt> possible_cen_2;
    rep(i, 0, k + 1) {
        int rest = k - i;
        rep(f, 0, rest + 1) {
            pt new_point = {
                    a[i].xx + a[n - 1 - f].xx,
                    a[i].yy + a[n - 1 - f].yy
                    };
            clog << db(a[i]) << db(a[n - 1 - f]) << db(new_point) << endl;
            possible_cen_2.insert(new_point);
        }
    }
    clog << db(possible_cen_2) << endl;
    
    vector<pt> ans;
    copy_if(all(possible_cen_2), back_inserter(ans), can_be_center);
    
    cout << sz(ans) << '\n';
    for (auto [x, y]: ans) {
        print_half(x);
        cout << ' ';
        print_half(y);
        cout << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker