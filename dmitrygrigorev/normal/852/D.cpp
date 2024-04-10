#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <fstream>
#include <bitset>
#include <time.h>
#include <queue>
#include <deque>
#define int long long
using namespace std;
struct Edge{int to; int f; int c; int tr;};
vector<Edge> edges;
vector<vector<int> > dat;
vector<vector<int> > data, money;
int v, e, n, k, ai, bi, ci;
vector<int> good, us, d;
queue<int> q;
int dijkstra[200][600];
int INF = 1e15;
int dfs(int vertex, int flow){
    if (flow == 0 || vertex == us.size() - 1) return flow;
    while (us[vertex] < dat[vertex].size()){
		int num = dat[vertex][us[vertex]];
        if (edges[num].c == edges[num].f || d[vertex] + 1 != d[edges[num].to]){
            us[vertex]++;
            continue;
        }
        int nw = dfs(edges[num].to, min(flow, edges[num].c - edges[num].f));
        if (nw > 0){
            edges[num].f += nw;
            edges[num^1].f -= nw;
            return nw;
        }
        us[vertex]++;
    }
    return 0;
}
void bfs(){
    while (!q.empty()){
        int v = q.front();
        q.pop();
        for (int i=0; i < dat[v].size(); i++){
			int num = dat[v][i];
            if (edges[num].f < edges[num].c && d[edges[num].to] == -1){
                d[edges[num].to] = d[v] + 1;
                q.push(edges[num].to);
            }
        }
    }
}
int dinic(){
    int res = 0;
    while (true){
        while (q.size() > 0) q.pop();
        for (int i=0; i < d.size(); i++){
            d[i] = -1;
        }
        d[0] = 0;
        q.push(0);
        bfs();
        if (d.back() == -1) return res;
        for (int i=0; i < us.size(); i++){
            us[i] = 0;
        }
        while (true){
            int fl = dfs(0, 1e18);
            if (fl == 0) break;
            res += fl;
        }
    }
}
bool check(int number){
    edges.clear();
    for (int i=0; i < us.size(); i++){
        dat[i].clear();
    }
    for (int i=0; i < n; i++){
        Edge e1 = {i+1, 0, 1};
		Edge e2 = {0, 0, 0};
		edges.push_back(e1);
		edges.push_back(e2);
		dat[0].push_back(edges.size() - 2);
		dat[i+1].push_back(edges.size() - 1);
    }
    int last = us.size() - 1;
    for (int i=0; i < v; i++){
        Edge e1 = {last, 0, 1};
		Edge e2 = {i+n+1, 0, 0};
		edges.push_back(e1);
		edges.push_back(e2);
		dat[i+n+1].push_back(edges.size() - 2);
		dat[last].push_back(edges.size() - 1);
    }
    for (int i=0; i < n; i++){
        for (int j=0; j < v; j++){
            if (dijkstra[i][j] <= number){
                Edge e1 = {j+n+1, 0, 1};
                Edge e2 = {i+1, 0, 0};
                edges.push_back(e1);
                edges.push_back(e2);
                dat[i+1].push_back(edges.size() - 2);
                dat[j+n+1].push_back(edges.size() - 1);
            }
        }
    }
    int result = dinic();
    if (result >= k) return true;
    return false;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> v >> e >> n >> k;
    for (int i=0; i < v; i++){
        vector<int> h1, h2;
        data.push_back(h1);
        money.push_back(h2);
    }
    for (int i=0; i < n; i++){
        cin >> ai;
        good.push_back(ai-1);
    }
    for (int i=0; i < e; i++){
        cin >> ai >> bi >> ci;
        data[ai-1].push_back(bi-1);
        data[bi-1].push_back(ai-1);
        money[ai-1].push_back(ci);
        money[bi-1].push_back(ci);
    }
    for (int i=0; i < n; i++){
        set<pair<int, int> > ms;
        for (int j=0; j < v; j++){
            if (j == good[i]){
               dijkstra[i][j] = 0;
            }
            else dijkstra[i][j] = INF;
            ms.insert(make_pair(dijkstra[i][j], j));
        }
        while (!ms.empty()){
            set<pair<int, int> >::iterator it = ms.begin();
            pair<int, int> p = *it;
            ms.erase(it);
            int vv = p.second;
            for (int j=0; j < data[vv].size(); j++){
                int to = data[vv][j];
                int relax = dijkstra[i][vv] + money[vv][j];
                if (relax < dijkstra[i][to]){
                    set<pair<int, int> >::iterator it1 = ms.upper_bound(make_pair(dijkstra[i][to], to-1));
                    ms.erase(it1);
                    dijkstra[i][to] = relax;
                    ms.insert(make_pair(relax, to));
                }
            }
        }
    }
    int MAX = 1731311;
    int left = -1;
    int right = MAX+1;
    int NUM = v + n + 2;
    for (int i=0; i < NUM; i++){
        us.push_back(-1);
        vector<int> b;
        dat.push_back(b);
        d.push_back(-1);
    }
    while (right - left > 1){
        int mid = (left + right) / 2;
        bool res = check(mid);
        if (res) right = mid;
        else left = mid;
    }
    if (right == MAX+1){
        cout << -1 << endl;
    }
    else cout << right << endl;
    return 0;
}