#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int maxx = 1e6 + 5;
    vector<vector<int>> small(maxx);

    for (int i = 2; i < maxx; ++i) {
        if (small[i].empty()) {
            for (int j = i; j < maxx; j += i) {
                small[j].push_back(i);
            }
        }
    }
    
    auto get_lowest = [&](int x) {
        int ans = 1e9;
        for (auto p : small[x]) {
            if (p == x) continue;
            ans = min(ans, x - p + 1);
        }
        return ans;
    };

    int n; cin >> n;
    int ans = n;
    for (int i = get_lowest(n); i <= n; ++i) {
        ans = min(ans, get_lowest(i));
    }
    cout << ans << endl;
    
    return 0;
}