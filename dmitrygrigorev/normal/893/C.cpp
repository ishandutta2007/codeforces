#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, ai, bi;
vector<int> v;
vector<vector<int> > data;
vector<bool> used;
int dfs(int vertex){
    used[vertex] = true;
    int ret = v[vertex];
    for (int i=0; i < data[vertex].size();i++){
        int to = data[vertex][i];
        if (used[to]) continue;
        ret = min(ret, dfs(to));
    }
    return ret;
}
signed main(){
    cin >> n >> m;
    for (int i=0; i < n; i++){
        cin >> ai;
        v.push_back(ai);
        vector<int> help;
        data.push_back(help);
        used.push_back(false);
    }
    for (int i=0; i < m; i++){
        cin >> ai >> bi;
        data[ai-1].push_back(bi-1);
        data[bi-1].push_back(ai-1);
    }
    int ans = 0;
    for (int i=0; i < n; i++){
        if (used[i]) continue;
        ans += dfs(i);
    }
    cout << ans << endl;
    return 0;
}