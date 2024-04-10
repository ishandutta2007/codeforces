#include <bits/stdc++.h>
using namespace std;
 
#define LL long long
 
int main() {
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        int min_x = 0, max_x = 0;
        int min_y = 0, max_y = 0;
        for (int i = 1;i <= n;++i) {
            int x, y;
            cin >> x >> y;
            min_x = min(min_x, x);
            min_y = min(min_y, y);
            max_x = max(max_x, x);
            max_y = max(max_y, y);
        }
        int ans = (max_x - min_x + max_y - min_y) * 2;
        cout << ans << endl;
    }
    return 0;
}