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

struct ConcaveFunction {
    const double INF = 1e10; // must be set appropriately!

    struct Line {
        double a, b;
        double eval(double x) { return a*x + b; }
    };

    double Intersection(Line U, Line V) { // U.a >= V.a
        // We consider the special case da == 0, to avoid 0.0 / 0.0.
        double da = U.a - V.a;
        assert(da >= 0);
        if (da == 0) return (V.b <= U.b) ? -INF : INF;
        
        double x = (V.b - U.b) / da;
        if (x > INF) return 2*INF;
        if (x < -INF) return -2*INF;

        return x;
    }
    
    vector<double> xx; // nondecreasing, starting from -INF, ending with +INF.
    vector<Line> pieces;

    // {a, b} -> ax + b
    ConcaveFunction(vector<pair<double,double>> _lines) {
        assert(!_lines.empty());
        vector<Line> lines;
        for (auto pp: _lines) lines.push_back({.a = pp.first, .b = pp.second});
        sort(all(lines), [&](const Line& U, const Line& V) { return U.a > V.a; });

        for (Line l: lines) {
            while (!pieces.empty() and
                   pieces.back().eval(xx.back()) >= l.eval(xx.back())) {
                pieces.pop_back();
                xx.pop_back();
            }
            if (pieces.empty()) {
                xx.push_back(-INF);
                pieces.push_back(l);
            } else {
                double new_x = Intersection(pieces.back(), l);
                if (new_x > INF) continue;

                if (new_x <= xx.back()) pieces.pop_back();
                else xx.push_back(new_x);

                pieces.push_back(l);
            }
        }
        xx.push_back(INF);
    }

    pair<pair<double,double>, Line> get_piece(double x) {
        assert(-INF < x and x < INF);
        int it = lower_bound(all(xx), x) - xx.begin();
        return {{xx[it-1], xx[it]}, pieces[it-1]}; 
    }

    double eval(double x) {
        return get_piece(x).second.eval(x);
    }
};

// 1 + x + ... + x**(k-1)
double sum_pow(double x, LL k) {
    return (pow(x, k) - 1) / (x-1);
}

double power_linear(ConcaveFunction::Line U, double x, LL k) {
    return pow(U.a, k) * x + U.b * sum_pow(U.a, k);
}

void solve() {
    int n;
    cin >> n;
    LL t;
    cin >> t;

    double z = 0;
    vector<pair<double,double>> lines;

    for (int i = 0; i < n; i++) {
        LL a, b;
        cin >> a >> b;
        double p;
        cin >> p;
        lines.emplace_back(1-p, -a*p);
        z = max(z, b*p);
    }
    for (int i = 0; i < n; i++) lines[i].second += z;

    ConcaveFunction cf(lines);

    LL t0 = t;
    double x = 0;
    while (t > 0) {
        auto pp = cf.get_piece(x);
        double up = pp.first.second;
        auto line = pp.second;
        LL pot = 1;
        while (pot < t and power_linear(line, x, pot) <= up) {
            t -= pot;
            x = power_linear(line, x, pot);
            pot *= 2;
        }
        pot >>= 1;
        for (; pot >= 1; pot >>= 1) {
            if (pot < t and power_linear(line, x, pot) <= up) {
                t -= pot;
                x = power_linear(line, x, pot);
            }
        }
        x = line.eval(x);
        t--;
    }
    // for (int i = 0; i < t; i++) {
        // x = cf.eval(x);
        // dbg(x);
    // }

    cout.precision(10);
    cout << fixed << z*t0 - x << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int t = 1;
    // cin >> t;
    while (t--) solve();
}