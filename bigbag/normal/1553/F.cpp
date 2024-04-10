/**
 *  created: 22/07/2021, 18:30:48
**/

#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2") // WINDOWS ONLY

#include <bits/stdc++.h>

using namespace std;

const int max_n = 303333, inf = 1000111222;
const int magic = 555;

int n, a[max_n], cnt[magic][magic];
int real_cnt[max_n], sum[max_n];
long long real_cnt2[max_n], sum2[max_n];
long long ans[max_n];

int get_sum(int l, int r) {
    r = min(r, max_n - 1);
    if (l <= 0) {
        return sum[r];
    }
    return sum[r] - sum[l - 1];
}

long long get_sum2(int l, int r) {
    r = min(r, max_n - 1);
    if (l <= 0) {
        return sum2[r];
    }
    return sum2[r] - sum2[l - 1];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output2.txt", "w", stdout);
    if (0) {
        mt19937 gen;
        n = 200000;
        for (int i = 0; i < n; ++i) {
            a[i] = gen() % 300000 + 1;
        }
    } else {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
    }
    int last = 0;
    long long tot_sum = 0;
    for (int i = 0; i < n; ++i) {
        if (i) {
            ans[i] = ans[i - 1];
        }

        if (i % magic == 0) {
            last = i;
            for (int j = 1; j < max_n; ++j) {
                sum[j] = sum[j - 1] + real_cnt[j];
                sum2[j] = sum2[j - 1] + real_cnt2[j];
            }
        }

        if (a[i] < magic) {
            for (int rem = 0; rem < a[i]; ++rem) {
                ans[i] += 1LL * rem * cnt[a[i]][rem];
            }
        } else {
            for (int j = last; j < i; ++j) {
                ans[i] += a[j] % a[i];
                ans[i] -= a[j];
            }
            ans[i] += tot_sum;
            for (int x = 0, val = 0; x < max_n; x += a[i], ++val) {
                ans[i] -= 1LL * val * a[i] * get_sum(x, x + a[i] - 1);
            }
        }

        for (int j = last; j < i; ++j) {
            ans[i] += a[i] % a[j];
            ans[i] -= a[i];
        }
        ans[i] += 1LL * i * a[i];
        int x = 1;
        while (x <= a[i]) {
            const int val = a[i] / x;
            int y = a[i] / val + 1;
            ans[i] -= 1LL * val * get_sum2(x, y - 1);
            //cout << a[i] << ": " << val << "   " << "[" << x << " " << y << ")" << endl;
            x = y;
        }

        tot_sum += a[i];
        ++real_cnt[a[i]];
        real_cnt2[a[i]] += a[i];
        for (int mod = 1; mod < magic; ++mod) {
            ++cnt[mod][a[i] % mod];
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%lld ", ans[i]);
    }
    puts("");
    return 0;
}