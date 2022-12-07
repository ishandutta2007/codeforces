#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define endl "\n"

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector <int> p(n + 1, 0);
    for(int i = 0; i < n; i++) {
        p[i + 1] = p[i];
        if(s[i] == '+') {
            p[i + 1]++;
        } else {
            p[i + 1]--;
        }
    }
    // for(int i = 0; i <= n; i++) {
    //     cout << p[i] << " ";
    // }
    long long ans = 0;
    for(int i = 0; i < 3; i++) {
        vector <pair<int, int>> v;
        for(int j = 0; j <= n; j++) {
            int temp = p[j] % 3;
            while(temp < 0) temp += 3;
            if(temp == i) {
                v.push_back({p[j], 0});
            }
        }
        int m = v.size();
        for(int j = 0; j < m; j++) {
            v[j].second = j;
        //     cout << v[j].first << " " << v[j].second << ";";
        }
        // cout << endl;
        sort(v.begin(), v.end(), [&](pair<int, int> a, pair<int, int> j) {
            if(a.first == j.first) return a.second > j.second;
            return a.first < j.first;
        });
        ordered_set X;
        // set <int> s;
        // for(int j = 0; j < m; j++) {
        //     cout << v[j].first << "," << v[j].second << " ";
        // }
        // cout << endl;

        for(int j = 0; j < m; j++) {
            // s.insert(v[j].second);
            int z = X.order_of_key(v[j].second);
            // cout << z << endl;
            
            // s.insert(v[j].second);
            int aa = X.size();
            X.insert(v[j].second);
            ans += aa - z;
            // cout << z << endl;
        }
        // cout << ans << endl;
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}