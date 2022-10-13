#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> small(2e5);
    for (int i = 1; i < 2e5; ++i)
        small[i] = i;

    for (int i = 2; i < 2e5; ++i) {
        if (small[i] != i) continue;
        for (int j = i + i; j < 2e5; j += i)
            small[j] = i;
    }

    auto fact = [&](int x) {
        vector<pair<int, int>> ans;
        while (x > 1) {
            int d = small[x];
            int e = 0;
            assert(x % d == 0);
            while (x % d == 0) {
                x /= d;
                e += 1;
            }
            ans.emplace_back(d, e);
        }
        return ans;
    };

    int n, k; cin >> n >> k;
    vector<int> cnt(5e5, 0);
    long long total = 0;

    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        auto ans = fact(x);
        long long seek = 1;
        int now = 1;
        for (auto& p : ans) {
            p.second %= k;
            if (p.second) {
                if (seek != -1) {
                    for (int i = 0; i < k - p.second; ++i) {
                        seek = 1LL * seek * p.first;
                        if (seek > 2e5) {
                            seek = -1;
                            break;
                        }
                    }
                }
            }
            for (int i = 0; i < p.second; ++i)
                now *= p.first;
        }
        if (seek != -1) {
            total += cnt[seek];
        }
        cnt[now] += 1;
    }
    cout << total << endl;

    return 0;
}