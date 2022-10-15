/// can you hear my SOS?
#include <bits/stdc++.h>

using namespace std;

int sol[1 << 24];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        int x = 0;
        cin >> s;
        for (auto &c : s)
            x |= (1 << (c - 'a'));
        sol[x]++;
    }
    for (int bit = 0; bit < 24; bit++)
        for (int mask = (1 << 24) - 1; mask >= 0; mask--)
            if (mask & (1 << bit))
                sol[mask] += sol[mask - (1 << bit)];
    int ans = 0;
    for (int mask = 0; mask < (1 << 24); mask++)
        ans ^= (n - sol[mask]) * (n - sol[mask]);
    cout << ans << "\n";
}