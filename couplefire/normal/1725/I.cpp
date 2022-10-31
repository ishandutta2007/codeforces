#include <bits/stdc++.h>
using namespace std;

const int P = 998244353;

template <class T> T qp(T a, int b) {
    T c = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) c *= a;
    }
    return c;
}

struct mint {
    int x;
    mint(int _x = 0) : x(_x % P) { x < 0 ? x += P : 0; }
    int val() const { return x; }

    mint operator - () const {
        return !x ? 0 : P - x;
    }
    mint inv() const {
        assert(x != 0);
        return qp(*this, P - 2);
    }
    mint &operator += (const mint &rhs) {
        x += rhs.x - P, x += x >> 31 & P;
        return *this;
    }
    mint &operator -= (const mint &rhs) {
        x -= rhs.x, x += x >> 31 & P;
        return *this;
    }
    mint &operator *= (const mint &rhs) {
        x = (long long)x * rhs.x % P;
        return *this;
    }
    mint &operator /= (const mint &rhs) {
        return *this *= rhs.inv();
    }
    friend mint operator + (const mint &lhs, const mint &rhs) {
        mint res = lhs;
        return res += rhs, res;
    }
    friend mint operator - (const mint &lhs, const mint &rhs) {
        mint res = lhs;
        return res -= rhs, res;
    }
    friend mint operator * (const mint &lhs, const mint &rhs) {
        mint res = lhs;
        return res *= rhs, res;
    }
    friend mint operator / (const mint &lhs, const mint &rhs) {
        mint res = lhs;
        return res /= rhs, res;
    }

    friend ostream &operator << (ostream &os, const mint &a) {
        return os << a.val();
    }
};

struct dsu {
    vector<int> fa, sz;
    dsu(int n) : fa(n), sz(n, 1) { iota(fa.begin(), fa.end(), 0); }

    int find(int x) {
        while (x != fa[x]) x = fa[x] = fa[fa[x]];
        return x;
    }
    bool same(int x, int y) { return find(x) == find(y); }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        sz[x] += sz[y], fa[y] = x;
        return true;
    }
    int size(int x) { return sz[find(x)]; }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    mint ans = 1;
    for (int i = 0; i < n - 1; i++) {
        ans *= 2 * i + 1;
    }
    dsu T(n);
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v;
        u--, v--;
        mint l = T.size(u), r = T.size(v);
        ans *= l * l * r * r;
        T.merge(u, v);
    }
    cout << ans << "\n";
    return 0;
}