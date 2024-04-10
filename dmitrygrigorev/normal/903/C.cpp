#include <bits/stdc++.h>
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int ans = 1;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    map<int, int> m;
    for (int i=0; i < n; i++){
        m[v[i]]++;
        ans = max(ans, m[v[i]]);
    }
    cout << ans << endl;
    return 0;
}