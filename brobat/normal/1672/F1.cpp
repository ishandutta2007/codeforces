#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> v(n);
        vector <int> cnt(n, 0);
        for(int i = 0; i < n; i++) {
            cin >> v[i].first; --v[i].first;
            v[i].second = i;
            cnt[v[i].first]++;
        }
        sort(v.begin(), v.end(), [&](pair<int, int> a, pair<int, int> b) {
            if(cnt[a.first] == cnt[b.first]) {
                return a.first > b.first;
            }
            return cnt[a.first] > cnt[b.first];
        });
        int id = 0;
        for(int i = 1; i < n; i++) {
            if(v[i].first != v[i - 1].first) {
                id = i;
                break;
            }
        }
        vector <int> ans(n);
        for(int i = 0; i < n; i++) {
            ans[v[i].second] = v[(i + id) % n].first + 1;
        }
        for(auto i : ans) cout << i << " ";
        cout << '\n';

    }
    
    return 0;
}