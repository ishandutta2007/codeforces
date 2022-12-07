#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<vector<int>> c(q, vector<int>(3)); // conditions.
    for(int i = 0; i < q; i++) {
        cin >> c[i][0] >> c[i][1] >> c[i][2];
        --c[i][0];
        --c[i][1];
    }
    vector <int> ans(n);
    for(int j = 0; j < 30; j++) {
        // solve for the j^th bit.
        vector <int> v(n, -1);
        vector <vector<int>> adj(n);
        queue <int> qq;
        for(int i = 0; i < q; i++) {
            if((c[i][2] >> j) & 1) {
                if(c[i][0] == c[i][1]) {
                    v[c[i][0]] = 1;
                    continue;
                }
                adj[c[i][0]].push_back(c[i][1]);
                adj[c[i][1]].push_back(c[i][0]);
            } else {
                if(v[c[i][0]] != 0) qq.push(c[i][0]);
                if(v[c[i][1]] != 0) qq.push(c[i][1]);
                v[c[i][0]] = 0;
                v[c[i][1]] = 0;
            }
        }
        for(int i = 0; i <= n; i++) {
            while(!qq.empty()) {
                int curr = qq.front();
                qq.pop();
                for(auto nx : adj[curr]) {
                    assert(v[nx] != 0);
                    v[nx] = 1;
                }
            }
            if(i == n) break;
            if(v[i] == -1) {
                qq.push(i);
                v[i] = 0;
            }
        }
        for(int i = 0; i < n; i++) {
            assert(v[i] != -1);
            ans[i] += (v[i] << j);
        }
    }
    for(auto i : ans) cout << i << ' ';

    return 0;
}