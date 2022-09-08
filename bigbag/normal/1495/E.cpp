/**
 *  created: 01/04/2021, 15:01:14
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 5005555, mod = 1000000007;

int n, a[max_n], tp[max_n];

void read() {
    int m;
    scanf("%d%d", &n, &m);
    vector<int> p(m + 1), k(m + 1), b(m + 1), w(m + 1);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d%d", &p[i], &k[i], &b[i], &w[i]);
    }

    int seed = 0, base = 0;

    auto rnd = [&seed, &base]() {
        int ret = seed;
        seed = (1LL * seed * base + 233) % mod;
        return ret;
    };
    for (int i = 1; i <= m; ++i) {
        seed = b[i];
        base = w[i];
        for (int j = p[i - 1] + 1; j <= p[i]; ++j) {
            tp[j - 1] = rnd() % 2;
            a[j - 1] = rnd() % k[i] + 1;
        }
    }
}

int ans[max_n];
long long sum[2];

void finish() {
    int res = 1;
    for (int i = 0; i < n; ++i) {
        //cout << i << ": " << ans[i] << endl;
        int x = ((ans[i] ^ (1LL * (i + 1) * (i + 1))) + 1) % mod;
        res = 1LL * res * x % mod;
    }
    printf("%d\n", res);
    exit(0);
}

void proc() {
    for (int i = n - 1; i >= 0; --i) {
        tp[i] ^= tp[0];
    }
    sum[0] = sum[1] = 0;
    for (int i = 0; i < n; ++i) {
        sum[tp[i]] += a[i];
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    read();
    if (0) {
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < n; ++i) {
            cout << tp[i] << " ";
        }
        cout << endl;
    }
    proc();
    int shift = 0;
    if (sum[0] > sum[1]) {
        ++ans[0];
        --a[0];
        for (int i = 1; i < n; ++i) {
            if (tp[i]) {
                shift = i;
                break;
            }
        }
        if (!shift) {
            finish();
        }
        rotate(a, a + shift, a + n);
        rotate(tp, tp + shift, tp + n);
        rotate(ans, ans + shift, ans + n);
        proc();
    }
    assert(sum[0] <= sum[1]);
    int pos = 0;
    for (int i = 0; i < n; ++i) {
        if (!tp[i]) {
            ans[i] += a[i];
            pos = max(pos, i + 1);
            while (a[i]) {
                while (!tp[pos % n] || !a[pos % n]) {
                    ++pos;
                }
                int x = min(a[i], a[pos % n]);
                ans[pos % n] += x;
                a[i] -= x;
                a[pos % n] -= x;
            }
        }
    }
    rotate(ans, ans + n - shift, ans + n);
    finish();
    return 0;
}