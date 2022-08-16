#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx,avx2,fma,tune=native") // codeforces

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


#ifdef LOCAL_RUN
//constexpr int M = 100;
constexpr int M = 2e5 + 10;
#else
constexpr int M = 2e5 + 10;
#endif // LOCAL_RUN

constexpr int off = 5;

void solve(){
    /// SOLVE HERE

    int n, k;
    cin >> n >> k;
    int m = min(n/2+5, k);
    if(m%2 != k%2) ++m;
    k = m;

    bitset<M> b, e, u, v, last;

    string s;
    cin >> s;
    for(int i=0;i<n;++i){
        if(s[i] == 'W'){
            b[i+off] = 1;
        }
    }
    for(int it=0;it<k;++it){
        //debug << named(b) << "\n";
        b[off-1] = b[off+n-1];
        b[off-2] = b[off+n-2];
        b[off+n+0] = b[off+0];
        b[off+n+1] = b[off+1];
        //debug << named(b) << "\n";
        //e = ~b;
        u = b;
        u <<= 1;
        v = b;
        v>>=1;
        e = u;
        e|=v;
        u&=v;
        //debug << named(e) << "\n";
        b = (b & e) | (u);
        if((k-it)%2){
            if(it > 3 && b == last) break;
            last = b;
        }
    }
    //debug << named(b) << "\n";
    for(int i=0;i<n;++i){
        if(b[i+off]){
            s[i] = 'W';
        } else {
            s[i] = 'B';
        }
    }
    cout << s << "\n";


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