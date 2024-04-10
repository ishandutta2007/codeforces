#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, m; cin >> n >> m;
    vector<pair<long long, long long>> adj[n];
    for(long long i = 0; i<m; i++){
        long long a, b, w; cin >> a >> b >> w;
        --a; --b;
        w *= 2;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    long long cost[n];
    for(long long i = 0; i<n; i++) cin >> cost[i];
    set<pair<long long, long long>> st;
    long long dist[n];
    for(long long i = 0; i<n; i++){
        st.insert({cost[i], i});
        dist[i] = cost[i];
    }
    while(!st.empty()){
        pair<long long, long long> t = *st.begin();
        st.erase(st.begin());
        for(auto k : adj[t.second]){
            if(dist[k.first] > t.first+k.second){
                st.erase({dist[k.first], k.first});
                dist[k.first] = t.first+k.second;
                st.insert({dist[k.first], k.first});
            }
        }
    }

    for(long long i = 0; i<n; i++) cout << dist[i] << " ";
    cout << endl;

}