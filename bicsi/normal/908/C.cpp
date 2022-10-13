#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, r; cin >> n >> r;

    vector<pair<int, double>> circs;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        double y = r;

        for (int j = 0; j < i; ++j) {
            int delta = x - circs[j].first;
            if (abs(delta) == 2 * r) y = max(y, circs[j].second);
            if (abs(delta) < 2 * r) {
                y = max(y, circs[j].second + sqrt(4.0 * r * r - delta * delta));
            }
        }
        circs.emplace_back(x, y);
    }

    cout << fixed << setprecision(20);
    for (auto x : circs)
        cout << x.second << " ";
    cout << endl;


    return 0;
}