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



struct Range{
    ll l, r;
    ll sum(){
        return (r-l+1) * (r+l)/2;
    }
    bool empty(){
        return r-l+1 == 0;
    }
};

vector<pair<int, int> > out;

ll sub;

bool can(Range a, Range b, ll ma){
    if(ma < max(a.sum(), b.sum())) return false;
    return true;

}

void rec(Range a, Range b, ll ma){
    top:
    //cerr << a.l << " " << a.r << "\n";
    if(a.empty()){
        assert(b.empty());
        sub = ma;
        return;
    }
    if(can(Range{a.l+1, a.r}, Range{b.l, b.r-1}, ma-max(a.l, b.r))){
        out.emplace_back(a.l, b.r);
        ma = ma-max(a.l, b.r);
        a = Range{a.l+1, a.r};
        b = Range{b.l, b.r-1};
        goto top;
    }
    if(can(Range{a.l, a.r-1}, Range{b.l+1, b.r}, ma-max(a.r, b.l))){
        out.emplace_back(a.r, b.l);
        ma = ma-max(a.r, b.l);
        a = Range{a.l, a.r-1};
        b = Range{b.l+1, b.r};
        goto top;
    }
    if(can(Range{a.l, a.r-1}, Range{b.l, b.r-1}, ma-max(a.r, b.l))){
        out.emplace_back(a.r, b.r);
        ma = ma-max(a.r, b.l);
        a = Range{a.l, a.r-1};
        b = Range{b.l, b.r-1};
        goto top;
    }
    assert(0);
}

void solve(){
    /// SOLVE HERE
    ll n, k;
    cin >> n >> k;
    if(n * (n+1)/2 > k){
        cout << "-1\n";
        return;
    }

    out.clear();
    Range A{1, n}, B{1, n};
    rec(A, B, k);
    k-=sub;
    cout << k << "\n";
    for(auto &e:out) cout << e.first << " ";
    cout << "\n";
    for(auto &e:out) cout << e.second << " ";
    cout << "\n";
    ll su = 0;
    for(auto &e:out){
        su += max(e.first, e.second);
    }
    assert(su == k);
    //cerr << "sum: " << su << "\n";
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
    freopen("out.txt", "w", stdout);
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