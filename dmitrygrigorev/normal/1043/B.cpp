#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n+1);
    v[0] = 0;
    for (int i=0; i < n; i++) cin >> v[i+1];
    vector<int> a;
    for (int i=0;i<n;i++) a.push_back(v[i+1] - v[i]);
    vector<int> ans;
    for (int step=1; step <= n; step++){
        bool c = true;
        for (int i=0; i + step < n; i++) c &= (a[i] == a[i+step]);
        if (c) ans.push_back(step);
    }
    cout << ans.size() << endl;
    for (int i=0;i<ans.size(); i++) cout << ans[i] << " ";

}