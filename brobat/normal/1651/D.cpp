#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

#define pi pair<int, int>

pair<int, int> add(pair<int, int> &a, pair<int, int> &b) {
    return {a.first + b.first, a.second + b.second};
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<pi> v(n);
    map<pi, int> m;
    for(int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        m[v[i]] = i;
    }
    vector<pi> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector <pi> ans(n, {-1, -1});
    vector <vector<int>> adj(n);
    for(int i = 0; i < n; i++) {
        for(int k = 0; k < 4; k++) {
            if(m.find(add(v[i], dir[k])) != m.end()) {
                adj[i].push_back(m[add(v[i], dir[k])]);
            }
        }
    }
    queue<int> q;
    for(int i = 0; i < n; i++) {
        if((int)adj[i].size() < 4) {
            for(int k = 0; k < 4; k++) {
                if(m.find(add(v[i], dir[k])) == m.end()) {
                    ans[i] = add(v[i], dir[k]);
                    q.push(i);
                    break;
                }
            }
        }
    }
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(auto next : adj[curr]) {
            if(ans[next].first == -1) {
                ans[next] = ans[curr];
                q.push(next);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}