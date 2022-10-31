#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1<<10;

int p[MAX][MAX], rje[2][2][MAX], r[MAX], s[MAX];

int main()
{
    int n, i, j, k, l, q, z, tmp=0, st, koji;

    scanf("%d", &n);

    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            scanf("%d", &p[i][j]);

    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            tmp += p[i][j] * p[j][i];

    tmp %= 2;
    scanf("%d", &q);

    for (i=0; i<q; i++) {
        scanf("%d", &st);
        if (st == 3)
            printf("%d", tmp);
        else {
            scanf("%*d");
            tmp = 1 - tmp;
        }
    }

    printf("\n");

    return 0;
}