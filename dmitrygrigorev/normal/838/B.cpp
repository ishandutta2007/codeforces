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
#define int long long
using namespace std;
int n, q, timer, ai, bi, ci;
vector<vector<int> > data;
vector<vector<int> > money;
vector<int> tin, tout, first, second, line, rmq, values, pushs, now;
vector<pair<int, int> > edges;
void dfs(int vertex, int dist){
    tin[vertex] = timer;
    timer++;
    line.push_back(dist + values[vertex]);
    first[vertex] = line.size() - 1;
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i];
        dfs(to, dist + money[vertex][i]);
    }
    tout[vertex] = timer;
    timer++;
    line.push_back(dist + values[vertex]);
    second[vertex] = line.size() - 1;
}
void create(int i, int l, int r){
    if (r- l == 1){
        rmq[i] = line[l];
        return;
    }
    int mid = (l + r) / 2;
    create(2*i+1, l, mid);
    create(2*i+2, mid, r);
    rmq[i] = min(rmq[2*i+1], rmq[2*i+2]);
}
void push(int i, int l, int r){
    if (l + 1 >= r) return;
    int p = pushs[i];
    rmq[2*i+1] += p;
    rmq[2*i+2] += p;
    pushs[2*i+1] += p;
    pushs[2*i+2] += p;
    pushs[i] = 0;
}
int get(int i, int l, int r, int ind){
    push(i, l, r);
    if (r - l == 1){
        return rmq[i];
    }
    int mid = (l + r) / 2;
    if (ind < mid) return get(2*i+1, l, mid, ind);
    else return get(2*i+2, mid, r, ind);
}
int get_big(int i, int l, int r, int l1, int r1){
    push(i, l, r);
    if (l1 >= r1) return 1e12;
    if (l1 == l && r1 == r){
        return rmq[i];
    }
    int mid = (l + r) / 2;
    return min(get_big(2*i+1, l, mid, l1, min(r1, mid)), get_big(2*i+2, mid, r, max(l1, mid), r1));
}
void change(int i, int l, int r, int l1, int r1, int vv){
    push(i, l, r);
    if (l1 >= r1) return;
    if (l == l1 && r == r1){
        rmq[i] += vv;
        pushs[i] += vv;
        return;
    }
    int mid = (l + r) / 2;
    change(2*i+1, l, mid, l1, min(r1, mid), vv);
    change(2*i+2, mid, r, max(l1, mid), r1, vv);
    rmq[i] = min(rmq[2*i+1], rmq[2*i+2]);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for (int i=0; i < n; i++){
        vector<int> h1, h2;
        data.push_back(h1);
        money.push_back(h2);
        tin.push_back(0);
        tout.push_back(0);
        first.push_back(0);
        second.push_back(0);
        values.push_back(0);
    }
    for (int i=0; i < n-1; i++){
        cin >> ai >> bi >> ci;
        edges.push_back(make_pair(ai, bi));
        now.push_back(ci);
        data[ai-1].push_back(bi-1);
        money[ai-1].push_back(ci);
    }
    for (int i=0; i < n-1; i++){
        cin >> ai >> bi >> ci;
        edges.push_back(make_pair(ai, bi));
        now.push_back(ci);
        values[ai-1] = ci;
    }
    timer = 0;
    dfs(0, 0);
    int sz = 2*n;
    for (int i=0; i < 4*sz; i++){
        rmq.push_back(0);
        pushs.push_back(0);
    }
    create(0, 0, sz);
    for (int i=0; i < q; i++){
        int t;
        cin >> t;
        if (t == 2){
            cin >> ai >> bi;
            ai--;
            bi--;
            if (tin[ai] <= tin[bi] && tout[ai] >= tout[bi]){
                cout << get(0, 0, sz, first[bi]) - get(0, 0, sz, first[ai]) - values[bi] + values[ai] << endl;
            }
            else{
                int r1 = get_big(0, 0, sz, first[ai], second[ai]+1);
                r1 -= get(0, 0, sz, first[ai]);
                r1 += values[ai];
                r1 += get(0, 0, sz, first[bi]);
                r1 -= values[bi];
                cout << r1 << endl;
            }
        }
        else{
            cin >> ai >> ci;
            if (ai < n){
                int v = edges[ai-1].second - 1;
                int diff = ci - now[ai-1];
                change(0, 0, sz, first[v], second[v] + 1, diff);
                now[ai - 1] = ci;
            }
            else{
                int v = edges[ai-1].first - 1;
                int diff = ci - values[v];
                values[v] = ci;
                change(0, 0, sz, first[v], first[v] + 1, diff);
                change(0, 0, sz, second[v], second[v] + 1, diff);
            }
        }
    }
    return 0;
}