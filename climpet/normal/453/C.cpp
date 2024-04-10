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


vector<int> cv;
VV(int) g;
vector<int> ans;
vector<int> pr;

int dfs1(int u){
    int t = pr[u];
    for(int v : g[u]){
        t += dfs1(v);
    }
    cv[u] = t;
    return t;
}

void dfs2(int u){
    ans.push_back(u);
    for(int v : g[u]){
        if(cv[v] % 2 == 0){
            ans.push_back(v);
            ans.push_back(u);
        }
        dfs2(v);
        ans.push_back(u);
    }
}


int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    VV(int) G0(n + 1);
    for(int i = 0; i < m; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        G0[a].push_back(b);
        G0[b].push_back(a);
    }
    pr.resize(n + 1);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &pr[i]);
    }

    queue<int> q;
    VV(int) vs;
    vector<char> vis(n + 1);
    vector<int> par(n + 1, -1);
    for(int f = 1; f <= n; ++f)
    if(!vis[f]){
        q.push(f);
        vis[f] = 1;
        vector<int> z;
        int c = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            z.push_back(u);
            c += pr[u];
            for(int v : G0[u]){
                if(!vis[v]){
                    vis[v] = 1;
                    par[v] = u;
                    q.push(v);
                }
            }
        }
        
        if(c){
            vs.push_back(move(z));
        }
    }

    if(vs.empty()){
        puts("0");
    }
    else if(vs.size() > 1){
        puts("-1");
    }
    else{
        cv.assign(n + 1, 0);
        g.resize(n + 1);
        for(size_t i = 1; i < vs[0].size(); ++i){
            int u = vs[0][i];
            g[par[u]].push_back(u);
        }
        int a = dfs1(vs[0][0]);
        dfs2(vs[0][0]);
        if(a % 2 == 0){
            ans.pop_back();
        }
        printf("%d\n", (int)ans.size());
        for(size_t i = 0; i < ans.size(); ++i){
            printf("%d%c", ans[i], i + 1 == ans.size() ? '\n' : ' ');
        }
    }
}