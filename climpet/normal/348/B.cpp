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
#include <cassert>

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

const LL INF = (LL)1e15;

inline LL gcd(LL x, LL y){
    while(y){
        LL r = x % y;
        x = y;
        y = r;
    }
    return x;
}

inline LL safemul(LL x, LL y){
    if(x <= INF / y){
        return x * y;
    }
    return INF;
}

inline LL lcm(LL x, LL y){
    return safemul(x, y / gcd(x, y));
}

vll as;
VV(int) G;
vint vis;

pll dfs(int u){
    vis[u] = 1;
    
    LL cm = 1;
    int numch = 0;
    LL minval = LLONG_MAX;
    for(int v : G[u]){
        if(vis[v]){ continue; }
        pll p = dfs(v);
        ++numch;
        minval = min(minval, p.first);
        cm = lcm(cm, p.second);
    }
    
    if(!numch){
        return pll(as[u], 1);
    }

    LL sum = minval / cm * cm * numch;
    LL t = safemul(cm, numch);

    return pll(sum, t);
}

void mainmain(){
    int n;
    cin >> n;
    as.resize(n);
    LL sum = 0;
    for(LL &x : as){
        cin >> x;
        sum += x;
    }
    G.resize(n);
    for(int i = 1; i < n; ++i){
        int x, y;
        cin >> x >> y;
        G[x - 1].push_back(y - 1);
        G[y - 1].push_back(x - 1);
    }
    vis.assign(n, 0);
    pll res = dfs(0);
    LL ans = sum - res.first;
    cout << ans << endl;
}



}
int main() try{
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(4);
    mainmain();
}
catch(...){}