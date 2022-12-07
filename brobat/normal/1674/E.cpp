#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = (int)1E18;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int ans = (int)1E18;
    for(int i = 1; i < n; i++) {
        int a = v[i - 1];
        int b = v[i];
        if(a > b) swap(a, b); // a < b
        if(a * 2 <= b) ans = min(ans, (b + 1)/2);
        else {
            int x = b - a;
            a -= x;
            b -= 2*x;
            x += ((a + b + 2)/3);
            ans = min(ans, x);
        }
        if(i != n - 1) {
            int a = v[i - 1];
            int b = v[i + 1];
            if(a > b) swap(a, b);
            ans = min(ans, a + (b - a + 1)/2);
        }
    }
    sort(v.begin(), v.end());
    ans = min(ans, (v[0] + 1)/2 + (v[1] + 1)/2);
    cout << ans;
    
    return 0;
}