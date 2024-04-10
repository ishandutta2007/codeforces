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

const int maxn = 44;
const int maxk = 11;
int n, k;
vector<int> cmds[maxk];

bool can_be_sorted(vector<int> x) {
    DB();
    clog << db(x) << endl;
    rep(i, 0, k) {
        vector<int> values;
        for (auto p: cmds[i]) values.push_back(x[p]);
        sort(all(values));
        rep(f, 0, sz(cmds[i])) {
            int p = cmds[i][f];
            x[p] = values[f];
        }
    }
    clog << db(x) << db(is_sorted(all(x))) << endl;
    return is_sorted(all(x));
}

bool solve() {
    if (n == 1) return true;
    if (k == 0) return false;
    DB();
#define nope() return false;
#ifdef LOCAL
    using Arr = array<short, 40>;
#else
    using Arr = array<char, 40>;
#endif
    
    vector<Arr> cur_arr;
    cur_arr.emplace_back();
    cur_arr[0].fill(2);
    vector<bool> has_id(n);
    rep(i, 0, k - 1) {
        DB();
        clog << db(i) << endl;
        vector<int> old_ids;
        int cnt_new = 0;
        for (auto id: cmds[i]) {
            if (has_id[id]) {
                old_ids.push_back(id);
            } else {
                has_id[id] = true;
                ++cnt_new;
            }
        }
        static vector<Arr> new_arr;
        new_arr.clear();
        new_arr.reserve(sz(cur_arr) * (cnt_new + 1));
        
        for (const auto& old_arr: cur_arr) {
            clog << db(old_arr) << endl;
            new_arr.resize(sz(new_arr) + cnt_new + 1, old_arr);
            rep(cur_1, 0, cnt_new + 1) {
                auto& arr = new_arr.rbegin()[cur_1];
                arr = old_arr;
                int total_1 = cur_1;
                for (auto& pos: old_ids) total_1 += arr[pos];
                int total_0 = sz(cmds[i]) - total_1;
                rep(pos, 0, total_0) {
                    arr[cmds[i][pos]] = 0;
                }
                rep(pos, total_0, sz(cmds[i])) {
                    arr[cmds[i][pos]] = 1;
                }
                // DB(); 
                // clog << db(cur_1) << db(arr) << endl; 
            }
        }
        
        // clog << db(new_arr) << endl; 
        swap(new_arr, cur_arr);
    }
    
    for (auto i: cmds[k - 1]) {
        has_id[i] = 1;
    }
    clog << db(has_id) << endl;
    rep(i, 0, n) if (!has_id[i]) nope();
    for (auto& arr: cur_arr) {
        int cnt[3] = {0};
        for (auto pos: cmds[k - 1]) cnt[arr[pos]] ++;
        cnt[2] += cnt[0];
        cnt[1] += cnt[2];
        rep(i, 0, cnt[0]) {
            arr[cmds[k - 1][i]] = 0;
        }
        rep(i, cnt[0], cnt[2]) {
            arr[cmds[k - 1][i]] = 2;
        }
        rep(i, cnt[2], cnt[1]) {
            arr[cmds[k - 1][i]] = 1;
        }
        int i = 0;
        while (i < n and arr[i] == 0) ++i;
        while (i < n and arr[i] == 2) ++i;
        while (i < n and arr[i] == 1) ++i;
        clog << db(arr) << db(i) << endl;
        if (i != n) nope();
    }
    return true;
}

bool brute() {
    vector<int> x(n);
    rep(mask, 0, (1 << n)) {
        rep(i, 0, n) x[i] = (mask >> i) & 1;
        if (!can_be_sorted(x)) return false;
    }
    return true;
}

mt19937 rng;
#define rand() ((int)(rng() >> 1))
void check() {
    while (true) {
        n = rand() % 20 + 1;
        k = rand() % 10 + 1;
        vector<int> ids(n);
        rep(i, 0, n) ids[i] = i;
        rep(i, 0, k) {
            cmds[i].resize(rand() % n + 1);
            shuffle(all(ids), rng);
            rep(f, 0, sz(cmds[i])) cmds[i][f] = ids[f];
            sort(all(cmds[i]));
        }
        
        auto ans = solve();
        auto exp = brute();
        if (ans == exp) {
            cout << "OK" << endl;
            continue;
        }
        ofstream inp("main.inp");
        inp << n << ' ' << k << endl;
        rep(i, 0, k) {
            inp << sz(cmds[i]) << ' ';
            for (auto x: cmds[i]) inp << x + 1 << ' ';
            inp << '\n';
        }
        inp << db(ans) << db(exp) << endl;
        inp.close();
        cout << "FAILED" << endl;
        exit(0);
    }
}

int main() {
    // check();     
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    rep(i, 0, k) {
        int l; cin >> l;
        cmds[i].resize(l);
        for (auto& x: cmds[i]) {
            cin >> x;
            --x;
        }
        
        
    }
    {
        DB();
        auto ans = solve();
        cout << (ans ? "ACCEPTED" : "REJECTED") << endl;
    }
#ifdef LOCAL
    {
        DB();
        auto exp = brute();
        cout << db(exp) << endl;
    }
#endif
    
    return 0;
}

// vim: foldmethod=marker