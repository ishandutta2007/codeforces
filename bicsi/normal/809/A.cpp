#include <bits/stdc++.h>

using namespace std;

#define int long long

const int kMod = 1e9 + 7;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> X(n);
    for (auto &x : X)
        cin >> x;

    sort(X.begin(), X.end());

    vector<int> Pow(n + 1);
    Pow[0] = 1;
    for (int i = 1; i <= n; ++i)
        Pow[i] = (Pow[i - 1] + Pow[i - 1]) % kMod;

    int p1 = 0, p2 = n - 1;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        ans += 1LL * Pow[p1] * X[i];
        ans -= 1LL * Pow[p2] * X[i];

        ans %= kMod;
        ans += kMod;
        ans %= kMod;

        p1 += 1;
        p2 -= 1;
    }  

    cout << ans << endl;
    
    return 0;
}