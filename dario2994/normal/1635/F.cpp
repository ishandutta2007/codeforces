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

struct Op {
    int l, r;
    LL val;
};

struct Query {
    int l, r;
    int id;
};

const int MAXN = 1<<19;
LL tt[2*MAXN];
const LL INF = 4e18;

LL query(int v, int l, int r, int a, int b) {
    if (r < a or b < l) return INF;
    if (a <= l and r <= b) return tt[v];
    int m = (l+r)/2;
    return min(query(2*v, l, m, a, b), query(2*v+1, m+1, r, a, b));
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    for (int i = 1; i < 2*MAXN; i++) tt[i] = INF;

    int n;
    int q;
    cin >> n >> q;
    vector<LL> x(n);
    vector<LL> w(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> w[i];
    vector<int> l(n), r(n);
    l[0] = -1;
    for (int i = 1; i < n; i++) {
        l[i] = i-1;
        while (l[i] != -1 and w[l[i]] > w[i]) l[i] = l[l[i]];
    }
    r[n-1] = n;
    for (int i = n-2; i >= 0; i--) {
        r[i] = i+1;
        while (r[i] != n and w[r[i]] > w[i]) r[i] = r[r[i]];
    }
    vector<Op> operations;
    for (int i = 0; i < n; i++) {
        if (l[i] != -1) {
            int j = l[i];
            LL val = (x[i] - x[j]) * (w[i] + w[j]);
            Op op;
            op.l = j, op.r = i;
            op.val = val;
            operations.push_back(op);
        }
        if (r[i] != n) {
            int j = r[i];
            LL val = (x[j] - x[i]) * (w[i] + w[j]);
            Op op;
            op.l = i, op.r = j;
            op.val = val;
            operations.push_back(op);
        }
    }
    sort(all(operations), [&](Op a, Op b) {
        return a.r < b.r;
    });

    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        auto& z = queries[i];
        z.id = i;
        cin >> z.l >> z.r;
        z.l--, z.r--;
    }
    sort(all(queries), [&](Query a, Query b) {
        return a.r < b.r;
    });

    vector<LL> ans(q, INF);
    int it_op = 0;
    int it_q = 0;
    for (int r = 0; r < n; r++) {
        while (it_op < SZ(operations) and operations[it_op].r == r) {
            auto op = operations[it_op++];
            // dbg(r, op.l, op.val);

            int v = op.l + MAXN;
            tt[v] = min(tt[v], op.val);
            while (v != 1) {
                v /= 2;
                tt[v] = min(tt[2*v], tt[2*v+1]);
            }
            // apply(op.l, op.val);
        }
        while (it_q < q and queries[it_q].r == r) {
            auto z = queries[it_q++];
            // dbg(r, z.l, z.r);
            ans[z.id] = query(1, 0, MAXN-1, z.l, z.r);
        }
    }

    for (int i = 0; i < q; i++) cout  << ans[i] << "\n";
}