#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> V(n);
    for (int i = 0; i < n; ++i) {
        cin >> V[i]; 
        V[i] -= 1;   
    }

    vector<int> pref(n, 0), suff(n, 0);

    for (int i = 0; i < n; ++i) {
        if (i > 0) pref[i] = pref[i - 1];
        if (V[i] == 0) pref[i] += 1;
    }

    for (int i = n - 1; i >= 0; --i) {
        if (i < (n - 1)) suff[i] = suff[i + 1];
        if (V[i] == 1) suff[i] += 1;
    }

    int best = 0;
    for (int i = 0; i < n; ++i) {
        vector<int> cnt = {0, 0};
        for (int j = i; j < n; ++j) {
            for (int k = V[j]; k <= 1; ++k) {
                cnt[V[j]] = max(cnt[V[j]], 1 + cnt[k]);
            }

            int now = max(cnt[0], cnt[1]);
            if (i > 0) now += pref[i - 1];
            if (j + 1 < n) now += suff[j + 1];
            best = max(best, now);
        }
    }

    cout << best << endl;

    return 0;
}