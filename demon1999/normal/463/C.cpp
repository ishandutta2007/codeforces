#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
    long long a[2001][2001], di1[4000], di2[4000], maxd[4000], nux[4000], nuy[4000] ;
    long  long p, i, j = 0, n, m, x1, y1, x2, y2, max1 = -1, kol;
    scanf("%I64d", &n);
    for(i = 0; i < n + n; i++)
    {
        di1[i] = 0;
        di2[i] = 0;
        maxd[i] = -1;
    }
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
        {
            scanf("%I64d", &a[i][j]);
            di1[i + j] += a[i][j];
            di2[i - j + n] += a[i][j];
        }
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
        {
            if (maxd[i + j] < di2[i - j + n] - a[i][j])
            {
                maxd[i + j] = di2[i - j + n] - a[i][j];
                nux[i + j] = i + 1;
                nuy[i + j] = j + 1;
            }
        }
    for(i = 0; i < n; i ++)
        for(j = 0; j < n; j ++)
        {
            kol = di1[2 * i] + maxd[2 * i];
            kol += di1[2 * j + 1] + maxd[2 * j + 1];
            if(kol > max1)
            {
                max1 = kol;
                x1 = nux[2 * i];
                y1 = nuy[2 * i];
                x2 = nux[2 * j + 1];
                y2 = nuy[2 * j + 1];
            }
        }
    printf("%I64d\n", max1);
    printf("%I64d %I64d %I64d %I64d", x1, y1, x2, y2);
    return 0;
}