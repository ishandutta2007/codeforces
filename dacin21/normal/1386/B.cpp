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

template<typename T>
int sign(T x){
    return (x>0) - (x<0);
}

struct Point{
    ll x, y;
    friend int side(Point const&a){
        const int A = sign(a.x);
        if(A) return A;
        return sign(a.y);
    }
    friend int ccw(Point const&a, Point const&b){
        //return sign(a.x*(__int128)b.y - b.x*(__int128)a.y);
        auto y = sign(a.x*(double)b.y - b.x*(double)a.y);
        return (y > 0.5) - (y<-0.5);
    }
    friend bool operator<(Point const&a, Point const&b){
        // ccw(a-base, b-base)
        return ccw(a, b) < 0;
    }
    friend bool operator>(Point const&a, Point const&b){
        return b<a;
    }
    friend Point operator-(Point const&o){
        return Point{-o.x, -o.y};
    }
    make_printable(x, y)

};

template<typename T>
bool has(multiset<T> const&s, T const&p){
    return s.find(p) != s.end();
}

void solve(){
    /// SOLVE HERE
    ll X, Y, Z;
    cin >> X >> Y >> Z;
    Z += X+Y;
    int n;
    cin >> n;
    multiset<Point> l, r, both;
    vector<pair<int, Point> > pool;
    int hits = 0;
    int pairs = 0;
    for(int it=0; it<n; ++it){
        //debug << named(l) << "\n" << named(r) << "\n";
        char c;
        cin >> c;
        if(c == 'R'){
            int i;
            cin >> i;
            --i;
            if(pool[i].first == 0){
                --hits;
            } else {
                assert(pool[i].first==1 || pool[i].first==-1);
                auto &me = (pool[i].first>0 ? r : l);
                auto &other = (pool[i].first>0 ? l : r);
                auto const p = pool[i].second;
                /*debug << &me << " : " << p << " rem\n";
                for(auto const&e:me) debug << e << " " << (e<p) << " " << (e>p) << " ---";
                debug << "\n";*/
                me.erase(me.find(p));
                if(has(other, -p) && !has(me, p)) --pairs;
            }
            pool[i].first = -2;
        } else {
            ll x, y, z;
            cin >> x >> y >> z;
            z+=x+y;
            Point p{Z*x-X*z, Z*y-Y*z};
            pool.emplace_back(side(p), p);
            if(side(p) == 0){
                ++hits;
            } else {
                auto &me = (side(p) > 0 ? r : l);
                auto &other = (side(p) > 0 ? l : r);
                if(has(other, -p) && !has(me, p)) ++pairs;
                //debug << &me << " : " << p << "\n";
                me.insert(p);
            }
        }
        if(hits){
            cout << "1\n";
        } else if(pairs){
            cout << "2\n";
        } else {
            if(l.empty() || r.empty() || (*l.rbegin() > *r.begin()) || (*r.rbegin() > *l.begin())){
                cout << "0\n";
            } else {
                cout << "3\n";
            }
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
        const int n = get_rand(1, 5000);
        const int M = 10000;
        {
            int X, Y, Z;
            do{
                X = get_rand(1, M);
                Y = get_rand(1, M);
                Z = get_rand(1, M);
            } while(X+Y+Z<= 0 || X+Y+Z > M);
            o << X << " " << Y << " " << Z << "\n";
            o << n << "\n";
        }
        int last = 1;
        set<pair<int, int> > used;
        for(int it=0; it<n; ++it){
            if(used.size() && get_rand(0, 99) <= 30){
                o << "R " << used.begin()->second << "\n";
                used.erase(used.begin());
            } else {
                int X, Y, Z;
                do{
                    X = get_rand(1, M);
                    Y = get_rand(1, M);
                    Z = get_rand(1, M);
                } while(X+Y+Z<= 0 || X+Y+Z > M);
                o << "A " << X << " " << Y << " " << Z << "\n";
                used.emplace(get_rand(last, 2*last), last);
                ++last;
            }
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
    cout << flush;
    }
    #endif // LOCAL_RUN
    return 0;
}