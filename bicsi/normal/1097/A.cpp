#pragma comment(linker, "/stack:200000000")

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string x; cin >> x;
    for (int i = 0; i < 5; ++i) {
        string y; cin >> y;
        if (x[0] == y[0] || x[1] == y[1]) {
            cout << "YES\n";
            return 0;
        }
    }
    

    cout << "NO\n";
    return 0;
}