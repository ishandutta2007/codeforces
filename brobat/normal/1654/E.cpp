#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef cc_hash_table<int, int, hash<int>> ht;

const int Q = 70;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    if(n < 3) {
        cout << 0;
        return 0;
    }
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int ans = 2;
    for(int d = 0; d <= Q; d++) {
        ht m;
        ht p;
        for(int i = 0; i < n; i++) {
            m[v[i] - i*d]++;
            p[v[i] + i*d]++;
        }
        for(auto i : m) {
            ans = max(ans, i.second);
        }
        for(auto i : p) {
            ans = max(ans, i.second);
        }
    }
    for(int i = 0; i < n; i++) {
        // Assume starting element is v[i].
        ht m;
        for(int j = 1; j <= 1430; j++) {
            if(i + j == n) break;
            int d = v[i + j] - v[i];
            if(d % j == 0) m[d/j]++;
        }
        for(auto i : m) {
            ans = max(ans, i.second + 1);
        }
    }
    cout << n - ans;
    
    return 0;
}