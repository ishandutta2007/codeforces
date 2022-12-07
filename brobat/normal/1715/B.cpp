#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, k, b, s;
        cin >> n >> k >> b >> s;
        if(s >= k*b && s - k*b <= (k - 1)*n) {
            vector <int> v;
            int rem = s - k*b;
            while(rem) {
                v.push_back(min(rem, k - 1));
                rem -= min(rem, k - 1);
            }
            while((int)v.size() < n) v.push_back(0);
            v.front() += k*b;
            for(auto i : v) cout << i << ' ';
            cout << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    
    return 0;
}