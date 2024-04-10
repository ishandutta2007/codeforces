#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
using namespace std;
long long  m, i, j, k, n, a[1001], b[1001][1001], p, q, l, r, l1, r1, l2[51], r2[51];
int main()
{
    cin >> p >> q >> l >> r;
    for(i = 0; i <= 1000; i++)a[i] = 0;
    for(i = 0; i  <= 1000; i++)
        for(j = 0; j <= 1000; j++) b[i][j] = 0;
    for(i = 1; i <= p; i++)
    {
        cin >> l1 >> r1;
        for(j = l1; j <= r1; j++) a[j] = 1;
    }
    for(i = 0; i <= 1000; i++)
        for(j = 0; j <= 1000; j++)
        {
            if(a[j] > 0)b[i][j] = 1;
            if(j > i && b[i][j - 1] > 0)b[i][j] = 1;
        }
    for(i = 0; i < q; i++)
    {
        cin >> l2[i] >> r2[i];
    }
    m = 0;
    for(j = l; j <= r; j++)
    {
        for(i = 0; i < q; i++)
        {
            long p = r2[i] + j;
            if (p > 1000)p = 1000;
            if(l2[i] + j <= 1000 && b[l2[i] + j][p] > 0)
            {
                m++;
                break;
            }
        }
    }
    cout << m;
    return 0;
}