#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

int mul(int x, int y) {
    return (1LL * x * y) % mod;
}

int power(int a, int b) {
    if (b == 0) {
        return 1 % mod;
    }
    if (b % 2 == 0) {
        return power(mul(a, a), b / 2);
    }
    return mul(a, power(a, b - 1));
}

int inv(int x) {
    return power(x, mod - 2);
}

const int max_n = 200222;
const int r100 = inv(100);

int n, q, p[max_n], pr[max_n], ipr[max_n], sum[max_n];
set<int> all;

int func(int l, int r) {
    int res = 0;
    if (r > 1) {
        res = sum[r - 2];
    }
    if (l) {
        res += mod - sum[l - 1];
        res %= mod;
        res = mul(res, ipr[l - 1]);
    }
    res += 1;
    res %= mod;
    int k = ipr[r - 1];
    if (l) {
        k = mul(k, pr[l - 1]);
    }
    res = mul(res, k);
    //cout << "$" << l << " " << r << ": " << res << endl;
    return res;
}

const bool div2 = true;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    if (div2) {
        scanf("%d", &n);
    } else {
        scanf("%d%d", &n, &q);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &p[i]);
        p[i] = mul(p[i], r100);
        pr[i] = p[i];
        if (i) {
            pr[i] = mul(pr[i], pr[i - 1]);
        }
        ipr[i] = inv(pr[i]);
        sum[i] = pr[i];
        if (i) {
            sum[i] += sum[i - 1];
            sum[i] %= mod;
        }
    }
    all.insert(0);
    all.insert(n);
    int ans = func(0, n);
    if (div2) {
        printf("%d\n", ans);
        return 0;
    }
    while (q--) {
        int pos;
        scanf("%d", &pos);
        --pos;
        if (all.count(pos)) {
            auto it = all.find(pos);
            ++it;
            int r = *it;
            --it;
            --it;
            int l = *it;
            ++it;
            all.erase(it);
            ans += mod - func(l, pos);
            ans %= mod;
            ans += mod - func(pos, r);
            ans %= mod;
            ans += func(l, r);
            ans %= mod;
        } else {
            auto it = all.lower_bound(pos);
            int r = *it;
            --it;
            int l = *it;
            ans += func(l, pos);
            ans %= mod;
            ans += func(pos, r);
            ans %= mod;
            ans += mod - func(l, r);
            ans %= mod;
            all.insert(pos);
        }
        printf("%d\n", ans);
    }
    return 0;
}