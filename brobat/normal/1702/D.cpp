#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = s.length();
        int p;
        cin >> p;
        vector <pair<char, int>> v(n);
        int curr = n;
        for(int i = 0; i < n; i++) {
            v[i] = {s[i], i};
            curr += (s[i] - 'a');
        }
        sort(v.begin(), v.end());
        while(curr > p) {
            auto x = v.back();
            v.pop_back();
            curr -= (x.first - 'a');
            curr--;
        }
        sort(v.begin(), v.end(), [&](pair<char, int> a, pair<char, int> b) {
            return a.second < b.second;
        });
        for(auto i : v) cout << i.first;
        cout << '\n';
    }
    
    return 0;
}