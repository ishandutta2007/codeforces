#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > v;
    int ans = 1e18;
    for (int i=0; i < n; i++){
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    vector<vector<int> > p(m);
    for (int votes=0; votes <= n; votes++){
        int sum = votes + (votes-1)*(m-1);
        if (sum < n) continue;
        for (int i=0;i<m;i++) p[i].clear();
        for (int i=0; i < n; i++){
            p[v[i].first-1].push_back(v[i].second);
        }
        if (p[0].size() > votes) continue;
        int need = votes - (int) p[0].size(), here=0;
        vector<int> dlt;
        for (int i=1; i < m; i++){
            sort(p[i].begin(), p[i].end());
            for (int j=0; j < (int) p[i].size() - (votes-1); j++){
                here += p[i][j];
                need--;
            }
            for (int j=max((int) 0, (int) p[i].size() - (votes-1)); j < (int) p[i].size(); j++){
                dlt.push_back(p[i][j]);
            }
        }
        sort(dlt.begin(), dlt.end());
        for (int i=0;i<need;i++) here += dlt[i];
        ans = min(ans, here);
    }
    cout << ans;
}