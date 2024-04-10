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

const int maxn = 101010;
#define xx first
#define yy second
int n;
pair<int, int> a[maxn];

struct Range {
    ld l, r;
    bool is_empty() const {
        return l > r;
    }
};
print_op(Range) {
    return out << pair{u.l, u.r};
}

Range intersect(const Range& u, const Range& v) {
    return {max(u.l, v.l), min(u.r, v.r)};
}

const Range all_real{LLONG_MIN, LLONG_MAX};

struct RangeStack {
    vector<pair<Range, Range>> st;
    RangeStack(): st{{all_real, all_real}} {}
    
    inline void push(const Range& u) {
        st.emplace_back(u, intersect(u, st.back().second));
    }
    
    inline Range pop() {
        auto ans = st.back().first;
        st.pop_back();
        return ans;
    }
    
    inline bool empty() const {
        return sz(st) == 1;
    }
    
    inline Range intersect_all() const {
        return st.back().second;
    }
    void clear() {
        st.resize(1);
    }
};

struct RangeQueue {
    RangeStack head, tail;
    inline void push(const Range& u) {
        tail.push(u);
    }
    inline Range pop() {
        if (!head.empty()) return head.pop();
        while (!tail.empty()) {
            head.push(tail.pop());
        }
        return head.pop();
    }
    
    bool empty() const {
        return head.empty() and tail.empty();
    }
    
    inline Range intersect_all() const {
        return intersect(head.intersect_all(), tail.intersect_all());
    }
    void clear() {
        head.clear();
        tail.clear();
    }
};

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i].xx >> a[i].yy;
    }
    
    rep(i, 0, n) {
        a[i] = {a[i].xx + a[i].yy, a[i].xx - a[i].yy};
        // clog << a[i] << endl; 
    }
    
    sort(a, a + n);
    
    auto check = [&](ld d) {
        DB();
        clog << db(d) << endl;
        static RangeQueue qu;
        qu.clear();
        rep(i, 0, n) qu.push({a[i].yy - d, a[i].yy + d});
        clog << db(qu.intersect_all()) << endl;
        if (!qu.intersect_all().is_empty()) return true;
        
        int l = 0, r = 0;
        rep(i, 0, n) {
            ld border = a[i].xx - d;
            clog << db(i) << db(border) << endl;
            while (r < n and a[r].xx -d - eps < border) {
                qu.pop();
                ++r;
            }
            while (l < n and a[l].xx + d - eps < border) {
                qu.push({a[l].yy - d, a[l].yy + d});
                ++l;
            }
            clog << db(l) << db(r) << endl;
            clog << db(qu.intersect_all()) << endl;
            if (!qu.intersect_all().is_empty()) return true;
        }
        return false;
    };
    
    ld l = 0, r = 100. * INT_MAX;
    rep(iter, 0, 60) {
        ld mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    // l /= 2; 
    cout << fixed << setprecision(10) << l << endl;
    
    return 0;
}

// vim: foldmethod=marker