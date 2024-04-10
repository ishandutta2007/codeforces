#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int k, n, s, p; cin >> k >> n >> s >> p;
    int need = (n + s - 1) / s * k;
    cout << (need + p - 1) / p << endl;

    return 0;
}