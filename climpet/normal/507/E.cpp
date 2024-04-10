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

void mainmain(){
    int n, m;
    scanf("%d%d", &n, &m);
    VV(pii) G(n + 1);
    vint as(m + 1), bs(m + 1), zs(m + 1), ns(m + 1);
    for(int i = 1; i <= m; ++i){
        int a, b, z;
        scanf("%d%d%d", &a, &b, &z);
        as[i] = a;
        bs[i] = b;
        zs[i] = z;
        G[a].emplace_back(b, i << 1 | z);
        G[b].emplace_back(a, i << 1 | z);
    }

    vint vis(n + 1, 1010101010);
    vint dp(n + 1, 1010101010);
    vector<pii> fr(n + 1);
    vis[1] = 0;
    dp[1] = 0;
    queue<int> q;
    q.push(1);
    q.push(-1);
    int tm = 1;
    int u;
    while(q.size() > 1){
        u = q.front();
        q.pop();
        if(u < 0){ q.push(-1); ++tm; continue; }
        for(cauto p : G[u]){
            int v = p.first;
            if(vis[v] < tm){ continue; }
            int c = dp[u] + (p.second & 1 ? -1 : 1);
            if(vis[v] != tm || dp[v] > c){
                if(vis[v] != tm){ q.push(v); }
                vis[v] = tm;
                dp[v] = c;
                fr[v] = pii(u, p.second >> 1);
            }
        }
    }

    u = n;
    while(u != 1){
        ns[fr[u].second] = 1;
        u = fr[u].first;
    }

    vint ans;
    for(int i = 1; i <= m; ++i){
        if(zs[i] != ns[i]){ ans.push_back(i); }
    }
    printf("%d\n", (int)ans.size());
    for(int x : ans){
        printf("%d %d %d\n", as[x], bs[x], ns[x]);
    }
}



}
int main() try{
    mainmain();
}
catch(...){}