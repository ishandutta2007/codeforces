#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector <int> p(n);
    p[0] = v[0];
    for(int i = 1; i < n; i++) {
        p[i] = p[i - 1] + v[i];
    }
    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << p[n - a - 1 + b] - (n - a - 1 < 0 ? 0 : p[n - a - 1]) << '\n';
    }
    
    return 0;
}