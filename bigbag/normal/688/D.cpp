#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 11111111, inf = 1111111111;

int n, k, res[max_n];
int mn[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    mn[1] = 1;
    for (int i = 2; i < max_n; ++i) {
        if (mn[i] == 0) {

            mn[i] = i;
            for (int j = 2 * i; j < max_n; j += i) {
                if (mn[j] == 0) {
                    mn[j] = i;
                }
            }
        }
    }
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        while (x > 1) {
            int cnt = 0, q = mn[x];
            while (x % q == 0) {
                x /= q;
                ++cnt;
            }
            res[q] = max(res[q], cnt);
        }
    }
    while (k > 1) {
        int cnt = 0, q = mn[k];
        while (k % q == 0) {
            k /= q;
            ++cnt;
        }
        if (cnt > res[q]) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}