#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int main() {
    int n; cin >> n;
    vector<pii> a(n);
    for(auto &v: a) cin >> v.first >> v.second;
    sort(a.begin(), a.end());
    int ans = 0;
    for(auto v: a) {
        if(v.second >= ans) ans = max(ans, v.second);
        else ans = max(ans, v.first);
    }
    cout << ans << endl;
    return 0;
}