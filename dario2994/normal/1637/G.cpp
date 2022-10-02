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
        function<string(typename iterator_traits<Iterator>::value_type)>* f = nullptr) {
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

set<vector<int>> memo;
void slow(vector<int> vec) {
    sort(vec.begin(), vec.end());
    if (memo.count(vec)) return;
    memo.insert(vec);
    int m = 1e9;
    int M = 0;
    for (int x: vec) m = min(m, x), M = max(M, x);
    if (m == M) {
        cout << vec[0] << endl;
        return;
    }
    if (M > 16) return;
    
    int n = SZ(vec);
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int x = vec[i], y = vec[j];
            vec[i] = x+y;
            vec[j] = abs(x-y);
            slow(vec);
            vec[i] = x, vec[j] = y;
        }
    }
}

void Join(vector<int>& a, vector<int> b) {
    if (SZ(a) < SZ(b)) a.resize(SZ(b), 0);
    for (int i = 0; i < SZ(b); i++) a[i] += b[i];
}

vector<pair<int,int>> moves;
vector<int> solve(int n, int e0) {
    auto add_move = [&](int x, int y) {
        moves.push_back({x<<e0, y<<e0});
    };
    if (n == 0) return {};
    int e = 0;
    while ((1<<e) < n) e++;
    vector<int> res(e + e0 + 1, 0);
    if (n == 1) {
        res[e0] = 1;
        return res;
    } else if (n == 2) {
        res[e0] = 1, res[e0+1] = 1;
        return res;
    }
    if (__builtin_popcount(n) == 1) {
        res = solve(n-1, e0);
        res[e0 + e]++;
        return res;
    }
    int pot = 1<<(e-1);
    int d = n - pot;
    for (int i = 1; i <= d; i++) add_move(pot + i, pot-i);
    res[e + e0] += d;
    res[e-1 + e0] = 1;
    Join(res, solve(d, e0+1));
    Join(res, solve(pot-d-1, e0));

    return res;
}

void real_solve(int n) {
    vector<int> res = solve(n, 0);
    bool found = true;
    while (found) {
        // dbg(moves, res);
        found = false;
        for (int i = 0; i < SZ(res)-1; i++) {
            if (res[i] >= 2) {
                found = true;
                res[i] -= 2;
                res[i+1]++;
                moves.push_back({1<<i, 1<<i});
                bool done = false;
                for (int j = 0; j < SZ(res); j++) {
                    if (res[j]%2) {
                        res[j]++;
                        moves.push_back({1<<j, 0});
                        done = true;
                        break;
                    }
                }
                if (done) break;
                for (int j = 0; j < SZ(res); j++) {
                    if (res[j]) {
                        res[j]++;
                        moves.push_back({1<<j, 0});
                        break;
                    }
                }
                break;
            }
        }
    }
    assert(res.back() == n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    // for (int n = 3; n <= 1000; n++) {
        // moves.clear();
        // real_solve(n);
        // cout << n << " " << moves.size() << endl;
    // }
    // return 0;

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        moves.clear();
        int n;
        cin >> n;
        if (n == 2) cout << -1 << "\n";
        else {
            real_solve(n);
            cout << moves.size() << "\n";
            for (auto pp: moves) cout << pp.first << " " << pp.second << "\n";
            assert(SZ(moves) <= 20 * n);
        }
    }
}