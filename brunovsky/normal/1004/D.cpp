#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

auto factor_map(int n) {
    unordered_map<int, int> primes;
    for (int p = 2; p * p <= n; p++) {
        while (n % p == 0) {
            primes[p]++;
            n = n / p;
        }
    }
    if (n > 1) {
        primes[n]++;
    }
    return primes;
}

template <typename T>
auto get_divisors(const unordered_map<T, int>& factors, bool one, bool self) {
    vector<T> divs = {1};
    for (const auto& [p, e] : factors) {
        int D = divs.size();
        divs.resize(D * (e + 1));
        for (int n = 1; n <= e; n++) {
            for (int d = 0; d < D; d++) {
                divs[d + n * D] = divs[d + (n - 1) * D] * p;
            }
        }
    }
    if (!one) {
        divs.erase(begin(divs));
    }
    if (!self && !divs.empty()) {
        divs.erase(begin(divs) + (divs.size() - 1));
    }
    return divs;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;

    vector<int> arr(T);
    for (int i = 0; i < T; i++) {
        cin >> arr[i];
    }

    vector<int> freq(T);
    for (int i = 0; i < T; i++) {
        freq[arr[i]]++;
    }

    if (freq[0] != 1) {
        printf("-1\n");
        return 0;
    }
    if (T == 1) {
        printf("1 1\n1 1\n");
        return 0;
    }
    int far = 0;
    for (int i = 1; i < T; i++) {
        if (freq[i] > 0) {
            far = i;
        }
    }
    int cut = 0;
    for (int i = 1; i < T; i++) {
        if (freq[i] != 4 * i) {
            cut = i;
            break;
        }
    }
    if (cut == 0) {
        printf("-1\n");
        return 0;
    }

    auto simulate = [&](int n, int m, int x, int y) {
        if (x >= 1 && y >= 1 && x <= n && y <= m) {
            // simulate
            vector<int> cnt(far + 1);
            bool ok = true;
            for (int i = 1; i <= n && ok; i++) {
                for (int j = 1; j <= m && ok; j++) {
                    int dist = abs(i - x) + abs(j - y);
                    if (dist <= far) {
                        cnt[dist]++;
                    } else {
                        ok = false;
                    }
                }
            }
            for (int i = 1; i <= far && ok; i++) {
                ok = cnt[i] == freq[i];
            }
            if (ok) {
                printf("%d %d\n%d %d\n", n, m, x, y);
                exit(0);
            }
        }
    };

    for (int n : get_divisors(factor_map(T), 1, 1)) {
        int m = T / n;

        // x+y=n+m-far
        // x+y=corner+2
        // WLOG x<=y and corner<=far
        // we try setting x=cut and m-y+1=cut

        // x == cut
        {
            int x = cut;
            int y = n + m - far - x;
            simulate(n, m, x, y);
        }

        // y == cut
        {
            int y = cut;
            int x = n + m - far - y;
            simulate(n, m, x, y);
        }

        // m-y+1 == cut
        {
            int y = m + 1 - cut;
            int x = n + m - far - y;
            simulate(n, m, x, y);
        }

        // n-x+1 == cut
        {
            int x = n + 1 - cut;
            int y = n + m - far - x;
            simulate(n, m, x, y);
        }
    }

    printf("-1\n");
    return 0;
}