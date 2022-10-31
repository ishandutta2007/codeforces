#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b; cin >> a >> b;
    int now = 1;
    long long ans = 0;
    while(b--) {
        int t; cin >> t;
        int dis = (t - now);
        if(dis < 0) dis += a;
        ans += dis;
        now = t;
    }
    cout << ans << endl;
    return 0;
}