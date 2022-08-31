#undef _GLIBCXX_DEBUG
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") // codeforces
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

template<bool enabled>
struct Debug{
    template<typename S, typename T = void> struct Tag_Printable : false_type {};
    template<typename S> struct Tag_Printable<S, decltype((void)(cerr << declval<S>()))> : true_type {};
    template<typename S, typename T = void> struct Tag_Iterable: false_type {};
    template<typename S> struct Tag_Iterable<S, decltype((void)(begin(declval<S>()), end(declval<S>())))> : true_type {};
    template<typename T, typename... Args>
    Debug& print(T const&x, true_type, Args...){
        #ifdef LOCAL_RUN
        if(enabled){
            cerr << boolalpha << x;
        }
        #endif // LOCAL_RUN
        return *this;
    }
    template<typename T>
    Debug& print(T const&x, false_type, true_type){
        *this << "[";
        bool first = true;
        for(auto &e:x){
            if(!first) *this << ", ";
            *this << e;
            first = false;
        }
        return *this << "]";
    }
    template<typename S, typename T>
    Debug& print(pair<S, T> const&x, false_type, false_type){
        return *this << "(" << x.first << ", " << x.second << ")";
    }
    template<typename T>
    Debug& operator<<(T const&x){
        return print(x, Tag_Printable<T>{}, Tag_Iterable<T>{});
    }
};
 Debug<true> debug;
// Debug<false> debug; // disable debug printing
#define named(x) string(#x) << " : " <<  x


template<typename traits>
class Mod_Int{
public:
    using int_t = typename traits::int_t;
    using long_t = typename traits::long_t;
    static constexpr int_t mod(){ return traits::get_mod(); };


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
    int_t const& get_value (){
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
    Mod_Int operator*(Mod_Int const&o) const {
        Mod_Int ret(mod_full(value * static_cast<long_t>(o.value)));
        return ret;
    }
    Mod_Int& operator*=(Mod_Int const&o){
        return *this = *this * o;
    }
    Mod_Int inv() const {
        return inv_impl(value);
    }
    Mod_Int operator/(Mod_Int const&o) const {
        return operator*(o.inv());
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

using num = Mod_Int<fixed_mod<998244353>>;

const int S = 62;
array<array<array<num, S>, S>, 11> pool;
array<array<num, S>, S> cnt;

array<array<array<num, S>, S>, S> tri;

num dp_0(){
    for(int b=0;b<S;++b){
        for(int c=0;c<=b;++c){
            for(int d=0;d<=c;++d){
                tri[b][c][d] = 0;
                for(int a=0;a<S;++a){
                    tri[b][c][d] += cnt[b][a] * cnt[c][a] * cnt[d][a];
                }
            }
        }
    }
    array<num, 8> perm;
    for(int i=0;i<8;++i){
        array<int, 4> tmp;
        for(int j=0;j<3;++j){
            tmp[j+1] = tmp[j] + !((i>>j)&1);
        }
        perm[i] = 0;
        do{
            ++perm[i];
        }while(next_permutation(tmp.begin(), tmp.end()));
    }
    num ret;
    for(int a=0;a<S;++a){
        for(int b=0;b<=a;++b){
            for(int c=0;c<=b;++c){
                const int i = (a==b)<<2 | (b==c)<<1;
                for(int d=0;d<=c;++d){
                    ret += perm[i|(c==d)]*tri[a][b][c]*tri[a][b][d]*tri[a][c][d]*tri[b][c][d];
                }
            }
        }
    }

    return ret;
}


void solve(){
    /// SOLVE HERE

    for(auto &e:pool) for(auto &f:e) fill(f.begin(), f.end(), 0);

    int n;
    cin >> n;
    vector<string> v;
    for(int i=0;i<n;++i){
        string s;
        cin >> s;
        v.push_back(s);
        reverse(s.begin(), s.end());
        v.push_back(s);
        //pool[s.size()][s[0]-'a'][s.back()-'a'] += 1;
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    auto decode = [](char const& c){
        if (c >= 'a') return c-'a';
        if(c >= 'A') return c-'A' + ('z'-'a'+1);
        return 52 + c-'0';
    };
    for(auto const&s:v){
        pool[s.size()][decode(s[0])][decode(s.back())] += 1;
    }
    num ans = 0;
    for(int l=3;l<11;++l){
        cnt = pool[l];
        num now = dp_0();
        ans += now;
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
    cin.tie(0); ios_base::sync_with_stdio(false);
    int TTT; cin >> TTT;
	if(TTT < 0) return gen(-TTT);
	while(TTT--){
    #else
    cin.tie(0); ios_base::sync_with_stdio(false);
    #endif // LOCAL_RUN

    solve();

    #ifdef LOCAL_RUN
    cout << flush;
    }
    #endif // LOCAL_RUN
    return 0;
}