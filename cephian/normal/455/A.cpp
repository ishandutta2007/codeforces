#include <iostream>
#include <algorithm>

using namespace std;

int f[100001];
long long dp[100001];

int main() {
    ios::sync_with_stdio(0);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        ++f[t];
    }
    
    for(long long i = 1; i <= 100000; ++i) {
        dp[i] = f[i]*i;
        if(i > 2)
            dp[i] += dp[i-2];
        dp[i] = max(dp[i], dp[i-1]);
    }
    cout << dp[100000];
    
    return 0;
}