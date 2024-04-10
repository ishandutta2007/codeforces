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

int main()
{
  //  freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, k;
    scanf("%d%d", &n, &k);
    
    if (k == 0) {
        if (n == 1) {
            printf("1\n");
        } else {
            printf("-1\n");
        }
        return 0;
    }
    
    int t = n / 2;
    
    if (t > k) {
        printf("-1\n");
        return 0;
    }
    
    if (n < 2) {
        printf("-1\n");
        return 0;
    }
    
    int a = k - t + 1;
    printf("%d %d ", a, 2 * a);
    --t;
    int t1 = 1;
    for (int i = 1; i <= t; ++i) {
        while (t1 == 2 * a || t1 == a || t1 + 1 == a || t1 + 1 == 2 * a) ++t1;
        printf("%d %d ", t1, t1 + 1);
        t1 += 2;
    }
    
    if ((n & 1) == 1) {
        printf("1000000000");
    }
    printf("\n");
    
    return 0;
}