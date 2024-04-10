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


#define MAX_V 300010

int V;
vector<int> G[MAX_V], rG[MAX_V];
vector<int> vs;
bool used[MAX_V];
int cmp[MAX_V];
VV(int) nG;

void add_edge(int from, int to){
    G[from].push_back(to);
    rG[to].push_back(from);
}

void dfs(int v){
    used[v] = true;
    for(size_t i = 0; i < G[v].size(); ++i){
        if( !used[ G[v][i] ] )  dfs( G[v][i] );
    }
    vs.push_back(v);
}

void rdfs(int v, int k){
    used[v] = true;
    cmp[v] = k;

    for(size_t i = 0; i < rG[v].size(); ++i){
        if( !used[ rG[v][i] ] ) rdfs( rG[v][i], k );
    }
}

int scc(){
    vs.clear();
    
    memset(used, 0, sizeof(used));
    for(int v = 0; v < V; ++v){
        if( !used[v] ) dfs(v);
    }

    memset(used, 0, sizeof(used));
    int k = 0;
    for(int i = vs.size() - 1; i >= 0; --i){
        if( !used[ vs[i] ] ) rdfs(vs[i], k++);
    }
    return k;
}


map<string,int> mp;
int getidx(string &s){
    for(char &c : s){
        c = tolower(c);
    }
    return mp.insert(make_pair(s, (int)mp.size())).first->second;
}
vector<pii> scr;
vector<pii> memo;

pii dfs2(int u){
    pii &r = memo[u];
    if(r.first >= 0){ return r; }
    r = scr[u];
    for(int v : nG[u]){
        pii p = dfs2(v);
        r = min(r, p);
    }
    return r;
}


int main(){
    ios::sync_with_stdio(false);
    
    int m, n;
    cin >> m;
    vector<int> ws(m);
    string x, y;
    for(int i = 0; i < m; ++i){
        cin >> x;
        ws[i] = getidx(x);
    }
    
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> x >> y;
        int u = getidx(x), v = getidx(y);
        add_edge(u, v);
    }
    
    V = mp.size();
    
    int nsc = scc();
    nG.resize(nsc);
    for(int u = 0; u < V; ++u){
        for(int v : G[u]){
            nG[cmp[u]].push_back(cmp[v]);
        }
    }
    
    scr.assign(nsc, pii(INT_MAX, INT_MAX));
    memo.assign(nsc, pii(-1, -1));
    for(cauto p : mp){
        int r = count(ALL(p.first), 'r');
        int c = p.first.size();
        pii &q = scr[cmp[p.second]];
        q = min(q, pii(r, c));
    }
    
    LL res1 = 0, res2 = 0;
    for(int i = 0; i < m; ++i){
        pii p = dfs2(cmp[ws[i]]);
        res1 += p.first;
        res2 += p.second;
    }
    cout << res1 << ' ' << res2 << endl;
}