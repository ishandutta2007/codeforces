#include <algorithm>
#include <iostream>
#include <tuple>

using namespace std;

const int LIM = 1e6 + 16;
const int MOD = 1e9 + 7;

/// ====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====

/// String Hash Table
template<const int LIM, const int BASE, const int MOD>
struct Hasher
{
    int n;
    int H[LIM];
    int P[LIM];

    /// Calculate x^n % MOD
    int powMOD(int x, int n)
    {
        int res = 1;
        for (; n > 0; n >>= 1)
        {
            if (n & 1) res = (1LL * res * x) % MOD;
            x = (1LL * x * x) % MOD;
        }

        return res;
    }

    /// Init Hash Table
    void init(const string &s)
    {
        n = s.size();
        H[0] = P[0] = 1;

        int b = 1;
        for (int i = 1; i <= n; ++i)
        {
            int v = s[i - 1] - 'a' + 1;
            H[i] = (H[i - 1] + 1LL * v * b) % MOD;
            b = (1LL * b * BASE) % MOD;
        }

        P[n] = powMOD(b, MOD - 2);
        for (int i = n - 1; i >= 1; --i)
            P[i] = (1LL * P[i + 1] * BASE) % MOD;
    }

    /// Fix (x) -> [0, MOD) but without modulo
    int fix(int x)
    {
        while (x < 0) x += MOD;
        while (x >= MOD) x -= MOD;
        return x;
    }

    /// Hash of a range: Hash(s[l..r])
    int query(int l, int r)
    {
        return (1LL * fix(H[r + 1] - H[l]) * P[l]) % MOD;
    }

    /// Longest Common Prefix of 2 substring
    int lcp(int i, int j)
    {
        int k = 0;
        for (int l = 1, r = n - max(i, j) + 1; l <= r; )
        {
            int m = (l + r) >> 1;
            if (query(i, i + m - 1) == query(j, j + m - 1))
            {
                k = m;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }

        return k;
    }
};

/// ====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====

/// Multihasher
typedef tuple<int, int, int, int, int, int, int> Pack;
struct Multihasher
{
    int n;
    Hasher<LIM, 123, int(1e9) + 7> A;
    Hasher<LIM, 1234, int(1e9) + 9> B;
    Hasher<LIM, 12345, int(1e9) + 21> C;
    Hasher<LIM, 123456, int(1e9) + 33> D;
    Hasher<LIM, 1234567, int(1e9) + 87> E;
    Hasher<LIM, 12345678, int(1e9) + 93> F;
    Hasher<LIM, 123456789, int(1e9) + 97> G;

    /// Init Hash Table
    void init(const string &s)
    {
        n = s.size();
        A.init(s);
        B.init(s);
        C.init(s);
        D.init(s);
        E.init(s);
        F.init(s);
        G.init(s);
    }

    /// Multihash of a range: Hash(s[l..r])
    Pack query(int l, int r)
    {
        return Pack(
            A.query(l, r),
            B.query(l, r),
            C.query(l, r),
            D.query(l, r),
            E.query(l, r),
            F.query(l, r),
            G.query(l, r)
        );
    }

    /// Longest Common Prefix of 2 substring
    int lcp(int i, int j)
    {
        int k = 0;
        for (int l = 1, r = n - max(i, j); l <= r; )
        {
            int m = (l + r) >> 1;
            if (query(i, i + m - 1) == query(j, j + m - 1))
            {
                k = m;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }

        return k;
    }
};

/// ====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====

int n, m, k;
string s;
int p[LIM];
Multihasher H;
int main()
{
    /// A little boost
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    /// Input
    cin >> n >> m;
    cin >> s;
    for (int i = 1; i <= m; ++i)
        cin >> p[i];

    H.init(s);
    k = s.size();
    sort(p + 1, p + m + 1);
    for (int i = 1; i + 1 <= m; ++i)
    {
        /// Non intersect
        if (p[i] + k - 1 < p[i + 1]) continue;

        int remaining = n - p[i + 1];
        int intersect = k - (p[i + 1] - p[i]);
        if (H.lcp(0, p[i + 1] - p[i]) != min(remaining, intersect))
        {
            /// Invalid intersect
            cout << 0;
            return 0;
        }
    }

    /// Count free character in string
    int cnt = m == 0 ? n : 0;
    if (m != 0) {
        cnt += p[1] - 1;
        cnt += max(0, n - (p[m] + k - 1));
        for (int i = 2; i <= m; ++i)
            cnt += max(0, p[i] - (p[i - 1] + k));
    }

    /// Number of choice: res = 26^(cnt)
    int res = 1;
    while (cnt-->0)
        res = (1LL * res * 26) % MOD;

    /// Output
    cout << res;
    return 0;
}