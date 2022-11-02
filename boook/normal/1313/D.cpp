#include <bits/stdc++.h>
using namespace std;
//--------------------------------------
#define maxn 300000 + 10
#define inf 0x3f3f3f3f

int n, x[maxn][2], dp[maxn][300];

int nowi, dpv;

int use[10], uuu[10], dpval[300];

vector<int> uni, kind[maxn];

void DFS(int deep, int idx, int bitcnt) {
    if (deep == kind[nowi].size()) {
        dp[nowi][idx] = max(dp[nowi][idx], dpv + bitcnt * (uni[nowi + 1] - uni[nowi]));
    }
    else {
        if (uuu[deep] != -1) DFS(deep + 1, idx, bitcnt ^ ((idx & (1 << deep)) != 0));
        else {
            DFS(deep + 1, idx              , bitcnt);
            DFS(deep + 1, idx ^ (1 << deep), bitcnt ^ 1);
        }
    }
}
int32_t main(){
    cin.tie(0), cout.sync_with_stdio(0);
    
    int trash;
    cin >> n >> trash >> trash;
    for (int i = 1; i <= n; ++ i) cin >> x[i][0] >> x[i][1], x[i][1] ++;

    for (int i = 1; i <= n; ++ i) uni.emplace_back(x[i][0]);
    for (int i = 1; i <= n; ++ i) uni.emplace_back(x[i][1]);

    sort(uni.begin(), uni.end());
    uni.resize(unique(uni.begin(), uni.end()) - uni.begin());

    for (int i = 1; i <= n; ++ i) x[i][0] = lower_bound(uni.begin(), uni.end(), x[i][0]) - uni.begin();
    for (int i = 1; i <= n; ++ i) x[i][1] = lower_bound(uni.begin(), uni.end(), x[i][1]) - uni.begin();
    
    // for (int i = 1; i <= n; ++ i) cout << x[i][0] << " " << x[i][1] << "\n";

    int nn = uni.size() - 1;

    for (int i = 1; i <= n; ++ i) 
        for (int j = x[i][0]; j < x[i][1]; ++ j)
            kind[j].emplace_back(i);

    for (int i = 0; i < (1 << kind[0].size()); ++ i) {
        int cnt = 0;
        for (int j = 0; j < kind[0].size(); ++ j)
            if (i & (1 << j)) cnt ^= 1;
        dp[0][i] = (uni[1] - uni[0]) * cnt;
        // printf("dp[%d][%d] = %d\n", 0, i, dp[0][i]);
    }
    // for (int i = 0; i < nn; ++ i) {for (auto to : kind[i]) cout << to << " "; cout << endl;}

    for (int i = 1; i < nn; ++ i) {
        memset(use, -1, sizeof use);
        memset(uuu, -1, sizeof uuu);
        memset(dpval, -1, sizeof dpval);

        for (int j = 0; j < kind[i - 1].size(); ++ j)
            for (int k = 0; k < kind[i].size(); ++ k) 
                if (kind[i - 1][j] == kind[i][k]) 
                    use[j] = k, uuu[k] = j;
        
        // cout << "[use] ";
        // for (int j = 0; j < kind[i - 1].size(); ++ j)
        //     cout << use[j] << " "; cout << endl;

        for (int j = 0; j < (1 << kind[i - 1].size()); ++ j) {
            int pat = 0;
            for (int k = 0; k < kind[i - 1].size(); ++ k) 
                if ((j & (1 << k)) && use[k] != -1) pat |= (1 << use[k]);
            dpval[pat] = max(dpval[pat], dp[i - 1][j]);
        }

        nowi = i;
        for (int j = 0; j < (1 << kind[i].size()); ++ j) if (dpval[j] != -1) {
            // printf("dpval[%d] = %d\n", j, dpval[j]);
            // if (i == 3 && j != 0) continue;
            dpv = dpval[j];
            DFS(0, j, 0);
        }
        // for (int j = 0; j < (1 << kind[i].size()); ++ j) 
        //     printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
        // if (i == 3) return 0;
    }

    int ans = 0;
    for (int i = 0; i < (1 << kind[nn - 1].size()); ++ i)
        ans = max(ans, dp[nn - 1][i]);
    cout << ans << "\n";

    // cout << "[fast cin]" << endl;
    return 0;
}