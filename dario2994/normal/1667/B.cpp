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



void solve() {
    int n;
    cin >> n;
    int pot = 2;
    while (pot <= n) pot *= 2;
    vector<int> tt(2*pot, -1e9);
    auto update = [&](int pos, int val) {
        // dbg(pos, val);
        pos += pot;
        tt[pos] = max(tt[pos], val);
        while (pos != 1) {
            pos /= 2;
            tt[pos] = max(tt[2*pos], tt[2*pos+1]);
        }
    };
    function<int(int,int,int,int,int)> query = [&](int v, int l, int r, int a, int b) {
        if (r < a or b < l) return -1<<30;
        if (a <= l and r <= b) return tt[v];
        int m = (l+r)/2;
        return max(query(2*v, l, m, a, b), query(2*v+1, m+1, r, a, b));
    };
    
    vector<LL> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i-1];
    vector<int> ord(n+1);
    for (int i = 0; i <= n; i++) ord[i] = i;
    sort(all(ord), [&](int x, int y) {
        return a[x] < a[y];
    });

    vector<int> b(n+1);
    int it = 0;
    for (int i = 0; i <= n; i++) {
        b[ord[i]] = it;
        if (i < n and a[ord[i]] < a[ord[i+1]]) it++;
    }

    vector<int> last_occ(n+1, -1);
    vector<int> f(n+1);
    last_occ[b[0]] = 0;
    update(b[0], 0);
    for (int i = 1; i <= n; i++) {
        int z = b[i];
        f[i] = -1 + f[i-1];
        if (last_occ[z] != -1) f[i] = max(f[i], f[last_occ[z]]);
        last_occ[z] = i;

        // int ris = -1e9;
        // for (int j = 0; j < i; j++) if (b[j] < b[i]) ris = max(ris, f[j] - j);
        int ris = query(1, 0, pot-1, 0, b[i]-1);
        f[i] = max(f[i], i + ris);
        update(b[i], f[i] - i);
    }
    cout << f[n] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int t;
    cin >> t;
    while (t--) solve();
}