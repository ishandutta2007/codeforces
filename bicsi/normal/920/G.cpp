#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int red[1000005], sgn[1000005];
vector<int> divs[1000005];

void Sieve() {
    for (int i = 1; i <= 1000000; ++i) {
        red[i] = 1; sgn[i] = -1;
    }

    for (int i = 1; i <= 1000000; ++i) {
        if (red[i] != 1) continue;
        for (int j = i; j <= 1000000; j += i) {
            red[j] *= i;
            sgn[j] = -sgn[j];
        }
    }

    for (int i = 1; i <= 1000000; ++i) {
        if (red[i] != i) continue;
        for (int j = i; j <= 1000000; j += i)
            if (red[j] == j) divs[j].push_back(i);
    }
}

int Query(int a, int p) {
    if (a <= 0) return 0;

    int ans = 0;
    for (auto x : divs[red[p]]) {
        ans += (a / x) * sgn[x];
    }
    return ans; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Sieve();

    int q; cin >> q;
    while (q--) {
        int x, p, k; cin >> x >> p >> k;
        k += Query(x, p);
        for (int step = (1 << 28); step; step /= 2) {
            x += step;
            if (Query(x, p) >= k)
                x -= step;
        } 
        cout << x + 1 << '\n';
    }

    return 0;
}