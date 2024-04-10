// vim: foldmethod=marker
#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define rand __rand
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
template<class T = int> T rand(T range = numeric_limits<T>::max()) { return (T)(rng() % range); }

/*{{{*/
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
int debug = 1;
#define DB(...) stringstream CONCAT(ss, __LINE__); CONCAT(ss, __LINE__) << __VA_ARGS__; debug_block CONCAT(dbbl, __LINE__)(CONCAT(ss, __LINE__).str())
#else
int debug = 0;
#define DB(...)
#endif
int __db_level = 0;
#define clog if (debug) cerr << string(__db_level * 2, ' ')
struct debug_block {
    string name;
    debug_block(const string& name_): name(name_) { clog << "{ " << name << endl; ++__db_level; }
    ~debug_block() { --__db_level; clog << "} " << name << endl; }
};
#define deb(...) "[" << #__VA_ARGS__ << "] = [" << __VA_ARGS__ << "]"
#define debln(...)  clog << "[" << #__VA_ARGS__ << "] = [" << __VA_ARGS__ << "]" << endl
#define _ << ", " <<
template<class U, class V>
ostream& operator<<(ostream& out, const pair<U, V>& p) { return out << "(" << p.first _ p.second << ")"; }
template<class A, class B>
ostream& operator<<(ostream& out, const tuple<A, B>& t) { return out << "(" << get<0>(t) _ get<1>(t) << ")"; }
template<class A, class B, class C>
ostream& operator<<(ostream& out, const tuple<A, B, C>& t) { return out << "(" << get<0>(t) _ get<1>(t) _ get<2>(t) << ")"; }
template<class T> ostream& operator<<(ostream& out, const vector<T>& container) { 
    out << "{";
    if (len(container)) out << container[0];
    rep1(i, len(container) - 1) out _ container[i];
    return out << "}";
}
template<class x> vector<typename x::value_type> $v(const x& a) { return vector<typename x::value_type>(a.begin(), a.end()); }
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> $v(u a, u b) { return vector<ptrtype(u)>(a, b); }
/*}}}*/
// ACTUAL SOLUTION BELOW ////////////////////////////////////////////////////////////

#define maxn 201010
int n;
pair<llong, llong> a[maxn];
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    rep(testcase, ntest) {
        DB(deb(testcase));
        vector<llong> vals;
        cin >> n;
        rep1(i, n) {
            cin >> a[i].first >> a[i].second;
            debln(i);
            debln(a[i]);
            a[i].first = a[i].first * 3;
            a[i].second = a[i].second * 3;
            debln(a[i]);
            vals.push_back(a[i].first);
            vals.push_back(a[i].second);
            vals.push_back(a[i].first - 1);
        }

        sort(vals.begin(), vals.end());
        vals.resize(unique(vals.begin(), vals.end()) - vals.begin());

        rep1(i, n) {
            a[i].first = (lower_bound(vals.begin(), vals.end(), a[i].first) - vals.begin());
            a[i].second = (lower_bound(vals.begin(), vals.end(), a[i].second) - vals.begin());
            debln(i _ a[i]);
        }

        llong max_val = vals.size() + 20;
        vector<int> sum(max_val), xor_sum(max_val);
        rep1(i, n) {
            sum[a[i].first]++;
            sum[a[i].second + 1]--;

            xor_sum[a[i].first] ^= i;
            xor_sum[a[i].second + 1] ^= i;
        }

        debln(sum);
        debln(xor_sum);

        rep1(i, max_val - 1) {
            sum[i] += sum[i - 1];
            xor_sum[i] ^= xor_sum[i - 1];
        }

        debln(sum);
        debln(xor_sum);
        
        int cnt_parts = 0;
        rep1(i, max_val - 1) {
            if (sum[i] == 0  and sum[i - 1] != 0) {
                ++cnt_parts;
            }
        }

        debln(cnt_parts);

        int f = 1;
        rep1(i, max_val - 1) {
            if (sum[i] == sum[f - 1]) continue;
            sum[f] = sum[i];
            xor_sum[f] = xor_sum[i];
            ++f;
        }

        sum.resize(f);
        xor_sum.resize(f);

        debln(sum);
        debln(xor_sum);

        vector<int> ans(n + 1, cnt_parts);
        rep1(i, len(sum) - 2) { 
            if (sum[i] != 1) continue;
            debln(i _ xor_sum[i]);
            if (sum[i - 1] != 0 and sum[i + 1] != 0) 
                ans[xor_sum[i]] ++;
            else if (sum[i - 1] == 0 and sum[i + 1] == 0)
                ans[xor_sum[i]] --;
        }

        debln(ans);
        cout << *max_element(ans.begin() + 1, ans.end()) << '\n';
        
    }

    return 0;
}