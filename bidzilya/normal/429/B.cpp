#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
 
#include <cassert>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;

const int max_n = 1e3 + 10;

int n, m;
int a[max_n][max_n];


int d00[max_n][max_n];
int d11[max_n][max_n];
int d01[max_n][max_n];
int d10[max_n][max_n];

int main()
{
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
    
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
        }
        
    d00[0][0] = a[0][0];
    for (int j = 1; j < m; ++j)
        d00[0][j] = d00[0][j - 1] + a[0][j];
    for (int i = 1; i < n; ++i)
        d00[i][0] = d00[i - 1][0] + a[i][0];
    for (int i = 1; i < n; ++i)
        for (int j = 1; j < m; ++j)
            d00[i][j] = max(d00[i - 1][j], d00[i][j - 1]) + a[i][j];
            
    d01[0][m - 1] = a[0][m - 1];
    for (int j = m - 2; j >= 0; --j)
        d01[0][j] = d01[0][j + 1] + a[0][j];
    for (int i = 1; i < n; ++i)
        d01[i][m - 1] = d01[i - 1][m - 1] + a[i][m - 1];
    for (int i = 1; i < n; ++i)
        for (int j = m - 2; j >= 0; --j)
            d01[i][j] = max(d01[i - 1][j], d01[i][j + 1]) + a[i][j];
    
    d10[n - 1][0] = a[n - 1][0];
    for (int j = 1; j < m; ++j)
        d10[n - 1][j] = d10[n - 1][j - 1] + a[n - 1][j];
    for (int i = n - 2; i >= 0; --i)
        d10[i][0] = d10[i + 1][0] + a[i][0];
    for (int i = n - 2; i >= 0; --i)
        for (int j = 1; j < m; ++j)
            d10[i][j] = max(d10[i + 1][j], d10[i][j - 1]) + a[i][j];
    
    d11[n - 1][m - 1] = a[n - 1][m - 1];
    for (int j = m - 2; j >= 0; --j)
        d11[n - 1][j] = d11[n - 1][j + 1] + a[n - 1][j];
    for (int i = n - 2; i >= 0; --i)
        d11[i][m - 1] = d11[i + 1][m - 1] + a[i][m - 1];
    for (int i = n - 2; i >= 0; --i)
        for (int j = m - 2; j >= 0; --j)
            d11[i][j] = max(d11[i + 1][j], d11[i][j + 1]) + a[i][j];

    
    int ans = 0;
    for (int i = 1; i < n - 1; ++i)
        for (int j = 1; j < m - 1; ++j) {
            ans = max(ans, max(d00[i][j - 1] + d10[i + 1][j] + d01[i - 1][j] + d11[i][j + 1],
                                d00[i - 1][j] + d10[i][j - 1] + d01[i][j + 1] + d11[i + 1][j]));
        }
        
    printf("%d\n", ans);
    
    return 0;
}