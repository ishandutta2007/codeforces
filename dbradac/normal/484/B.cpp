#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1<<21, LOG = 21;

int p[MAX], br[MAX], konst[LOG][MAX], kor[MAX];

int Vrati(int poc, int kraj)
{
    int l;

    l = kraj - poc + 1;

    return max(konst[kor[l]][poc], konst[kor[l]][kraj+1-(1<<kor[l])]);
}

int main()
{
    int n, i, j, tmp, rje=0;

    for (i=0; i<LOG; i++)
        for (j=1<<i; j<(1<<(i+1)); j++)
            kor[j] = i;

    scanf("%d", &n);

    for (i=0; i<n; i++) {
        scanf("%d", &br[i]);
        p[br[i]] = br[i];
    }

    for (i=0; i<MAX; i++)
        konst[0][i] = p[i];

    for (i=1, tmp=1; i<LOG; i++, tmp<<=1)
        for (j=0; j<MAX; j++)
            konst[i][j] = max(konst[i-1][j], konst[i-1][j+tmp]);

    for (i=1; i<MAX; i++) {
        if (p[i]) {
            for (j=i; j+i<MAX; j+=i)
                rje = max(rje, Vrati(j, j+i-1) - j);
        }
    }

    printf("%d\n", rje);

    return 0;
}