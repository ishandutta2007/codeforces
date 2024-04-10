#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAX = 1000005, MOD = 1000000007;

ll PrvihN(int n)
{
    return ((ll) n * (n+1) / 2) % MOD;
}

int polje[MAX], fen[MAX];
ll dp[MAX], fak[MAX], kolko[MAX];

void Stavi(int pos, int val)
{
    for (; pos < MAX; pos += pos & -pos)
        fen[pos] += val;
}

int Vrati(int pos)
{
    int r=0;

    for (; pos; pos -= pos & -pos)
        r += fen[pos];
    return r;
}

int main()
{
    int i, n;
    ll r=0;

    fak[0] = 1;

    for (i=1; i<MAX; i++)
        fak[i] = (fak[i-1] * i) % MOD;

    dp[0] = 0;

    for (i=1; i<MAX; i++)
        dp[i] = (PrvihN(i-1) * fak[i-1] + i * dp[i-1]) % MOD;

    scanf("%d", &n);

    for (i=0; i<n; i++)
        scanf("%d", &polje[i]);

    kolko[n] = 1;
    for (i=n-1; i>=0; i--) {
        kolko[i] = (Vrati(polje[i]) * fak[n-i-1] + kolko[i+1]) % MOD;
        Stavi(polje[i], 1);
    }

    memset(fen, 0, sizeof fen);

    for (i=0; i<n; i++) {
        r = (r + (polje[i] - Vrati(polje[i]) - 1) * dp[n-i-1]) % MOD;
        r = (r + PrvihN(polje[i] - Vrati(polje[i]) - 2) * fak[n-i-1]) % MOD;
        r = (r + (polje[i] - Vrati(polje[i]) - 1) * kolko[i+1]) % MOD;
        Stavi(polje[i], 1);
    }

    printf("%I64d\n", r);

    return 0;
}