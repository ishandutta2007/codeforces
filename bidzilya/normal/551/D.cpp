#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

inline int GetBit(long long mask, int num)
{
    return (mask >> num) & 1;
}

int GetBinaryPow(int x, long long pw, int mod)
{
    if (pw == 0) {
        return 1 % mod;
    }
    if (pw & 1) {
        return (1LL * x * GetBinaryPow(x, pw - 1, mod)) % mod;
    }
    return GetBinaryPow((1LL * x * x) % mod, pw >> 1, mod);
}

typedef vector<vector<int> > Matr;

Matr MatrMult(const Matr& a, const Matr& b, int mod)
{
    Matr r(a.size(), vector<int>(a.size(), 0));
    for (int i = 0; i < (int) a.size(); ++i) {
        for (int j = 0; j < (int) b.size(); ++j) {
            for (int k = 0; k < (int) a.size(); ++k) {
                r[i][j] += (1LL * a[i][k] * b[k][j]) % mod;
                if (r[i][j] >= mod) {
                    r[i][j] -= mod;
                }
            }
        }
    }
    return r;
}

Matr GetMatrBinaryPow(const Matr& a, long long pw, int mod)
{
    if (pw == 0) {
        Matr ed(a.size(), vector<int>(a.size(), 0));
        ed[0][0] = ed[1][1] = 1 % mod;
        return ed;
    }
    if (pw & 1) {
        return MatrMult(a, GetMatrBinaryPow(a, pw - 1, mod), mod);
    }
    return GetMatrBinaryPow(MatrMult(a, a, mod), pw >> 1, mod);
}

// f[2] = 3
// f[3] = 5
int GetMyFib(long long n, int mod)
{
    if (n == 2) {
        return 3 % mod;
    }
    if (n == 3) {
        return 5 % mod;
    }
    Matr m(2, vector<int>(2, 0));
    m[0][0] = m[0][1] = m[1][0] = 1 % mod;
    m = GetMatrBinaryPow(m, n - 3, mod);
    int r = (5LL * m[0][0]) % mod + (3LL * m[1][0]) % mod;
    r %= mod;
    return r;
}

long long GetAns(long long n, int b, int mod)
{
    if (b == 0) {
        return GetMyFib(n, mod);
    } else {
        int r = GetBinaryPow(2, n, mod) - GetAns(n, 0, mod);
        if (r < 0) {
            r += mod;
        }
        return r;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    int l;
    int mod;

    cin >> n >> k >> l >> mod;

    int amount_of_bits_in_k = 0;
    long long ck = k;
    while (ck > 0) {
        ++amount_of_bits_in_k;
        ck >>= 1;
    }

    if (amount_of_bits_in_k > l) {
        cout << 0 << endl;
        return 0;
    }

    int ans = 1 % mod;
    for (int i = 0; i < l; ++i) {
        int b = GetBit(k, i);
        ans = (1LL * ans * GetAns(n, b, mod)) % mod;
    }

    cout << ans << endl;

    return 0;
}