#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    for (int msk = 0; msk < (1 << n); ++msk) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (msk & (1 << i)) sum -= v[i];
            else sum += v[i];
        }

        sum = (sum % 360 + 360) % 360;
        if (sum == 0) {
            cout << "YES\n";
            return 0;
        }

    }
    
    cout << "NO\n";
    return 0;
}