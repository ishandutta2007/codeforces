#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") // codeforces

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
//using fl = long double;
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
mt19937 rng(std::chrono::duration_cast<std::chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());

template<typename cap_t, typename excess_t, bool global_relabeling = true, bool min_cut_only = false, bool shuffle_edges = true>
class Push_Relabel{
public:
    struct Edge{
        int to, rev;
        cap_t f;
    };

    Push_Relabel(int n_):n(n_), m(0){}

    void add_edge(int u, int v, cap_t c, cap_t c_rev = 0){
        edge_pool.emplace_back(u, v, c, c_rev);
        ++m;
    }
    excess_t max_flow(int s_, int t_){
        s = s_; t = t_;
        run_pr();
        return excess[t]-1;
    }

//private:
    void compile_g(){
        g_pos.resize(n+1);
        if(shuffle_edges) shuffle(edge_pool.begin(), edge_pool.end(), rng);
        for(auto &e:edge_pool){
            ++g_pos[get<0>(e)];
            ++g_pos[get<1>(e)];
        }
        for(int i=0;i<n;++i){
            g_pos[i+1]+=g_pos[i];
        }
        g.resize(g_pos.back());
        for(auto &e:edge_pool){
            int u, v; cap_t c, c_rev;
            tie(u, v, c, c_rev) = e;
            const int i = --g_pos[u], j = --g_pos[v];
            g[i] = Edge{v, j, c};
            g[j] = Edge{u, i, c_rev};
        }
    }
    void global_relabel(){
        q.reserve(n);
        fill(h.begin(), h.end(), n);
        fill(h_cnt.begin(), h_cnt.end(), 0);
        h_cnt[n] = 1;
        q.push_back(t);
        h[t] = 0;
        for(auto &e:buck) e.clear();
        for(auto &e:buck_all) e.clear();
        for(auto it = q.begin();it<q.end();++it){
            const int u = *it;
            if(u != t && excess[u]){
                hi = h[u];
                buck[h[u]].push_back(u);
            }
            if(u != t) buck_all[h[u]].push_back(u);
            ++h_cnt[h[u]];
            for(int i = g_pos[u],i_end = g_pos[u+1];i < i_end;++i){
                Edge const&e = g[i];
                if(g[e.rev].f && h[e.to] == n){
                    h[e.to] = h[u]+1;
                    q.push_back(e.to);
                }
            }
        }
        hi_all = h[q.back()];
        assert(h[s] == n);
        q.clear();
    }
    void push(int u, Edge &e, excess_t f){
        if(!excess[e.to]){
            buck[h[e.to]].push_back(e.to);
        }
        Edge&back = g[e.rev];
        e.f-=f;
        back.f+=f;
        excess[e.to]+=f;
        excess[u]-=f;
    }
    void init_pr(){
        compile_g();
        cur.assign(n, 0);
        copy(g_pos.begin(), prev(g_pos.end()), cur.begin());
        h.resize(n);
        excess.assign(n, 0);
        buck.resize(2*n);
        buck_all.resize(n+1);
        h_cnt.assign(2*n, 0);
        h[s] = n;
        h_cnt[n] = 1;
        h_cnt[0] = n-1;
        excess[t] = 1;
    }
    void run_pr(){
        init_pr();
        for(int i = g_pos[s],i_end = g_pos[s+1];i < i_end;++i){
            push(s, g[i], g[i].f);
        }
        hi = hi_all = 0;
        if(global_relabeling) {
            global_relabel();
            for(int i=0; i<n; ++i){
                if(i != s && h[i] == n && excess[i]){
                    buck[n].push_back(i);
                    hi = n;
                }
            }
        }
        if(!buck[hi].empty())
        for(;hi>=0;){
            int u = buck[hi].back(); buck[hi].pop_back();
            int u_cur = cur[u];
            //discharge
            if(!min_cut_only || h[u] < n)
            while(excess[u] > 0){
                if(__builtin_expect(u_cur == g_pos[u+1], false)){
                    int new_h = 1e9;
                    for(int i = g_pos[u],i_end = g_pos[u+1];i < i_end;++i){
                        auto const&e = g[i];
                        if(e.f && new_h > h[e.to]+1){
                            new_h = h[e.to]+1;
                            u_cur = i;
                        }
                    }
                    ++h_cnt[new_h];
                    h[u] = new_h;
                    if(__builtin_expect(!--h_cnt[hi] && hi < n, false)){
                        // gap relabel
                        for(int j = hi;j <= hi_all;++j){
                            for(auto &f:buck_all[j]) if(!min_cut_only || h[f] < n){
                                --h_cnt[h[f]];
                                h[f] = n+1;
                            }
                            buck_all[j].clear();
                        }
                    }
                    hi = h[u];
                } else {
                    Edge &e_cur = g[u_cur];
                    if(e_cur.f && h[u] == h[e_cur.to]+1){
                        push(u, e_cur, min<excess_t>(excess[u], e_cur.f));
                    } else ++u_cur;
                }
            }
            if(h[u] < n) {
                hi_all = max(hi_all, h[u]);
                buck_all[h[u]].push_back(u);
            }
            cur[u] = u_cur;
            while(hi>=0 && buck[hi].empty()) --hi;
        }
    }

    int n, m, s, t, hi, hi_all;
    vector<tuple<int, int, cap_t, cap_t> > edge_pool;
    vector<int> g_pos;
    vector<Edge> g;
    vector<int> q, cur, h, h_cnt;
    vector<excess_t> excess;
    vector<vector<int> > buck, buck_all;
};
struct Upflow{
    struct Edge{
        uint32_t val;
        uint32_t to() const {
            return val&((1u<<17)-1);
        }
        uint32_t f() const {
            return val >> 17;
        }
        void set_f(uint32_t v) {
            val = to()|v<<17;
        }
        void operator+=(int const&o){
            set_f(f()+o);
        }
    };
    template<typename T>
    Upflow(T& pr, int s_, int t_) : flow(pr.max_flow(s_, t_)), s(s_), t(t_), n(pr.n), g(2*pr.m), rev(2*pr.m), g_pos(pr.g_pos), vis(n){
        for(int i=0; i<2*pr.m; ++i){
            g[i].val = pr.g[i].to;
            g[i].set_f(pr.g[i].f);
            rev[i] = pr.g[i].rev;
        }
    }
    bool rec_old(int u){
        if(u==t) return true;
        vis[u] = 1;
        for(int j = g_pos[u], j_end = g_pos[u+1]; j!=j_end; ++j){
            auto &e = g[j];
            if(e.f() && !vis[e.to()]){
                vis[e.to()]=1;
                if(rec(e.to())){
                    e+=-1;
                    g[rev[j]]+=1;
                    return true;
                }
            }
        }
        return false;
    }
    bool rec(int u){
        int b = 0;
        sta[0].first = u;
        vis[u]=1;
        while(b>=0){
            u = sta[b].first;
            if(u<0) { --b; continue;}
            if(__builtin_expect(u == t, false)){
                sta[b].first=-1-u;
                goto yes;
            }
            sta[b].first=-1-u;
            for(auto *a = g.data()+g_pos[u], *aa = g.data()+g_pos[u+1]; a!=aa; ++a){
                auto const&e = *a;
                if((bool)e.f() & !vis[e.to()]){
                    vis[e.to()]=1;
                    sta[++b] = make_pair(e.to(), a-g.data());
                }
            }
        }
        return false;
        yes:
        for(int i=1; i<=b; ++i){
            auto const&e = sta[i];
            if(e.first<0){
                g[e.second]+=-1;
                g[rev[e.second]]+=1;
            }
        }
        return true;
    }
    void calc(){
        sta.resize(n+5);
        do{
            ++flow;
            fill(vis.begin(), vis.end(), 0);
        } while(rec(s));
        --flow;
    }

    int flow;
    int s, t, n;
    vector<Edge> g;
    vector<pair<int, int> > sta;
    vector<int> rev;
    vector<int> g_pos;
    vector<char> vis;
};


int n, m, k, q;
vector<Upflow> flows;
vector<int> ind;
vector<int> ans;

void rec(int d, uint32_t m, Upflow fl){
    if(d == k){
        ans[m] = fl.flow;
        return;
    }
    Upflow next = fl;
    next.g[ind[d]]+=25;
    next.calc();
    rec(d+1, m|(1u<<d), move(next));
    rec(d+1, m, move(fl));
}


void solve(){
    /// SOLVE HERE
    cin >> n >> m >> k >> q;
    vector<pair<int, int> > ed;
    Push_Relabel<int, int> pr(n);
    for(int i=0; i<m; ++i){
        int a, b, c;
        cin >> a >> b >>c;
        --a; --b;
        if(i<k) ed.emplace_back(a, b);
        pr.add_edge(a, b, c);
    }
    Upflow fl(pr, 0, n-1);
    ind.resize(k);
    for(int i=0; i<k; ++i){
        const int u = ed[i].first;
        const int v = ed[i].second;
        for(int j=pr.g_pos[u], j_end = pr.g_pos[u+1]; j<j_end; ++j){
            if(pr.g[j].to == v){
                ind[i]=j;
                break;
            }
        }
    }
    debug << named(ind) << "\n";
    ans.resize(1<<k);
    rec(0, 0, fl);
    vector<int> cap(1<<k), w(k);
    for(int it=0; it<q; ++it){
        for(auto &e:w) cin >> e;
        int out = ans.back();
        for(int i=1; i<(1<<k); ++i){
            const int j = __builtin_ctz(i);
            cap[i] = cap[i^(1<<j)] + w[j];
            out = min(out, cap[i]+ans[(1<<k)-1-i]);
        }
        cout << out << "\n";
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
    //freopen("02.01.in", "r", stdin);
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
    cout << endl;
    }
    #endif // LOCAL_RUN
    return 0;
}