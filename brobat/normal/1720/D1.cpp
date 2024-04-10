#include <bits/stdc++.h>
using namespace std;

const int N = 256;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector <int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        vector <int> dp(n, 1);
        for(int i = 1; i < n; i++) {
            int curr = 1;
            for(int j = max(0, i - N - 5); j < i; j++) {
                if((v[j] ^ i) < (v[i] ^ j)) {
                    curr = max(curr, dp[j] + 1);
                }
            }
            dp[i] = curr;
        }
        cout << (*max_element(dp.begin(), dp.end())) << '\n';
    }
    
    return 0;
}