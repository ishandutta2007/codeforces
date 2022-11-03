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

const int max_n = 25;

int n, p;
int a[max_n][max_n];

int bit(int mask, int i) {
    return (mask >> i) & 1;
}

int main() {
  //  freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    
    int tests;
    scanf("%d", &tests);
    for (int test = 0; test < tests; ++test) {
        scanf("%d%d", &n, &p);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) 
                a[i][j] = 0;
        int m = 2 * n + p;
        for (int step = 1; step < n; ++step) {
            for (int i = 0; i < n; ++i)
                if (m > 0) {
                    int j = (i + step) % n;
                    if (!a[i][j]) {
                        --m;
                        a[i][j] = a[j][i] = 1;
                        printf("%d %d\n", i + 1, j + 1);
                    }
                }
        }
        /*
        bool good = true;
        for (int mask = 0; mask < (1 << n); ++mask) {
            int c = 0;
            int mc = 0;
            for (int i = 0; i < n; ++i)
                mc += bit(mask, i);
            mc *= 2;
            mc += p;
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (bit(mask, i) && bit(mask, j) && a[i][j]) {
                        ++c;
                    }
            c /= 2;
            if (c > mc) {
                good = false;
                printf("mask = ");
                for (int i = 0; i < n; ++i)
                    if (bit(mask, i)) 
                        printf("%d ", i);
                printf("\n");
                break;
            }
        }
        if (!good) {
            printf("Fail\n");
        }
        */
    }
    
    
    return 0;
}