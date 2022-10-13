#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<vector<int>> cnt(n + 1);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        cnt[n - x].push_back(i);
    }

    int at = 0;
    vector<int> ans(n, -1);
    for (int i = 1; i <= n; ++i) {
        if (cnt[i].size() % i) {
            cout << "Impossible\n";
            return 0;
        }

        for (int j = 0; j < (int)cnt[i].size(); ++j) {
            if (j % i == 0) ++at;
            ans[cnt[i][j]] = at - 1;
        }
    }

    cout << "Possible\n";
    for (int i = 0; i < n; ++i)
        cout << ans[i] + 1 << " ";
    cout << endl;

    return 0;
}