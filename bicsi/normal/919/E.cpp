#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;
#define int long long

int kMod;

struct ModInt {
    int n;

    ModInt(int n = 0) : n(n % kMod) {}
    ModInt operator+(const ModInt& oth) { return n + oth.n; }
    ModInt operator-(const ModInt& oth) { return n - oth.n; }
    ModInt operator*(const ModInt& oth) { return n * oth.n; }
    int get() { return n < 0 ? n + kMod : n; }
};

ModInt lgpow(ModInt b, int e) {
    ModInt r;
    for (r = 1; e; e /= 2, b = b * b)
        if (e % 2) r = r * b;
    return r;
}
ModInt inv(ModInt x) { return lgpow(x, kMod - 2); }

int Euclid(int a, int b, int &x, int &y) {
    if (b) {
        int d = Euclid(b, a % b, y, x);
        return y -= a/b * x, d;
    } else return x = 1, y = 0, a;
}

pair<int, int> CRT(int m1, int r1, int m2, int r2) {
    int s, t;
    int g = Euclid(m1, m2, s, t);
    if (r1 % g != r2 % g) return make_pair(0, -1);
    int z = (s * r2 * m1 + t * r1 * m2) % (m1 * m2);
    if (z < 0) z += m1 * m2;
    assert(z % m1 == r1);
    assert(z % m2 == r2);
    return make_pair(m1 * m2 / g, z / g);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int aa, bb, x; 
    cin >> aa >> bb >> kMod >> x;
    ModInt a = aa, b = bb;

    ModInt pw = b;
    ModInt mul = inv(a);
    
    int ans = 0;
    for (int i = 0; i < (kMod - 1); ++i) {
        int m, r;
        tie(m, r) = CRT(kMod, pw.get(), kMod - 1, i);
        int now = (x / m) + (x % m >= r);
        ans += now;
        pw = pw * mul;
    }
    cout << ans << endl;

    return 0;
}