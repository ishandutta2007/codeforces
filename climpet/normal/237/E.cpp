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
#include <cassert>
using namespace std;


typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;


#define MAX_V 200
#define INF INT_MAX

struct edge{ int to, cap, cost, rev; };

int V;
vector<edge> G[MAX_V];
int dist[MAX_V];
int prevv[MAX_V], preve[MAX_V];

void add_edge(int from, int to, int cap, int cost){
assert(from < V && to < V);
    G[from].push_back((edge){to, cap, cost, G[to].size()});
    G[to].push_back((edge){from, 0, -cost, G[from].size() - 1});
}

int min_cost_flow(int s, int t, int f){
    int res = 0;
    while(f > 0){
        fill(dist, dist + V, INF);
        dist[s] = 0;
        bool update = true;
        while(update){
            update = false;
            for(int v = 0; v < V; ++v){
                if(dist[v] == INF) continue;
                for(int i = 0; i < G[v].size(); ++i){
                    edge &e = G[v][i];
                    if(e.cap > 0 && dist[e.to] > dist[v] + e.cost){
                        dist[e.to] = dist[v] + e.cost;
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        update = true;
                    }
                }
            }
        }
        
        if(dist[t] == INF){
            return -1;
        }
        
        int d = f;
        for(int v = t; v != s; v = prevv[v]){
            d = min(d, G[prevv[v]][preve[v]].cap);
        }
        f -= d;
        res += d * dist[t];
        for(int v = t; v != s; v = prevv[v]){
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
    return res;
}


int cnt[26] = {};


int main(){
    string s;
    int n, a;
    cin >> s >> n;
    int len = s.size();

    V = n + 30;

    for(int i = 0; i < len; ++i){
        ++cnt[s[i] - 'a'];
    }
    for(int i = 0; i < 26; ++i){
        if( cnt[i] ){
            add_edge(i + 2, 1, cnt[i], 0);
        }
    }

    for(int i = 0; i < n; ++i){
        cin >> s >> a;
        memset(cnt, 0, sizeof(cnt));

        for(int j = 0; j < s.size(); ++j){
            ++cnt[s[j] - 'a'];
        }
        for(int j = 0; j < 26; ++j){
            if( cnt[j] ){
                add_edge(i + 28, j + 2, cnt[j], i + 1);
            }
        }
        
        add_edge(0, i + 28, a, 0);
    }
    
    cout << min_cost_flow(0, 1, len) << endl;
}