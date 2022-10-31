#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 3010;

int p[MAX];

int main()
{
    int i, j, n, br=0;

    scanf("%d", &n);

    for (i=0; i<n; i++)
        scanf("%d", &p[i]);

    for (i=0; i<n; i++)
        for (j=0; j<i; j++)
            if (p[j] > p[i])
                br++;

    if (br % 2)
        printf("%d.000000\n", br * 2 - 1);
    else
        printf("%d.000000\n", br*2);

    return 0;
}