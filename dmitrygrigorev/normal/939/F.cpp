#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
int INF = 1e9;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int> > v;
    for (int i=0; i < k; i++){
        int L, R;
        cin >> L >> R;
        v.push_back(make_pair(L, R));
    }
    int dp[2][n+1];
    int old = 0;
    for (int i=0; i < 2; i++){
        for (int j=0; j <= n; j++) dp[i][j] = INF;
    }
    dp[0][0] = 0;
    for (int i=0; i < k; i++){
        //cout << i << endl;
        int dp1[2][n+1];
        for (int it=0; it < 2; it++){
            for (int j=0; j <= n; j++) dp1[it][j] = INF;
        }
        int D = v[i].first - old;
        int our = v[i].second - v[i].first;
        deque<int> q;
        for (int j=D; j <= n; j++){
            while (q.size() > 0 && q.back()>dp[0][j-D]) q.pop_back();
            q.push_back(dp[0][j-D]);
            if (j >= D+our+1){
                if (q.front() == dp[0][j-D-our-1]) q.pop_front();
            }
            if (j >= D+our) dp1[0][j] = min(dp1[0][j], dp[0][j-D-our]);
            dp1[0][j] = min(dp1[0][j], q.front()+2);
            dp1[1][j] = min(dp1[1][j], q.front()+1);
        }
        q.clear();
        for (int j=0; j <= n; j++){
            while (q.size() > 0 && q.back()>dp[1][j]) q.pop_back();
            q.push_back(dp[1][j]);
            if (j >= our+1){
                if (q.front() == dp[1][j-our-1]) q.pop_front();
            }
            dp1[1][j] = min(dp1[1][j], dp[1][j]);
            dp1[1][j] = min(dp1[1][j], q.front()+2);
            dp1[0][j] = min(dp1[0][j], q.front()+1);
        }
        for (int it=0; it < 2; it++){
            for (int j=0; j <= n; j++) dp[it][j] = dp1[it][j];
        }
        old = v[i].second;
    }
    int ost = 2*n - v[k-1].second;
    int res = INF;
    if (ost > n){
        cout << "Hungry" << endl;
        return 0;
    }
    res = min(res, dp[0][n - ost]);
    res = min(res, dp[1][n]);
    if (res==INF){
        cout << "Hungry" << endl;
        return 0;
    }
    cout << "Full" << endl;
    cout << res << endl;
    return 0;
}