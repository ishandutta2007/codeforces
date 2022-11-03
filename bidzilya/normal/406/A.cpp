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

const int max_n = 1e3 + 100;

int a[max_n][max_n];
int s, n, m;

int main() {
 //   freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &a[i][j]);
        s = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                s = ((s + a[i][j] * a[j][i]) & 1);
        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            int tp;
            scanf("%d", &tp);
            if (tp == 1) {
                int k;
                scanf("%d", &k);
                s = (s + 1) & 1;
            } else if (tp == 2) {
                int k;
                scanf("%d", &k);
                s = (s + 1) & 1;
            } else {
                printf("%d", s);
            }
        }
        printf("\n");
    }
    

    return 0;
}