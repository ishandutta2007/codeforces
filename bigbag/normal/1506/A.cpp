/**
 *  created: 25/03/2021, 16:35:44
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t, n, m;
long long num;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m >> num;
        --num;
        int x = num % n;
        int y = num / n;
        long long ans = 1LL * x * m + y + 1;
        cout << ans << "\n";
    }
    return 0;
}