// #pragma GCC optimize ("Ofast") 
// #pragma GCC optimize ("unroll-loops") 
// #define stress 
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

#define maxbit 20
const int maxval = (1 << maxbit) + 10;
const int half_val = maxval / 2 + 5;

int n, m;
int lower_half, upper_half;

char popcount[half_val];

struct Block {
    vector<array<int, maxbit / 2 + 2>> res;
    Block(): res(1 << lower_half) {}
    void cal(int* cnt) {
        rep(i, 0, (1 << lower_half)) {
            clog << db(i) << db(cnt[i]) << endl;
        }
        // memset(res, 0, sizeof(res)); 
        rep(mask, 0, (1 << lower_half)) {
            static array<int, maxbit / 2 + 1> cnt_lower_diff;
            cnt_lower_diff.fill(0);
            rep(val, 0, (1 << lower_half)) {
                int diff = popcount[mask ^ val];
                cnt_lower_diff[diff] += cnt[val];
            }
            
            auto& cur_res = res[mask];
            rep(lower_diff, 0, lower_half + 1) {
                rep(upper_diff, 0, upper_half + 2) {
                    int val = min(upper_diff + lower_diff, n - lower_diff - upper_diff);
                    clog << db(lower_diff) << db(upper_diff) << db(val) << db(cnt_lower_diff[lower_diff]) << endl;
                    cur_res[upper_diff] += cnt_lower_diff[lower_diff] * val;
                }
            }
        }
    }
};

int cnt[maxval];
vector<Block> blk;

void precal() {
    rep(i, 0, half_val) popcount[i] = (char)__builtin_popcount(i);
    
    lower_half = n / 2;
    upper_half = n - lower_half - 1;
    clog << db(lower_half) << db(upper_half) << endl;
    blk.resize(1 << upper_half);
    rep(bi, 0, (1 << upper_half)) {
        DB();
        clog << db(bi) << endl;
        blk[bi].cal(cnt + (1 << lower_half) * bi);
    }
}

int query(int mask) {
    DB();
    clog << db(mask) << endl;
    int ans = 0;
    rep(upper_mask, 0, (1 << upper_half)) {
        int upper_diff = popcount[upper_mask ^ (mask >> lower_half)];
        auto cur_ans = blk[upper_mask].res[mask & ((1 << lower_half) - 1)][upper_diff];
        clog << db(upper_mask) << db(upper_diff) << db(cur_ans) << endl;
        ans += cur_ans;
    }
    clog << db(ans) << endl;
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin);  
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef stress
    cin >> n >> m;
#else
    n = 20;
    m = 100000;
#endif
    {
        vector<string> s(n);
        rep(i, 0, n) {
            s[i].reserve(m);
#ifndef stress
            cin >> s[i];
#else
            rep(f, 0, m) s[i] += char((rand() & 1) + '0');
#endif
        }
        rep(f, 0, m) {
            int mask = 0;
            rep(i, 0, n) mask = mask << 1 | (s[i][f] & 1);
            if (mask >= (1 << n) / 2) mask = (1 << n) - 1 - mask;
            cnt[mask]++;
        }
    }
    
    precal();
    
    int ans = INT_MAX;
    rep(mask, 0, (1 << n)) {
        ans = min(ans, query(mask));
    }
    cout << ans;
    
    return 0;
}

// vim: foldmethod=marker