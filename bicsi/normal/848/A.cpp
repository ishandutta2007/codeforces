#include <bits/stdc++.h>

using namespace std;

int main() {
    int k; cin >> k;
    
    if (k == 0) {
        cout << "a" << endl;
        return 0;
    }
    
    vector<int> dp(k + 1);
    
    for (int i = 1; i <= k; ++i) {
        dp[i] = 500000;
        for (int j = 1, comb = 1; comb <= i; ++j, comb += j)
            dp[i] = min(dp[i], 1 + dp[i - comb]);
    }
    
    char at = 'a';
    while (k > 0) {
        bool ok = false;
        for (int j = 1, comb = 1; comb <= k; ++j, comb += j)
            if (dp[k] == dp[k - comb] + 1) {
                k -= comb;
                for (int i = 0; i <= j; ++i)
                    cout << at;
                at += 1;
                ok = true;
                break;
            }
            
        assert(ok);
    }
    return 0;
}