#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    vector<int> col;
    int z = 1, num = v[0];
    for (int i=1; i < n; i++){
        if (v[i] == num) z++;
        else{
            col.push_back(z);
            z = 1;
            num = v[i];
        }
    }
    col.push_back(z);
    int ans = 0;
    int freed = col[0];
    for (int i=1; i < col.size(); i++){
        int p = min(freed, col[i]);
        ans += min(freed, col[i]);
        freed += col[i] - p;
    }
    cout << ans;
    return 0;
}