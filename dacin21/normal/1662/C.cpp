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

template<typename traits>
class Mod_Int{
public:
    using int_t = typename traits::int_t;
    using long_t = typename traits::long_t;
    static constexpr int_t mod(){ return traits::get_mod(); };

    struct Summer{
    public:
        static constexpr long_t modmod(){ return traits::get_mod()*(long_t)traits::get_mod(); };
        static long_t modmod_step(long_t const& val){
            return val >= modmod() ? val-modmod() : val;
        }

        Summer() : val{} {}
        explicit Summer(Mod_Int const&o) : val(o.get_value()){}
        operator Mod_Int() const {
            return Mod_Int(mod_full(val));
        }

        Summer operator-(Summer const&o){
            return Summer(modmod() - modmod_step(o.val));
        }
        Summer& operator+=(Summer const&o){
            val = modmod_step(val+o.val);
            return *this;
        }
        Summer& operator-=(Summer const&o){
            return operator-=(-o);
        }
        Summer& addmul(Mod_Int const&a, Mod_Int const&b){
            val = modmod_step(val + a.get_value()*(long_t)b.get_value());
            return *this;
        }

    private:
        long_t val;
    };


    Mod_Int() : value(0) {}
    Mod_Int(int_t value_) : value(value_) {}

    friend ostream& operator<<(ostream&o, Mod_Int const&val){
        return o << val.value;
    }
    friend istream& operator>>(istream&i, Mod_Int &val){
         i >> val.value;
         val.value = mod_full(val.value);
         return i;
    }
    int_t const& get_value() const {
        return value;
    }

    Mod_Int operator+(Mod_Int const&o) const {
        Mod_Int ret(mod_step(value + o.value));
        return ret;
    }
    Mod_Int& operator+=(Mod_Int const&o){
        return *this = *this + o;
    }
    Mod_Int& operator++(){
        return operator+=(int_t{1});
    }
    Mod_Int operator-() const{
        Mod_Int ret(mod_step(mod() - value));
        return ret;
    }
    Mod_Int operator-(Mod_Int const&o) const {
        return operator+(-o);
    }
    Mod_Int& operator-=(Mod_Int const&o){
        return operator+=(-o);
    }
    Mod_Int& operator--(){
        return operator-=(int_t{1});
    }
    friend Mod_Int operator*(Mod_Int const&a, Mod_Int const&b) {
        Mod_Int ret(mod_full(a.value * static_cast<long_t>(b.value)));
        return ret;
    }
    Mod_Int& operator*=(Mod_Int const&o){
        return *this = *this * o;
    }
    Mod_Int inv() const {
        return inv_impl(value);
    }
    Mod_Int operator/(Mod_Int const&o) const {
        return *this * o.inv();
    }
    Mod_Int& operator/=(Mod_Int const&o) {
        return *this = *this / o;
    }

    bool operator==(Mod_Int const&o) const {
        return value == o.value;
    }
    bool operator!=(Mod_Int const&o) const {
        return !(*this == o);
    }
    bool operator!() const {
        return !value;
    }

private:
    static int_t mod_step(int_t const& val){
        return val >= mod() ? val-mod() : val;
    }
    static int_t mod_full(long_t const&val){
        return mod() ? val%mod() : val;
    }
    static Mod_Int inv_impl(Mod_Int const& val){
        if(mod() == 0){
            assert(val*val == 1);
            return val;
        }
        int_t value = val.value;
        constexpr size_t cache_size = traits::inv_cache_size()+1;
        static_assert(cache_size > 1);
        static array<Mod_Int, cache_size> cache = [](){
            array<Mod_Int, cache_size> ret;
            ret[1] = 1;
            for(int_t i=2;i<cache_size && i < mod();++i){
                ret[i] = -ret[mod()%i] * (mod()/i);
            }
            return ret;
        } ();
        assert(value != 0);
        Mod_Int factor = 1;
        while(value >= cache_size){
            factor *= - Mod_Int(mod() / value);
            value = mod() % value;
        }
        assert(value != 0);
        assert(factor != 0  && value != 0);
        return factor * cache[value];
    }

    int_t value;
};

template<uint32_t mod>
struct fixed_mod{
    using int_t = uint32_t;
    using long_t = uint64_t;
    static_assert(mod != 0, "Negative numbers won't work.");
    static_assert(numeric_limits<int_t>::max()/2 >= mod, "Addition might overflow.");
    static constexpr size_t inv_cache_size(){ return 30000; }
    static constexpr int_t get_mod(){ return mod; }
};
#ifdef __SIZEOF_INT128__
template<uint64_t mod>
struct fixed_mod_long{
    using int_t = uint64_t;
    using long_t = __int128;
    static_assert(mod != 0, "Negative numbers won't work.");
    static_assert(numeric_limits<int_t>::max()/2 >= mod, "Addition might overflow.");
    static constexpr size_t inv_cache_size(){ return 30000; }
    static constexpr int_t get_mod(){ return mod; }
};
#endif // __SIZEOF_INT128__
struct no_mod{
    using int_t  = int64_t;
    using long_t = int_t;
    static constexpr size_t inv_cache_size(){ return 1; }
    static constexpr int_t get_mod(){ return 0; }
};
struct mutable_mod{
    using int_t = uint32_t;
    using long_t = uint64_t;
    static int_t mod;
    // can't use cache if mod is changing
    static constexpr size_t inv_cache_size(){ return 1; }
    static int_t get_mod(){ return mod; }
};
mutable_mod::int_t mutable_mod::mod = 1000000007;

using num = Mod_Int<fixed_mod<998244353> >;

template<typename T>
struct Matrix{
    Matrix() {}
    Matrix(int R_, int C_) : R(R_), C(C_), data(R*C) {}
    // column vector
    Matrix(std::vector<T> data_) : R(data_.size()), C(1), data(move(data_)) {}
    // matrix from vector of rows
    Matrix(std::vector<std::vector<T> > const&data_) : R(data_.size()), C(data_.empty() ? 0 : data_[0].size()), data(R*C) {
        for(int i=0;i<R;++i){
            copy(data_[i].begin(), data_[i].end(), data.begin()+i*C);
        }
    }

    static Matrix eye(int n, const T diag_val = 1){
        Matrix ret(n, n);
        for(int i=0;i<n;++i){
            ret.at(i, i) = diag_val;
        }
        return ret;
    }

    Matrix operator*(Matrix const&other) const {
        assert(C == other.R);
        Matrix ret(R, other.C);
        const Matrix o = other.transposed();
        for(int i=0;i<R;++i){
            for(int j=0;j<other.C;++j){
                typename T::Summer su{};
                for(int k=0;k<C;++k){
                    //ret.at(i, j) += at(i, k) * o.at(j, k);
                    su.addmul(data[i*C+k], o.data[j*o.C+k]);
                }
                ret.data[i*ret.C+j] = T(su);
            }
        }
        return ret;
    }

    Matrix transposed() const {
        Matrix ret(C, R);
        for(int i=0;i<C;++i){
            for(int j=0;j<R;++j){
                ret.at(j, i) = at(i, j);
            }
        }
        return ret;
    }
    friend void operator+=(Matrix &a, Matrix const&b){
        assert(a.R == b.R);
        assert(a.C == b.C);
        for(int i=0; i<a.R*a.C; ++i){
            a.data[i] += b.data[i];
        }
    }

    T& at(int i, int j){
        assert(0 <= i && i < R);
        assert(0 <= j && j < C);
        return data[i*C+j];
    }
    T const& at(int i, int j) const {
        assert(0 <= i && i < R);
        assert(0 <= j && j < C);
        return data[i*C+j];
    }
    T trace() const {
        T ret = 0;
        for(int i=0; i<min(R, C); ++i){
            ret += at(i, i);
        }
        return ret;
    }

    int R, C;
    vector<T> data;
};

// computes base^exp * start
template<typename T>
T powmul(T base, T start, uint64_t exp){
    for(;exp;exp>>=1){
        if(exp&1){
            start = base * start;
        }
        base = base * base;
    }
    return start;
}

using Mat = Matrix<num>;

void solve(){
    int n, m, K;
    cin >> n >> m >> K;
    Mat B(n, n), diag(n, n);
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        --a; --b;
        B.at(a, b) = B.at(b, a) = 1;
        diag.at(a, a) -= 1;
        diag.at(b, b) -= 1;
    }
    auto diag_2 = diag;
    for(int i=0; i<n; ++i){
        diag_2.at(i, i) += 1;
    }
    /*vector<Mat> dp(K+1);
    dp[0] = Mat::eye(n);
    dp[1] = B;
    for(int i=2; i<=K; ++i){
        dp[i] = dp[i-1] * B;
        dp[i] += dp[i-2] * (i == 2 ? diag : diag_2);
    }
    Mat& ans = dp[K];
    for(int i=0; i<n; ++i){
        cerr << ans.at(i, i).get_value() << " ";
    }
    cerr << "\n";*/
    map<int, Mat*> cache;

    auto rec = [&](int K, auto rec) -> Mat&{
        Mat*& ret = cache[K];
        if(!ret){
            ret = new Mat(n, n);
            if(K == 0){
                *ret = Mat::eye(n);
            } else if(K == 1) {
                *ret = B;
            } else if(K == 2){
                *ret = B*B;
                *ret += diag_2;
            } else {
                const int l = (K-3)/2, r = K-3-l;
                *ret  = rec(l+1, rec)*B*rec(r+1, rec);
                *ret += rec(l+1, rec)*diag_2*rec(r, rec);
                *ret += rec(l, rec)*diag_2*rec(r+1, rec);
            }
        }
        return *ret;
    };
    Mat ans = B*rec(K-1, rec);
    if(K > 1) ans += diag * rec(K-2, rec);
    num out = ans.trace();
    cout << out.get_value() << "\n";
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
    #endif // LOCAL_RUN

    solve();

    #ifdef LOCAL_RUN
    cout << flush;
    }
    #endif // LOCAL_RUN
    return 0;
}