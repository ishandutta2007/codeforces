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


struct Dsu{
    Dsu(int n_) : n(n_), p(n, -1) {}

    int f(int x){
        return p[x]<0 ? x : p[x] = f(p[x]);
    }
    void u(int a, int b){
        a=f(a);
        b=f(b);
        if(a!=b) p[a]=b;
    }

    int n;
    vector<int> p;
};

struct Dir{
    int dx=0;
    int dy=0;
};

Dir ccw90(Dir const&d){
    return Dir{-d.dy, d.dx};
}
Dir operator+(Dir const&a, Dir const&b){
    return Dir{a.dx+b.dx, a.dy+b.dy};
}

Dir get_dir(int d){
    switch(d){
        case 0:
            return Dir{-1, 0};
        case 1:
            return Dir{0, 1};
        case 2:
            return Dir{1, 0};
        case 3:
            return Dir{0, -1};
        default:
            assert(0);
            return Dir{};
    }
}


void solve(){
    /// SOLVE HERE

    int n, t;
    cin >> n >> t;
    vector<vector<int> > g(n);
    int m = 0;
    vector<pair<int, int> > encode;
    map<pair<int, int>, int> decode;

    auto dd = [&](int x, int y, Dir const&d) -> int{
        auto it = decode.find(make_pair(x+d.dx, y+d.dy));
        if(it == decode.end()) return -1;
        return it->second;
    };

    auto add = [&](int i, int x, int y){
        decode[make_pair(x, y)] = i;
        for(int dx = -1;dx<=1;++dx){
            for(int dy=-1;dy<=1;++dy){
                if(abs(dx) + abs(dy) >= 1){
                    auto it = decode.find(make_pair(x+dx, y+dy));
                    if(it != decode.end()){
                        g[i].push_back(it->second);
                        g[it->second].push_back(i);
                        ++m;
                    }
                }
            }
        }
    };

    for(int i=0;i<n;++i){
        int x, y;
        cin >> x >> y;
        encode.push_back({x, y});
        add(i, x, y);
    }

    vector<bool > vis_1(4*n);
    Dsu uni(4*n);

    auto do_edge = [&](int const x, int const y, int const d){
        int me = dd(x, y, Dir{});
        if(vis_1[4*me+d]) return;
        vis_1[4*me+d] = true;
        auto visit = [&](int u, int d_){
            vis_1[4*u+d_] = true;
            uni.u(4*me+d, 4*u+d_);
        };
        {
            // check two blocks touching
            Dir R = get_dir(d);
            int a = dd(x, y, R);
            if(a != -1){
                visit(a, (d+2)%4);
                return;
            }
        }
        // walk around face
        int X=x, Y=y, D=d;
        auto step = [&](Dir const&D_, int d_offset) -> bool{
            int b = dd(X, Y, D_);
            const int new_d = (D + d_offset)%4;
            if(b != -1){
                visit(b, new_d);
                X = X+D_.dx;
                Y = Y+D_.dy;
                D = new_d;
                return true;
            }
            return false;

        };
        debug << "GOGOGO " << x << " " << y << " " << d << "\n";
        do{
            debug << X << " " << Y << " " << D << "\n";
            auto R = get_dir(D);
            auto U = get_dir((D+3)%4);
            if(step(U+R, 1)){}
            else if(step(U, 0)){}
            else if(step(Dir{}, 3)){}
            else{assert(0);}
        } while(X!=x || Y!=y || D!=d);
    };
    for(auto const&e:decode) for(int i=0;i<4;++i){
        do_edge(e.first.first, e.first.second, i);
    }




    Dsu l(n);

    for(int i=0;i<n;++i){
        for(auto const&e:g[i]) if(e<i){
            l.u(i, e);
        }
    }

    for(int i=1;i<n;++i){
        if(l.f(0) != l.f(i)){
            cout << "NO\n";
            return;
        }
    }
    auto uni_ed = uni;

    vector<char> vis(n, 0);
    vector<bool> face_vis(4*n);
    vector<vector<int> > ch(4*n);
    for(int i=0;i<4*n;++i){
        ch[uni.f(i)].push_back(i/4);
    }
    // mark infinite face
    face_vis[uni.f(4*decode.begin()->second+0)] = true;


    auto remove = [&](int u){
        vis[u] = 1;
        for(int i=0;i<4;++i){
            uni_ed.u(4*u+i, 4*u);
        }
    };


    auto is_cut_vertex = [&](int u){
        array<array<char, 3>, 3> grid {};
        auto g = [&](Dir const&dir){
            return grid[dir.dx+1][dir.dy+1];
        };
        const int x = encode[u].first, y = encode[u].second;
        // get image of 3x3 grid
        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                const int a = dd(x, y, Dir{i-1, j-1});
                if(a != -1 && !vis[a]) grid[i][j] = 1;
            }
        }
        // case 1:
        // X-X
        // XuX
        // X-X

        for(int d=0;d<2;++d){
            if(uni_ed.f(4*u+d) == uni_ed.f(4*u+d+2)){
                auto U = get_dir(d);
                auto L = ccw90(U);
                auto D = ccw90(L);
                auto R = ccw90(D);
                if(g(L)|g(L+U)|g(L+D)){
                    if(g(R)|g(R+U)|g(R+D)){
                        return true;
                    }
                }
            }
        }
        // case 2:

        // X|X
        // -yX
        // XXX
        for(int d=0;d<4;++d){
            if(uni_ed.f(4*u+d) == uni_ed.f(4*u+(d+3)%4)){
                auto U = get_dir(d);
                auto L = ccw90(U);
                auto D = ccw90(L);
                auto R = ccw90(D);
                if(g(L+U)){
                    if(g(D+L)|g(D)|g(D+R)|g(R)|g(R+U)){
                        return true;
                    }
                }
            }
        }
        return false;
    };
    auto is_border = [&](int u){
        for(int i=0;i<4;++i){
            if(face_vis[uni.f(4*u+i)]) return true;
        }
        return false;
    };

    priority_queue<int> pq;
    for(int i=0;i<n;++i){
        if(is_border(i)){
            pq.emplace(i);
        }
    }
    vector<int> out;
    int last = -1;
    while(!pq.empty()){
        int u = pq.top();
        pq.pop();
        if(u==last) continue;
        last = u;
        if(vis[u]) continue;
        if(!is_border(u)) continue;
        if(is_cut_vertex(u)) continue;
        remove(u);
        out.push_back(u);
        for(int i=0;i<4;++i){
            if(face_vis[uni.f(4*u+i)]) continue;
            face_vis[uni.f(4*u+i)] = true;
            for(auto const&e:ch[uni.f(4*u+i)]) pq.emplace(e);
        }
        for(auto const&e:g[u]) pq.push(e);
    }
    assert((int)out.size() == n);
    reverse(out.begin(), out.end());
    cout << "YES\n";
    for(auto const&e:out){
        cout << e+1 << "\n";
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
        const int X = 10;
        const int n = get_rand(1, 50);

        o << n << " " << 2 << "\n";
        set<pair<int, int> > s;
        while((int)s.size() < n){
            s.emplace(get_rand(1, X), get_rand(1, X));
        }
        vector<pair<int, int> > out(s.begin(), s.end());
        shuffle(out.begin(), out.end(), rng);
        for(auto const&e:out){
            o << e.first << " " << e.second << "\n";
        }

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