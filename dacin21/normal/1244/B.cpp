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



void s2(){
    /// SOLVE HERE
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(s == string(n, '0')){
        cout << n << "\n";
        return;
    }
    const int L = 10;
    array<ll, L> w;
    {
        int i = 0;
        while(s[i] == '0') ++i;
        int j = n-1;
        while(s[j] == '0') --j;
        if(i == j){
            int l = max(i, n-1-j);
            cout << 2*(l+1) << "\n";
            return;
        }
        w[0] = w[1] = (i);
        w[2] = w[3] = 1;
        w[4] = w[5] = (j-i-1);
        w[6] = w[7] = 1;
        w[8] = w[9] = n-j-1;
    }
    array<bitset<L>, L> g{};
    for(int i=0;i+2<L;++i){
        g[i][i+2] = g[i+2][i] = 1;
    }
    g[2][3] = g[3][2] = 1;
    g[6][7] = g[7][6] = 1;
    array<array<ll, L>, (1<<L)> dp{};
    for(int i=0;i<L;++i){
        dp[1<<i][i] = w[i];
    }
    for(int m=0;m<(1<<L);++m){
        for(int i=0;i<L;++i){
            if((m>>i)&1){
                for(int j=0;j<L;++j){
                    if(!((m>>j)&1) && g[i][j]){
                        xmax(dp[m | (1<<j)][j], dp[m][i] + w[j]);
                    }
                }
            }
        }
    }
    ll ans = 0;
    for(auto &e:dp){
        xmax(ans, *max_element(e.begin(), e.end()));
    }
    cout << ans << "\n";



}

void solve(){
    int T;
    cin >> T;
    while(T--){
        s2();
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