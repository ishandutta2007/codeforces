#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MOD = 1000000007;

int p[21], n;
ll rje=0, f[21], inverz[21], sum;

ll Pot(ll a, ll eksp)
{
    ll rj=1;

    for (; eksp; eksp>>=1, a = (a * a) % MOD)
        if (eksp & 1)
            rj = (rj * a) % MOD;
    return rj;
}

ll Povrh(ll a, ll b)
{
    ll i, rj=1;

    if (a < b)
        return 0;

    for (i=a; i>a-b; i--)
        rj = (rj * (i%MOD)) % MOD;

    for (i=1; i<=b; i++)
        rj = (rj * inverz[i]) % MOD;

    return rj;
}

void Rek(int dub)
{
    int i, pl=1;
    ll tmp;

    if (dub == n) {
        for (i=0, tmp=sum; i<n; i++) {
            if (p[i]) {
                pl *= -1;
                tmp -= f[i] + 1;
            }
        }

        rje = (rje + MOD + pl * Povrh(tmp+n-1, n-1)) % MOD;

        return;
    }

    p[dub] = 0;
    Rek(dub+1);
    p[dub] = 1;
    Rek(dub+1);
}

int main()
{
    int i;

    scanf("%d%I64d", &n, &sum);

    for (i=0; i<n; i++)
        scanf("%I64d", &f[i]);

    for (i=1; i<=20; i++)
        inverz[i] = Pot(i, MOD-2);

    Rek(0);

    printf("%I64d\n", rje);

    return 0;
}