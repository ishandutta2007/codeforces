#include <bits/stdc++.h>
using namespace std;
#define maxn 200000 + 10

int t, n, k;

int32_t main() {
    cin.tie(0), cout.sync_with_stdio(0);
    
    cin >> t;
    while (t --) {
        cin >> n >> k;
        int tmp = n / k;
        int las = n - n / k * k;

        int v1 = k - las; // v1 * (tmp);
        int v2 = las;     // v1 * (tmp + 1);
//        cout << "v1 = " << v1 << "  v2 = " << v2 << endl;
        if (v2 > k / 2) v2 = k / 2, v1 = k - v2;

        cout << v1 * tmp + v2 * (tmp + 1) << endl;
    }
    return 0;
}