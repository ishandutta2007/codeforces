#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
long long n, p, q, j = 0, m, k, b[5001], sum[5001], i;
long long a[5001][5001];
int main()
{
    cin >> n >> m >> k;
    for(i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    sum[0] = b[0];
    for(i = 1; i < m; i++)sum[i] = sum[i - 1] + b[i];
    for(j = m; j < n; j++)
    {
        sum[j] = sum[j - 1] + b[j] - b[j - m];
    }
    for(i = 0; i < m; i++)
        for(j = 0; j <= k; j++)
            a[i][j] = 0;
    a[m - 1][1] = sum[m - 1];
    for (i = m; i < n; i++)
    {
        a[i][0] = 0;
        for(j = 1; j <= k; j++)
        {
            a[i][j] = max(a[i - 1][j], a[i - m][j - 1] + sum[i]);
        }
    }
    cout << a[n - 1][k];
    return 0;
}