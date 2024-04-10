#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int last_cur;
int Build(int depth, int parity, int cur) {
    assert(depth >= -1);
    if (depth <= 0 && parity == cur % 2) {
        return cur + 1;
    } else {
        cur = Build(depth - 1, !parity, cur);
        if (depth <= 0 && parity == cur % 2)
            return cur + 1;
        int root_cur = cur;
        assert(root_cur % 2 == parity);
        cur = Build(depth - 1, parity, cur + 1);
        last_cur = root_cur;
        return cur;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    
    int at = 1, pw = 2, depth = 0;
    while (at + pw <= n) {
        at += pw;
        pw *= 2;
        depth += 1;
    }

    if (n == 1) {
        cout << 1 << endl;
    } else {
        int ans = 0;
        if (Build(depth, 0, 1) == n + 1) ans += 1;
        if (Build(depth, 1, 1) == n + 1) ans += 1;
        cout << ans << endl;
    }

    return 0;
}