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
#include <queue>
#include <map>

using namespace std;

typedef long long ll;

const int modulo = 1e9 + 7;

const int max_n = 2e3 + 10;

int b[max_n][max_n];
int n, k;

inline void minc(int& x, int y) { x += y; if (x >= modulo) x -= modulo; }

int main()
{
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    
    scanf("%d%d", &n, &k);
    
    b[0][1] = 1;
    for (int len = 0; len < k; ++len)
        for (int last = 1; last <= n; ++last)
            if (b[len][last] == 0)
                continue;
            else {
                for (int next = last; next <= n; next += last)
                    minc(b[len + 1][next], b[len][last]);
            }

    int ans = 0;
    for (int last = 1; last <= n; ++last)
        minc(ans, b[k][last]);
    printf("%d\n", ans);
    
    return 0;
}