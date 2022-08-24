#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    int ans = 360;
    for (int i=0; i < n; i++){
        int summ = 0;
        for (int j=i; j < n; j++){
            summ += v[j];
            int diff = abs(summ - (360-summ));
            ans = min(ans, diff);
        }
    }
    cout << ans << endl;
    return 0;
}