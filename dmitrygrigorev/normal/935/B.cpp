#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k = -1, x=0, y=0, ans=-1;
    for (int i=0; i < n; i++){
        if (s[i] == 'R') x++;
        else y++;
        if (x==y) continue;
        int K;
        if (x < y) K = 1;
        else K = 2;
        if (k!=K)ans++;
        k = K;
    }
    cout << ans << endl;
    return 0;
}