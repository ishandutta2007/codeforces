/**
 *  created: 13/06/2021, 19:14:27
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 555, inf = 1000111222;

int n, k, dist[max_n];
pair<int, int> parent[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    memset(dist, -1, sizeof(dist));
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        //cout << cur << ": " << parent[cur].first << " " << parent[cur].second << endl;
        for (int common = 0; common <= min(cur, k); ++common) {
            int to = cur - common + k;
            if (to > n) {
                continue;
            }
            to -= common;
            if (dist[to] == -1) {
                dist[to] = dist[cur] + 1;
                parent[to] = {cur, common};
                q.push(to);
            }
        }
    }
    if (dist[n] == -1) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> ans;
    int cur = n;
    while (cur) {
        ans.push_back(parent[cur].second);
        cur = parent[cur].first;
    }
    reverse(ans.begin(), ans.end());
    vector<int> used(n);
    int res = 0;
    for (int common : ans) {
        //cout << "com = " << common << endl;
        vector<int> ids;
        int need = k - common;
        for (int f = 0; f < 2; ++f) {
            int cnt = need;
            for (int i = 0; i < n && cnt; ++i) {
                if (used[i] == f) {
                    ids.push_back(i);
                    --cnt;
                }
            }
            need = k - need;
        }
        assert(ids.size() == k);
        cout << "?";
        for (int id : ids) {
            used[id] ^= 1;
            cout << " " << id + 1;
        }
        cout << endl;
        int val;
        cin >> val;
        res ^= val;
    }
    cout << "! " << res << endl;
    return 0;
}