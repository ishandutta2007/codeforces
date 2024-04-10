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

int code(char ch) {
    switch (ch) {
        case 'A': return 0;
        case 'T': return 1;
        case 'O': return 2;
        case 'N': return 3;
        default: assert(false);
    }
}


int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        DB();
        string s; cin >> s;
        vector<int> a(sz(s));
        int cnt[4] = {0, 0, 0, 0};
        
        rep(i, 0, sz(s)) {
            a[i] = code(s[i]);
            ++cnt[a[i]];
        }
        
        auto get_pos = [&](int mask) {
            vector<int> ans;
            rep(i, 0, sz(a)) {
                if ((mask >> a[i]) & 1) ans.push_back(i);
            }
            return ans;
        };
        
        auto cal_inv = [&](const vector<int>& left, const vector<int>& right) {
            int f = 0;
            ll ans = 0;
            rep(i, 0, sz(left)) {
                while (f < sz(right) and right[f] < left[i]) {
                    ans += sz(left) - i;
                    ++f;
                }
            }
            // clog << db(left) << db(right) << db(ans) << endl; 
            return ans;
        };
        
        vector<int> pos(4);
        rep(i, 0, 4) {
            pos[i] = i;
        }
        
        
        ll max_inv = -1;
        string ans = "";
        string order = "ATON";
        do {
            ll cur_ans = cal_inv(get_pos(1 << pos[0]), get_pos(1 << pos[1]));
            cur_ans += cal_inv(get_pos(1 << pos[2]), get_pos(1 << pos[3]));
            cur_ans += cal_inv(get_pos((1 << pos[0]) | (1 << pos[1])), get_pos((1 << pos[2]) | (1 << pos[3])));
            if (cur_ans > max_inv) {
                ans = "";
                for (auto i: pos) {
                    ans += string(cnt[i], order[i]);
                }
                max_inv = cur_ans;
            }
        } while (next_permutation(all(pos)));
        clog << db(max_inv) << endl;
        cout << ans << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker