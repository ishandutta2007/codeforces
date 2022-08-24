#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    int n, p;
    cin >> n >> p;
    vector<int> v(n);
    for (int i=0;i<n;i++) cin >> v[i];
    int ans = 0;
    int S = 0;
    for (int i=0; i < n; i++) S += v[i];
    int A = 0;
    for (int i=0; i < n-1; i++){
        A += v[i];
        S -= v[i];
        int K = ((A%p)+p) % p;
        int D = ((S%p)+p) % p;
        ans = max(ans, K+D);
    }
    cout << ans << endl;
    return 0;
}