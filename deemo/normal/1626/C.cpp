#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100 + 5;

int n, k[MAXN], h[MAXN];
ll dp[MAXN];

ll f(ll x) {
    return x*(x+1)/2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te; cin >> te;
    while (te--){
        cin >> n;
        for (int i = 0; i < n; i++) cin >> k[i];
        for (int i = 0; i < n; i++) cin >> h[i];

        for (int i = n-2; ~i; i--)
            h[i] = max(h[i], h[i+1] - (k[i+1] - k[i]));

        memset(dp, 63, sizeof(dp));
        for (int i = n-1; ~i; i--) {
            dp[i] = f(h[i] + (k[n-1] - k[i]));
            for (int j = i+1; j < n; j++)
                if (k[j] - k[j-1] >= h[j]) {
                    dp[i] = min(dp[i], dp[j] + f(h[i] + (k[j-1] - k[i])));
                }
        }
        cout << dp[0] << "\n";
    }
    return 0;
}