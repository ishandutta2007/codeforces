#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;
const int max_p = 200222;

int used[max_p];
vector<int> primes;

void get_all_primes() {
    for (int i = 2; i < max_p; ++i) {
        if (used[i] == 0) {
            primes.push_back(i);
            if ((long long) i * i < (long long) max_p) {
                for (int j = i * i; j < max_p; j += i) {
                    used[j] = 1;
                }
            }
        }
    }
}


int n, a[max_n], tot[max_n];
vector<int> all[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_primes();
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        int x = a[i];
        for (int j = 0; j < primes.size() && primes[j] * primes[j] <= x; ++j) {
            if (x % primes[j] == 0) {
                int cnt = 0;
                while (x % primes[j] == 0) {
                    x /= primes[j];
                    ++cnt;
                }
                all[primes[j]].push_back(cnt);
            }
        }
        if (x > 1) {
            all[x].push_back(1);
        }
    }
    long long ans = 1;
    for (int p : primes) {
        if (all[p].size() + 2 <= n) {
            continue;
        }
        if (all[p].size() < n) {
            all[p].push_back(0);
        }
        sort(all[p].begin(), all[p].end());
        for (int i = 0; i < all[p][1]; ++i) {
            ans *= p;
        }
    }
    printf("%I64d\n", ans);
    return 0;
}