#include <cstdio>
#include <algorithm>

using namespace std;

int polje[305];

int main()
{
    int n, i, j;

    scanf("%d", &n);

    for (i=0; i<n; i++)
        scanf("%d", &polje[i]);

    for (i=0; i<polje[0]; i++)
        printf("PRL");

    printf("R");

    for (i=1; i<n; i++) {
        for (j=0; j<polje[i]; j++)
            printf("PLR");
        if (i != n - 1)
            printf("R");
    }

    printf("\n");

    return 0;
}