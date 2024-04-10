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


struct IT {
    vector<int> ma, mi, lz;
    IT(int len): ma(len * 4), mi(len * 4), lz(len * 4) {}
    
    IT(int len, const function<int(int)>& get): IT(len) {
        build(1, 0, (int)size(), get);
    }
    
    size_t size() const { return sz(mi) / 4; }
    
    void build(int i, int l, int r, const function<int(int)>& get) {
        if (r - l == 1) {
            mi[i] = ma[i] = get(l);
            return ;
        }
        int mid = (l + r) / 2;
        build(2 * i, l, mid, get);
        build(2 * i + 1, mid, r, get);
        merge(i);
    }
    
    void merge(int i) {
        mi[i] = min(mi[2 * i], mi[2 * i + 1]);
        ma[i] = max(ma[2 * i], ma[2 * i + 1]);
    }
    
    void push(int i, int l, int r) {
        mi[i] += lz[i];
        ma[i] += lz[i];
        if (r - l > 1) {
            lz[2 * i] += lz[i];
            lz[2 * i + 1] += lz[i];
        }
        lz[i] = 0;
    }
    
    void upd(int from, int to, int del, int i, int l, int r) {
        push(i, l, r);
        if (from >= r or l >= to) return ;
        if (from <= l and r <= to) {
            lz[i] += del;
            push(i, l, r);
            return ;
        }
        int mid = (l + r) / 2;
        upd(from, to, del, 2 * i, l, mid);
        upd(from, to, del, 2 * i + 1, mid, r);
        merge(i);
    }
    
    int get_max(int from, int to, int i, int l, int r) {
        push(i, l, r);
        if (from >= r or l >= to) return INT_MIN;
        if (from <= l and r <= to) {
            return ma[i];
        }
        int mid = (l + r) / 2;
        return max(get_max(from, to, 2 * i, l, mid), get_max(from, to, 2 * i + 1, mid, r));
    }
    int get_min(int from, int to, int i, int l, int r) {
        push(i, l, r);
        if (from >= r or l >= to) return INT_MAX;
        if (from <= l and r <= to) {
            return mi[i];
        }
        int mid = (l + r) / 2;
        return min(get_min(from, to, 2 * i, l, mid), get_min(from, to, 2 * i + 1, mid, r));
    }
    
    void upd(int from, int to, int del) {
        return upd(from, to, del, 1, 0, (int)size());
    }
    
    int get_max(int from, int to) { return get_max(from, to, 1, 0, (int)size()); }
    int get_min(int from, int to) { return get_min(from, to, 1, 0, (int)size()); }
    
    void print(ostream& out) {
        print(out, 1, 0, (int)size());
    }
    
    void print(ostream& out, int i, int l, int r) {
        push(i, l, r);
        if (r - l == 1) {
            out << mi[i] << ' ';
            return ;
        }
        int mid = (l + r) / 2;
        print(out, 2 * i, l, mid);
        print(out, 2 * i + 1, mid, r);
    }
    
    friend ostream& operator<<(ostream& out, IT& it) {
        it.print(out);
        return out;
    }
};

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> pos(n + 10);
    rep(i, 0, n) {
        int x; cin >> x;
        pos[x].push_back(i);
    }
    
    IT it(n + 1, [](int i) { return i; });
    
    vector<int> ans(n);
    
    auto upd = [&](int i, int val) {
        clog << db(i) << db(val) << endl;
        ans[i] = max(ans[i], val);
    };
    
    rep(val, 1, n + 10) {
        auto& cp = pos[val];
        if (cp.empty()) continue;
        DB();
        clog << db(val) << db(cp) << endl;
        for (auto i: cp) {
            clog << db(i) <<endl;
            it.upd(i + 1, n + 1, -1);
            clog << it << endl;
            
            clog << it << endl;
            int cur_sum = it.get_max(i + 1, i + 2);
            int max_left = cur_sum - it.get_min(0, i + 2);
            int max_right = it.get_max(i + 1, n + 1) - cur_sum;
            clog << db(max_left) << db(max_right) << db(cur_sum) << endl;
            upd(i, (max_left + max_right + 1) / 2);
            
            
            it.upd(i + 1, n + 1, 1);
        }
        
        for (auto i: cp) {
            it.upd(i + 1, n + 1, -2);
        }
        
        for (auto i: cp) {
            clog << db(i) <<endl;
            it.upd(i + 1, n + 1, 1);
            
            int cur_sum = it.get_max(i + 1, i + 2);
            int min_left = cur_sum - it.get_max(0, i + 2);
            int min_right = it.get_min(i + 1, n + 1) - cur_sum;
            clog << db(min_left) << db(min_right) << db(cur_sum) << endl;
            upd(i, (-min_left - min_right) / 2);
            
            
            it.upd(i + 1,  n + 1, -1);
        }
    }
    
    rep(i, 0, n) cout << ans[i] << ' ';
    
    return 0;
}

// vim: foldmethod=marker