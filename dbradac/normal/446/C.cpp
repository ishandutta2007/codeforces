#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

const int MOD = 1000000009, TOUR = 1<<19, MAX = 300100;

struct tour {
    int val, prop1, prop2;
} t[2*TOUR];

int pocmat[3][3] = {0, 1, 0,
                    1, 1, 0,
                    1, 1, 1};

int mat[MAX][3][3];

void mnoz(int a[3][3], int b[3][3], int c[3][3])
{
    int i, j, k;

    for (i=0; i<3; i++)
        for (j=0; j<3; j++) {
            c[i][j] = 0;
            for (k=0; k<3; k++)
                c[i][j] = (c[i][j] + (ll) a[i][k] * b[k][j]) % MOD;
        }
}

int pot(int poc1, int poc2, int eksp, int st) // 1 - zbroj, 0 - n-ti
{
    if (!eksp)
        return 0;

    if (eksp == 1)
        return poc1;

    if (!st)
        eksp++;
    eksp -= 2;

    if (st == 1)
        return (((ll) mat[eksp][2][0] * poc1 + (ll) mat[eksp][2][1] * poc2) % MOD + (ll) mat[eksp][2][2] * (poc1 + poc2)) % MOD;
    return ((ll) mat[eksp][0][0] * poc1 + (ll) mat[eksp][0][1] * poc2) % MOD;
}

void Prop(int node, int lo, int hi)
{
    int p1=t[node].prop1, p2=t[node].prop2, t1, t2;

    if (t[node].prop2) {
        t[2*node].prop1 = (t[2*node].prop1 + p1) % MOD;
        t[2*node].prop2 = (t[2*node].prop2 + p2) % MOD;
        t[2*node].val = ((ll) t[2*node].val + pot(p1, p2, (hi-lo) / 2, 1)) % MOD;
        t1 = pot(p1, p2, (hi-lo)/2 + 1, 0);
        t2 = pot(p1, p2, (hi-lo)/2 + 2, 0);
        t[2*node+1].prop1 = (t[2*node+1].prop1 + t1) % MOD;
        t[2*node+1].prop2 = (t[2*node+1].prop2 + t2) % MOD;
        t[2*node+1].val = ((ll) t[2*node+1].val + pot(t1, t2, (hi-lo)/2, 1)) % MOD;
    }

    t[node].prop1 = t[node].prop2 = 0;
}

void Stavi(int pos, int lo, int hi, int begin, int end, int p1, int p2)
{
    int poc1, poc2;

    if (lo >= end || hi <= begin)
        return;
    if (lo >= begin && hi <= end) {
        poc1 = pot(p1, p2, lo - begin + 1, 0);
        poc2 = pot(p1, p2, lo - begin + 2, 0);
        t[pos].prop1 = (t[pos].prop1 + poc1) % MOD;
        t[pos].prop2 = (t[pos].prop2 + poc2) % MOD;
        t[pos].val = (t[pos].val + pot(poc1, poc2, hi-lo, 1)) % MOD;
        return;
    }

    Prop(pos, lo, hi);

    Stavi(2*pos+0, lo, (lo+hi)/2, begin, end, p1, p2);
    Stavi(2*pos+1, (lo+hi)/2, hi, begin, end, p1, p2);
    t[pos].val = (t[2*pos+0].val + t[2*pos+1].val) % MOD;
}

int Vrati(int pos, int lo, int hi, int begin, int end)
{
    int r;

    if (lo >= end || hi <= begin)
        return 0;
    if (lo >= begin && hi <= end)
        return t[pos].val;

    Prop(pos, lo, hi);

    r = (Vrati(2*pos+0, lo, (lo+hi)/2, begin, end) +
         Vrati(2*pos+1, (lo+hi)/2, hi, begin, end)) % MOD;

    t[pos].val = (t[2*pos].val + t[2*pos+1].val) % MOD;

    return r;
}

int main()
{
    int n, q, i, st, tmp, l, r;

    for (i=0; i<3; i++)
        mat[0][i][i] = 1;

    for (i=1; i<MAX; i++)
        mnoz(mat[i-1], pocmat, mat[i]);

    scanf("%d%d", &n, &q);

    for (i=0; i<n; i++) {
        scanf("%d", &tmp);
        Stavi(1, 0, TOUR, i, i+1, tmp, tmp);
    }

    for (i=0; i<q; i++) {
        scanf("%d%d%d", &st, &l, &r); l--;
        if (st == 1)
            Stavi(1, 0, TOUR, l, r, 1, 1);
        else
            printf("%d\n", Vrati(1, 0, TOUR, l, r));
    }

    return 0;
}