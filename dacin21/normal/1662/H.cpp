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

// Integer factorization in O(N^{1/4}
// uses squfof from msieve https://github.com/radii/msieve
// with fixes to work for n = p^3
// works up to 10^18
// probably fails on 5003^5 which is ~10^{18.5}

namespace Factor {
    template<typename T, typename SFINAE = void> struct bigger_type{};
    template<typename T> using bigger_type_t = typename bigger_type<T>::type;
    template<typename T> struct bigger_type<T, typename enable_if<is_integral<T>::value && is_signed<T>::value && sizeof(T) == 4>::type>{using type = long long;};
    template<typename T> struct bigger_type<T, typename enable_if<is_integral<T>::value && !is_signed<T>::value && sizeof(T) == 4>::type>{using type = unsigned long long;};
    template<typename T> struct bigger_type<T, typename enable_if<is_integral<T>::value && is_signed<T>::value && sizeof(T) == 8>::type>{using type = __int128;};
    template<typename T> struct bigger_type<T, typename enable_if<is_integral<T>::value && !is_signed<T>::value && sizeof(T) == 8>::type>{using type = unsigned __int128;};

    template<typename int_t = unsigned long long>
    struct Mod_Int{
        static inline int_t add(int_t const&a, int_t const&b, int_t const&mod){
            int_t ret = a+b;
            if(ret>=mod) ret-=mod;
            return ret;
        }
        static inline int_t sub(int_t const&a, int_t const&b, int_t const&mod){
            return add(a, mod-b);
        }
        static inline int_t mul(int_t const&a, int_t const&b, int_t const&mod){
            return a*static_cast<bigger_type_t<int_t>>(b)%mod;
        }
        static inline int_t pow(int_t const&a, int_t const&b, int_t const&mod){
            int_t ret = 1;
            int_t base = a;
            for(int i=0;b>>i;++i){
                if((b>>i)&1) ret = mul(ret, base, mod);
                base = mul(base, base, mod);
            }
            return ret;
        }
    };

    template<typename T>
    bool is_prime(T x){
        static_assert(is_integral<T>::value);
        if(x<T(4)) return x>T(1);
        for(T i=2;i*i<=x;++i){
            if(x%i == 0) return false;
        }
        return true;
    }

    template<typename T>
    bool miller_rabin_single(T const&x, T base){
        static_assert(is_integral<T>::value);
        if(x<T(4)) return x>T(1);
        if(x%2 == 0) return false;
        base%=x;
        if(base == 0) return true;

        T xm1 = x-1;
        int j = 1;
        T d = xm1/2;
        while(d%2 == 0){ // could use __builtin_ctz
            d/=2;
            ++j;
        }
        T t = Mod_Int<T>::pow(base, d, x);
        if(t==T(1) || t==T(xm1)) return true;
        for(int k=1;k<j;++k){
            t = Mod_Int<T>::mul(t, t, x);
            if(t == xm1) return true;
            if(t<=1) break;
        }
        return false;
    }

    template<typename T>
    bool miller_rabin_multi(T const&){return true;}
    template<typename T, typename... S>
    bool miller_rabin_multi(T const&x, T const&base, S const&...bases){
        static_assert(is_integral<T>::value);
        if(!miller_rabin_single(x, base)) return false;
        return miller_rabin_multi(x, bases...);
    }

    template<typename T>
    bool miller_rabin(T const&x){
        static_assert(is_integral<T>::value);
        if(x < 316349281) return miller_rabin_multi(x, T(11000544), T(31481107));
        if(x < 4759123141ull) return miller_rabin_multi(x, T(2), T(7), T(61));
        return miller_rabin_multi(x, T(2), T(325), T(9375), T(28178), T(450775), T(9780504), T(1795265022));
    }

    template<typename T>
    T isqrt(T const&x){
        static_assert(is_integral<T>::value);
        assert(x>=T(0));
        T ret = static_cast<T>(sqrtl(x));
        while(ret>0 && ret*ret>x) --ret;
        while(x-ret*ret>2*ret)
            ++ret;
        return ret;
    }
    template<typename T>
    T icbrt(T const&x){
        static_assert(is_integral<T>::value);
        assert(x>=T(0));
        T ret = static_cast<T>(cbrt(x));
        while(ret>0 && ret*ret*ret>x) --ret;
        while(x-ret*ret*ret>3*ret*(ret+1))
            ++ret;
        return ret;
    }
    uint64_t isqrt(unsigned __int128 const&x){
        unsigned __int128 ret = sqrtl(x);
        while(ret>0 && ret*ret>x) --ret;
        while(x-ret*ret>2*ret)
            ++ret;
        return ret;
    }
    vector<uint16_t> saved;
    // fast prime factorization from
    // https://github.com/radii/msieve
    uint64_t squfof_iter_better(uint64_t const&x, uint64_t const&k, uint64_t const&it_max, uint32_t cutoff_div){
        if(__gcd((uint64_t)k, x)!=1) return __gcd((uint64_t)k, x);
        //cerr << "try: " << x << " " << k << "\n";
        saved.clear();
        uint64_t scaledn = k*x;
        if(scaledn>>62) return 1;
        uint32_t sqrtn = isqrt(scaledn);
        uint32_t cutoff = isqrt(2*sqrtn)/cutoff_div;
        uint32_t q0 = 1;
        uint32_t p1 = sqrtn;
        uint32_t q1 = scaledn-p1*p1;

        if(q1 == 0){
            uint64_t factor = __gcd(x, (uint64_t)p1);
            return factor==x ? 1:factor;
        }

        uint32_t multiplier = 2*k;
        uint32_t coarse_cutoff = cutoff * multiplier;
        //cerr << "at: " << multiplier << "\n";

        uint32_t i, j;
        uint32_t p0 = 0;
        uint32_t sqrtq = 0;

        for(i=0;i<it_max;++i){
            uint32_t q, bits, tmp;

            tmp = sqrtn + p1 - q1;
            q = 1;
            if (tmp >= q1)
                q += tmp / q1;

            p0 = q * q1 - p1;
            q0 = q0 + (p1 - p0) * q;

            if (q1 < coarse_cutoff) {
                tmp = q1 / __gcd(q1, multiplier);

                if (tmp < cutoff) {
                    saved.push_back((uint16_t)tmp);
                }
            }

            bits = 0;
            tmp = q0;
            while(!(tmp & 1)) {
                bits++;
                tmp >>= 1;
            }
            if (!(bits & 1) && ((tmp & 7) == 1)) {

                sqrtq = (uint32_t)isqrt(q0);

                if (sqrtq * sqrtq == q0) {
                    for(j=0;j<saved.size();++j){
                        if(saved[j] == sqrtq) break;
                    }
                    if(j == saved.size()) break;
                    //else cerr << "skip " << i << "\n";;
                }
            }
            tmp = sqrtn + p0 - q0;
            q = 1;
            if (tmp >= q0)
                q += tmp / q0;

            p1 = q * q0 - p0;
            q1 = q1 + (p0 - p1) * q;

            if (q0 < coarse_cutoff) {
                tmp = q0 / __gcd(q0, multiplier);

                if (tmp < cutoff) {
                    saved.push_back((uint16_t) tmp);
                }
            }
        }

        if(sqrtq == 1) { return 1;}
        if(i == it_max) { return 1;}

        q0 = sqrtq;
        p1 = p0 + sqrtq * ((sqrtn - p0) / sqrtq);
        q1 = (scaledn - (uint64_t)p1 * (uint64_t)p1) / (uint64_t)q0;

        for(j=0;j<it_max;++j) {
            uint32_t q, tmp;

            tmp = sqrtn + p1 - q1;
            q = 1;
            if (tmp >= q1)
                q += tmp / q1;

            p0 = q * q1 - p1;
            q0 = q0 + (p1 - p0) * q;

            if (p0 == p1) {
                q0 = q1;
                break;
            }

            tmp = sqrtn + p0 - q0;
            q = 1;
            if (tmp >= q0)
                q += tmp / q0;

            p1 = q * q0 - p0;
            q1 = q1 + (p0 - p1) * q;

            if (p0 == p1)
                break;
        }
        if(j==it_max) {cerr << "RNG\n"; return 1;} // random fail

        uint64_t factor = __gcd((uint64_t)q0, x);
        if(factor == x) factor=1;
        return factor;
    }
    uint64_t squfof(uint64_t const&x){
        static array<uint32_t, 16> multipliers{1, 3, 5, 7, 11, 3*5, 3*7, 3*11, 5*7, 5*11, 7*11, 3*5*7, 3*5*11, 3*7*11, 5*7*11, 3*5*7*11};

        uint64_t cbrt_x = icbrt(x);
        if(cbrt_x*cbrt_x*cbrt_x == x) return cbrt_x;

        //uint32_t iter_lim = isqrt(isqrt(x))+10;
        uint32_t iter_lim = 300;
        for(uint32_t iter_fact = 1;iter_fact<20000;iter_fact*=4){
            for(uint32_t const&k : multipliers){
                if(numeric_limits<uint64_t>::max()/k<=x) continue; //would overflow
                uint32_t const it_max = iter_fact*iter_lim;
                uint64_t factor = squfof_iter_better(x, k, it_max, 1);
                if(factor==1 || factor==x) continue;
                return factor;
            }
        }
        cerr << "failed to factor: " << x << "\n";
        assert(0);
        return 1;
    }

    template<typename T>
    vector<T> factorize(T x){
        static_assert(is_integral<T>::value);
        vector<T> ret;
        const uint32_t trial_limit = 5000;
        auto trial = [&](int i){while(x%i == 0){x/=i; ret.push_back(i);}};
        trial(2); trial(3);
        for(uint32_t i=5, j=2;i<trial_limit && i*i <= x;i+=j, j=6-j){
            trial(i);
        }
        if(x>1){
            static stack<T> s;
            s.push(x);
            while(!s.empty()){
                x = s.top(); s.pop();
                if(!miller_rabin(x)){
                    T factor = squfof(x);
                    if(factor == 1 || factor == x){assert(0); return ret;}
                    s.push(factor);
                    s.push(x/factor);
                } else {
                    ret.push_back(x);
                }
            }
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
    template<typename T>
    vector<T> all_factors(T x){
        auto primes = factorize(x);
        vector<T> ret;
        auto run = [&](T cur, T skip, int i, auto run) -> void{
            if(i == (int)primes.size()){
                ret.push_back(cur);
            } else {
                auto P = primes[i];
                if(P == skip){
                    run(cur, skip, i+1, run);
                } else {
                    run(cur*P, skip, i+1, run);
                    run(cur, P, i+1, run);
                }
            }
        };
        run(T{1}, T{1}, 0, run);
        sort(ret.begin(), ret.end());
        return ret;
    }
}


void solve(){
    /// SOLVE HERE
    ll X, Y;
    cin >> X >> Y;
    ll U = 2*(X+Y-2);
    auto factors = Factor::all_factors(U);
    vector<ll> out;
    for(ll a : factors){
        for(ll t: {0, 1}){
            bool fail = false;
            ll tail = t;
            ll Z = X;
            for(int it=0; it<4; ++it){
                tail += Z-1;
                tail %= a;
                if(tail > 1){
                    fail=true;
                    break;
                }
                Z ^= (X^Y);
            }
            if(!fail){
                out.push_back(a);
                break;
            }
        }
    }
    cout << out.size() << " ";
    for(auto e : out) cout << e << " ";
    cout << "\n";

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