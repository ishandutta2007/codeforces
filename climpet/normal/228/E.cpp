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
using namespace std;

#define MAX_V 200

int V;
vector<int> G[MAX_V], rG[MAX_V];
vector<int> vs;
bool used[MAX_V];
int cmp[MAX_V];

void add_edge(int from, int to){
    G[from].push_back(to);
    rG[to].push_back(from);
}

void dfs(int v){
    used[v] = true;
    for(int i = 0; i < G[v].size(); ++i){
        if( !used[ G[v][i] ] )  dfs( G[v][i] );
    }
    vs.push_back(v);
}

void rdfs(int v, int k){
    used[v] = true;
    cmp[v] = k;

    for(int i = 0; i < rG[v].size(); ++i){
        if( !used[ rG[v][i] ] ) rdfs( rG[v][i], k );
    }
}

int scc(){
    vs.clear();
    
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


int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    V = 2 * n;
    
    int a, b, c;
    for(int i = 0; i < m; ++i){
        scanf("%d%d%d", &a, &b, &c);
        --a;
        --b;
        
        if( c ){
            add_edge(a + n, b + n);
            add_edge(b, a);
            add_edge(a, b);
            add_edge(b + n, a + n);
        }
        else{
            add_edge(a, b + n);
            add_edge(b, a + n);
            add_edge(a + n, b);
            add_edge(b + n, a);
        }
    }
    
    scc();
    for(int i = 0; i < n; ++i){
        if(cmp[i] == cmp[i + n] ){
            puts("Impossible");
            return 0;
        }
    }
    
    vector<int> ans;
    for(int i = 0; i < n; ++i){
        if( cmp[i] > cmp[i + n] ){
            ans.push_back(i + 1);
        }
    }
    
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); ++i){
        if( i > 0 ) putchar(' ');
        printf("%d", ans[i]);
    }
    puts("");
}