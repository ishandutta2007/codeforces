#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#ifdef testing
mt19937 rng(177013);
#else
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
#endif
#define rand() (int)(rng() >> 1)
#define CONCAT_(x, y) x##y/*{{{*/
#define CONCAT(x, y) CONCAT_(x, y)
#define SPEC(name) CONCAT(name, __LINE__)
#ifdef LOCAL_DEBUG   
int __db_level = 0;
#define clog cerr << string(__db_level * 2, ' ')
struct debug_block {
    string msg;
    debug_block(const string& s): msg(s) { clog << "{ " << msg << endl; ++__db_level; }
    ~debug_block() { --__db_level; clog << "} " << msg << endl; }
};
#define DB(args...) stringstream SPEC(ss); SPEC(ss)<< args; debug_block SPEC(dbbl)(SPEC(ss).str())
#else
#define clog if (0) cerr
#define DB(...)
#endif
#define db(val) "[" #val " = " << val << "]; "
template<class U, class V> ostream& operator<<(ostream& out, const pair<U, V>& p) {
    return out << "(" << p.first << ", " << p.second << ")";
}
template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")";
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup);
}
template<class ...U>
ostream& operator<<(ostream& out, const tuple<U...>& tup) { return print_tuple_utils<0, tuple<U...>>(out, tup); }
template<class, typename = void> struct has_const_iterator : false_type {};
template<class T> struct has_const_iterator<T, void_t<typename T::const_iterator>> : true_type {};
template<class T>
typename enable_if<has_const_iterator<T>::value && !is_same<T, string>::value, ostream&>::type
operator<<(ostream& out, const T& container) { 
    auto beg = container.begin(), end = container.end();
    out << "(" << container.size() << ") {";
    if (beg != end) out << *(beg++);
    while (beg != end) out << ", " << *(beg++);
    return out << "}";
}
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> $v(u a, u b) { return vector<ptrtype(u)>(a, b); }/*}}}*/
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////

const int maxn = 101010;
const int maxm = maxn;
const int max_len = 41;
int n, m;
vector<int> a[maxn];
vector<pair<int, int>> pos[maxm];

int pgcd[max_len][max_len];
void precal() {
    rep1(i, max_len - 1)
        rep1(f, max_len - 1)
            pgcd[i][f] = __gcd(i, f);
}

using vpit = vector<pair<int, int>>::iterator;

int solve(vpit beg, vpit end) {
    clog << db(vector(beg, end)) << endl;
    vector<int> mod(max_len, -1), cnt_mod(max_len, 0);
    auto check = [&](int l, int cur_mod) -> bool {
        rep1(i, max_len - 1) {
            if (!cnt_mod[i]) continue;
            if (abs(mod[i] - cur_mod) % pgcd[i][l]) return false;
        }
        return true;
    };
    
    int ans = 0;
    auto right = beg;
    for (auto left = beg; left != end; ++left) {
        while (right != end and check(len(a[right->first]), right->second)) {
            ++cnt_mod[len(a[right->first])];
            mod[len(a[right->first])] = right->second;
            ++right;
        }
        clog << (left - beg) << ' ' << (right - beg) << endl;
        ans = max(ans, (int)(right - left));
        --cnt_mod[len(a[left->first])];
    }
    return ans;
}

int main(void) {
    precal();
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rep(i, n) {
        int k; cin >> k;
        a[i].resize(k);
        rep(f, k) cin >> a[i][f];
    }
    
    rep(i, n) {
        rep(f, len(a[i])) pos[a[i][f]].emplace_back(i, f);
    }
    
    rep1(i, m) {
        DB(i);
        int prev = 0;
        int cur_ans = 0;
        rep1(cur, len(pos[i]) - 1) {
            if (pos[i][cur].first != pos[i][cur - 1].first + 1) {
                cur_ans = max(cur_ans, solve(pos[i].begin() + prev, pos[i].begin() + cur));
                prev = cur;
            }
        }
        cur_ans = max(cur_ans, solve(pos[i].begin() + prev, pos[i].end()));
        cout << cur_ans << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker