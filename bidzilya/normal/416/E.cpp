#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <iostream>
using namespace std;

typedef long long ll;

const int inf = 1e9;

const int max_n = 501;

int n, m;
int a[max_n][max_n];
int d[max_n][max_n];
int c[max_n];

int main()
{
  //  freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            d[i][j] = inf;
            a[i][j] = 0;
        }
    for (int i = 0; i < n; ++i) d[i][i] = 0;
    
    for (int i = 0; i < m; ++i) {
        int v1, v2, l;
        scanf("%d%d%d", &v1, &v2, &l);
        --v1; --v2;
        a[v1][v2] = a[v2][v1] = l;
        d[v1][v2] = d[v2][v1] = l;
    }
    
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) c[j] = 0;

        for (int k = 0; k < n; ++k)
            for (int j = 0; j < n; ++j)
                if (a[k][j] && d[i][j] == d[i][k] + a[k][j])
                    ++c[j];
        
        for (int j = i + 1; j < n; ++j) {
            int ans = 0;
            for (int k = 0; k < n; ++k)
                if (d[i][j] == d[i][k] + d[k][j])
                    ans += c[k];
            printf("%d ", ans);
        }
    }
    printf("\n");

    return 0;
}