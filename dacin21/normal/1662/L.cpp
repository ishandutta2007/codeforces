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

#define int long long

/*
 *	off-line sparse Fenwick tree
 *	point updates, range queries in O(log(n)^2)
 *	hopefully the compiler optimizes the templates...
 */
template<typename T, size_t dim>
enable_if_t<dim!=0, array<T, dim-1>> pop_front(array<T, dim> const&a){
    array<T, dim-1> ret;
    copy_n(a.begin()+1, dim-1, ret.begin());
    return ret;
}
template<typename T, int dim>
struct Fenwick_Tree{
    vector<Fenwick_Tree<T, dim-1>> trees;
    vector<int> coords;
    vector<array<int, dim> > ups;
    Fenwick_Tree(){}
    unsigned int compress(int const&coord){
        return upper_bound(coords.begin(), coords.end(), coord) - coords.begin();
    }
    void fake_update(array<int, dim> const&pos){
        coords.push_back(pos[0]);
        ups.push_back(pos);
    }
    void compile(){
        sort(coords.begin(), coords.end());
        coords.erase(unique(coords.begin(), coords.end()), coords.end());
        trees.resize(coords.size());
        for(auto &e:ups){
            for(unsigned int x = compress(e[0]);x<=trees.size();x+=x&(-x)){
                trees[x-1].fake_update(pop_front(e));
            }
        }
        ups.clear();
        for(auto &e:trees) e.compile();
    }
    T q(array<int, dim> const&pos){
        T ret = -1e9; array<int, dim-1> newpos = pop_front(pos);
        for(unsigned int x = compress(pos[0]);x;x-=(x&-x)){
            xmax(ret, trees[x-1].q(newpos));
        }
        return ret;
    }
    T qq(array<int, dim> const&l, array<int, dim> const&r){
        --l[0];
        return q(r)-q(l);
    }
    void up(array<int, dim> const&pos, T const&val){
        array<int, dim-1> newpos =pop_front(pos);
        for(unsigned int x = compress(pos[0]);x<=trees.size();x+=(x&-x)){
            trees[x-1].up(newpos, val);
        }
    }
};
template<typename T>
struct Fenwick_Tree<T, 0>{
    T data;
    Fenwick_Tree():data(-1e9){}
    void fake_update(array<int, 0>){}
    void compile(){}
    T q(array<int, 0>){return data;}
    T qq(array<int, 0>, array<int, 0>){return data;}
    void up(array<int, 0>, T const&val){data=max(data, val);}
};




struct Pos{
    static ll V;

    ll t, a;
    ll t_scaled() const { return t*V; }
    ll x() const {return t_scaled()-a; }
    ll y() const {return t_scaled()+a; }
};
ll Pos::V;

void solve(){
    int n;
    cin >> n >> Pos::V;
    vector<Pos> v(n);
    for(auto &e:v) cin >> e.t;
    for(auto &e:v) cin >> e.a;

    Fenwick_Tree<ll, 2> fen;
    for(auto const&e : v){
        fen.fake_update({e.x(), e.y()});
    }
    fen.fake_update({0ll, 0ll});
    fen.compile();
    fen.up({0ll, 0ll}, 0);
    ll best = 0;
    for(auto const&e:v){
        ll me = fen.q({e.x(), e.y()}) + 1;
        fen.up({e.x(), e.y()}, me);
        xmax(best, me);
    }
    cout << best << "\n";

}
#undef int

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
    #endif // LOCAL_RUN

    solve();

    #ifdef LOCAL_RUN
    cout << flush;
    }
    #endif // LOCAL_RUN
    return 0;
}