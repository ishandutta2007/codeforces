#pragma GCC optimize("O3")
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

struct Fen{
    Fen(int n_) : n(n_+5) {}

    void u(int x, ll val){
        for(++x;x<n;x+=x&-x) v[x]+=val;
    }

    ll q(ll x){
        ll ret = 0;
        for(++x;x;x-=x&-x) ret+=v[x];
        return ret;
    }
    // sum on [a,b]
    ll q(ll a, ll b){
        return q(b) - q(a-1);
    }

    int n;
    vector<ll> v;
};

vector<int> p;
vector<vector<int> > ch;
vector<int> L, R;
vector<int> w, t;
int tim;

using Ret = unique_ptr<map<int, ll> >;

Ret merge(Ret a, Ret b){
    if(!a) return b;
    if(!b) return a;
    if(a->size() < b->size()) swap(a, b);
    for(auto const&e:*b) (*a)[e.first]+=e.second;
    return a;
}

Ret dfs(int u){
    L[u] = ++tim;
    Ret ret = nullptr;
    for(auto const&e:ch[u]) {
        auto tmp = dfs(e);
        ret = merge(move(ret), move(tmp));
    }
    if(!ret){
        ret = make_unique<Ret::element_type>();
    } else {
        auto it = ret->upper_bound(t[u]);
        ll sub = w[u];
        while(it != ret->end() && sub>0){
            if(it->second <= sub){
                sub -= it->second;
                auto it2 = next(it);
                ret->erase(it);
                it = it2;
            } else {
                it->second -= sub;
                sub = 0;
                ++it;
            }
        }
    }
    (*ret)[t[u]]+=w[u];
    R[u] = tim;
    return ret;
}

void solve(){
    /// SOLVE HERE
    int n, m, k;
    cin >> n >> m >> k;

    p.resize(n);
    ch.assign(n, decltype(ch)::value_type{});
    L.resize(n);
    R.resize(n);
    tim = -1;
    t.resize(n);
    w.resize(n);

    for(int i=1;i<n;++i){
        cin >> p[i];
        --p[i];
        ch[p[i]].push_back(i);
    }
    for(int i=0;i<m;++i){
        int v, d, W;
        cin >> v >> d >> W;
        --v;
        assert(w[v] == 0);
        w[v] = W;
        t[v] = d;
    }
    auto ans = dfs(0);
    ll out = 0;
    if(ans){
        for(auto const&e:*ans){
            out += e.second;
        }
    }
    cout << out << "\n";

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