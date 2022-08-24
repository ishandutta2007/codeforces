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
int n, xi, yi, ci, min_ans;
vector<vector<int> > data;
vector<vector<int> > money;
vector<bool> used, in;
vector<int> cycl, cost, edges;
bool check;
void dfs(int vertex, int last, vector<int> &v){
    used[vertex] = true;
    v.push_back(vertex);
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i];
        if (to == last) continue;
        if (used[to]){
            if (!check){
                int u = v.size() - 1;
                while (true){
                    cycl.push_back(v[u]);
                    cost.push_back(0);
                    in[v[u]] = true;
                    if (v[u] == to) break;
                    u--;
                }
                check = true;
            }
            continue;
        }
        dfs(to, vertex, v);
    }
    v.pop_back();
}
int dfs2(int vertex){
    used[vertex] = true;
    int max1 = 0, max2 = 0;
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i];
        if (in[to] || used[to]) continue;
        int res = dfs2(to) + money[vertex][i];
        if (res > max1){
            max2 = max1;
            max1 = res;
        }
        else if (res > max2){
            max2 = res;
        }
    }
    min_ans = max(min_ans, max1+max2);
    return max1;
}
int32_t main(){
    cin >> n;
    for (int i=0; i < n; i++){
        vector<int> h1, h2;
        data.push_back(h1);
        money.push_back(h2);
        used.push_back(false);
        in.push_back(false);
    }
    for (int i=0; i < n; i++){
        cin >> xi >> yi >> ci;
        data[xi-1].push_back(yi-1);
        data[yi-1].push_back(xi-1);
        money[xi-1].push_back(ci);
        money[yi-1].push_back(ci);
    }
    vector<int> v;
    check = false;
    dfs(0, -1, v);
    min_ans = 0;
    fill(used.begin(), used.end(), false);
    for (int i=0; i < cycl.size(); i++){
        cost[i] = dfs2(cycl[i]);
    }
    int N = cycl.size();
    for (int i=0; i < cycl.size(); i++){
        int f = cycl[i];
        int s = cycl[(i + 1) % N];
        for (int j=0; j < data[f].size(); j++){
            if (data[f][j] == s){
                edges.push_back(money[f][j]);
                break;
            }
        }
    }
    int dist_r[N], max_r[N], dist_l[N], max_l[N];
    dist_r[0] = 2*cost[0];
    max_r[0] = cost[0];
    for (int i=1; i < N; i++){
        dist_r[i] = max(dist_r[i-1] + cost[i] - cost[i-1] + edges[i - 1], cost[i] + cost[i-1] + edges[i-1]);
        max_r[i] = max(max_r[i-1], dist_r[i]);
    }
    dist_l[N-1] = 2 * cost[N-1];
    max_l[0] = 0;
    max_l[N-1] = cost[N-1];
    for (int i=N-2; i >= 1; i--){
        dist_l[i] = max(dist_l[i+1] + cost[i] - cost[i+1] + edges[i], cost[i] + cost[i+1] + edges[i]);
        max_l[i] = max(max_l[i+1], dist_l[i]);
    }
    int dr[N], dl[N], mr[N], ml[N];
    dr[0] = cost[0];
    mr[0] = cost[0];
    for (int i=1; i < N; i++){
        dr[i] = dr[i-1] + cost[i] - cost[i-1] + edges[i - 1];
        mr[i] = max(mr[i-1], dr[i]);
    }
    dl[N-1] = cost[N-1] + edges.back();
    ml[N-1] = cost[N-1] + edges.back();
    ml[0] = 0;
    for (int i=N-2; i >= 1; i--){
        dl[i] = dl[i+1] + cost[i] - cost[i+1] + edges[i];
        ml[i] = max(ml[i+1], dl[i]);
    }
    int ans = 1e18;
    for (int i=0; i < N; i++){
        int na = max(max_r[i], max(max_l[(i+1) % N], mr[i] + ml[(i + 1) % N]));
        na = max(na, min_ans);
        ans = min(na, ans);
    }
    cout << ans << endl;
    return 0;
}