#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
using namespace std;

typedef long long ll;

const int max_n = 202;
const int max_k = 11;

int n, k, m1, m2;
int a[max_n];
int b[max_n];
int c[max_n];

int main()
{
    /*
    freopen("input.txt", "w", stdout);
    printf("200 10\n");
    for (int i = 0; i < 200; ++i)
        printf("%d ", i);
    printf("\n");
    return 0;
    */
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);
        
    int ans;
    bool found = false;
    for (int l = 0; l < n; ++l)
        for (int r = l; r < n; ++r) {
            m1 = r - l + 1;
            for (int i = l; i <= r; ++i) b[i - l] = a[i];
            sort(b, b + m1);
            m2 = 0;
            for (int i = 0; i < l; ++i) {
                c[m2] = a[i];
                ++m2;
            }
            for (int i = r + 1; i < n; ++i) {
                c[m2] = a[i];
                ++m2;
            }
            sort(c, c + m2);
            for (int i = 0; i < k; ++i)
                if (i < m1 && m2 - i - 1 >= 0) {
                    if (b[i] >= c[m2 - i - 1]) break;
                    b[i] = c[m2 - i - 1];
                }
            int cans = 0;
            for (int i = 0; i < m1; ++i) cans += b[i];
            if (!found || cans > ans) {
                found = 1;
                ans = cans;
            }
        }
    printf("%d\n", ans);

    return 0;
}