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


// All directions DP in O(n)
template<typename Traits>
class All_Directions_DP{
public:
    using Val = typename Traits::Val;

    All_Directions_DP(int n_) : n(n_), d(n), up(n), down(n), vertex(n){
        pre.reserve(n);
        suff.reserve(n);
    }
    void run(vector<vector<int> > g_){
        g = move(g_);
        dfs_1<true>(0, -1);
        dfs_2<true>(0, -1);
    }

    Val const& get_edge_val(int a, int b){
        return d[a] < d[b] ? down[a] : up[b];
    }
    Val const& get_vertex_val(int u){
        return vertex[u];
    }

private:
    template<bool is_root>
    void dfs_1(int u, int p){
        if(!is_root){
            up[u] = Traits::init(u, p);
            d[u] = d[p]+1;
            rotate(g[u].begin(), find(g[u].begin(), g[u].end(), p), g[u].end());
        } else {
            d[u] = 0;
        }
        for(auto &e:g[u]) if(e != p){
            dfs_1<false>(e, u);
            if(!is_root){
                up[u] = Traits::merge(up[u], up[e]);
            }
        }
        if(!is_root){
            Traits::post_edge(up[u], u, p);
        }
    }
    template<bool is_root>
    void dfs_2(int u, int p){
        const int k = g[u].size();
        pre.assign(k+1, Traits::neutral());
        suff.assign(k+1, Traits::neutral());
        if(!is_root){
            pre[1] = suff[0] = down[u];
        }
        for(int i=!is_root; i<k; ++i){
            auto const e = g[u][i];
            pre[i+1] = suff[i] = up[e];
        }
        Traits::full_vertex(pre); // NEW
        for(int i=1; i<=k; ++i){
            pre[i] = Traits::merge(pre[i-1], pre[i]);
        }
        vertex[u] = pre.back();
        Traits::post_vertex(vertex[u], u);
        for(int i=k-1; i>=0; --i){
            suff[i] = Traits::merge(suff[i], suff[i+1]);
        }
        for(int i=!is_root; i<k; ++i){
            auto const e = g[u][i];
            down[e] = Traits::merge(Traits::init(u, e), Traits::merge(pre[i], suff[i+1]));
            Traits::post_edge(down[e], u, e);
        }
        for(auto const&e:g[u]) if(e != p){
            dfs_2<false>(e, u);
        }
    }

    int n;
    vector<vector<int> > g;
    vector<int> d;
    vector<Val> up, down, pre, suff, vertex;
};

// Subset sum with integers weights
// Implementation uses std::bitset and compresses equal weights
// For items with total weight S, this runs in O(S^{1.5} / 64)
// (Use Jensen to avoid a factor of log S.)
struct Subset_Sum{
    struct Item{
        int weight;
        int id;
        bool operator<(Item const&o) const {
            return make_pair(weight, id) < make_pair(o.weight, o.id);
        }
    };
    struct Ret{
        vector<int> possible;
    };
    Subset_Sum(vector<int> w) : Subset_Sum(to_items(move(w))) {}
    Subset_Sum(vector<Item> items_) : n(items_.size()), items(move(items_)) {}

    Ret solve(int goal_weight){
        sort(items.begin(), items.end());
        return solve_find_impl<>(goal_weight);
    }

private:
    // Used to find a near optimal bitset size
    // Higher values of log_W will exceed the stack limit or hang the compiler.
    template<size_t log_W=29>
    Ret solve_find_impl(int goal_weight){
        if(log_W >= 4 && !(goal_weight >> log_W)){
            return solve_find_impl<log_W - (log_W>=4) >(goal_weight);
        }
        return solve_impl<log_W+1>(goal_weight);
    }
    // implementation in separate function to avoid unused bitsets on the stack frames of solve_find_impl
    template<size_t log_W>
    Ret solve_impl(int goal_weight){
        constexpr int W = 1<<log_W;
        assert(goal_weight < W);
        using bset = bitset<W>;

        bset possible(1);
        vector<pair<int, int> > from(W);

        auto process_step = [&](int weight, int step){
            if(weight*(int64_t)step < W){
                bset added = possible<<(weight*step);
                added &= ~possible;
                possible |= added;
                for(int i=added._Find_first();i<W;i = added._Find_next(i)){
                    from[i] = make_pair(weight, step);
                }
            }
        };
        auto process = [&](int weight, int cnt){
            // compress, keeping at most 2 copies of each power of 2
            for(int step = 1;cnt;){
                cnt-=step;
                process_step(weight, step);
                if(!(cnt&step)) step*=2;
            }
        };
        int run = 0;
        for(int i=0; i<n; ++i){
            ++run;
            // batch equal items
            if(i+1 == n || items[i].weight != items[i+1].weight){
                process(items[i].weight, run);
                run = 0;
            }
        }
        vector<int> out;
        for(int i=0; i<goal_weight; ++i){
            if(possible[i]) out.push_back(i);
        }
        return Ret{out};
    }
    static vector<Item> to_items(vector<int> w){
        vector<Item> ret(w.size());
        for(int i=0; i<(int)w.size(); ++i){
            ret[i].id = i;
            ret[i].weight = w[i];
        }
        return ret;
    }
    int n;
    vector<Item> items;
};

ll out;

// Example: Sum of distances for each vertex
struct AD_Traits{
    struct Val{
        int siz;
        ll total;
    };
    ///using Val = int;

    static Val neutral(){
        return Val{0, 0};
    }
    // edge a -> b
    static Val init(int a, int b){
        return Val{1, 0};
    }
    static Val merge(Val const&a, Val const&b){
        return Val{a.siz+b.siz, a.total+b.total};
    }
    static void post_edge(Val &v, int a, int b){
        v.total += v.siz;
    }
    static void post_vertex(Val &v, int a){
    }
    static void full_vertex(vector<Val> v){
        int total_size = 0, max_size = 0;
        ll total = 0;
        vector<int> ws;
        for(Val const&e:v){
            total_size += e.siz;
            ws.push_back(e.siz);
            xmax(max_size, e.siz);
            total += e.total;
        }
        total += total_size+1;
        //cerr << total_size << " / " << max_size << " / " << total << "\n";
        if(2*max_size >= total_size){
            xmax(out, total + (total_size-max_size)*(ll)(max_size));
            return;
        }
        // subsetsum, yay
        Subset_Sum sum(ws);
        for(int s : sum.solve(total_size+2).possible){
            xmax(out, total + (total_size-s)*(ll)(s));
        }
    }
};



void solve(){
    /// SOLVE HERE
    out = 0;
    int n;
    cin >> n;
    All_Directions_DP<AD_Traits> dp(n);
    vector<vector<int> > g(n);
    for(int i=1; i<n; ++i){
        int u;
        cin >> u;
        --u;
        g[i].push_back(u);
        g[u].push_back(i);
    }
    dp.run(g);
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