#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

using Bitset = bitset<7001>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Bitset sqfree;
    sqfree.set();
    for (int i = 1; i <= 7000; ++i) {
        for (int d = 2; d * d <= i; ++d) {
            if (i % (d * d) == 0)
                sqfree[i] = false;
        }
    }

    // Compute masks.    
    vector<Bitset> masks(7001), init(7001);
    for (int i = 1; i <= 7000; ++i) {
        for (int j = 1; j * i <= 7000; ++j) {
            if (sqfree[j])
                masks[i][i * j] = true;
            init[i * j][i] = true;
        }
    }
    /*
    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= 10; ++j) {
            cout << masks[i][j];
        }
        cout << endl;
    }
    */
    int n, q; cin >> n >> q;
    vector<Bitset> bs(n);
    string ret = "";

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int x, v; cin >> x >> v; --x;
            bs[x] = init[v];
        }
        if (t == 2) {
            int x, y, z; cin >> x >> y >> z; --x; --y; --z;
            bs[x] = bs[y] ^ bs[z];
        }
        if (t == 3) {
            int x, y, z; cin >> x >> y >> z; --x; --y; --z;
            bs[x] = bs[y] & bs[z];
        }
        if (t == 4) {
            int x, v; cin >> x >> v; --x;
            int ans = (bs[x] & masks[v]).count();
            ret += '0' + ans % 2;
        }
    }
    
    cout << ret << endl;
    return 0;
}