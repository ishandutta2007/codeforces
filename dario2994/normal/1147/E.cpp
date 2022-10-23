#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SZ(x) ((int)((x).size()))
#define all(x) (x).begin(), (x).end()

// Returns the time elapsed in nanoseconds from 1 January 1970, at 00:00:00.
LL get_time() {
    return chrono::duration_cast<chrono::nanoseconds>(
        chrono::steady_clock::now().time_since_epoch())
        .count();
}

// Returns a random integer from the range [l, r].
LL randint(LL l, LL r) {
	#if DEBUG && !ONLINE_JUDGE
	static mt19937_64 gen; // Deterministic on the local machine.
	#else
	static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
	#endif
	return uniform_int_distribution<LL>(l, r)(gen);
}

template <typename Iterator>
string print_iterable(Iterator begin, Iterator end, string bef, string aft,
        function<string(typename iterator_traits<Iterator>::value_type)>* f = nullptr);

template <typename S, typename T>
ostream& operator <<(ostream& out, const pair<S, T>& p);

#define _define_print_container(Container, bef, aft)        \
template <typename T>                                       \
ostream& operator <<(ostream& out, const Container<T>& v) { \
    out << print_iterable(v.begin(), v.end(), bef, aft);    \
    return out;                                             \
}                                                           \

_define_print_container(vector, "[", "]");
_define_print_container(set, "{", "}");
_define_print_container(unordered_set, "{", "}");
_define_print_container(multiset, "{", "}");
_define_print_container(unordered_multiset, "{", "}");
_define_print_container(deque, "[", "]");

#define _define_print_dictionary(Dictionary, bef, aft)                      \
template <typename T1, typename T2>                                         \
ostream& operator <<(ostream& out, const Dictionary<T1, T2>& v) {           \
    out << print_iterable(v.begin(), v.end(), bef, aft);                    \
    return out;                                                             \
}                                                                           \

_define_print_dictionary(map, "{", "}");
_define_print_dictionary(unordered_map, "{", "}");

#define _define_print_container_adaptor(Adaptor, OP)                        \
template <typename T>                                                       \
ostream& operator <<(ostream& out, Adaptor<T> a) {                          \
    vector<T> v;                                                            \
    while (!a.empty()) v.push_back(a.OP()), a.pop();                        \
    out << v;                                                               \
    return out;                                                             \
}                                                                           \

_define_print_container_adaptor(stack, top)
_define_print_container_adaptor(queue, front)
_define_print_container_adaptor(priority_queue, top)

template <typename Iterator>
string print_iterable(Iterator begin, Iterator end, string bef, string aft,
        function<string(typename iterator_traits<Iterator>::value_type)>* f) {
    stringstream res;
    res << bef;
    bool is_first = true;
    for (Iterator it = begin; it != end; ++it) {
        if (!is_first) res << ", ";
        if (f != nullptr) res << (*f)(*it);
        else res << *it;
        is_first = false;
    }
    res << aft;
    return res.str();
}

template <typename S, typename T>
ostream& operator <<(ostream& out, const pair<S, T>& p) {
    out << "{" << p.first << ", " << p.second << "}";
    return out;
}

template<class TH>
void _dbg(const char* name, TH val){
    clog << name << ": " << val << endl;
}
template<class TH, class... TA>
void _dbg(const char* names, TH curr_val, TA... vals) {
    while(*names != ',') clog << *names++;
    clog << ": " << curr_val << ", ";
    _dbg(names+1, vals...);
}

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
    #define dbg_arr(x, len) \
    clog << #x << ": " << print_iterable(x, x+len, "[", "]") << endl;
    #define dbg_arr1(x, len) \
    clog << #x << ": " << print_iterable(x+1, x+len+1, "[", "]") << endl;
#else
    #define dbg(...)
    #define dbg_arr(x, len)
    #define dbg_arr1(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

namespace local {
int n;
vector<int> color;
void generate_test(int _n) {
    n = _n;
    color.resize(n+1);
    for (int i = 1; i <= n; i++) color[i] = randint(0, 2);
}

vector<bool> ask_query(vector<pair<int,int>> vec) {
    vector<bool> ans;
    for (auto pp: vec) ans.push_back(color[pp.first] == color[pp.second]);
    return ans;
}

void answer(vector<int> _color) {
    set<int> S1, S2;
    set<pair<int,int>> S12;
    for (int i = 1; i <= n; i++) {
        S1.insert(color[i]);
        S2.insert(_color[i]);
        S12.insert({color[i], _color[i]});
    }
    assert(SZ(S1) == SZ(S2) and SZ(S2) == SZ(S12));
}
    
}

vector<bool> ask_query(vector<pair<int,int>> vec) {
    int k = SZ(vec);
    
    if (k == 0) return {};
    cout << "Q " << k << " ";
    for (auto pp: vec) cout << pp.first << " " << pp.second << " ";
    cout << endl;
    vector<bool> ans(k);
    string _ans;
    cin >> _ans;
    for (int i = 0; i < k; i++) ans[i] = _ans[i] == '1';
    return ans;
}

void answer(vector<int> color) { // 0, 1, 2 colors
    int n = SZ(color)-1;
    vector<int> cnt(3);
    for (int i = 1; i <= n; i++) cnt[color[i]]++;
    cout << "A " << cnt[0] << " " << cnt[1] << " " << cnt[2] << endl;
    for (int c = 0; c <= 2; c++) {
        for (int i = 1; i <= n; i++) if (color[i] == c) cout << i << " ";
        cout << endl;
    }
}

typedef pair<int,int> pii;
void solve() {
    int n;
    cin >> n;
    // local::generate_test(n);

    vector<pii> q1, q2;
    for (int i = 1; i <= n-1; i += 2) q1.emplace_back(i, i+1);
    for (int i = 2; i <= n-1; i += 2) q2.emplace_back(i, i+1);
    vector<bool> a1 = ask_query(q1);
    vector<bool> a2 = ask_query(q2);
    vector<bool> a12(n+1);
    for (int i = 0; i < SZ(a1); i++) a12[2*i+2] = a1[i];
    for (int i = 0; i < SZ(a2); i++) a12[2*i+3] = a2[i];

    vector<vector<int>> buckets;
    buckets.push_back({1});
    for (int i = 2; i <= n; i++) {
        if (a12[i] == 1) buckets.back().push_back(i);
        else buckets.push_back({i});
    }

    vector<pii> q3, q4;
    for (int i = 0; i < SZ(buckets)-2; i += 4) {
        q3.emplace_back(buckets[i][0], buckets[i+2][0]);
        if (i + 3 < SZ(buckets)) q3.emplace_back(buckets[i+1][0], buckets[i+3][0]);
    }
    for (int i = 2; i < SZ(buckets)-2; i += 4) {
        q4.emplace_back(buckets[i][0], buckets[i+2][0]);
        if (i + 3 < SZ(buckets)) q4.emplace_back(buckets[i+1][0], buckets[i+3][0]);
    }
    vector<bool> a3 = ask_query(q3);
    vector<bool> a4 = ask_query(q4);
    vector<bool> a34(SZ(buckets));
    for (int i = 0; 2*i < SZ(a3); i++) {
        a34[4*i+2] = a3[2*i];
        if (2*i+1 < SZ(a3)) a34[4*i+3] = a3[2*i+1];
    }
    for (int i = 0; 2*i < SZ(a4); i++) {
        a34[4*i+4] = a4[2*i];
        if (2*i+1 < SZ(a4)) a34[4*i+5] = a4[2*i+1];
    }
    vector<int> bucket_color(SZ(buckets));
    bucket_color[0] = 0;
    if (SZ(buckets) > 1) bucket_color[1] = 1;
    for (int i = 2; i < SZ(buckets); i++) {
        if (a34[i] == 1) bucket_color[i] = bucket_color[i-2];
        else bucket_color[i] = 3 - bucket_color[i-2] - bucket_color[i-1];
    }
    vector<int> color(n+1);
    for (int i = 0; i < SZ(buckets); i++) {
        for (int x: buckets[i]) color[x] = bucket_color[i];
    }
    answer(color);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int t;
    cin >> t;
    while (t--) solve();
}