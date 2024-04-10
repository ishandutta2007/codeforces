#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    
    int n, m; cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    vector<int> all;
    for (auto& line : mat) {
        for (auto& x : line) {
            cin >> x;
            all.push_back(x);
        }
    }
    sort(all.begin(), all.end());

    int ans = 0;
    for (int step = (1 << 20); step; step /= 2) {
        if (ans + step >= (int)all.size()) continue;

        ans += step;
        vector<bitset<1024>> bs(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] >= all[ans])
                    bs[i][j] = true;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((bs[i] & bs[j]).count() >= 2)
                    goto done;        
            }
        }
        ans -= step;
done:;
    }
    cout << all[ans] << endl;
    return 0;
}