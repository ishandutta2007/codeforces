#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> V(m + 1, 0);
    for (int i = 0; i < n; ++i) {
        int l, r; cin >> l >> r; --l; --r;
        V[l] += 1; V[r + 1] -= 1;
    }

    for (int i = 1; i < m; ++i)
        V[i] += V[i - 1];
    V.pop_back();

    vector<int> pref(m), suff(m);
    
    {
        vector<int> best;
        for (int i = 0; i < m; ++i) {
            int pos = distance(best.begin(), 
                    upper_bound(best.begin(), best.end(), V[i]));
            if (pos == (int)best.size()) best.push_back(0);
            best[pos] = V[i];
            pref[i] = best.size();
        }
    }
    {
        vector<int> best;
        for (int i = m - 1; i >= 0; --i) {
            int pos = distance(best.begin(), 
                    upper_bound(best.begin(), best.end(), V[i]));
            if (pos == (int)best.size()) best.push_back(0);
            best[pos] = V[i];
            suff[i] = best.size();
        }
    }
    
    int ans = 0;
    for (int i = -1; i < m; ++i) {
        int cl = (i == -1 ? 0 : pref[i]);
        int cr = (i == m - 1 ? 0 : suff[i + 1]);
        ans = max(ans, cl + cr);
    }
    cout << ans << endl;


    return 0;
}