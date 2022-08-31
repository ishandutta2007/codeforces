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

 debug_::Debug<true> debug;
// debug_::Debug<false> debug; // disable debug printing

#endif

#define named(x) string(#x) << " : " <<  x

struct Fen{
    Fen(int n_) : n(n_+5), v(n, 0) {}

    int q(int x){
        int ret = 0;
        for(++x; x; x-=x&-x){
            ret += v[x];
        }
        return ret;
    }
    void u(int x, int a){
        for(++x; x<n; x+=x&-x){
            v[x] += a;
        }
    }
    int n;
    vector<int> v;
};

void solve(){
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    for(auto &e : p){
        cin >> e; --e;
    }
    for(int i=0; i<n; ++i){
        q[p[i]] = i;
    }
    vector<int> diffs(n, 0);
    for(int i=1; i<n; ++i){
        int d = q[i]-q[i-1]-1;
        if(d < 0) d += n;
        diffs[i] = d;
    }
    vector<ll> moves(n, 0);
    for(int i=1; i<n; ++i){
        moves[i] = moves[i-1] + diffs[i];
    }
    debug << named(p) << "\n";
    debug << named(q) << "\n";
    debug << named(diffs) << "\n";
    debug << named(moves) << "\n";
    ll total_moves = accumulate(moves.begin(), moves.end(), 0ll);
    assert(total_moves % n == 0);
    ll rotation = total_moves / n;
    for(auto &e : moves) e -= rotation;
    // now some weird inversion counting
    vector<pair<ll, int> > ps(n);
    for(int i=0; i<n; ++i){
        ps[i] = make_pair(i+moves[i], i);
    }
    sort(ps.begin(), ps.end());
    ll ans = 0;
    Fen ft(n);
    Fen ft2(n);
    Fen ft3(n);
    queue<pair<int, pair<int, int> > > qq;
    ll edge = 0;
    int done = 0;
    for(auto &el:ps){
        const int i = el.second;
        ll m = el.first;
        ll e = m / n;
        while(e*n < m) ++e;
        while(e*n > m) --e;
        m -= e*n;
        assert(0 <= m && m < n);

        while(!qq.empty() && qq.front().first < e){
            const int j = qq.front().second.first;
            const int jj = qq.front().second.second;
            qq.pop();
            ft.u(j, -1);
            ft2.u(j, 1);
            ft3.u(jj, 1);
        }
        //debug << i << " " << m << " " << e << " -> ";
        //debug << ft.q(n)-ft.q(i) << " | " <<  ft2.q(n)-ft2.q(i) << " | " << ft3.q(m) << " | " << done*e - edge << "\n";

        ans += ft.q(n)-ft.q(i);
        ans += ft2.q(n)-ft2.q(i);
        ans -= ft3.q(n)-ft3.q(m);
        ft.u(i, 1);
        qq.emplace(e, make_pair(i, m));

        ans += done*e - edge;
        ++done;
        edge += e;
    }
    cout << ans << "\n";
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
    int TTT; cin >> TTT;
    if(TTT < 0) return gen(-TTT);
    while(TTT--){
    #endif // LOCAL_RUN

    solve();

    #ifdef LOCAL_RUN
    cout << flush;
    #endif // LOCAL_RUN
    }
    return 0;
}