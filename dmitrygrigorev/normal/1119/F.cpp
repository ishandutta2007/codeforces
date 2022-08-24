#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Edge{int to; int w;};
vector<vector<Edge> > data, inkek;
vector<multiset<int> > best, worst;
vector<bool> can, used;
vector<int> sum;
int dp[250000][2];
int cur;
void dfs(int vertex, int W){
    used[vertex] = true;
    vector<Edge> nlist;
    int th = 0;
    vector<int> profit;
    dp[vertex][0] = 0, dp[vertex][1] = 0;
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i].to;
        if (!can[to]) continue;
        nlist.push_back(data[vertex][i]);
        if (used[to]) continue;
        dfs(to, data[vertex][i].w);
        th += dp[to][0];
        profit.push_back(dp[to][1] - dp[to][0]);
    }
    sort(profit.begin(), profit.end());
    data[vertex] = nlist;
    for (int e=0; e < 2; e++){
        if (e > cur){
            continue;
        }
        int take = sum[vertex] + th;
        if (e==1) take += W;
        auto it = best[vertex].end();
        if (best[vertex].size()) it = best[vertex].begin();
        int wh = best[vertex].size() + e;
        for (int p=0; p <= min((int) profit.size(), cur-e); p++){
            while (wh + p > cur){
                take -= *it;
                it++;
                wh--;
            }
            dp[vertex][e] = max(dp[vertex][e], take);
            if (p==min((int) profit.size(), cur-e)) break;
            take += profit[profit.size() - p - 1];
        }
    }
}
main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int S = 0;
    data.resize(n, {});
    best.resize(n, {});
    worst.resize(n, {});
    sum.resize(n, 0);
    can.resize(n, true);
    used.resize(n, false);
    for (int i=0; i < n-1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        data[u-1].push_back({v-1, w});
        data[v-1].push_back({u-1, w});
        S+=w;
    }
    inkek = data;
    vector<int> left, pos;
    for (int i=0; i < n; i++){
        left.push_back(i);
        pos.push_back(i);
    }
    vector<pair<int, int> > deg;
    for (int i=0; i < n; i++) deg.push_back({data[i].size(), i});
    sort(deg.begin(), deg.end());
    int u = 0;
    int grt=0;
    for (int i=0; i < n; i++){
        cur = i;
        while (u < deg.size() && deg[u].first <= i){
            int vertex = deg[u].second;
            int V = left.back();
            if (V==vertex) left.pop_back();
            else{
                int p = pos[vertex];
                pos[V] = p;
                swap(left[p], left[left.size()-1]);
                left.pop_back();
            }
            can[vertex] = false;
            for (int j=0; j < inkek[vertex].size(); j++){
                int to = inkek[vertex][j].to;
                if (!can[to]){
                    grt += inkek[vertex][j].w;
                    continue;
                }
                worst[to].insert(inkek[vertex][j].w);
            }
            u++;
        }
        for (int j=0; j < left.size(); j++){
            int V = left[j];
            while (worst[V].size()){
                auto it = worst[V].end();
                it--;
                int T = *it;
                if (best[V].size() < i){
                    best[V].insert(T);
                    sum[V] += T;
                    worst[V].erase(it);
                }
                else{
                    auto e = best[V].begin();
                    int Q = *e;
                    if (Q < T){
                        sum[V] += T-Q;
                        worst[V].erase(it);
                        best[V].erase(e);
                        best[V].insert(T);
                        worst[V].insert(Q);
                    }
                    else break;
                }
            }
        }
        //if (i==1) cout << sum[0] << endl;
        int ans = grt;
        for (int j=0; j < left.size(); j++){
            int to = left[j];
            if (!used[to]){
                //if (i==1) cout << to << endl;
                dfs(to, 0);
                ans += max(dp[to][0], dp[to][1]);
            }
        }
        for (int j=0; j < left.size(); j++){
            int to = left[j];
            used[to] = false;
        }
        cout << S-ans << " ";
    }
}