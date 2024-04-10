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
vector<vector<pair<int, int> > > data;
vector<pair<int, int> > edges;
int INF = 1e9;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, s, t, u, v;
    cin >> n >> m >> s;
    for (int i=0; i < n; i++){
        vector<pair<int, int> > v;
        data.push_back(v);
    }
    for (int i=0; i < m; i++){
        cin >> t >> u >> v;
        if (t == 1){
            data[u-1].push_back(make_pair(v-1, 1));
        }
        else{
            data[u-1].push_back(make_pair(v-1, 2));
            data[v-1].push_back(make_pair(u-1, 2));
            edges.push_back(make_pair(u-1, v-1));
        }
    }
    vector<int> d(n);
    fill(d.begin(), d.end(), -1);
    queue<int> q;
    q.push(s-1);
    d[s-1] = 0;
    int ans = 1;
    while (!q.empty()){
        int v = q.front();
        q.pop();
        for (int i=0; i < data[v].size(); i++){
            int to = data[v][i].first;
            if (d[to] != -1) continue;
            q.push(to);
            d[to] = d[v]+1;
            ans++;
        }
    }
    cout << ans << endl;
    for (int i=0; i < edges.size(); i++){
        int f = edges[i].first;
        int w = edges[i].second;
        if (d[f] <= d[w]) cout << "+";
        else cout << "-";
    }
    cout << endl;
    fill(d.begin(), d.end(), INF);
    q.push(s-1);
    d[s-1] = 0;
    ans = 1;
    while (!q.empty()){
        int v = q.front();
        q.pop();
        for (int i=0; i < data[v].size(); i++){
            int to = data[v][i].first;
            if (d[to] != INF) continue;
            if (data[v][i].second == 2) continue;
            q.push(to);
            d[to] = d[v]+1;
            ans++;
        }
    }
    cout << ans << endl;
    for (int i=0; i < edges.size(); i++){
        int f = edges[i].first;
        int w = edges[i].second;
        if (d[f] <= d[w]) cout << "-";
        else cout << "+";
    }
    cout << endl;
    return 0;
}