#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    long long x = 0, y = 0;
    for (int i = 0; i < 2 * n; ++i) {
        int a, b; cin >> a >> b;
        x += a; y += b;
    }
    cout << x / n << " " << y / n << endl;

    return 0;
}