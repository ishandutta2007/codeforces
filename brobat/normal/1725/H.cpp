#include <bits/stdc++.h>
using namespace std;
 
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i;
        v[i].first = (v[i].first % 3 == 0 ? 0 : 1);
    }
    sort(v.begin(), v.end());
    if(v[n/2].first == 0) cout << 2 << '\n';
    else cout << 0 << '\n';
    vector<int> ans(n, 1);
    for(int i = 0; i < n/2; i++) {
        ans[v[i].second] = 0;
    }
    for(auto i : ans) cout << i;
    return 0;
}