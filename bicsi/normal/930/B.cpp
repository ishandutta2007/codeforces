#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str; cin >> str;
    int n = str.size();

    vector<vector<int>> options(256);
    for (int i = 0; i < n; ++i) {
        options[str[i]].push_back(i);
    }

    double ans = 0;
    vector<int> cnt(256, 0);
    for (auto v : options) {
        if (v.size() == 1) ans += 1.0 / n;
        else {
            int best = 0;
            for (int i = 1; i < n; ++i) {
                int res = 0;
                for (auto x : v) {
                    int pos = (x + i) % n;
                    char chr = str[pos];
                    cnt[chr] += 1;
                }
                for (auto x : v) {
                    int pos = (x + i) % n;
                    char chr = str[pos];
                    if (cnt[chr] == 1) {
                        res += 1;
                    }
                    cnt[chr] = 0;
                }
                best = max(best, res);
            }
            ans += best * 1.0 / n;
        }
    }

    cout << fixed << setprecision(20) << ans << endl;

    return 0;
}