    // Why do I need to ternarize and shave off a log factor?
    //#pragma GCC optimize("O3")
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
    // Debug<true> debug;
     Debug<false> debug; // disable debug printing
    #define named(x) string(#x) << " : " <<  x


    template<typename T>
    struct Small_Set{
        array<T, 5> data;
        int size = 0;
        T max(){
            return *max_element(data.begin(), data.begin()+size);
        }
        bool empty(){
            return size == 0;
        }
        void insert(T const&x){
            data[size++] = x;
        }
        void erase(T const&x){
            auto i = find(data.begin(), data.end(), x) - data.begin();
            --size;
            swap(data[i], data[size]);
        }
    };
    struct LL{
        ll val;
        int index;
        bool operator<(LL const&o) const{
            return make_pair(val, index) < make_pair(o.val, o.index);
        }
        bool operator==(LL const&o) const {
            return make_pair(val, index) == make_pair(o.val, o.index);
        }
        friend ostream& operator<<(ostream&o, LL const&a){
            return o << "(" << a.val << "," << a.index << ")";
        }
    };
    LL operator+(LL const&a, ll const&x){
        return LL{a.val+x, a.index};
    }
    LL operator+(ll const&x, LL const&a){
        return a+x;
    }

    constexpr ll inf = 2e18;

    struct Agg{
        LL pre, suff;
        ll sum;
        int id;
        Small_Set<LL> passive_ch;
        LL ch_max(){
            return passive_ch.empty() ? LL{0, id} : passive_ch.max();
        }
    };
    const Agg NONE {LL{-inf, -1}, LL{-inf, -1}, 0, -1, {}};
    // Link-cut tree with path aggregates
    #define lct_assert(x) assert(x)
    struct LinkCutTree{
        struct Node{
            Node*p=0, *pp=0, *c[2]={0, 0};
            int id;
            bool ev=0;
            ll agg;
            Agg sub_agg;
            LL pp_up_val;
            Node(int _id=-1):id(_id), agg(0), sub_agg{LL{0,id}, LL{0,id}, 0, id, {}} {}
            void recalc(){
                //assert(!ev);
                auto L = c[0] ? c[0]->sub_agg : NONE;
                auto R = c[1] ? c[1]->sub_agg : NONE;
                if(c[0] && c[0]->ev) swap(L.pre,L.suff);
                if(c[1] && c[1]->ev) swap(R.pre,R.suff);
                sub_agg.sum = L.sum + agg + R.sum;
                sub_agg.pre = max({
                                  L.pre,
                                  L.sum + agg + sub_agg.ch_max(),
                                  L.sum + agg + R.pre
                                  });
                sub_agg.suff = max({
                                   L.suff + agg + R.sum,
                                   sub_agg.ch_max() + agg + R.sum,                               R.suff
                                   });

                for(int i:{0, 1})
                    if(c[i]){
                        c[i]->p=this;
                    }
            }
            template<bool do_recalc>
            LL get_upval() {
                if(do_recalc) pp_up_val = ev ? sub_agg.suff : sub_agg.pre;
                return pp_up_val;
                //return ev ? sub_agg.suff : sub_agg.pre;
            }
            void add_passive_ch(LL x){
                //debug << "Add " << id << " : " << x << "\n";
                sub_agg.passive_ch.insert(x);
                recalc();
            }
            void rem_passive_ch(LL x){
                //debug << "Rem " << id << " : " << x << "\n";
                sub_agg.passive_ch.erase(x);
                recalc();
            }
            void push(){
                if(ev){
                    ev=0;
                    swap(sub_agg.pre, sub_agg.suff);
                    swap(c[0], c[1]);
                    for(int i:{0, 1})
                        if(c[i]) c[i]->ev^=1;
                }
            }
            void unlink(int i){
                lct_assert(c[i]);
                c[i]->p=0;
                c[i]=0;
                recalc();
            }
            int up(){return p?p->c[1]==this:-1;}
            void rot(){
                swap(pp, p->pp);
                swap(pp_up_val, p->pp_up_val);
                int i = up(), j=p->up();
                p->c[i]=c[!i];
                c[!i]=p; p=p->p;
                if(p) p->c[j]= this;
                c[!i]->recalc(); recalc();
                if(p) p->recalc();
            }
            Node* splay(){
                for(push();p;){
                    if(p->p) p->p->push();
                    p->push(); push();
                    if(p->up()==up())
                        p->rot();
                    rot();
                }
                return this;
            }
            Node*first(){
                push();
                return c[0]?c[0]->first():splay();
            }
        };
        vector<Node> g;
        LinkCutTree(size_t N){
            g.reserve(N);
            for(size_t i=0;i<N;++i)
                g.emplace_back(i);
        }
        bool connected(int u, int v){
            Node*x = access(&g[u])->first();
            Node*y = access(&g[v])->first();
            return x==y;
        }
        void link(int u, int p){
            assert(0 <= u && u <(int)g.size());
            lct_assert(!connected(u, p));
            make_root(&g[u]);
            g[u].pp=&g[p];
            g[p].add_passive_ch(g[u].get_upval<true>());
        }
        void cut_up(int u){
            Node*x = &g[u];
            access(x);
            x->unlink(0);
        }
        /*void cut(int u, int v){
            lct_assert(connected(u, v));
            Node*x = &g[u],*y=&g[v];
            make_root(x); make_root(y);
            x->splay();
            lct_assert(x->pp?y==x->pp:(y==x->c[0] || (x->c[0] && y==x->c[0]->c[0])));
            if(x->pp) x->pp=0;
            else x->unlink(0);
        }*/
        void make_root(Node*u){
            access(u);
            u->ev^=1;
            access(u);
        }
        /// TODO
        Node*access(Node*x){
            Node*u = x;
            u->splay();
            while(Node*pp=u->pp){
                pp->splay();
                u->pp=0;
                pp->rem_passive_ch(u->get_upval<false>());
                if(pp->c[1]){
                    pp->add_passive_ch(pp->c[1]->get_upval<true>());
                    swap(pp->c[1]->p,pp->c[1]->pp);
                }
                pp->c[1]=u;
                pp->recalc();
                u=pp;
            }
            x->splay();
            if(x->c[1]){
                x->add_passive_ch(x->c[1]->get_upval<true>());
                x->c[1]->pp=x;
                x->unlink(1);
            }
            return u;
        }
        /*int lca(int u, int v){
            access(&g[u]);
            return access(&g[v])->id;
        }
        pair<int, int> pathagg(int u, int v){
            make_root(&g[u]);
            access(&g[v]);
            return g[v].sub_agg;
        }*/
    	void set_agg(int u, ll const& new_agg){
    		access(&g[u]);
    		g[u].agg = new_agg;
    		g[u].recalc();
    	}
    	LL get_subagg_pre(int u){
            make_root(&g[u]);
            auto const ret = g[u].get_upval<true>();
            debug << u << ": " << ret << "\n";
            return ret;
    	}
    };


    void solve(){
        /// SOLVE HERE

        int n, q;
        ll w;
        cin >> n >> q >> w;
        LinkCutTree lct(4*n);

        vector<vector<int> > g(n+1);


        for(int i=1;i<n;++i){
            int a, b;
            ll c;
            cin >> a >> b >> c;
            const int u = n+i;
            g[a].push_back(u);
            g[b].push_back(u);
            lct.set_agg(u, c);
            //lct.link(a, u);
            //lct.link(b, u);
        }
        const int k = 3;
        int pool = 2*n;
        for(int i=1;i<=n;++i){
            int x = i;
            for(int j=0;j<(int)g[i].size();++j){
                if((j+1) % k == 0){
                    lct.link(x, ++pool);
                    x = pool;
                }
                lct.link(x, g[i][j]);
            }
        }
        // no idea why this fixes stuff xD
        for(int i=n;i<2*n;++i){
            lct.access(&lct.g[i]);
        }

        int u = 1;
        ll last = 0;
        for(int it=0;it<q;++it){
            int d;
            ll e;
            cin >> d >> e;
            d = (d+last)%(n-1)+1;
            e = (e+last)%w;
            lct.set_agg(n+d, e);
            debug << "Query: " << d << " " << e << "\n";
            for(int it=0;it<2;++it){
                auto tmp = lct.get_subagg_pre(u);
                u = tmp.index;
                assert(u != -1);
                last = tmp.val;
            }
            cout << last << "\n";
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