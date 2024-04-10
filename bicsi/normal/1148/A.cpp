#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long a, b, ab; cin >> a >> b >> ab;
    int x = min(a, b);
    ab += x;
    a -= x;
    b -= x;

    long long ans = 2 * ab + (a > 0 || b > 0);
    cout << ans << endl;

    return 0;
}