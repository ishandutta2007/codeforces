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
    
    // cerr << "A" << endl;

    vector<int> pref(n), suff(n);
    for (int i = 0; i < n; ++i) {
        pref[i] = v[i];
        if (i > 0) pref[i] |= pref[i - 1];
    }

    for (int i = n - 1; i >= 0; --i) {
        suff[i] = v[i];
        if (i + 1 < n) suff[i] |= suff[i + 1];
    }
    
    // cerr << "B" << endl;

    if (n == 1) {
        cout << v[0] << endl;
        return 0;
    }
    
    int best = -1, choose = -1;
    for (int i = 0; i < n; ++i) {
        int oth = 0;
        if (i > 0) oth |= pref[i - 1];
        if (i + 1 < n) oth |= suff[i + 1];
        int now = (v[i] & (~oth));
        if (best < now) {
            best = now;
            choose = i;
        }
    }

    cout << v[choose] << " ";
    for (int i = 0; i < n; ++i) {
        if (i != choose) {
            cout << v[i] << " ";
        }
    }
    cout << endl;

    return 0;
}