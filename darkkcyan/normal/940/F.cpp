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

struct DS {
    vector<int> freq, cnt_freq;
    
    DS(int len): freq(len), cnt_freq(len) {
        cnt_freq[0] = len;
    }
    
    void add(int val) {
        --cnt_freq[freq[val]];
        freq[val]++;
        ++cnt_freq[freq[val]];
    }
    void rem(int val) {
        --cnt_freq[freq[val]];
        freq[val]--;
        ++cnt_freq[freq[val]];
    }
    
    int find_mex_cnt() const {
        int ans = 0;
        while (cnt_freq[ans]) ++ ans;
        return ans;
    }
};

struct Query {
    int id, l, r;
};

struct Update {
    int id, pos, val;
};

const int maxn = 101010;
const int k = 2150;
vector<Query> queries[k][k];
vector<Update> updates;

int n, q;
vector<int> org_arr;
int ans[maxn];
void process(int l_blk, int r_blk) {
    DS ds(n + q + 1);
    int l = l_blk * k, r = l;
    
    int upd_it = 0;
    auto arr = org_arr;
    for (auto [qid, ql, qr]: queries[l_blk][r_blk]) {
        while (l > ql) ds.add(arr[--l]);
        while (r < qr) ds.add(arr[r++]);
        while (l < ql) ds.rem(arr[l++]);
        while (r > qr) ds.rem(arr[--r]);
        
        while (upd_it < sz(updates) and updates[upd_it].id < qid) {
            auto [uid, pos, val] = updates[upd_it++];
            if (l <= pos and pos < r) {
                ds.rem(arr[pos]);
                arr[pos] = val;
                ds.add(val);
            } else {
                arr[pos] = val;
            }
        }
        ans[qid] = ds.find_mex_cnt();
    }
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> q;
    org_arr.resize(n);
    rep(i, 0, n) cin >> org_arr[i];
    auto values = org_arr;
    rep(i, 0, q) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r; cin >> l >> r;
            --l;
            queries[l / k][r / k].push_back({i, l, r});
        } else {
            int pos, val;
            cin >> pos >> val;
            updates.push_back({i, --pos, val});
            ans[i] = -1;
            values.push_back(val);
        }
    }
    
    sort(all(values));
    values.erase(unique(all(values)), values.end());
    
    for (auto & i: org_arr) {
        i = (int)(lower_bound(all(values), i) - values.begin());
    }
    
    for (auto& [id, pos, val]: updates) {
        val = (int)(lower_bound(all(values), val) - values.begin());
    }
    
    int last_blk = (n - 1) / k;
    rep(lblk, 0, last_blk + 1) {
        rep(rblk, lblk, last_blk + 1) 
            process(lblk, rblk);
    }
    
    rep(i, 0, q) {
        if (ans[i] != -1) cout << ans[i] << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker