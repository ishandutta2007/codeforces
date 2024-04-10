#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2005;

int n, m;
vector<array<int, 2>> adj[N];
int s[2], dist[2][N], val[N];
int dp[2][N][N], sum[N][N], cnt[N][N], nxt[2][N][N];
map<int, int> id[2];
vector<int> events[2];

signed main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    cin >> s[0] >> s[1]; --s[0]; --s[1];
    for(int i = 0; i<n; i++) cin >> val[i];
    for(int i = 0; i<m; i++){
        int a, b, w; cin >> a >> b >> w; --a; --b;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    for(int t = 0; t<2; t++){
        memset(dist[t], 63, sizeof dist[t]);
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> pq;
        dist[t][s[t]] = 0; pq.push({0, s[t]});
        while(pq.size()){
            int v = pq.top()[1], d = pq.top()[0]; pq.pop();
            if(d != dist[t][v]) continue;
            for(auto u : adj[v])
                if(dist[t][u[0]] > d + u[1])
                    dist[t][u[0]] = d+u[1], pq.push({dist[t][u[0]], u[0]});
        }
        for(int i = 0; i<n; i++) events[t].push_back(dist[t][i]);
        sort(events[t].begin(), events[t].end());
        events[t].erase(unique(events[t].begin(), events[t].end()), events[t].end());
        for(int i = 0; i<(int)events[t].size(); i++) id[t][events[t][i]] = i;
    }
    for(int i = 0; i<n; i++) 
        sum[id[0][dist[0][i]]][id[1][dist[1][i]]] += val[i],
        cnt[id[0][dist[0][i]]][id[1][dist[1][i]]] += 1;
    for(int i = n-1; i>=0; i--)
        for(int j = n-1; j>=0; j--)
            sum[i][j] += sum[i+1][j]+sum[i][j+1]-sum[i+1][j+1];
    for(int i = 0; i<=n; i++)
        for(int j = 0; j<=n; j++)
            nxt[0][i][j] = nxt[1][i][j] = n;
    for(int i = n-1; i>=0; i--){
        for(int j = n-1; j>=0; j--){
            nxt[0][i][j] = min(nxt[0][i+1][j], nxt[0][i][j+1]);
            nxt[1][i][j] = min(nxt[1][i+1][j], nxt[1][i][j+1]);
            if(cnt[i][j]) nxt[0][i][j] = i+1, nxt[1][i][j] = j+1;
            dp[0][i][j] = sum[i][j]-dp[1][nxt[0][i][j]][j];
            dp[1][i][j] = sum[i][j]-dp[0][i][nxt[1][i][j]];
            if(i == 0 && j == 0) break;
            dp[0][i][j] = min(dp[0][i][j], dp[0][i][j+1]);
            dp[1][i][j] = min(dp[1][i][j], dp[1][i+1][j]);
        }
    }
    int ans = sum[0][0]-2*dp[0][0][0];
    if(ans < 0) cout << "Break a heart" << endl;
    else if(ans == 0) cout << "Flowers" << endl;
    else cout << "Cry" << endl;
}