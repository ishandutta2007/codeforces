#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int lp[N+1];
vector<int> primes;

void genPrimes(){
    for(int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.push_back (i);
        }
        for (int j=0; j<(int)primes.size() && primes[j]<=lp[i] && i*primes[j]<=N; ++j)
            lp[i * primes[j]] = primes[j];
    }
}

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
};

int n, k;
vector<array<int, 3>> stuff;
vector<array<int, 3>> arr;

int solve(int mid){
    stuff.clear();
    int oneid = -1;
    for(int i = 0; i<n; i++){
        if(arr[i][2] > mid) continue;
        if(arr[i][1] != 1) stuff.push_back(arr[i]);
        else{
            if(oneid == -1 || arr[i][0] > arr[oneid][0])
                oneid = i;
        }
    }
    if(oneid != -1) stuff.push_back(arr[oneid]);
    HLPP hlpp;
    int m = stuff.size();
    hlpp.init(m+2);
    int tot = 0;
    for(int i = 0; i<m; i++){
        if(stuff[i][1]%2) hlpp.ae(i, m+1, stuff[i][0]);
        else hlpp.ae(m, i, stuff[i][0]);
        tot += stuff[i][0];
    }
    for(int i = 0; i<m; i++){
        for(int j = 0; j<m; j++){
            if(stuff[i][1]%2 == 1 || stuff[j][1]%2 == 0) continue;
            if(lp[stuff[i][1]+stuff[j][1]] == stuff[i][1]+stuff[j][1])
                hlpp.ae(i, j, 1e9);
        }
    }
    return tot-hlpp.maxFlow(m, m+1);
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    genPrimes();
    cin >> n >> k;
    arr.resize(n);
    for(int i = 0; i<n; i++){
        int p, c, l; cin >> p >> c >> l;
        arr[i] = {p, c, l};
    }
    int lo = 1, hi = n+1;
    while(lo < hi){
        int mid = lo+(hi-lo)/2;
        if(solve(mid) >= k) hi = mid;
        else lo = mid+1;
    }
    if(lo == n+1) cout << -1 << endl;
    else cout << lo << endl;
}