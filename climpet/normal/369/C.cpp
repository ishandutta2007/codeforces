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
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define PB push_back


#define MOD 1000000009LL
#define EPS 1e-8


vint xs, ys, ts;
VV(int) G;
vint vis;
vint ans;


bool dfs(int u, bool need){
    vis[u] = 1;
    bool rp = false;

    for(int i = 0; i < G[u].size(); ++i){
        int e = G[u][i];
        int v = xs[e] ^ ys[e] ^ u;
        if(vis[v]){ continue; }
        rp |= dfs(v, ts[e] == 2);
    }
    
    if(need && !rp){
        ans.push_back(u);
        rp = true;
    }
    
    return rp;
}


int main(){
    int n;
    scanf("%d", &n);
    xs.resize(n - 1);
    ys = ts = xs;
    G.resize(n + 1);
    for(int i = 0; i < n - 1; ++i){
        scanf("%d%d%d", &xs[i], &ys[i], &ts[i]);
        G[xs[i]].push_back(i);
        G[ys[i]].push_back(i);
    }

    vis.resize(n + 1);
    dfs(1, false);

    printf("%d\n", (int)ans.size());
    for(int i = 0; i < ans.size(); ++i){
        if(i){ putchar(' '); }
        printf("%d", ans[i]);
    }
    puts("");
}