#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int GetBrut(int n, int k) {
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        if (dp[i - 1] == 0) dp[i] = 1;
        if (i >= 2 && dp[i - 2] == 0) dp[i] = 1;
        if (i >= k && dp[i - k] == 0) dp[i] = 1;
    }
    return dp[n];
}

int GetGood(int n, int k) {
    if (k % 3) {
        return !!(n % 3);
    } else {
        n %= (k + 1);
        if (n == k || !!(n % 3))
            return 1;
        return 0;
    }
}

void Test() {
    for (int n = 0; n <= 100; ++n) {
        for (int k = 3; k <= n; ++k) {
            assert(GetBrut(n, k) == GetGood(n, k));
        }
    }
}

int main() {
//    Test();
//    cerr << "OK" << endl;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int q; cin >> q;
    while (q--) {    
        int n, k; cin >> n >> k;
        int ans = GetGood(n, k);
        if (ans == 0) cout << "Bob\n";
        else cout << "Alice\n";
    }

    return 0;
}