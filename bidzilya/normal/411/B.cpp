#include <string>
#include <cstdio>
using namespace std;

const int max_n = 101;

int n, m, k;
int bc[max_n], bm[max_n], nm[max_n], bt[max_n];
int X[max_n][max_n];

int main() 
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);
    
    for (int c = 1; c <= n; ++c)
        for (int t = 1; t <= m; ++t)
            scanf("%d", &X[t][c]);

    for (int t = 1; t <= m; ++t) {
        for (int i = 1; i <= k; ++i) nm[i] = 0;
        for (int c = 1; c <= n; ++c) {
            int x = X[t][c];
            if (x == 0) continue;
            if (bc[c]) continue;
            if (bm[x]) {
                bc[c] = 1;
                bt[c] = t;
                continue;
            }
            if (nm[x] == 0) {
                nm[x] = c;
            } else {
                bm[x] = 1;
                bc[nm[x]] = 1;
                bt[nm[x]] = t;
                bc[c] = 1;
                bt[c] = t;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        printf("%d\n", bt[i]);
    
    return 0;
}