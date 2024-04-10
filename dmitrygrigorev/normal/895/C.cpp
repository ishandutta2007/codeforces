#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> steps;
int MOD = 1000000007;
int x[19] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    steps.push_back(1);
    for (int i=1; i < 1e6; i++){
        steps.push_back((2 * steps[i-1]) % MOD);
    }
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    map<int, int> mm;
    for (int i=0; i < n; i++){
        int N = 0;
        for (int j=0; j < 19; j++){
            int X = v[i];
            int C = 0;
            while (X % x[j] == 0){
                X /= x[j];
                C++;
            }
            if (C % 2 != 0) N += (1 << j);
        }
        mm[N]++;
    }
    vector<pair<int, int> > pl;
    while (mm.size() > 0){
        int el = (*mm.begin()).first;
        int val = mm[el];
        mm.erase(mm.begin());
        pl.push_back(make_pair(el, steps[val-1]));
    }
    int INF = 1 << 19;
    int dp[INF], dp1[INF];
    for (int i=0; i < INF; i++) dp[i] = 0;
    dp[pl[0].first] += pl[0].second;
    dp[0] += pl[0].second;
    for (int i=1; i < pl.size(); i++){
        for (int j=0; j < INF; j++){
            dp1[j] = dp[j];
            dp[j] = 0;
        }
        for (int j=0; j < INF; j++){
            dp[j] += dp1[j] * pl[i].second;
            dp[j] %= MOD;
            dp[j] += dp1[j^pl[i].first] * pl[i].second;
            dp[j] %= MOD;
        }
    }
    cout << dp[0] - 1 << endl;
    return 0;
}