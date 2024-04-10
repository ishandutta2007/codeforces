#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define rand __rand
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
template<class T = int> T rand(T range = numeric_limits<T>::max()) { return (T)(rng() % range); }

#define CONCAT_(x, y) x##y/*{{{*/
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
int __db_level = 0;
bool __db_same_line = false;
#define clog cerr << string(!__db_same_line ? __db_level * 2 : 0, ' ')
struct debug_block {
    function<void()> fn;
    void print_name() { __db_same_line = true; fn(); clog << endl; __db_same_line = false;  }
    debug_block(function<void()> fn_): fn(fn_) { clog << "{ "; print_name(); ++__db_level; }
    ~debug_block() { --__db_level; clog << "} "; print_name(); }
};
#define DB(args...) debug_block CONCAT(dbbl, __LINE__)([=]{ clog << args; })
#define deb(...)  if (1) { (clog << "[" #__VA_ARGS__ "] = [" << __VA_ARGS__) << "]"; if (!__db_same_line) clog << endl; }
#else
#define clog if (0) cerr
#define DB(...)
#define deb(...)
#endif
template<class T>
ostream& operator,(ostream& out, const T& thing) { return out << ", " << thing; }
template<class U, class V>
ostream& operator<<(ostream& out, const pair<U, V>& p) { return (out << "(" << p.first, p.second) << ")"; }
template<class A, class B>
ostream& operator<<(ostream& out, const tuple<A, B>& t) { return (out << "(" << get<0>(t), get<1>(t)) << ")"; }
template<class A, class B, class C>
ostream& operator<<(ostream& out, const tuple<A, B, C>& t) { return (out << "(" << get<0>(t), get<1>(t), get<2>(t)) << ")"; }
template<class T> ostream& operator<<(ostream& out, const vector<T>& container) { 
    out << "{";
    if (len(container)) out << container[0];
    rep1(i, len(container) - 1) out, container[i];
    return out << "}";
}
template<class x> vector<typename x::value_type> $v(const x& a) { return vector<typename x::value_type>(a.begin(), a.end()); }
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> $v(u a, u b) { return vector<ptrtype(u)>(a, b); }/*}}}*/
// ACTUAL SOLUTION BELOW ////////////////////////////////////////////////////////////

const llong inf = LLONG_MAX;
llong find_single_num(int sum_dig) {
    deb(sum_dig);
    if (sum_dig < 0) return -1;
    if (sum_dig == 0) return 0;
    int num_len = 1;
    while (num_len * 9 < sum_dig) num_len ++;
    deb(num_len);
    llong ans = 0;
    rep(i, num_len) {
        deb(i);
        bool has_ans = false;
        for (int dig = (i == 0); dig < 10; ++dig) {
            if ((sum_dig - dig) > (num_len - i - 1) * 9) continue;
            has_ans = true;
            ans = ans * 10 + dig;
            deb(dig);
            sum_dig -= dig;
            break;
        }
        assert(has_ans);
    }
    deb(ans);
    return ans;
}

int sum_dig(llong num) {
    if (num == 0) return 0;
    return (int)(num % 10) + sum_dig(num / 10);
}

llong find_num(int n, int k) {
    if (k == 0) return find_single_num(n);
    rep(temp_ans, 1000) {
        llong s = 0;
        rep(i, k + 1) {
            s += sum_dig(temp_ans + i);
        }
        if (s == n) return temp_ans;
    }

    llong ans = inf;
    llong pw = 100;
    llong mid = 0;
    for (int tail_len = 2; tail_len < 13;
            tail_len++, pw *= 10, mid = mid * 10 + 90
    ) {
        rep(u, 9) rep(v, 10) {
            llong base = u * pw / 10 + mid + v;
            int temp_sum = 0;
            rep(i, k + 1) temp_sum += sum_dig(base + i);

            int rem_sum = n - temp_sum;
            if (rem_sum % (k + 1) != 0) continue;
            rem_sum /= k + 1;
            llong head = find_single_num(rem_sum);
            if (head < 0) continue;
            ans = min(ans, head * pw + base);
        }
    }
    return ans == inf ? -1 : ans;
}

void all_test() {
    rep1(n, 150) rep(k, 10) {
        llong ans = find_num(n, k);
        int check = 0;
        rep(i, k + 1) check += sum_dig(ans + i);
        cout << n << ' ' << k << ' ' << find_num(n, k) << ' ' << check << endl;
        if (ans == -1) continue;
        if (check != n) {
            exit(1);
        }
    }
    exit(0);
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // all_test();   
    int ntest; cin >> ntest;
    while (ntest--) {
        DB("test");
        int n, k; cin >> n >> k;
        deb(n, k);
        cout << find_num(n, k) << '\n';
    }

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker