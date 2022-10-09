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
// ACTUAL SOLUTION BELOW ////////////////////////////////////////////////////////////

// #define testing   

#ifdef testing
int x;
#endif

const int maxn = 100001;
int n;
vector<llong> primes;
bool not_prime[maxn];

void sieve() {
    for (int i = 2; i < maxn; ++i) {
        if (not_prime[i]) continue;
        primes.push_back(i);
        for (llong f = 1ll * i * i; f < maxn; f += i)
            not_prime[f] = true;
    }
}

bool removed[maxn];

llong cnt_op = 10000;
#ifndef testing
template<bool del>
int ask(llong num) {
    assert(cnt_op-- > 0);
    cout << (del ? "B " : "A ") << num << endl;
    int ans; cin >> ans;
    if (del) {
        for (llong i = num; i <= n; i += num) removed[i] = true;
    }
    return ans;
}

void answer(llong num) {
    assert(cnt_op-- > 0);
    cout << "C " << num << endl;
    exit(0);
}
#else
bool testing_removed[maxn];
template<bool del>
int ask(llong num) {
    assert(cnt_op-- > 0);
    if (del) assert(num >= 2);
    int ans = 0;
    for (llong i = num; i <= n; i += num) {
        ans += !testing_removed[i];
        if (del and i != x) testing_removed[i] = true;
    }
    
    if (del) {
        for (llong i = num; i <= n; i += num) removed[i] = true;
    }
    clog << "asking " << db(del) << db(num) << db(ans) << endl;
    return ans;
}

void answer(llong num) {
    assert(cnt_op-- > 0);
    clog << "answer " << db(num) << endl;
    if (num == x) {
        cout << "OK " << endl;
    } else {
        cout << "FAIL" << endl;
        cout << n << ' ' << x << endl;
    }
    exit(0);
}
#endif

int get_expected(llong num) {
    int ans = 0;
    for (llong i = num; i <= n; i += num)
        ans += !removed[i];
    return ans;
}

llong brute(const vector<llong>& divs, int i, llong cur_num = 1) {
    if (i == len(divs)) {
        if (ask<false>((int)cur_num)) return cur_num;
        return 1;
    }
    
    llong ans = 1;
    for (cur_num *= divs[i]; cur_num <= n; cur_num *= divs[i]) {
        ans = max(ans, brute(divs, i + 1, cur_num));
    }
    return ans;
}

int main(void) {
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    sieve();
#ifndef testing
    cin >> n;
#else
    // n = rand(100000) + 1;    
    // x = rand(n)- 10; 
    // x = (int)*upper_bound(primes.begin(), primes.end(), (llong)x); 
    cin >> n >> x;     
#endif
    // clog << db(len(primes)) << endl; 
    // int cnt = 0; 
    // for (auto i: primes) cnt += 1ll * i * i <= 100000; 
    // clog << db(cnt) << endl; 
    if (n == 1) answer(1);
    
    vector<llong> divs;
    
    for (auto num: primes) {
        if (num * num > n) break;
        ask<true>(num);
        if (ask<false>(num)) divs.push_back(num);
        continue;
    }
    clog << db(cnt_op) << endl;
    
    if (len(divs)) {
        for (auto num: primes) {
            if (num > n) break;
            if (num * num <= n) continue;
            auto cur_expected = get_expected(num);
            if (ask<false>(num) != cur_expected) divs.push_back(num);
        }
        llong ans =  brute(divs, 0);
        answer((int)ans);
    } else {
        const int blk_size = 100;
        auto cur_cnt = ask<false>(1);
        vector<llong> cur_primes;
        
        auto process_block = [&]() {
            auto new_cnt = ask<false>(1);
            clog << db(cnt_op) << db(cur_cnt) << db(new_cnt) << endl;
            if (cur_cnt - new_cnt!= len(cur_primes)) {
                for (auto i: cur_primes) if (ask<false>(i)) answer(i);
                assert(false);
            }
            cur_cnt = new_cnt;
            cur_primes.clear();
        };
        
        for (auto num: primes) {
            if (num > n) break;
            if (num * num <= n) continue;
            ask<true>(num);
            cur_primes.push_back(num);
            if (len(cur_primes) == blk_size) process_block();
        }
        process_block();
        answer(1);
    }

    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker