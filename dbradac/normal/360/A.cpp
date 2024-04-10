#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 5010, INF = 2000000000;

int tren[MAX], l[MAX], r[MAX], polje[MAX][MAX], maxx[MAX], gran[MAX];

int main()
{
    int n, q, i, j, st, tmp, ind=0, ll, rr, ne=0, da=0;

    for (i=0; i<MAX; i++)
        gran[i] = INF;

    scanf("%d%d", &n, &q);

    for (i=0; i<q; i++) {
        scanf("%d%d%d%d", &st, &ll, &rr, &tmp); ll--; rr--;
        if (st == 1)
            for (j=ll; j<=rr; j++)
                tren[j] += tmp;
        else {
            l[ind] = ll;
            r[ind] = rr;
            maxx[ind] = tmp;
            for (j=ll; j<=rr; j++)
                polje[ind][j] = tren[j];
            for (j=ll; j<=rr; j++)
                gran[j] = min(gran[j], maxx[ind] - tren[j]);
            ind++;
        }
    }

    for (i=0; i<ind; i++) {
        for (j=l[i], da=0; j<=r[i]; j++) {
            if (gran[j] + polje[i][j] == maxx[i]) {
                da = 1;
                break;
            }
        }
        if (!da) {
            ne = 1;
            break;
        }
    }

    if (ne)
        printf("NO\n");
    else {
        printf("YES\n");
        for (i=0; i<n; i++) {
            if (gran[i] == INF)
                printf("-1 ");
            else
                printf("%d ", gran[i]);
        }
        printf("\n");
    }

    return 0;
}