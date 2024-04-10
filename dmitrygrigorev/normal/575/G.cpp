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
int n, m, ai, bi, ci, INF = 1e18;
vector<vector<int> > data, money;
vector<int> d, what, reb, go, D;
vector<pair<int, int> > nv;
vector<int> pos, old, vert;
vector<bool> used;
bool comp(int f, int s){
    if (nv[f].first < nv[s].first) return true;
    if (nv[f].first > nv[s].first) return false;
    if (pos[nv[f].second] < pos[nv[s].second]) return true;
    if (pos[nv[f].second] > pos[nv[s].second]) return false;
    if (D[vert[f]] < D[vert[s]]) return true;
    return false;
}
bool cmp(int f, int s){
    if (pos[f] < pos[s]) return true;
    if (pos[f] > pos[s]) return false;
    return false;
}
void bfs(){
    bool our = false;
    vert.clear();
    for (int i=0; i < old.size(); i++){
        int v = old[i];
        if (used[v]) our = true;
        for (int j=0; j < data[v].size(); j++){
            int to = data[v][j];
            if (d[to] != -1 && d[to] != d[v] + 1) continue;
            if (d[to] != d[v] + 1) vert.push_back(to);
            d[to] = d[v] + 1;
            int R = money[v][j];
            if (R < reb[to]){
                reb[to] = R;
                what[to] = v;
            }
            else if (R == reb[to]){
                if (pos[v] < pos[what[to]]){
                    what[to] = v;
                }
            }
        }
    }
    for (int i=0; i < vert.size(); i++){
        int V = vert[i];
        nv.push_back(make_pair(reb[V], what[V]));
    }
    vector<int> q;
    for (int i=0; i < nv.size(); i++) q.push_back(i);
    sort(q.begin(), q.end(), comp);
    for (int i=0; i < q.size(); i++){
        pos[vert[q[i]]] = i;
    }
    if (!our){
        old = vert;
        nv.clear();
        bfs();
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i=0; i < n; i++){
        vector<int> help1, help2;
        data.push_back(help1);
        money.push_back(help2);
        d.push_back(-1);
        D.push_back(INF);
        what.push_back(-1);
        reb.push_back(10);
        pos.push_back(-1);
        go.push_back(-1);
        used.push_back(false);
    }
    for (int i=0; i < m; i++){
        cin >> ai >> bi >> ci;
        data[ai].push_back(bi);
        money[ai].push_back(ci);
        data[bi].push_back(ai);
        money[bi].push_back(ci);
    }
    queue<int> q;
    q.push(n-1);
    D[n-1] = 0;
    go[n-1] = n-1;
    while (!q.empty()){
        int v = q.front();
        q.pop();
        used[v] = true;
        for (int i=0; i < data[v].size(); i++){
            if (money[v][i] != 0) continue;
            int to = data[v][i];
            if (D[to] != INF) continue;
            go[to] = v;
            q.push(to);
            D[to] = D[v] + 1;
        }
    }
    fill(d.begin(), d.end(), -1);
    d[0] = 0;
    old.push_back(0);
    bfs();
    sort(old.begin(), old.end(), cmp);
    int ANS;
    for (int i=0; i < old.size(); i++){
        if (used[old[i]]){
            ANS = old[i];
            break;
        }
    }
    string AP = "";
    int NV = ANS;
    vector<int> answer;
    answer.push_back(NV);
    while (what[NV] != -1){
        int NEW = what[NV];
        AP += '0' + reb[NV];
        NV = NEW;
        answer.push_back(NV);
    }
    if (AP == "") AP =  "0";
    reverse(answer.begin(), answer.end());
    cout << AP << endl;
    while (ANS != n-1){
        int Q = go[ANS];
        ANS = Q;
        answer.push_back(ANS);
    }
    cout << answer.size() << endl;
    for (int i=0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }
    return 0;
}