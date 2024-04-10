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

const int maxn = 2222;
int n, s;
int a[maxn];
map<int, vector<int>> pos;

int forw_dist(int from, int to) {
    int ans = to - from;
    if (ans < 0) ans += n;
    return ans;
}

inline int back_dist(int from, int to) {
    return forw_dist(to, from);
}

int dist(int from, int to) {
    return min(forw_dist(from, to), back_dist(from, to));
}

int rel_dist(int from, int to) {
    auto fd = forw_dist(from, to);
    auto bd = back_dist(from, to);
    if (fd < bd) return fd;
    return -bd;
}

vector<int>::const_iterator find_next(const vector<int>& p, int val) {
    auto it = upper_bound(all(p), val);
    if (it == p.end()) return p.begin();
    return it;
}

vector<int>::const_iterator find_prev(const vector<int>& p, int val) {
    auto it = lower_bound(all(p), val);
    if (it == p.begin()) return --p.end();
    return --it;
}

function<int(int, int)> cal_ans[] = {
    [](int start, int stop) {
        // forward only
        auto& stop_pos = pos[a[stop]];
        auto target = find_prev(stop_pos, start);
        return forw_dist(start, *target) + dist(*target, stop);
    },
    [](int start, int stop) {
        // backwoard only
        auto& stop_pos = pos[a[stop]];
        auto target = find_next(stop_pos, start);
        return back_dist(start, *target) + dist(*target, stop);
    },
    [](int start, int stop) {
        // foward then backward
        auto& stop_pos = pos[a[stop]];
        auto target = find_prev(stop_pos, stop);
        return forw_dist(start, *target) + back_dist(*target, stop);
    },
    [](int start, int stop) {
        // backward then forward
        auto& stop_pos = pos[a[stop]];
        auto target = find_next(stop_pos, stop);
        return back_dist(start, *target) + forw_dist(*target, stop);
    },
};

function<list<int>(int, int)> get_ans[] = {
    [](int start, int stop) -> list<int> {
        // forward only
        list<int> ans;
        auto target = find_prev(pos[a[stop]], start);
        int prev_pos = start;
        for (int i = start; i != *target; i = (i + 1) % n) {
            if (a[i] != a[stop]) continue;
            if (i == stop) continue;
            ans.push_back(forw_dist(prev_pos, i));
            prev_pos = i;
        }
        ans.push_back(forw_dist(prev_pos, *target));
        auto last = rel_dist(*target, stop);
        if (last) ans.push_back(last);
        return ans;
    },
    [](int start, int stop) -> list<int> {
        // backward only
        list<int> ans;
        auto target = find_next(pos[a[stop]], start);
        int prev_pos = start;
        for (int i = start; i != *target; i = (i - 1 + n) % n) {
            if (a[i] != a[stop]) continue;
            if (i == stop) continue;
            ans.push_back(-back_dist(prev_pos, i));
            prev_pos = i;
        }
        ans.push_back(-back_dist(prev_pos, *target));
        auto last = rel_dist(*target, stop);
        if (last) ans.push_back(last);
        return ans;
    },
    [](int start, int stop) -> list<int> {
        // forward then backward
        list<int> ans;
        auto target = find_prev(pos[a[stop]], stop);
        int prev_pos = start;
        for (int i = start; i != *target; i = (i + 1) % n) {
            if (a[i] != a[stop]) continue;
            if (i == stop) continue;
            ans.push_back(forw_dist(prev_pos, i));
            prev_pos = i;
        }
        ans.push_back(forw_dist(prev_pos, *target));
        prev_pos = *target;
        for (int i = (start - 1 + n) % n; i != stop; i = (i - 1 + n) % n) {
            if (a[i] != a[stop]) continue;
            ans.push_back(-back_dist(prev_pos, i));
            prev_pos = i;
        }
        auto last = rel_dist(prev_pos, stop);
        if (last) ans.push_back(last);
        return ans;
    },
    [](int start, int stop) -> list<int> {
        // backward then forward
        list<int> ans;
        auto target = find_next(pos[a[stop]], stop);
        int prev_pos = start;
        for (int i = start; i != *target; i = (i - 1 + n) % n) {
            if (a[i] != a[stop]) continue;
            if (i == stop) continue;
            ans.push_back(-back_dist(prev_pos, i));
            prev_pos = i;
        }
        ans.push_back(-back_dist(prev_pos, *target));
        prev_pos = *target;
        for (int i = (start + 1) % n; i != stop; i = (i + 1) % n) {
            if (a[i] != a[stop]) continue;
            ans.push_back(forw_dist(prev_pos, i));
            prev_pos = i;
        }
        auto last = rel_dist(prev_pos, stop);
        if (last) ans.push_back(last);
        return ans;
    },
};

tuple<int, int, int> dp[maxn];

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    --s;
    rep(i, 0, n) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    
    rep(i, 0, n) {
        dp[i] = {INT_MAX, 0, 0};
    }
    
    for (auto u: pos.begin()->second) {
        rep(strat, 0, 4) {
            dp[u] = min(dp[u], {cal_ans[strat](s, u), -s - 1, strat});
        }
            clog << db(u) << db(dp[u]) << endl;
    }
    
    vector<int>* prev_pos;
    for (auto& it: pos) {
        if (it.first == pos.begin()->first) {
            prev_pos = &it.second;
            continue;
        }
        DB();
        clog << db(it.first) << endl;
        clog << db(it.second) << endl;
        clog << db(*prev_pos) << endl;
        
        for (auto stop: it.second) {
            for (auto start: *prev_pos) {
                rep(strat, 0, 4) {
                    auto cur_ans = cal_ans[strat](start, stop) + get<0>(dp[start]);
                    dp[stop] = min(dp[stop], {cur_ans, start, strat});
                }
            }
            clog << db(stop) << db(dp[stop]) << endl;
        }
        
        prev_pos = &it.second;
    }
    
    pair<tuple<int, int, int>, int> ans = {{INT_MAX, 0, 0}, 0};
    rep(i, 0, n) if (a[i] == pos.rbegin()->first)
        ans = min(ans, {dp[i], i});
    
    cout << get<0>(ans.first) << '\n';
    list<int> ans_list;
    
    for (int u = ans.second; u >= 0; u = get<1>(dp[u])) {
        int v = get<1>(dp[u]);
        if (v < 0) v = s;
        int strat = get<2>(dp[u]);
        auto cur_ans_list = get_ans[strat](v, u);
        ans_list.splice(ans_list.begin(), cur_ans_list);
    }
    
    for (auto i: ans_list) {
        if (i >= 0) cout << '+';
        cout << i << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker