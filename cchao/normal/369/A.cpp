#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b, da = 0, db = 0, t, ans = 0;
    cin >> n >> a >> b;
    while(n--) {
        cin >> t;
        if(t == 2 && b > db) db++;
        else if(a > da) da++;
        else ans++;
    }
    cout << ans << endl;
    return 0;
}