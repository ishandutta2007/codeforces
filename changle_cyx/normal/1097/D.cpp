#include <bits/stdc++.h>

typedef long long s64; 

const int MaxK = 1e4 + 5; 
const int mod = 1e9 + 7; 

inline int qpow(int x, int y)
{
    int res = 1; 
    for (; y; y >>= 1, x = 1LL * x * x % mod)
        if (y & 1)
            res = 1LL * res * x % mod; 
    return res; 
}

inline void add(int &x, const int &y)
{
    x += y; 
    if (x >= mod) x -= mod; 
}

s64 n; 
int K; 

inline int dp(int pri, int p)
{
    static int f[MaxK][80]; 
    memset(f, 0, sizeof(f)); 

    f[0][p] = 1; 
    for (int i = 0; i < K; ++i)
        for (int j = 0; j <= p; ++j)
            if (f[i][j])
            {
                int inv = qpow(j + 1, mod - 2); 
                for (int k = 0; k <= j; ++k)
                    add(f[i + 1][k], 1LL * f[i][j] * inv % mod); 
            }
    
    int res = 0; 
    for (int i = 0, t = 1; i <= p; ++i, t = 1LL * pri * t % mod)
        add(res, 1LL * t * f[K][i] % mod); 
    return res; 
}

int main()
{
    std::cin >> n >> K; 

    int res = 1; 
    for (s64 i = 2, t = sqrt(n) + 1; i <= t; ++i)
        if (n % i == 0)
        {
            int cnt = 0; 
            while (n % i == 0)
                ++cnt, n /= i; 
            res = 1LL * res * dp(i % mod, cnt) % mod; 
        }
    
    if (n != 1)
        res = 1LL * res * dp(n % mod, 1) % mod; 
    std::cout << res << std::endl; 

    return 0; 
}