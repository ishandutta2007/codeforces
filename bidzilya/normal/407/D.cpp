#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

const int max_n = 400;
const int max_a = 400 * 400 + 1;

int a[max_n][max_n];
short l[max_a][max_n];
int lf[max_n][max_n];
int rg[max_n][max_n];
int ansr[max_n];
int n, m;
int ans;

int main() {
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
    
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                scanf("%d", &a[i][j]);
        ans = 0;
        for (int x = 0; x < max_a; ++x)
            for (int j = 0; j < m; ++j)
                l[x][j] = m;
        for (int up = n - 1; up >= 0; --up) {
            for (int j = 0; j < m; ++j) {
                lf[up][j] = -1;
                for (int k = 0; k < j; ++k)
                    if (a[up][k] == a[up][j]) 
                        lf[up][j] = k;
                rg[up][j] = m;
                for (int k = j + 1; k < m; ++k)
                    if (a[up][k] == a[up][j]) {
                        rg[up][j] = k;
                        break;
                    }
            }
            for (int j = 0; j < m; ++j)
                ansr[j] = rg[up][j] - 1;
            for (int j = m - 2; j >= 0; --j)
                ansr[j] = min(ansr[j], ansr[j + 1]);
            for (int j = 0; j < m; ++j) 
                ans = max(ans, ansr[j] - j + 1);
            for (int j = 0; j < m; ++j)
                for (int k = j; k < m; ++k)
                    if (k < l[a[up][k]][j]) 
                        l[a[up][k]][j] = k;
            for (int down = up + 1; down < n; ++down) {
                for (int j = 0; j < m; ++j) {
                    rg[down][j] = min(rg[down][j], (int) l[a[down][j]][j]);
                    ansr[j] = min(ansr[j], rg[down][j] - 1);
                }
                for (int j = 0; j < m; ++j) {
                    int d = lf[down][j];
                    int x = a[down][j];
                    while (d + 1 <= j && l[x][d + 1] <= j) {
                        d = l[x][d + 1];
                    }
                    lf[down][j] = d;
                    ansr[d] = min(ansr[d], j - 1);
                }
                for (int j = m - 2; j >= 0; --j)
                    ansr[j] = min(ansr[j], ansr[j + 1]);
                for (int j = 0; j < m; ++j)
                    ans = max(ans, (down - up + 1) * (ansr[j] - j + 1));
            }
            for (int j = 0; j < m; ++j )
                for (int k = j; k < m; ++k)
                    l[a[up][k]][j] = m;
        }
        printf("%d\n", ans);
    }
    

    return 0;
}