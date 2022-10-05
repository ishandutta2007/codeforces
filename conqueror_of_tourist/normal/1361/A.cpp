#include <iostream>
#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;

bool compare(const pair<int, int>&i, const pair<int, int>&j)
{
    return i.first < j.first;
}
 
int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> adj[n];
    int bestAdj[n];
    
    for (int i = 0; i < n; i++){
        bestAdj[i] = 0;   
        adj[i].clear();
    }
    
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    
    int want[n];
    vector<pair<int, int>> order;
    for (int i = 0; i < n; i++){
        cin >> want[i];
        order.push_back(make_pair(want[i], i));
    }
    
    std::sort(std::begin(order), std::end(order), compare);
    
    bool works = true;
    for (int i = 0; i < n; i ++){
        int w,v;
        w = order[i].first;
        v = order[i].second;
        
        if (bestAdj[v] != w - 1){
            works = false;
            break;
        }
        
        for (int nex : adj[v]){
            if (bestAdj[nex] == w - 1){
                bestAdj[nex] = w;
            }
        }
    }
    
    
    if (works){
        for (int i = 0; i < n; i ++){
        int w,v;
        w = order[i].first;
        v = order[i].second;
        cout << v + 1 << " ";
        }
        
    }
    else{
        cout << -1;
    }
    
    
    
    
    return 0;
}