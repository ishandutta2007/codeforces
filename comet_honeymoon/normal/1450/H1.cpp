#include<bits/stdc++.h>
using namespace std;

const int p = 998244353, inv2 = (p + 1) / 2;
struct Z {
    int x;
    Z (int x0 = 0) : x(x0) {}
};
int check(int x) { return x >= p ? x - p : x; }
Z operator +(const Z a, const Z b) { return check(a.x + b.x); }
Z operator -(const Z a, const Z b) { return check(a.x - b.x + p); }
Z operator -(const Z a) { return check(p - a.x); }
Z operator *(const Z a, const Z b) { return 1LL * a.x * b.x % p; }
Z &operator +=(Z &a, const Z b) { return a = a + b; }
Z &operator -=(Z &a, const Z b) { return a = a - b; }
Z &operator *=(Z &a, const Z b) { return a = a * b; }

Z qpow(Z a, int k) {
    Z ans = 1;
    while (k) {
        if (k & 1) ans *= a;
        a *= a;
        k >>= 1;
    }
    return ans;
}

const int maxn = 200005;
Z fac[maxn], inv[maxn], ifac[maxn];
Z C(int n, int m) {
    if (n < m || n < 0 || m < 0) return 0;
    return fac[n] * ifac[m] * ifac[n - m];
}
void init() {
    fac[0] = fac[1] = inv[1] = ifac[0] = ifac[1] = 1;
    for (int i = 2; i < maxn; i++)
        fac[i] = fac[i - 1] * i,
        inv[i] = -inv[p % i] * (p / i),
        ifac[i] = ifac[i - 1] * inv[i];
}

struct node {
    int n, m; Z ans;
    // sum_{i = 0}^{n}{m\choose i}
    node (int n0, int m0) : n(n0), m(m0), ans(0) {}
    void nU() { ans += C(m, ++n); }
    void nD() { ans -= C(m, n--); }
    void mU() {
        ans += ans - C(m++, n);
        if (m == 0) ans = (n >= 0);
    }
    void mD() {
        if (m == 0) ans = 0;
        (ans += C(--m, n)) *= inv2;
    }
} L0(0, -1), L1(-1, -2), L2(0, -1), L3(-1, -2);

int n, m;
void nU() { L0.nU(), L1.nU(); n++; }
void nD() { L0.nD(), L1.nD(); n--; }
void mU() { L0.mU(), L1.mU(), L2.mU(), L3.mU(), L2.nU(), L3.nU(); m++; }
void mD() { L0.mD(), L1.mD(), L2.mD(), L3.mD(), L2.nD(), L3.nD(); m--; }

Z calc() {
    Z ans = 0;
    if (m == 1) {
        for (int i = 0; i <= m; i++) if (!((n + i) & 1))
            ans += abs(n - i) * C(m, i);
        return ans * inv2;
    }
    ans = 2 * ((n + p) * L0.ans - m * L1.ans) - ((n + p) * L2.ans - m * L3.ans);
    ans *= qpow(inv2, m);
    return ans;
}

int main() {
    init();
    int L, q; char s[maxn];
    scanf("%d%d", &L, &q);
    scanf("%s", s + 1);
    for (int i = 1; i <= L; i++)
        if (s[i] == 'b')
            i & 1 ? nD() : nU();
        else if (s[i] == '?')
            i & 1 ? mU() : (mU(), nU());
    printf("%d\n", calc());
    while (q--) {
        int x; char c; scanf("%d", &x);
        c = getchar(); while (c != 'w' && c != 'b' && c != '?') c = getchar();
        if (s[x] == 'b')
            x & 1 ? nU() : nD();
        else if (s[x] == '?')
            x & 1 ? mD() : (mD(), nD());
        s[x] = c;
        if (s[x] == 'b')
            x & 1 ? nD() : nU();
        else if (s[x] == '?')
            x & 1 ? mU() : (mU(), nU());
        printf("%d\n", calc());
    }
}