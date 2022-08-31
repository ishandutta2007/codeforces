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


struct Solver{
    struct Res{
        ll l, r;
    };

    ll jump(ll x){
        return (x)/2;
        //return 1ll << __lg(x-1);
    }
    Res space(ll x){
        if(x == 1) return Res{0, 0};
        if(cache.count(x)) return cache[x];
        const ll k = jump(x);
        auto const A = space(k);
        auto const B = space(x-k);
        return cache[x] = Res{max(A.r-k, B.r), k+max(A.l, B.l)};
    }
    map<ll, Res> cache;
};

ll N, c;
ll last;
set<ll> did;

bool ask(ll pos){
    cout << "? " << pos << endl;
    ll ans;
    #ifdef LOCAL_RUN
    assert(!did.count(pos));
    did.insert(pos);
    ans = abs(pos-last) >= c;
    last = pos;
    #else
    cin >> ans;
    #endif // LOCAL_RUN
    return ans;
}

void answer(ll C){
    cout << "= " << C << endl;
    #ifdef LOCAL_RUN
    assert(c == C);
    #endif // LOCAL_RUN
}

void solve(){
    /// SOLVE HERE
    /*for(int i=2; i<10000; ++i){
        Solver ss;
        auto tmp = ss.space(i);
        cerr << i << " " << tmp.l << " " << tmp.r << "\n";
        assert(tmp.l + tmp.r <= i-1);
    }*/
    ll n;
    #ifndef LOCAL_RUN
    cin >> N;
    #endif // LOCAL_RUN
    n = N;
    Solver sol;
    auto s = sol.space(N);
    debug << s.l << " " << s.r << "\n";
    assert(s.l + s.r <= N-1);
    ll pos = s.l+1;
    ask(pos);
    ll ret = 0;
    ll dir = 1;
    while(n > 1){
        const ll k = sol.jump(n);
        const ll p2 = pos + dir*(ret+k);
        assert(1 <= p2 && p2 <= N);
        if(ask(p2)){
            n = k;
        } else {
            ret += k;
            n = n-k;
        }
        dir = -dir;
        pos = p2;
    }
    answer(ret+1);
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
        const ll n = get_rand(2, 64);
        const ll c = get_rand(1, n);
        o << n << " " << c << "\n";

        o << "\n";
    }
    o << endl;
    o.close();
    return 0;
}

signed main()
{
    mt19937 rng(532532);
    #ifdef LOCAL_RUN
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.exceptions(ios::badbit | ios::eofbit | ios::failbit);
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    #else
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    #endif // LOCAL_RUN
    int TTT; cin >> TTT;
    if(TTT < 0) return gen(-TTT);
    while(TTT--){

    #ifdef LOCAL_RUN
    cin >> N >> c;
    did.clear();
    #endif // LOCAL_RUN

    solve();

    #ifdef LOCAL_RUN

    cout << flush;
    #endif // LOCAL_RUN
    }
    return 0;
}