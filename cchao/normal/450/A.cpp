#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, t;
    cin >> n >> m;
    int ans = 0, x;
    for(int i = 1; i <= n; ++i) {
        cin >> t;
        if(i == 1 || (t + m - 1)/m >= x) { ans=i; x = (t + m - 1)/m; }
    }
    cout << ans << endl;
    return 0;
}