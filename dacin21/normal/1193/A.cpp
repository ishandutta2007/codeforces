#undef _GLIBCXX_DEBUG
//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx,avx2,fma,tune=native") // codeforces

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
    int_t const& get_value(){
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

template<typename Int, size_t MAXN = 32>
struct Chroma{
    using Graph = vector<bitset<MAXN> >;
    static Graph build_graph(const int n, vector<pair<int, int> > const&ed){
        Graph ret(n);
        for(auto const&e:ed){
            ret[e.first][e.second] = ret[e.second][e.first] = 1;
        }
        return ret;
    }
    static Graph delete_vertex(Graph const&g, int const v){
        const int n = g.size();
        Graph ret(n-1);
        for(int j=0;j<n-1;++j){
            for(int k=0;k<n-1;++k){
                ret[j][k] = g[j + (j>=v)][k + (k>=v)];
            }
        }
        return ret;
    }
    static Graph contract_edge(Graph const&g, int u, int v){
        const int n = g.size();
        Graph ret(n-1);
        if(u > v) swap(u, v);
        for(int j=0;j<n;++j){
            int a = j<v ? j : j==v ? u : j-1;
            for(int k=0;k<n;++k){
                int b = k<v ? k : k==v ? u : k-1;
                if(g[j][k] && a != b) ret[a][b] = 1;
            }
        }
        return ret;
    }

    static Int binom(int n, int k){
        if(n<0) return 0;
        if(n-k < k) k = n-k;
        if(k < 0) return 0;
        Int ret{1};
        for(int i=0;i<k;++i) {
            ret *= n-i;
            ret /= i+1;
        }
        return ret;
    }

    static void bitflip(vector<Int> &v){
        int n = v.size();
        for(int i=1, j=0;i<n;++i){
            int m = n >> 1;
            for(;j>=m;m >>= 1)
                j -= m;
            j += m;
            if(i < j) std::swap(v[i], v[j]);
        }
    }

    /// Fast Möbius Transform.
    /// turns or convolution into point-wise multiplication
    template<bool inverse>
    static void fmt(vector<Int> &vec){
        const int n = vec.size();
        for(int iter=1, sh=0;iter<n;iter*=2, ++sh){
            for(int x=0;x<n;x+=2*iter){
                for(int y=0;y<iter;++y){
                    Int v = vec[x+y], w=vec[x+y+iter];
                    vec[x+y+iter] = inverse ? w-v : v+w;
                }
            }
        }
    }

    // O(n^3 2^n)
    static array<Int, 32> count_colorings_multi(Graph g){
        using int_t = typename Int::int_t;
        using long_t = typename Int::long_t;
        const int n = g.size();
        if(!n){
            array<Int, 32> ans;
            fill(ans.begin(), ans.end(), Int{1});
            return ans;
        }
        vector<vector<Int> > f(n+1, vector<Int>(1<<n));
        for(int m=1;m<(1<<n);++m){
            bitset<32> bi(0);
            bool fail = false;
            for(int i=0;i<n;++i)
                if((m>>i)&1){
                    if(bi[i]) fail=true;
                    bi|=g[i];
                }
            if(!fail){
                f[__builtin_popcount(m)][m] = 1;
            }
        }
        for(auto &e:f){
            fmt<false>(e);
        }
        decltype(f) f_cur(n+1, vector<Int>(1<<n));
        auto f_next = f_cur;
        f_cur[0][0] = 1;
        fmt<false>(f_cur[0]);
        array<Int, 32> ans{};
        vector<long_t> tmp(1<<n);
        const int_t mod = Int::mod();
        const long_t modmod = Int::mod() * (long_t) Int::mod();
        for(int i=0;i<n;++i){
            for(int j=0;j<=n;++j){
                auto &e = f_next[j];
                fill(tmp.begin(), tmp.end(), 0);
                for(int k=0;k<=j;++k){
                    for(int l=0;l<(1<<n);++l){
                        tmp[l] += f_cur[j-k][l].get_value()*(long_t)f[k][l].get_value();
                        if(tmp[l] >= modmod) tmp[l]-=modmod;
                    }
                }
                for(int l=0;l<(1<<n);++l){
                    e[l] = tmp[l] % mod;
                }
            }
            f_next.swap(f_cur);
            auto cnts = f_cur[n];
            fmt<true>(cnts);
            for(int j=0;j<32;++j){
                ans[j] += binom(j, i+1)*cnts.back();
            }
        }
        return ans;
    }
    static Int count_colorings(Graph g, int c){
        const int n = g.size();
        auto tmp = count_colorings_multi(g);
        if(0 <= c && c < (int)tmp.size()) return tmp[c];
        // polynomial interpolation
        Int ret = 0;
        for(int i=0;i<=n;++i){
            Int prod = tmp[i];
            for(int j=0;j<=n;++j) if(j != i){
                prod *= (c<0 ? -Int(-c) : Int(c)) - Int(j);
                prod /= Int(i) - Int(j);
            }
            ret += prod;
        }
        return ret;
    }
};

const int V = 20;


void solve(){
    /// SOLVE HERE

    int n, m;
    cin >> n >> m;
    /*vector<vector<num> > cost(n, vector<num>(n));
    for(int i=0;i<m;++i){
        int a, b, c;
        cin >> a >> b >> c;
        cost[b][a] = 1;
    }*/
    vector<pair<int, int> > ed;
    for(int i=0;i<m;++i){
        int a, b;
        cin >> a >> b;
        --a; --b;
        ed.emplace_back(a, b);
    }
    // polynomial interpolation
    num ret = Chroma<num>::count_colorings(Chroma<num>::build_graph(n, ed), -1);
    if(n%2){
        ret = -ret;
    }
    ret *= m;
    ret /= 2;
    cout << ret << "\n";


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