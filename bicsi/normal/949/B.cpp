#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

#define int long long

int GetPosForSz(int k, int sz) {
    if (sz == 1) return 1;
    if (k % 2 == 0) return GetPosForSz(k / 2, sz / 2);
    else return sz / 2 + k / 2 + 1;
}

int GetAtPos(int k) {
    int pw = 1;
    while (k >= pw) {
        k -= pw;
        pw *= 2;
    }
    return GetPosForSz(k, pw);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q; cin >> n >> q;
    while (q--) {
        int pos; cin >> pos;
        if (pos % 2 == 1) {
            cout << pos / 2 + 1 << '\n';
        } else {
            int real_pos = (2 * n - 1 - pos);
            cout << n + 1 - GetAtPos(real_pos) << '\n';
        }
    } 

    return 0;
}