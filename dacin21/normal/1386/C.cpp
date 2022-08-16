#undef _GLIBCXX_DEBUG

#pragma GCC optimize("O3")
//#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") // codeforces

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using fl = long double;
template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename S, typename T>
void xmin(S&a, T const&b){if(b<a) a=b;}
template<typename S, typename T>
void xmax(S&a, T const&b){if(b>a) a=b;}



namespace debug_{

template<size_t N> struct priority : priority<N-1> {};
template<> struct priority<0> {};

template<bool enabled> struct Debug;
template<typename T, typename SFINAE = void> struct Printer : enable_if<false> {};
// pair and tuple
template<typename S, typename T>
struct Printer<pair<S, T> > : enable_if<true> {
    template<typename D>
    static void print(D const&d, pair<S, T> const&val){
        d << "(" << val.first << ", " << val.second << ")";
    }
};
template<typename... S>
struct Printer<tuple<S ...> > : enable_if<true> {
    template<size_t i, size_t n, typename D>
    static void print_rec(D const&d, tuple<S ...> const&val){
        d << get<i>(val);
        if(i+1 < n) {
            d << ", ";
            print_rec<i+(i+1<n), n>(d, val);
        }
    }
    template<typename D>
    static void print(D const&d, tuple<S ...> const&val){
        d << "(";
        print_rec<0, tuple_size<tuple<S...> >::value >(d, val);
        d << ")";
    }
};
template<>
struct Printer<tuple<> > : enable_if<true> {
    template<typename D>
    static void print(D const&d, tuple<> const&){
        d << "()";
    }
};
// non-iterable container
template<typename T>
struct Hacked_Container : T{
    static auto get(T const& val){
        return val.*&Hacked_Container::c;
    }
};
template<typename T> struct is_hackable_container : false_type{};
template<typename... T> struct is_hackable_container<stack<T...> > : true_type{};
template<typename... T> struct is_hackable_container<queue<T...> > : true_type{};
template<typename... T> struct is_hackable_container<priority_queue<T...> > : true_type{};
template<typename T>
struct Printer<T, enable_if_t<is_hackable_container<T>::value> >  : enable_if<true> {
    template<typename D>
    static void print(D const&d, T const&s){
        d << Hacked_Container<T>::get(s);
    }
};
// custom printable struct
template<typename T>
struct Printer<T,enable_if_t<sizeof((declval<T>().debug_print_(2), 1)) != -1>> : enable_if<true>{
    template<typename D>
    static void print(D const&d, T const&val){
        val.debug_print_(d);
    }
};

template <>
struct Debug<false>{
    template<typename T, typename = enable_if_t<is_same<int, decltype((declval<Debug<true>>() << declval<T>()), (int)1)>::value > >
    friend const Debug& operator<<(Debug const&o, T const&){
        return o;
    }
    template<typename... Args>
    void pprint_all(string const&names, Args const& ... vals){}
};
template <>
struct Debug<true>{
    template<typename T, typename = decltype(cerr << declval<T>())>
    void print(T const&val, priority<30>) const {
        cerr << val;
    }
    template<typename T, typename = decltype((begin(declval<T>()), end(declval<T>())))>
    void print(T const&val, priority<20>) const {
        *this << "[";
        bool first = true;
        for(auto const&e:val){
            if(!first) *this << ", ";
            *this << e;
            first = false;
        }
        *this << "]";
    }
    template<typename T, typename = typename Printer<T>::type>
    void print(T const&val, priority<50>) const {
        Printer<T>::print(*this, val);
    }
    void pprint_all_rec(string const&, size_t) const {}
    template<typename T, typename... Args>
    void pprint_all_rec(string const&names, size_t pos, T const&val, Args const& ... rest) const {
        if(pos != 0) *this << ", ";
        assert(pos != string::npos);
        size_t next = names.find(",", pos);
        if(next == string::npos){
                *this << names.substr(pos);
        } else {
            *this << names.substr(pos, next-pos);
            ++next;
        }
        *this << "=" << val;
        pprint_all_rec(names, next, rest...);
    }

    template<typename... Args>
    void pprint_all(string const&names, Args const& ... vals) const {
        *this << "(";
        pprint_all_rec(names, 0, vals...);
        *this << ")";
    }
    template<typename T, typename = decltype(declval<Debug>().print(declval<T>(), priority<99>{}))>
    friend const Debug& operator<<(Debug const &o, T const& val){
        o.print(val, priority<99>{});
        return o;
    }
};
}

#define make_printable(...)\
template<typename T>\
void debug_print_(T const& d)const{\
    d.pprint_all(#__VA_ARGS__, __VA_ARGS__);\
}
#ifndef LOCAL_RUN
debug_::Debug<false> debug;
#else

// debug_::Debug<true> debug;
 debug_::Debug<false> debug; // disable debug printing

#endif

#define named(x) string(#x) << " : " <<  x

// off-line dynamic bridges
// runs in O(n + q log(n))
// uses link-cut trees and is faster than divide&conquer

template<typename S>
inline void xmin(S&a, S const&b){
    a=min(a, b);
}
template<typename S>
inline void xmax(S&a, S const&b){
    a=max(a, b);
}
template<typename S>
inline void xmin_2(S&a, S const&b, S const& inf){
    if((a>b && b!=inf) || a==inf) a=b;
}
template<typename S>
inline void xmax_2(S&a, S const&b, S const& neg_inf){
    if((a<b && b!=neg_inf) || a==neg_inf) a=b;
}
uint64_t steps = 0, calls = 0;



struct DSU{
    DSU(){}
    DSU(int n) : p(n, make_pair(-1, false)), rank(n){
        mt19937 rng(std::chrono::duration_cast<std::chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
        for(auto &e:rank){
            e = uniform_int_distribution<int>(0, 1e9)(rng);
        }
    }
    struct Change{
        int pos = -1;
        pair<int, bool> old;
        make_printable(pos,old)
    };
    pair<int, bool> f(int x){
        ++calls;
        bool odd = false;
        while(p[x].first != -1){
            ++steps;
            odd ^= p[x].second;
            x = p[x].first;
        }
        return {x, odd};
    }
    bool odd(int a, int b){
        auto x = f(a), y = f(b);
        if(x.first != y.first) return false;
        return x.second == y.second;
    }
    Change u(int a, int b){
        //assert(!odd(a, b));
        auto x = f(a);
        auto y = f(b);
        if(x.first == y.first) return Change{}; // no change
        if(rank[x.first] < rank[y.first]) swap(x, y);
        Change ret{x.first};
        ret.old = p[x.first];
        p[x.first] = make_pair(y.first, x.second==y.second);
        //ret.now = p[x.first];
        debug << "-> " << ret << "\n";
        return ret;
    }
    void revert(Change const&c){
        debug << "<- " << c << "\n";
        if(c.pos == -1) return;
        //assert(p[c.pos] == c.now);
        p[c.pos] = c.old;
    }
    /*void revert(vector<Change> const&v){
        for(auto it = v.rbegin(); it != v.rend(); ++it){
            revert(*it);
        }
    }*/
    template<typename T>
    void revert(T const&v){
        for(auto it = v.r; it != v.l;){
            --it;
            revert(*it);
        }
    }
    vector<pair<int, uint8_t> > p;
    vector<int> rank;
};


DSU uni;
vector<pair<int, int> > ed;
vector<int> R;

int M;

vector<DSU::Change> le, ri;

template<typename T>
struct dumb_vector{
    T*l, *r;
    dumb_vector(T* l_ = nullptr):l(l_), r(l){}
    size_t size(){
        return r-l;
    }
    bool empty(){
        return l==r;
    }
    void push_back(T const&x){
        *(r++) = x;
    }
    void clear(){
        r=l;
    }
    void reserve(size_t) {}
    T* begin() { return l; }
    T* end() { return r; }
};

void rec(int d, int a, int b, int baseA, int r){
    // now [baseA, r)
    if(b<=a) return;
    debug << "rec " << a << " " << b << " " << r << "\n";
    const int m = a + (b-a)/2;
    debug << named(m) << "\n";
    //vector<DSU::Change> left, right;
    dumb_vector<DSU::Change> left(le.data()+d*M), right(ri.data()+d*M);
    left.reserve(m-a+1);
    // move to [m, r)
    for(int i=baseA; i<m; ++i){
        if(uni.odd(ed[i].first, ed[i].second)){
            uni.revert(left);
            for(int j=m; j<b; ++j){
                R[j] = 1e9;
            }
            debug << "FAILED: " << m << "\n";
            rec(d, a, m, baseA, r);
            return;
        }
        left.push_back(uni.u(ed[i].first, ed[i].second));
    }
    // now [m, r)
    right.reserve(r-m);
    // move to [m, l)
    int l = r;
    while(l > m){
        auto const f = ed[l-1];
        if(uni.odd(f.first, f.second)) break;
        --l;
        right.push_back(uni.u(f.first, f.second));
    }
    // now [m, l)
    R[m] = l;
    uni.revert(right); right.clear();
    // now [m, r)
    rec(d+1, m+1, b, m, r);
    uni.revert(left); left.clear();
    for(int i = r-1; i >= l; --i){
        auto const f = ed[i];
        right.push_back(uni.u(f.first, f.second));
    }
    // now [baseA, l)
    rec(d+1, a, m, baseA, l);
    uni.revert(right); right.clear();
    // now [baseA, r)
    debug << "done " << a << " " << b << " " << r << "\n";
}

void solve(){
    /// SOLVE HERE
    int n, m, q;
    cin >> n >> m >> q;
    M = m;
    uni = DSU(n);
    ed.resize(m);
    le.resize(m*(2+__lg(m)));
    ri.resize(m*(2+__lg(m)));
    R.assign(m, -1);
    for(auto &e:ed){
        cin >> e.first >> e.second;
        --e.first; --e.second;
    }
    rec(0, 0, m, 0, m);
    debug << named(R) << "\n";
    for(int it=0; it<q; ++it){
        int l, r;
        cin >> l >> r;
        --l; //--r;
        if(r < R[l]){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

signed gen(int T){
    mt19937 rng(43151);
    auto get_rand = [&](int64_t l, int64_t r){
        return uniform_int_distribution<int64_t>(l, r)(rng);
    }; (void) get_rand;
    auto get_double = [&](double l, double r){
        return uniform_real_distribution<double>(l, r)(rng);
    };  (void) get_double;
    ofstream o("gen.txt");
    o << T << "\n";
    for(int cas=0;cas<T;++cas){
        /// GEN HERE
        const int n = get_rand(1, 2e5);
        const int m = get_rand(1e5, 2e5);
        const int q = 0;
        o << n << " " << m << " " << q << "\n";
        for(int i=0; i<m; ++i){
            int a = get_rand(1, n), b = get_rand(1, n-1);
            b += (b>=a);
            o << a << " " << b << "\n";
        }


        o << "\n";
    }
    o << endl;
    o.close();
    return 0;
}

signed main()
{
    #ifdef LOCAL_RUN
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.exceptions(ios::badbit | ios::eofbit | ios::failbit);
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int TTT; cin >> TTT;
    if(TTT < 0) return gen(-TTT);
    while(TTT--){
    #else
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    #endif // LOCAL_RUN

    solve();

    #ifdef LOCAL_RUN
    cerr << "steps: " << steps << ", " << "calls: " << calls << "\n";
    cout << flush;
    }
    #endif // LOCAL_RUN
    return 0;
}