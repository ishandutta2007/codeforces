#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

int debug;

const int MAX = 205, MOD = 1000000007;

int dp[MAX][MAX], moze[MAX][MAX], x[MAX], y[MAX], n;

int Brtoc(int t1, int t2)
{
    if (t2 > t1)
        return t2 - t1 + 1;
    return n - t1 + t2 + 1;
}

int Slj(int t)
{
    return (t+1) % n;
}

int Prije(int t)
{
    return (t+n-1) % n;
}

ll Ccw(int a, int b, int c)
{
    ll r = (ll) x[a] * (y[b] - y[c]) + (ll) x[b] * (y[c] - y[a]) + (ll) x[c] * (y[a] - y[b]);;
    if (r < 0)
        return -1;
    if (r > 0)
        return 1;
    return 0;
}

ll Povrsina(int t1, int t2)
{
    int i;
    ll r=0;

    for (i=t1; i!=t2; i=Slj(i))
        r += (ll) x[i] * y[Slj(i)] - (ll) y[i] * x[Slj(i)];
    r += (ll) x[t2] * y[t1] - (ll) y[t2] * x[t1];

    return r;
}

int Sijece(int a1, int a2, int b1, int b2, int st)
{
    if (!Ccw(a1, a2, b1) && !Ccw(a1, a2, b2) && !Ccw(b1, b2, a1) && !Ccw(b1, b2, a2)) {
        if (st) {
            return (x[b1] > min(x[a1], x[a2]) && x[b1] < max(x[a1], x[a2]) && y[b1] >= min(y[a1], y[a2]) && y[b1] <= max(y[a1], y[a2])) ||
                   (x[b1] >= min(x[a1], x[a2]) && x[b1] <= max(x[a1], x[a2]) && y[b1] > min(y[a1], y[a2]) && y[b1] < max(y[a1], y[a2])) ||
                   (x[b2] > min(x[a1], x[a2]) && x[b2] < max(x[a1], x[a2]) && y[b2] >= min(y[a1], y[a2]) && y[b2] <= max(y[a1], y[a2])) ||
                   (x[b2] >= min(x[a1], x[a2]) && x[b2] <= max(x[a1], x[a2]) && y[b2] > min(y[a1], y[a2]) && y[b2] < max(y[a1], y[a2]));
        }
        return ((x[b1] >= min(x[a1], x[a2]) && x[b1] <= max(x[a1], x[a2]) && y[b1] >= min(y[a1], y[a2]) && y[b1] <= max(y[a1], y[a2])) ||
                     x[b2] >= min(x[a1], x[a2]) && x[b2] <= max(x[a1], x[a2]) && y[b2] >= min(y[a1], y[a2]) && y[b2] <= max(y[a1], y[a2]));
    }

    return !st && Ccw(a1, a2, b1) * Ccw(a1, a2, b2) <= 0 && Ccw(b1, b2, a1) * Ccw(b1, b2, a2) <= 0;
}

int Rek(int t1, int t2)
{
    int i;

    if (dp[t1][t2] != -1)
        return dp[t1][t2];

    if (Brtoc(t1, t2) == 3) {
        //printf("dp[%d][%d] = %d           1\n", t1, t2, moze[t1][t2] * moze[t1][Slj(t1)] * moze[Slj(t1)][t2]);
        return dp[t1][t2] = moze[t1][t2] * moze[t1][Slj(t1)] * moze[Slj(t1)][t2];
    }

    if (Brtoc(t1, t2) == 2) {
        //printf("dp[%d][%d] = %d                2\n", t1, t2, moze[t1][t2]);
        return dp[t1][t2] = moze[t1][t2];
    }

    if (Brtoc(t1, t2) == 1)
        return dp[t1][t2] = 1;

    dp[t1][t2] = 0;

    for (i=Slj(t1); i!=t2; i = Slj(i))
        if (moze[t1][i] && moze[t2][i])
            dp[t1][t2] = (dp[t1][t2] + (ll) Rek(t1, i) * Rek(i, t2)) % MOD;

    //printf("dp[%d][%d] = %d                      3\n", t1, t2, dp[t1][t2]);
    return dp[t1][t2];
}

int main()
{
    int i, j, k, st;
    ll pov=0;

    scanf("%d", &n);

    for (i=0; i<n; i++)
        scanf("%d%d", &x[i], &y[i]);

    pov = Povrsina(0, n-1);

    memset(dp, -1, sizeof dp);

    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            moze[i][j] = 1;
            if (j == Slj(i) || j == Prije(i))
                continue;
            if (i==j)
                moze[i][j] = 0;
            for (k=0; k<n; k++) {
                st = 0;
                if (k == i || k == j || Slj(k) == i || Slj(k) == j)
                    st = 1;
                if (i == 0 && j == 2 && k == 1) {
                    debug = 1;
                    //printf("DDD %d %d\n", st, Sijece(i, j, k, Slj(k), st));
                    debug = 0;
                }
                if (Sijece(i, j, k, Slj(k), st)) {
                    moze[i][j] = 0;
                    /*if (i == 4 && j == 6) {
                        printf("AKSDOAJ %d %d %d %d %d\n", i, j, k, Slj(k), st);
                        debug = 1;
                        Sijece(i, j, k, Slj(k), st);
                        debug = 0;
                    }*/
                }
            }
            if (abs(Povrsina(i, j)) > abs(pov) || abs(Povrsina(j, i)) > abs(pov)) {
                moze[i][j] = 0;
                //if (i == 4 && j == 6)
                    //printf("IOJIO %d %d %d %I64d %I64d %I64d\n", i, j, k, abs(pov), abs(Povrsina(i, j)), abs(Povrsina(j, i)));
            }
        }
    }

    /*for (i=0; i<n; i++)
        for (j=i+1; j<n; j++)
            printf("moze[%d][%d] = %d\n", i, j, moze[i][j]);*/

    //printf("POV %I64d\n", abs(pov));
    printf("%d\n", Rek(0, n-1));

    return 0;
}