#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MOD = (int) 1e9 + 7;

int add(int a, int b) {
        a += b;
        if (a >= MOD) {
                return a - MOD;
        }
        if (a < 0) {
                return a + MOD;
        }
        return a;
}

int mul(int a, int b) {
        return a * (ll) b % MOD;
}

int pw(int a, int b) {
        int r = 1;
        while (b) {
                if (b & 1) {
                        r = mul(r, a);
                }
                a = mul(a, a);
                b /= 2;
        }
        return r;
}

int dv(int a, int b) {
        return mul(a, pw(b, MOD - 2));
}

const int N = (int) 1e5 + 7;
int n;
int k;
int dig[N];
int fact[N];
int inv[N];
string s;
int suf[N];
int i10[N];
int ans;

int comb(int n, int k) {
        return mul(fact[n], mul(inv[k], inv[n - k]));
}

int get(int l, int r) {
        int val = add(suf[l], -suf[r + 1]);
        return mul(val, i10[n - r]);
}

void upd_dumb(int l, int r) {
        int num = get(l, r);
        int cuts = k - (l != 1) - (r != n);
        int places = max(0, l - 2) + max(0, n - r - 1);
        if (places >= cuts) {
                ans = add(ans, mul(comb(places, cuts), num));
        }
}

void upd(int l, int r) {
        int num = get(l, r);
        int cuts = k - 2;
        int places = l + n - r - 3;
        if (places >= cuts) {
                ans = add(ans, mul(comb(places, cuts), num));
        }
}

int cur;
int ln = 1;
int sum[N];

void grow() {
        cur = add(cur, -get(n - ln, n - 1));
        cur = mul(cur, 10);
        ln++;
        cur = add(cur, sum[n - 1]);
        cur = add(cur, -sum[ln]);
}

void upd_len(int len) {
        int cuts = k - 2;
        int places = n - len - 2;
        if (places >= cuts) {
                ans = add(ans, mul(comb(places, cuts), cur));
        }
        grow();
}

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        fact[0] = 1;
        for (int i = 1; i < N; i++) {
                fact[i] = mul(fact[i - 1], i);
        }
        inv[N - 1] = dv(1, fact[N - 1]);
        for (int i = N - 2; i >= 0; i--) {
                inv[i] = mul(inv[i + 1], i + 1);
        }
        cin >> n >> k >> s;
        for (int i = 1; i <= n; i++) {
                dig[i] = s[i - 1] - '0';
                sum[i] = add(sum[i - 1], dig[i]);
        }
        int p10 = 1;
        for (int i = n; i >= 1; i--) {
                suf[i] = add(suf[i + 1], mul(p10, dig[i]));
                p10 = mul(p10, 10);
        }
        i10[N - 1] = dv(1, pw(10, N - 1));
        for (int i = N - 2; i >= 0; i--) {
                i10[i] = mul(10, i10[i + 1]);
        }
        for (int i = 1; i <= n; i++) {
                upd_dumb(1, i);
        }
        for (int i = 2; i < n; i++) {
                cur = add(cur, dig[i]);
        }
        for (int i = 2; i <= n; i++) {
                upd_dumb(i, n);
        }
        for (int i = 1; i <= n - 2; i++) {
                upd_len(i);
        }
        cout << ans << "\n";
}