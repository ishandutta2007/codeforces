#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<bool> take(n, false);
    for (int i = 0; i < n; ++i) {
        long long cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (a[i] == a[j]) 
                cnt += 1;
        }
        if (cnt >= 2) {
            for (int j = 0; j < n; ++j) {
                if ((a[i] | a[j]) == a[i])
                    take[j] = true;
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i)
        if (take[i])
            ans += b[i];
    cout << ans << endl;

    return 0;
}