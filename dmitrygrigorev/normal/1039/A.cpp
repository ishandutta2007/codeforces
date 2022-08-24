#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t;
    cin >> n >> t;
    vector<int> a(n), b(n);
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) cin >> b[i];
    for (int i=0;i<n;i++) b[i]--;
    vector<pair<int, int> > ans;
    for (int i=0;i<n;i++) ans.push_back({1, 3e18});
    int mx = 0, mn = 1e9;
    for (int i=0;i<n;i++){
        mx = max(mx, b[i]);
        mn = min(mn, b[i]);
        ans[b[i]].first = max(ans[b[i]].first, a[i] + t);
        if (mn <= i) ans[i].first = max(ans[i].first, a[i]+t);
        if (mx > i) ans[i].first = max(ans[i].first, a[i+1]+t);
        if (b[i] < n-1){
            int ind = b[i];
            if (i <= b[i]) ind++;
            ans[b[i]].second = min(ans[b[i]].second, a[ind]+t-1);
        }
    }
    vector<int> res = {-1};
    for (int i=0;i<n;i++){
        if (ans[i].first > ans[i].second || ans[i].second <= res.back()){
            cout << "No";
            return 0;
        }
        res.push_back(max(res.back()+1, ans[i].first));
    }
    cout << "Yes" << endl;
    for (int i=0;i<n;i++) cout << res[i+1] << " ";
}