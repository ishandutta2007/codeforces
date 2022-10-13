#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int Mask(string s) {
    int ans = 0;
    for (auto x : s) {
        ans |= (1 << (x - 'a'));
    }
    return ans;
}

int cb(int x) { return __builtin_popcount(x); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int full = Mask("qwertyuiopasdfghjklzxcvbnm");
    cerr << cb(full) << endl;
    
    int msk = full;
    int extra = 0;

    int n; cin >> n;
    while (n--) {
        char op; string s; cin >> op >> s;
        if (op == '.') {
            msk &= (full ^ Mask(s));
        }
        if (op == '!') {
            if (cb(msk) == 1) ++extra;
            msk &= Mask(s);
        } 
        if (op == '?') {
            if (cb(msk) == 1 && msk != Mask(s)) ++extra;
            msk &= (full ^ Mask(s));
        }
    }
    cout << extra << endl;

    return 0;
}