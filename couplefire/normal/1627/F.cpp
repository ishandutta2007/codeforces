#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k; cin >> n >> k;
    vector<vector<int>> vert(k+1, vector<int>(k+1, 0)), hori(k+1, vector<int>(k+1, 0));
    auto add = [&](int x, int y, bool f){
        if(!f) ++vert[x][y], ++vert[k-x][k-y-1];
        else ++hori[x][y], ++hori[k-x-1][k-y];
    };
    for(int i = 0; i<n; ++i){
        int r1, r2, c1, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        --r1; --r2; --c1; --c2;
        if(r1+c1>r2+c2)
            swap(r1, r2), swap(c1, c2);
        if(r1!=r2) add(r1+1, c1, 0);
        else add(r1, c1+1, 1);
    }
    vector<vector<int>> dist(k+1, vector<int>(k+1, 1e9));
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    for(int i = 0; i<k; ++i)
        dist[i][0] = 0, pq.push({0, i, 0});
    for(int i = 0; i<k; ++i)
        dist[k][i] = 0, pq.push({0, k, i});
    for(int i = k; i>=1; --i)
        dist[i][k] = 0, pq.push({0, i, k});
    for(int i = k; i>=1; --i)
        dist[0][i] = 0, pq.push({0, 0, i});
    while(!pq.empty()){
        auto [d, x, y] = pq.top(); pq.pop();
        if(d!=dist[x][y]) continue;
        if(x<k && d+hori[x][y]<dist[x+1][y])
            dist[x+1][y] = d+hori[x][y], pq.push({dist[x+1][y], x+1, y});
        if(y<k && d+vert[x][y]<dist[x][y+1])
            dist[x][y+1] = d+vert[x][y], pq.push({dist[x][y+1], x, y+1});
        if(x>0 && d+hori[x-1][y]<dist[x-1][y])
            dist[x-1][y] = d+hori[x-1][y], pq.push({dist[x-1][y], x-1, y});
        if(y>0 && d+vert[x][y-1]<dist[x][y-1])
            dist[x][y-1] = d+vert[x][y-1], pq.push({dist[x][y-1], x, y-1});
    } cout << n-dist[k/2][k/2] << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}