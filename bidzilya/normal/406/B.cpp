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

const int s = 1e6;

int in_x[s + 1];
int in_y[s + 1];
int n;
int m;

int main() {
    //freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= s; ++i)
            in_x[i] = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            in_x[x] = 1;
        }
        for (int i = 1; i <= s; ++i)
            in_y[i] = 0;
        int sp = 0;
        for (int i = 1; 2 * i < s + 1; ++i) {
            int si = s + 1 - i;
            if (in_x[i] && in_x[si]) ++sp;
        }
        m = 0;
        for (int i = 1; i <= s; ++i) {
            if (in_x[i] || in_y[i]) continue;
            int si = s + 1 - i;
            if (in_x[si]) {
                in_y[i] = 1;
                ++m;
            } else {
                if (sp > 0) {
                    in_y[i] = in_y[si] = 1;
                    m += 2;
                    --sp;
                }
            }
        }
        printf("%d\n", m);
        for (int i = 1; i <= s; ++i)
            if (in_y[i])
                printf("%d ", i);
        printf("\n");
    }
    

    return 0;
}