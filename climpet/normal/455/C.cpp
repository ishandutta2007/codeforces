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


struct UF{
    vector<int> par;
    UF(int m) : par(m + 1){
        for(int i = 1; i <= m; ++i){
            par[i] = i;
        }
    }
    int find(int x){
        return x != par[x] ? par[x] = find(par[x]) : x;
    }
    void unite(int x, int y){
        par[find(x)] = find(y);
    }
};


VV(int) G;
pii dfs(int u, int p){
    pii r(0, u);
    for(int v : G[u]){
        if(v != p){
            pii t = dfs(v, u);
            ++t.first;
            r = max(r, t);
        }
    }
    return r;
}


int main(){
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    UF uf(n);
    G.resize(n + 1);
    for(int i = 0; i < m; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        uf.unite(a, b);
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> ds(n + 1);
    for(int i = 1; i <= n; ++i){
        if(uf.find(i) == i){
            pii r = dfs(i, -1);
            pii t = dfs(r.second, -1);
            ds[i] = t.first;
        }
    }
    
    for(int i = 0; i < q; ++i){
        int tp, x, y;
        scanf("%d%d", &tp, &x);
        if(tp == 1){
            int r = ds[uf.find(x)];
            printf("%d\n", r);
        }
        else{
            scanf("%d", &y);
            x = uf.find(x);
            y = uf.find(y);
            if(x != y){
                int a = ds[x], b = ds[y];
                uf.unite(x, y);
                int z = uf.find(x);
                ds[z] = max({a, b, (a + 1) / 2 + (b + 1) / 2 + 1});
            }
        }
    }
}