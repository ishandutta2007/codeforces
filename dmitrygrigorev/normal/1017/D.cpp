#include <bits/stdc++.h>
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q, m;
    cin >> n >> q >> m;
    vector<int> how((1<<n));
    vector<int> cost(n);
    for (int i=0; i < n; i++) cin >> cost[i];
    vector<int> pod((1<<n));
    for (int i=0; i < (1<<n); i++){
        int S = 0;
        for (int j=0; j < n; j++){
            int ba = i & (1<<j);
            if (ba == 0) continue;
            S += cost[j];
        }
        pod[i] = S;
    }
    for (int i=0; i < q; i++){
        string A;
        cin >> A;
        int S = 0;
        for (int j=0; j < n; j++){
            int symb = (A[j] - '0');
            if (symb == 1) S += (1<<j);
        }
        how[S]++;
    }
    vector<vector<pair<int, int> > > quer(1<<n);
    for (int i=0; i < m; i++){
        string A;
        int ss;
        cin >> A >> ss;
        int S = 0;
        for (int j=0; j < n; j++){
            int symb = (A[j] - '0');
            if (symb == 1) S += (1<<j);
        }
        quer[S].push_back(make_pair(ss, i));
    }
    vector<int> ans(m);
    for (int i=0; i < (1<<n); i++) sort(quer[i].begin(), quer[i].end());
    for (int i=0; i < (1<<n); i++){
        vector<pair<int, int> > xx;
        for (int j=0; j < (1<<n); j++){
            int xr = i^j^((1<<n)-1);
            xx.push_back(make_pair(pod[xr], how[j]));
        }
        sort(xx.begin(), xx.end());
        int now = 0, ind = 0;
        //cout << xx.back().first << " " << xx.back().second << endl;
        for (int j=0; j < quer[i].size(); j++){
            while (ind < xx.size() && xx[ind].first <= quer[i][j].first){
                now += xx[ind].second;
                ind++;
            }
            ans[quer[i][j].second] = now;
        }
    }
    for (int i=0;i<m;i++) cout << ans[i] << "\n";
    return 0;
}