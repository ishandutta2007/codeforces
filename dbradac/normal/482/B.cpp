#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1<<17;

int l[MAX], r[MAX], val[MAX], p[MAX], mora[30][MAX], sum[30][MAX];

int main()
{
    int n, m, i, j, tmp, ne=0;

    scanf("%d%d", &n, &m);

    for (i=0; i<m; i++) {
        scanf("%d%d%d", &l[i], &r[i], &val[i]);
        for (j=0; j<30; j++)
            if ((1<<j) & val[i]) {
                mora[j][l[i]]++;
                mora[j][r[i]+1]--;
            }
    }

    for (i=0; i<30; i++)
        for (tmp=0, j=1; j<=n; j++) {
            tmp += mora[i][j];
            sum[i][j] = sum[i][j-1];
            if (tmp) {
                p[j] |= 1<<i;
                sum[i][j]++;
            }
        }

    for (i=0; i<m; i++)
        for (j=0; j<30; j++)
            if (!((1<<j) & val[i]))
                if (sum[j][r[i]] - sum[j][l[i]-1] == r[i] - l[i] + 1)
                    ne = 1;

    if (ne)
        printf("NO\n");
    else {
        printf("YES\n");
        for (i=1; i<=n; i++)
            printf("%d ", p[i]);
        printf("\n");
    }

    return 0;
}