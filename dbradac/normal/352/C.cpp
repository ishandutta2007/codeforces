#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 2010, INF = 1000000000;

int main()
{
    int i, j, n, tmp, prom, br0=0;
    int zbroj=0, rje=INF;

    scanf("%d", &n); n*=2;

    for (i=1; i<=n; i++) {
        scanf("%*d.%d", &tmp);
        zbroj += tmp;
        if (!tmp)
            br0++;
    }

    for (i=0; i<=br0; i++)
        rje = min(rje, abs(zbroj - (n*500 - i * 1000)));

    printf("%d.%03d\n", rje / 1000, rje % 1000);

    return 0;
}