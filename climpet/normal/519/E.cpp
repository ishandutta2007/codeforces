#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
#include <numeric>
#include <list>
#include <iomanip>

#if __cplusplus >= 201103L
#include <array>
#include <tuple>
#include <initializer_list>
#include <unordered_set>
#include <unordered_map>
#include <forward_list>

#define cauto const auto&
#define ALL(v) begin(v),end(v)
#else
#define ALL(v) (v).begin(),(v).end()
#endif

using namespace std;


namespace{
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

#define VV(T) vector<vector< T > >

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
    v.assign(a, vector<T>(b, t));
}

template <class F, class T>
void convert(const F &f, T &t){
    stringstream ss;
    ss << f;
    ss >> t;
}


#define REP(i,n) for(int i=0;i<int(n);++i)
#define RALL(v) (v).rbegin(),(v).rend()


#define MOD 1000000007LL
#define EPS 1e-8


struct lca_struct{
    vector<vector<int> > parent;
    vector<int> depth;
    vector<vector<int> > G;

    lca_struct(){}
    explicit lca_struct(const vector<int> &par){
        init(par);
    }
    lca_struct(const vector<vector<int> > &graph, int root){
        init(graph, root);
    }

    size_t size() const{
        return depth.size();
    }

    // root = -1  ->  forest
    void init(const vector<vector<int> > &graph, int root){
        int n = graph.size();
        int log_v = 32 - __builtin_clz(n | 1);
        parent.assign(log_v, vector<int>(n, -1));
        depth.assign(n, -1);
        G = graph;
        if(root < 0){
            for(int i = 0; i < n; ++i){
                if(depth[i] < 0){ dfs1(i, -1, 0); }
            }
        }
        else{
            dfs1(root, -1, 0);
        }

        vector<vector<int> >().swap(G);
        doubling();
    }
    void dfs1(int v, int p, int d){
        parent[0][v] = p;
        depth[v] = d;
        for(size_t i = 0; i < G[v].size(); ++i){
            int c = G[v][i];
            if(c != p){
                dfs1(c, v, d + 1);
            }
        }
    }

    void init(const vector<int> &par){
        int n = par.size();
        int log_v = 32 - __builtin_clz(n | 1);
        parent.assign(log_v, vector<int>(n, -1));
        depth.assign(n, -1);
        parent[0] = par;
        for(int i = 0; i < n; ++i){
            if(depth[i] < 0){
                dfs2(i);
            }
        }
        doubling();
    }
    int dfs2(int v){
        if(parent[0][v] < 0){
            depth[v] = 0;
        }
        else{
            depth[v] = dfs2(parent[0][v]) + 1;
        }
        return depth[v];
    }

    void doubling(){
        int n = depth.size();
        int log_v = parent.size();
        for(int k = 0; k + 1 < log_v; ++k){
            for(int v = 0; v < n; ++v){
                if(parent[k][v] < 0){ parent[k + 1][v] = -1; }
                else{ parent[k + 1][v] = parent[k][parent[k][v]]; }
            }
        }
    }

    int operator() (int u, int v) const{
        int log_v = parent.size();
        if(depth[u] > depth[v]){ swap(u, v); }
        for(int k = 0; k < log_v; ++k){
            if((depth[v] - depth[u]) >> k & 1){
                v = parent[k][v];
            }
        }
        if(u == v){ return u; }
        for(int k = log_v - 1; k >= 0; --k){
            if(parent[k][u] != parent[k][v]){
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }
};

lca_struct lca;
VV(int) children;
vint tsz;
void dfs3(int u){
    tsz[u] = 1;
    for(int v : children[u]){
        dfs3(v);
        tsz[u] += tsz[v];
    }
}

int levelanc(int u, int d){
    for(int i = lca.parent.size(); i--; ){
        if(d >> i & 1){ u = lca.parent[i][u]; }
    }
    return u;
}

void mainmain(){
    int n;
    scanf("%d", &n);
    VV(int) G(n);
    for(int i = 1; i < n; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        --a; --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    lca.init(G, 0);
    children.resize(n);
    for(int i = 1; i < n; ++i){
        children[lca.parent[0][i]].push_back(i);
    }
    tsz.resize(n);
    dfs3(0);
    int m;
    scanf("%d", &m);
    for(int i = 0; i < m; ++i){
        int u, v;
        scanf("%d%d", &u, &v);
        --u; --v;
        int ans = 0;
        if(u == v){ ans = n; }
        else if(!((lca.depth[u] + lca.depth[v]) & 1)){
            if(lca.depth[u] < lca.depth[v]){
                swap(u, v);
            }
            int a = lca(u, v);
            if(lca.depth[u] == lca.depth[v]){
                int d = lca.depth[u] - lca.depth[a];
                int w1 = levelanc(u, d - 1), w2 = levelanc(v, d - 1);
                ans = n - tsz[w1] - tsz[w2];
            }
            else{
                int d = ((lca.depth[u] + lca.depth[v] - 2 * lca.depth[a]) >> 1);
                int w = levelanc(u, d - 1);
                ans = tsz[lca.parent[0][w]] - tsz[w];
            }
        }
        printf("%d\n", ans);
    }
}



}
int main() try{
//  ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(4);
    mainmain();
}
catch(...){}