#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <set>
#include <cassert>
using namespace std;

typedef long long ll;

const int max_n = 111;

int n, m, k;
int a[max_n][max_n];

inline int bit(int mask, int i) { return (mask >> i) & 1; }

int main()
{
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
   
    scanf("%d%d%d", &n, &m, &k);
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%d", &a[i][j]);
    
    if (n <= k) {
        int ans = k + 1;
        for (int mask = 0; mask < (1 << n); ++mask) {
            int cans = 0;
            for (int j = 0; j < m; ++j) {
                int c0 = 0, c1 = 0;
                for (int i = 0; i < n; ++i) {
                    if (a[i][j] != bit(mask, i)) 
                        ++c0;
                    if (a[i][j] != (1 ^ bit(mask, i)))
                        ++c1;
                }
                cans += min(c0, c1);
            }
            ans = min(ans, cans);
        }
        if (ans <= k)
            printf("%d\n", ans);
        else
            printf("-1\n");
    } else {
        int ans = k + 1;
        for (int fixed = 0; fixed < n; ++fixed) {
            int cans = 0;
            for (int i = 0; i < n; ++i) {
                int c0 = 0, c1 = 0;
                for (int j = 0; j < m; ++j) {
                    if (a[i][j] != a[fixed][j]) 
                        ++c0;
                    if (a[i][j] != (1 ^ a[fixed][j]))
                        ++c1;
                }
                cans += min(c0, c1);
            }
            ans = min(ans, cans);
        }
        if (ans <= k)
            printf("%d\n", ans);
        else
            printf("-1\n");
    }
            
    return 0;
}