#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<int> v(n), t(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    priority_queue<int> pq;
    int melted_from_all = 0;

    for (int i = 0; i < n; ++i) {
        pq.emplace(-(v[i] + melted_from_all));
        
        int ans = 0;
        while (pq.size()) {
            int add = (-pq.top() - melted_from_all);
            if (add < t[i]) {
                ans += add;
                pq.pop();
            }
            else break;
        }    
        ans += pq.size() * t[i];
        melted_from_all += t[i];
        cout << ans << ' ';
    }
    cout << endl;

    return 0;
}