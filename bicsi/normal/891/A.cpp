#include <bits/stdc++.h>

using namespace std;

int __gcd(int a, int b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return __gcd(a, b % a);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;

    vector<int> dp(n + 1, 1e9);
    vector<int> A(n);
    dp[0] = 0;

    int non1 = 0;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        non1 += (A[i] != 1);
    }

    if (non1 < n) {
        cout << non1 << endl;
        return 0;
    }


    int cost1 = 1e9;
    for (int i = 0; i < n; ++i) {
        int gc = 0;
        for (int j = i; j < n; ++j) {
            gc = __gcd(gc, A[j]);
            if (gc == 1) {
                cost1 = min(cost1, j - i);
                break;
            }
        }
    }
    
    if (cost1 > 2 * n) {
        cout << -1 << endl;
        return 0;
    }

    cout << cost1 + (n - 1) << endl;
    
    return 0;
}