#include <bits/stdc++.h>
using namespace std;

struct HLPP{
    using F = int;
    const F INF = numeric_limits<F>::max();
    struct Edge{int to, rev; F f;};

    int n, s, t; vector<vector<Edge>> adj;
    vector<vector<int>> lst, gap;
    vector<int> height, cnt;
    int highest, work;
    vector<F> excess;

    void init(int _n){
        n = _n; 
        adj.resize(n+5); lst.resize(n+5); 
        gap.resize(n+5); excess.resize(n+5);
        height.resize(n+5); cnt.resize(n+5);
    }
    void ae(int a, int b, F cap){
        adj[a].push_back({b, (int)adj[b].size(), cap});
        adj[b].push_back({a, (int)adj[a].size()-1, 0});
    }
    void updHeight(int v, int nh){
        work++;
        if(height[v] != n) cnt[height[v]]--;
        height[v] = nh;
        if(nh == n) return;
        cnt[nh]++, highest = nh;
        gap[nh].push_back(v);
        if(excess[v] > 0) lst[nh].push_back(v);
    }
    void globalRelabel(){
        work = 0, highest = 0;
        for(int i = 0; i<n; i++) height[i] = n, cnt[i] = 0;
        for(int i = 0; i<highest; i++) lst[i].clear(), gap[i].clear();
        height[t] = 0;
        queue<int> q({t});
        while(!q.empty()){
            int v = q.front(); q.pop();
            for(auto& e : adj[v]) if(height[e.to] == n && adj[e.to][e.rev].f > 0) q.push(e.to), updHeight(e.to, height[v]+1);
            highest = height[v];
        }
    }
    void push(int v, Edge& e){
        if(excess[e.to] == 0) lst[height[e.to]].push_back(e.to);
        F df = min(excess[v], e.f);
        e.f -= df, adj[e.to][e.rev].f += df;
        excess[v] -= df, excess[e.to] += df;
    }
    void discharge(int v){
        int nh = n;
        for(auto& e : adj[v]){
            if(e.f > 0){
                if(height[v] == height[e.to]+1){
                    push(v, e);
                    if(excess[v] <= 0) return;
                }
                else nh = min(nh, height[e.to]+1);
            }
        }
        if(cnt[height[v]] > 1) updHeight(v, nh);
        else{
            for(int i = height[v]; i<=highest; i++){
                for(auto& j : gap[i]) updHeight(j, n);
                gap[i].clear();
            }
        }
    }
    F maxFlow(int _s, int _t){
        s = _s, t = _t;
        for(int i = 0; i<n; i++) excess[i] = 0;
        excess[s] = INF, excess[t] = -INF;
        globalRelabel();
        for(auto& e : adj[s]) push(s, e);
        for(; highest >= 0; highest--){
            while(!lst[highest].empty()){
                int v = lst[highest].back();
                lst[highest].pop_back();
                discharge(v);
                if(work > 4*n) globalRelabel();
            }
        }
        return excess[t]+INF;
    }
} hlpp;

int _, n, m, a, b;
vector<int> x_events, y_events;
vector<array<int, 4>> stuff;

int main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> _ >> m; stuff.resize(m);
    for(int i = 0; i<m; i++){
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        --x1, --y1, --x2, --y2;
        stuff[i] = {x1, y1, x2, y2};
        x_events.push_back(x1);
        x_events.push_back(x2+1);
        y_events.push_back(y1);
        y_events.push_back(y2+1);
    }
    x_events.push_back(_);
    y_events.push_back(_);
    sort(x_events.begin(), x_events.end());
    sort(y_events.begin(), y_events.end());
    x_events.erase(unique(x_events.begin(), x_events.end()), x_events.end());
    y_events.erase(unique(y_events.begin(), y_events.end()), y_events.end());
    a = x_events.size();
    b = y_events.size();
    n = a+b;
    hlpp.init(n+2);
    for(int i = 0; i<a-1; i++)
        hlpp.ae(n, i, x_events[i+1]-x_events[i]);
    for(int i = 0; i<b-1; i++)
        hlpp.ae(a+i, n+1, y_events[i+1]-y_events[i]);
    for(int i = 0; i<m; i++){
        int x1, y1, x2, y2;
        x1 = stuff[i][0], y1 = stuff[i][1], x2 = stuff[i][2], y2 = stuff[i][3];
        vector<int> x_tmp, y_tmp;
        int x_id = lower_bound(x_events.begin(), x_events.end(), x1)-x_events.begin();
        int y_id = lower_bound(y_events.begin(), y_events.end(), y1)-y_events.begin();
        while(x_events[x_id] <= x2)
            x_tmp.push_back(x_id++);
        while(y_events[y_id] <= y2) 
            y_tmp.push_back(y_id++);
        for(int x : x_tmp)
            for(int y : y_tmp)
                hlpp.ae(x, y+a, 1e9+7);
    }
    cout << hlpp.maxFlow(n, n+1) << endl;
}