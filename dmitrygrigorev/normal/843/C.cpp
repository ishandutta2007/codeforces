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
#include <queue>
#include <ctime>
#define int long long
using namespace std;
int INF = 1e18;
int maximum, n, ai, bi;
struct Vertex{int l; int r; int pr; int sz; int value; bool p;};
vector<Vertex> decart;
vector<vector<int> > data, ne, ans;
vector<pair<int, int> > edges;
vector<int> h, bases;
vector<bool> orient;
pair<int, int> SP = make_pair(-1, -1);
void update(int vertex){
    if (vertex == -1) return;
    int sz = 1;
    if (decart[vertex].l != -1){
        sz += decart[decart[vertex].l].sz;
    }
    if (decart[vertex].r != -1){
        sz += decart[decart[vertex].r].sz;
    }
    decart[vertex].sz = sz;
}
void push(int vertex){
    if (vertex == -1) return;
    if (!decart[vertex].p) return;
    decart[vertex].p = false;
    swap(decart[vertex].l, decart[vertex].r);
    if (decart[vertex].l != -1){
		decart[decart[vertex].l].p ^= 1;
    }
    if (decart[vertex].r != -1){
		decart[decart[vertex].r].p ^= 1;
    }
}
pair<int, int> split(int father, int number){
    if (father == -1) return SP;
    push(father);
    int l = 1;
    if (decart[father].l != -1){
        l += decart[decart[father].l].sz;
    }
    if (l <= number){
        pair<int, int> p = split(decart[father].r, number - l);
        decart[father].r = p.first;
        p.first = father;
        update(father);
        return p;
    }
    pair<int, int> p = split(decart[father].l, number);
    decart[father].l = p.second;
    p.second = father;
    update(father);
    return p;
}
int merg(int first, int second){
    push(first);
    push(second);
    if (first == -1) return second;
    if (second == -1) return first;
    if (decart[first].pr >= decart[second].pr){
        int v = merg(decart[first].r, second);
        decart[first].r = v;
        update(first);
        return first;
    }
    int v = merg(first, decart[second].l);
    decart[second].l = v;
    update(second);
    return second;
}
int dfs(int vertex, int last){
	int g = 1;
	for (int i=0; i < data[vertex].size(); i++){
		int to = data[vertex][i];
		if (last == to) continue;
        int num_e = ne[vertex][i];
        if (edges[num_e].first != vertex) orient[num_e] = false;
		g += dfs(to, vertex);
	}
	h[vertex] = g;
	return g;
}
int get_left(int vertex){
	push(vertex);
	if (decart[vertex].l == -1) return decart[vertex].value;
	return get_left(decart[vertex].l);
}
int get_right(int vertex){
	push(vertex);
	if (decart[vertex].r == -1) return decart[vertex].value;
	return get_right(decart[vertex].r);
}
void form(int vertex, int e, int last){
	int ff = vertex;
	Vertex v = {-1, -1, rand(), 1, e, false};
	decart.push_back(v);
	int num = decart.size() - 1;
	int lastv;
	for (int i=0; i < data[vertex].size(); i++){
		int to = data[vertex][i];
		if (last == to) continue;
		lastv = i;
	}
    for (int i=0; i < data[vertex].size(); i++){
		int to = data[vertex][i];
		if (last == to) continue;
		form(to, ne[vertex][i], vertex);
		if (i == lastv){
			num = merg(num, bases[to]);
			continue;
		}
		int me = get_right(num);
		int b = bases[to];
		decart[b].p ^= 1;
        int ed = get_left(b);
        int so;
        if (orient[ed]) so = edges[ed].second;
        else so = edges[ed].first;
        int drv;
        if (edges[me].first == vertex) drv = edges[me].second;
        else drv = edges[me].first;
        vector<int> help;
        help.push_back(drv);
        help.push_back(vertex);
        help.push_back(so);
        ans.push_back(help);
        if (edges[me].first == vertex){
			edges[me].first = so;
		}
		else edges[me].second = so;
		num = merg(num, b);
    }
    bases[vertex] = num;
}
void solve(int vertex, int sec){
	vector<int> sv;
	for (int i=0; i < data[vertex].size(); i++){
		int to = data[vertex][i];
		if (to == sec) continue;
		sv.push_back(to);
        form(data[vertex][i], ne[vertex][i], vertex);
	}
	if (sec != -1){
	for (int i=0; i < data[sec].size(); i++){
		int to = data[sec][i];
		if (to == vertex) continue;
		sv.push_back(to);
        form(data[sec][i], ne[sec][i], sec);
	}
	}
	for (int i=0; i < sv.size(); i++){
		int to = sv[i];
        int b = bases[to];
        int sz = decart[b].sz;
        if (sz <= 2) continue;
        pair<int, int> p = split(b, sz-1);
        pair<int, int> p1 = split(p.first, sz-2);
        int ov, ev;
        int N = decart[p.second].value;
        int V = decart[p1.second].value;
        if ((edges[N].first == edges[V].second) || (edges[N].second == edges[V].second)){
			ov = edges[V].second;
			ev = edges[V].first;
        }
        if ((edges[N].first == edges[V].first) || (edges[N].second == edges[V].first)){
			ev = edges[V].second;
			ov = edges[V].first;
        }
        b = p1.first;
        while (b != -1){
            pair<int, int> p = split(b, decart[b].sz - 1);
			b = p.first;
			int W = decart[p.second].value;
			if (edges[W].first == ev){
                vector<int> help;
                help.push_back(edges[W].second);
                help.push_back(edges[W].first);
                help.push_back(ov);
                ans.push_back(help);
                ev = edges[W].second;
			}
			else{
				vector<int> help;
                help.push_back(edges[W].first);
                help.push_back(edges[W].second);
                help.push_back(ov);
                ans.push_back(help);
                ev = edges[W].first;
			}
        }
	}
}
void get_centroid(int vertex){
	maximum = 0;
	int wh;
	for (int i=0; i < data[vertex].size(); i++){
		int to = data[vertex][i];
		int res = dfs(to, vertex);
		if (res > maximum){
			maximum = res;
			wh = to;
		}
	}
	int ll = vertex;
	while (maximum*2 >= n){
		int mm = 0, vv;
		for (int i=0; i < data[wh].size(); i++){
			int to = data[wh][i];
			if (to == ll) continue;
			if (h[to] > mm){
				mm = h[to];
				vv = to;
			}
		}
        maximum = mm;
        ll = wh;
        wh = vv;
	}
	dfs(ll, -1);
	int se = -1;
	for (int i=0; i < data[ll].size(); i++){
		int to = data[ll][i];
        if (2 * h[to] >= n){
			se = to;
        }
	}
    solve(ll, se);
}
int32_t main(){
    cin >> n;
    for (int i=0; i < n; i++){
		vector<int> help, hh;
		h.push_back(0);
		ne.push_back(hh);
		bases.push_back(-1);
		orient.push_back(true);
		data.push_back(help);
    }
    for (int i=0; i < n-1; i++){
		cin >> ai >> bi;
		data[ai-1].push_back(bi-1);
		data[bi-1].push_back(ai-1);
		ne[ai-1].push_back(i);
		ne[bi-1].push_back(i);
		edges.push_back(make_pair(ai-1, bi-1));
    }
    get_centroid(0);
    cout << ans.size() << endl;
    for (int i=0; i < ans.size(); i++){
		cout << ans[i][0] + 1 << " " << ans[i][1] + 1 << " " << ans[i][2] + 1 << endl;
    }
	return 0;
}