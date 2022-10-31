#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX = 10005, MOD = 1000000007;

ll dp[105][MAX], povrh[MAX], pot[105][105];

ll Pot(ll b, ll e)
{
    ll r=1;

    for (; e; e>>=1, b = (b * b) % MOD)
        if (e & 1)
            r = (r * b) % MOD;
    return r;
}

int main()
{
    int i, j, l;
    ll n, k, m, kolko;

    cin >> n >> m >> k;

    povrh[0] = 1;
    for (i=1; i<=n; i++)
        povrh[i] = ((povrh[i-1] * (n - i + 1)) % MOD * Pot(i, MOD - 2)) % MOD;

    for (i=0; i<n; i++) {
        for (j=0; j<=n; j++) {
            kolko = m / n;
            if (m % n > (ll) i)
                kolko++;
            pot[i][j] = Pot(povrh[j], kolko);
        }
    }

    dp[0][0] = 1;
    for (i=0; i<n; i++)
        for (j=0; j<=k; j++)
            for (l=0; l<=min(k-j, n); l++)
                dp[i+1][j+l] = (dp[i+1][j+l] + (dp[i][j] * pot[i][l]) % MOD) % MOD;

    cout << dp[n][k] << endl;

    return 0;
}