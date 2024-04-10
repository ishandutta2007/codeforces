#include <bits/stdc++.h>
using namespace std;
int n, a[100010];
int main() {
    int n; cin >> n;
    for(int i = 0; i < n; ++i) {
        int h, m; cin >> h >> m;
        a[i] = h * 60 + m;
    }
    int ans = 0;
    for(int i = 0; i < n; ++i)
        if(a[i] == a[i - ans])
            ans++;
    cout << ans << endl;
    return 0;
}