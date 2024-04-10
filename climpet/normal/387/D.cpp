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


#include <vector>
#include <cstring>
using namespace std;

#define MAX_V 1100

int V = MAX_V;
vector<int> G[MAX_V];
int match[MAX_V];
bool used[MAX_V];

void init(){
    for(int i = 0; i < MAX_V; ++i){
        G[i].clear();
    }
}

void add_edge(int u, int v){
    G[u].push_back(v);
    G[v].push_back(u);
}

bool dfs(int v){
    used[v] = true;
    for(int i = 0; i < G[v].size(); ++i){
        int u = G[v][i], w = match[u];
        if( w < 0 || !used[w] && dfs(w) ){
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

int bipartite_matching(){
    int res = 0;
    memset(match, -1, sizeof(match));
    for(int v = 0; v < V; ++v){
        if( match[v] < 0 ){
            memset(used, 0, sizeof(used));
            if( dfs(v)){
                ++res;
            }
        }
    }
    return res;
}




int main(){
    int n, m, a, b;
    scanf("%d%d", &n, &m);
    VV(int) edge;
    initvv(edge, n + 1, n + 1);
    for(int i = 0; i < m; ++i){
        scanf("%d%d", &a, &b);
        edge[a][b] = 1;
    }
    
    int ans = INT_MAX;
    for(int t = 1; t <= n; ++t){
        int cnt = !edge[t][t];
        for(int i = 1; i <= n; ++i){
            if(i != t){
                cnt += !edge[i][t] + !edge[t][i];
            }
        }

        init();
        int e = 0;
        for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j){
            if(i != t && j != t && edge[i][j]){
                ++e;
                add_edge(i, j + 510);
            }
        }
        
        int bm = bipartite_matching();
        cnt += (e - bm) + (n - 1 - bm);
        ans = min(ans, cnt);
    }
    
    printf("%d\n", ans);
}