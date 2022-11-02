#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    
    cin >> n;

    for (int i = 1; i <= n; ++ i) {
        int v1, v2;
        cin >> v1 >> v2;
        int ans = 0;
        while (v1 != 0 || v2 != 0) {
            v2 ++;
            if (v2 == 60) v1 ++, v2 = 0;
            if (v1 == 24) v1 = 0;
            ans ++;
        }
        cout << ans << endl;
    }
    return 0;
}