#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    bool bit = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0) {
            cout << a[i] / 2 << "\n";
        } else {
            int sgn = 0;
            a[i] += 1000;
            a[i] /= 2;
            if (bit) a[i] += 1;
            bit = !bit;
            a[i] -= 500;
            cout << a[i] << "\n";
        }
    }

    return 0;
}