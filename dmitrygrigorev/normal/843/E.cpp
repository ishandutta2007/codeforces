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
#include <ctime>
#include <math.h>
#include <fstream>
#include <bitset>
#include <queue>
#define int long long
using namespace std;
struct Edge{int to; int f; int c; int tr;};
vector<Edge> edges;
vector<vector<int> > data, dd, rev;
vector<bool> used;
vector<int> good_edge, answer;
vector<int> us, d;
queue<int> q;
set<int> good;
int n, m, s, t, u, v, g;
int INF = 1e9;
bool up(int vertex, vector<int> &vv){
	used[vertex] = true;
	if (vertex == s-1){
        for (int i=0; i < vv.size(); i++){
            good_edge.push_back(vv[i]);
        }
        return true;
	}
	for (int i=0; i < rev[vertex].size(); i++){
		int to = rev[vertex][i];
		int go = edges[to].to;
		if (used[go]) continue;
		vv.push_back(edges[to].tr);
		bool rr = up(go, vv);
		vv.pop_back();
		if (rr) return true;
	}
	return false;
}
bool down(int vertex, vector<int> &vv){
	used[vertex] = true;
	if (vertex == t-1){
        for (int i=0; i < vv.size(); i++){
            good_edge.push_back(vv[i]);
        }
        return true;
	}
	for (int i=0; i < dd[vertex].size(); i++){
		int to = dd[vertex][i];
		int go = edges[to].to;
		if (used[go]) continue;
		vv.push_back(edges[to].tr);
		bool rr = down(go, vv);
		vv.pop_back();
		if (rr) return true;
	}
	return false;
}
int dfs(int vertex, int flow){
    if (flow == 0 || vertex == t - 1) return flow;
    while (us[vertex] < data[vertex].size()){
		int num = data[vertex][us[vertex]];
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
        for (int i=0; i < data[v].size(); i++){
			int num = data[v][i];
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
        d[s-1] = 0;
        q.push(s-1);
        bfs();
        if (d[t-1] == -1) return res;
        for (int i=0; i < us.size(); i++){
            us[i] = 0;
        }
        while (true){
            int fl = dfs(s-1, 1e18);
            if (fl == 0) break;
            res += fl;
        }
    }
}
void dfsf(int vertex){
    used[vertex] = true;
    good.insert(vertex);
    for (int i=0; i < data[vertex].size(); i++){
		int to = data[vertex][i];
		if (used[edges[to].to]) continue;
		if (edges[to].f == edges[to].c) continue;
		dfsf(edges[to].to);
    }
}
int32_t main(){
    cin >> n >> m >> s >> t;
    for (int i=0; i < n; i++){
		vector<int> help, hh, hhh;
		data.push_back(help);
		rev.push_back(hhh);
		dd.push_back(hh);
		used.push_back(false);
		us.push_back(-1);
		d.push_back(-1);
    }
    vector<vector<int> > e;
    for (int i=0; i < m; i++){
		cin >> u >> v >> g;
		if (g == 0) g = INF;
		else{
            dd[u-1].push_back(edges.size());
            rev[v-1].push_back(edges.size() + 1);
		}
		Edge e1 = {v-1, 0, g, i};
		Edge e2 = {u-1, 0, 0, i};
		edges.push_back(e1);
		edges.push_back(e2);
		data[u-1].push_back(edges.size() - 2);
		data[v-1].push_back(edges.size() - 1);
		if (g == 1){
			Edge e3 = {v-1, 0, 0, i};
			Edge e4 = {u-1, 0, INF, i};
			edges.push_back(e3);
			edges.push_back(e4);
			data[u-1].push_back(edges.size() - 2);
			data[v-1].push_back(edges.size() - 1);
		}
		vector<int> h;
		h.push_back(u);
		h.push_back(v);
		if (g == INF) g = 0;
		h.push_back(g);
		e.push_back(h);
    }
    cout << dinic() << endl;
    for (int i=0; i < e.size(); i++){
		answer.push_back(0);
    }
    for (int i=0; i < e.size(); i++){
		if (e[i][2] == 0) continue;
		vector<int> vv;
		fill(used.begin(), used.end(), false);
        bool res = up(e[i][0] - 1, vv);
        fill(used.begin(), used.end(), false);
        bool res2 = down(e[i][1] - 1, vv);
        if (res && res2){
            good_edge.push_back(i);
            for (int j=0; j < good_edge.size(); j++){
				answer[good_edge[j]]++;
            }
        }
        else{
			answer[i] = 1;
        }
        good_edge.clear();
    }
    fill(used.begin(), used.end(), false);
    good.insert(s-1);
    dfsf(s-1);
    set<int> reb;
    for (int i=0; i < e.size(); i++){
		if (e[i][2] == 0) continue;
		if (good.count(e[i][0]-1) && !good.count(e[i][1]-1)){
			reb.insert(i);
		}
    }
    for (int i=0; i < e.size(); i++){
        if (reb.count(i)) cout << answer[i] << " " << answer[i] << endl;
        else cout << answer[i] << " " << 1000000000 << endl;
    }
	return 0;
}