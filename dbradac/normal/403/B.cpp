#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX = 5010, KOR = 31622, INF = (int) 1e9;

int sito[10*MAX], prosti[MAX], ind, dp[MAX], p[MAX], bad[MAX], g[MAX], n, m;

int Eval(int x)
{
    int i, v=0;

    for (i=0; i<ind; i++) {
        if (prosti[i] > (int) (sqrt(x) + 1e-7))
            break;
        if (!(x % prosti[i])) {
            if (*lower_bound(bad, bad + m, prosti[i]) == prosti[i])
                v--;
            else
                v++;
            x /= prosti[i];
            i--;
        }
    }

    if (x != 1) {
        if (*lower_bound(bad, bad + m, x) == x)
            v--;
        else
            v++;
    }

    return v;
}

int Gcd(int a, int b)
{
    if (!b)
        return a;
    return Gcd(b, a%b);
}

int Rek(int ind, int gc)
{
    int i, r=0, dijel;

    if (dp[ind] != -INF)
        return dp[ind];

    for (i=ind; i>=0; i--) {
        dijel = g[i] / gc;
        r = max(r, Rek(i-1, g[i]) - Eval(dijel) * (i + 1));
    }

    return dp[ind] = r;
}

int main()
{
    int i, j, uk;

    for (i=2; i<=KOR; i++)
        if (!sito[i]) {
            prosti[ind++] = i;
            for (j=2*i; j<=KOR; j+=i)
                sito[j] = 1;
        }

    scanf("%d%d", &n, &m);

    for (i=0; i<n; i++)
        scanf("%d", &p[i]);

    for (i=0; i<m; i++)
        scanf("%d", &bad[i]);

    g[0] = p[0];

    for (i=1; i<n; i++)
        g[i] = Gcd(p[i], g[i-1]);

    for (i=uk=0; i<n; i++) {
        dp[i] = -INF;
        uk += Eval(p[i]);
    }

    printf("%d\n", uk + Rek(n-1, 1));

    return 0;
}