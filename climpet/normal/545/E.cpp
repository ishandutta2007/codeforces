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

struct edge{
    int t;
    LL c;
    int i;
    edge(int t_, LL c_, int i_) : t(t_), c(c_), i(i_) {}
};

struct state{
    LL d, c;
    int u, i;
    state(LL d_, LL c_, int u_, int i_)
    : d(d_), c(c_), u(u_), i(i_) {}
    bool operator< (const state &s) const{
        return pll(d, c) > pll(s.d, s.c);
    }
};

void mainmain(){
    int n, m, start;
    scanf("%d%d", &n, &m);
    VV(edge) G(n + 1);
    for(int i = 1; i <= m; ++i){
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        G[x].emplace_back(y, z, i);
        G[y].emplace_back(x, z, i);
    }
    scanf("%d", &start);

    LL sum = 0;
    vint ans;
    priority_queue<state> pq;
    vector<char> vis(n + 1);
    pq.emplace(0, 0, start, 0);
    while(!pq.empty()){
        state st = pq.top();
        pq.pop();
        if(vis[st.u]){ continue; }
        vis[st.u] = 1;
        sum += st.c;
        if(st.i){ ans.push_back(st.i); }
        for(cauto e : G[st.u]){
            pq.emplace(st.d + e.c, e.c, e.t, e.i);
        }
    }
    
    char spl = '\n';
    printf("%I64d", sum);
    for(int x : ans){
        printf("%c%d", spl, x);
        spl = ' ';
    }
    puts("");
}



}
int main() try{
//  ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(4);
    mainmain();
}
catch(...){}