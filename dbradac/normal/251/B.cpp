#include <cstdio>
#include <algorithm>

using namespace std;

int q[110], p[2][110], kraj[110], n, brnar;

int Prov (int ind)
{
    int i;

    for (i=1; i<=n; i++)
        if (p[ind][i] != kraj[i])
            return 0;

    return 1;
}

int main()
{
    int i, j, ind=0, rje=0, moze=0;

    scanf("%d %d", &n, &brnar);

    for (i=1; i<=n; i++)
        p[0][i] = i;
    ind=0;

    for (i=1; i<=n; i++)
        scanf("%d", &q[i]);

    for (i=1; i<=n; i++)
        scanf("%d", &kraj[i]);

    for (j=1; j<=n; j++)
        p[1-ind][j] = p[ind][q[j]];

    if (!Prov(1) || brnar == 1)
        moze=1;

    ind = 0;

    for (i=1; i<=n; i++)
        p[0][i] = i;

    for (j=1; j<=n; j++)
        p[1-ind][q[j]] = p[ind][j];

    if (!Prov(1) || brnar == 1)
        moze=1;

    for (i=1; i<=n; i++)
        p[0][i] = i;
    ind=1;

    if (Prov(0) || !moze)
        printf("NO\n");
    else {
        for (i=1; i<=brnar; i++) {
            ind = 1 - ind;
            for (j=1; j<=n; j++)
                p[1-ind][j] = p[ind][q[j]];

            if (Prov(1-ind)) {
                if (!((brnar-i) % 2))
                    rje=1;
            }

            if (rje)
                break;
        }

        if (rje)
            printf("YES\n");
        else {
            for (i=1; i<=n; i++)
                p[0][i] = i;

            ind = 1;

            for (i=1; i<=brnar; i++) {
                ind = 1 - ind;
                for (j=1; j<=n; j++)
                    p[1-ind][q[j]] = p[ind][j];

                if (Prov(1-ind)) {
                    if (!((brnar-i) % 2))
                        rje=1;
                }

                if (rje)
                    break;
            }

            if (rje)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}