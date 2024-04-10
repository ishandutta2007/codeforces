/*input
5
0 0
1 0
2 0
3 0
2 0
*/
    // cout << "now = " << now << endl;
#include <bits/stdc++.h>
using namespace std;
#define maxn 2020
 
int n, p[maxn], c[maxn];
 
vector<int> v[maxn];
 
int ans[maxn];
vector<pair<int, int>> dfs(int now) {
    // cout << "now = " << now << endl;
    if (v[now].size() == 0) {
        if (c[now] != 0) {
            cout << "NO" << endl;
            exit(0);
        }
        ans[now] = 3000 * now;
        vector<pair<int, int>> sol;
        sol.emplace_back(3000 * now, now);
        return sol;
    }
    else {
        vector<pair<int, int>> sol;
        for (auto to : v[now]) {
            vector<pair<int, int>> tmp = dfs(to);
            for (auto val : tmp) sol.emplace_back(val);
        }
        sort(sol.begin(), sol.end());
        if (c[now] > sol.size()) {
            cout << "NO" << endl;
            exit(0);
        }
        else {
 
            int aans;
            if (c[now] == sol.size()) aans = sol.back().first + 1;
            else  aans = sol[c[now]].first;
            // cout << "aans = " << c[now] << endl;
 
            // for (auto to : sol) cout << to.first << "-" << to.second << endl;
            for (int i = c[now]; i < sol.size(); ++ i) {
                sol[i].first ++;
                ans[sol[i].second] ++;
            }
            // for (auto to : sol) cout << to.first << "^" << to.second << endl;
            sol.emplace_back(aans, now);
            ans[now] = aans;
            return sol;
        }
    }
}
int32_t main(){
    cin.tie(0), cout.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++ i) cin >> p[i] >> c[i];
 
    int root;
    for (int i = 1; i <= n; ++ i) {
        if (p[i] != 0) v[p[i]].emplace_back(i);
        else root = i;
    }
 
    dfs(root);
    cout << "YES\n";
    for (int i = 1; i <= n; ++ i) {
        cout << ans[i] << " \n"[i == n];
    }
    return 0;
}