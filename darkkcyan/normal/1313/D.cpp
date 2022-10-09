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

const int maxn = 101010;
const int maxbit = 10;
int n;
int l[maxn], r[maxn];

int parity[1 << maxbit];

void precal() {
    rep(i, 1, (1 << maxbit))
        parity[i] = parity[i - (i & (-i))] ^ 1;
}

int main() {
    precal();
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int m, k; cin >> m >> k;
    rep(i, 0, n) {
        cin >> l[i] >> r[i];
        ++r[i];
    }
    
    vector<int> vals;
    rep(i, 0, n) {
        vals.push_back(l[i]);
        vals.push_back(r[i]);
    }
    
    sort(all(vals));
    auto id = [&](int num) {
        return (int)(lower_bound(all(vals), num) - vals.begin());
    };
    
    vals.erase(unique(all(vals)), vals.end());
    
    rep(i, 0, n) {
        l[i] = id(l[i]);
        r[i] = id(r[i]);
    }
    
    vector<vector<int>> cards(sz(vals));
    rep(i, 0, n) {
        rep(f, l[i], r[i])
            cards[f].push_back(i);
    }
    
    vector<int> cur_dp(1 << sz(cards[0]));
    rep(i, 0, sz(cur_dp)) {
        cur_dp[i] = parity[i] * (vals[1] - vals[0]);
    }
    
    rep(i, 1, sz(vals) - 1) {
        auto &prv = cards[i - 1], &cur = cards[i];
        int cur_len = vals[i + 1] - vals[i];
        vector<int> next_dp(1 << sz(cur));
        
        vector<pair<int, int>> same;
        vector<int> left_diff, right_diff;
        
        vector<bool> right_mark(sz(cur));
        
        rep(left, 0, sz(prv)) {
            int match_right = 0;
            while (match_right < sz(cur) and cur[match_right] != prv[left])
                ++match_right;
            if (match_right < sz(cur))  {
                same.emplace_back(left, match_right);
                right_mark[match_right] = 1;
            } else {
                left_diff.push_back(left);
            }
        }
        
        rep(right, 0, sz(cur)) 
            if (!right_mark[right]) right_diff.push_back(right);
        
        auto gen_mask = [&](const vector<int>& se) {
            vector<int> ans;
            rep(mask, 0, 1 << sz(se)) {
                int cur_ans = 0;
                rep(f, 0, sz(se))
                    if ((mask >> f) & 1) cur_ans |= 1 << se[f];
                ans.push_back(cur_ans);
            }
            return ans;
        };
        
        auto left_diff_mask = gen_mask(left_diff);
        auto right_diff_mask = gen_mask(right_diff);
        
        rep(same_mask, 0, 1 << sz(same)) {
            int left_same_mask = 0, right_same_mask = 0;
            rep(bit, 0, sz(same)) {
                if (!((same_mask >> bit) & 1)) continue;
                left_same_mask |= 1 << same[bit].first;
                right_same_mask |= 1 << same[bit].second;
            }
            
            int cur_opt = 0;
            for (auto mask: left_diff_mask)
                cur_opt = max(cur_opt, cur_dp[mask ^ left_same_mask]);
            
            for (auto mask: right_diff_mask) {
                mask ^= right_same_mask;
                next_dp[mask] = max(next_dp[mask], cur_opt + parity[mask] * cur_len);
            }
        }
        cur_dp = move(next_dp);
    }
    
    cout << *max_element(all(cur_dp));
    
    return 0;
}

// vim: foldmethod=marker