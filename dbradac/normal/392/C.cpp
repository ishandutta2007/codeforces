#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MOD = 1000000007, MAX = 100;

// rje Ai(k) -> 0
// dalje Fi-1(j) -> j * 2 + 1, Fi(j) -> j * 2 + 2
int mat[2][MAX][MAX], rje[2][MAX][MAX], poc[MAX][MAX], vel;

int Pot(int b, int eksp)
{
    int r=1;

    for (; eksp; eksp>>=1, b = ((ll) b * b) % MOD)
        if (eksp & 1)
            r = ((ll)r * b) % MOD;
    return r;
}

int Povrh(int n, int k)
{
    int i, r=1;

    for (i=n; i>n-k; i--)
        r = ((ll) r * i) % MOD;

    for (i=1; i<=k; i++)
        r = ((ll) r * Pot(i, MOD-2)) % MOD;

    return r;
}

void Mnoz(int a[MAX][MAX], int b[MAX][MAX], int c[MAX][MAX])
{
    int i, j, k;

    for (i=0; i<vel; i++)
        for (j=0; j<vel; j++) {
            c[i][j] = 0;
            for (k=0; k<vel; k++)
                c[i][j] = (c[i][j] + (ll) a[i][k] * b[k][j]) % MOD;
        }
}

int Pot(ll eksp)
{
    int i, indm=0, indr=0;

    for (i=0; i<vel; i++)
        rje[0][i][i] = 1;

    for (; eksp; eksp >>= 1, indm = 1 - indm) {
        if (eksp & 1) {
            Mnoz(rje[indr], mat[indm], rje[1-indr]);
            indr = 1 - indr;
        }
        Mnoz(mat[indm], mat[indm], mat[1-indm]);
    }

    return indr;
}

int main()
{
    int k, i, j, ind, r=0;
    ll n;

    scanf("%I64d%d", &n, &k);

    mat[0][0][0] = mat[0][0][2*k+2] = 1;

    for (i=0; i<=k; i++) {
        mat[0][i*2+1][i*2+2] = 1;
        for (j=0; j<=i; j++) {
            mat[0][i*2+2][j*2+2] = Povrh(i, j);
            mat[0][i*2+2][j*2+1] = ((ll) Povrh(i, j) * Pot(2, i-j)) % MOD;
        }
    }

    vel = 2 * k + 3;
    ind = Pot(n-1);

    for (i=1; i<vel; i++)
        r = (r + (ll) Pot((1 + ((i+1) & 1)), (i-1) / 2 + 1) * rje[ind][0][i]) % MOD;

    printf("%d\n", (r+1) % MOD);

    return 0;
}