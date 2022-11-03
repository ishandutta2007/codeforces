#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int n, m;

int main() {
   // freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    
    while (scanf("%d%d", &n, &m) != EOF) {
        if (n == m + 1) {
            printf("0");
            for (int i = 1; i < n + m; ++i)
                if (i & 1) 
                    printf("1");
                else
                    printf("0");
            printf("\n");
            continue;
        }
        if (n > m) {
            printf("-1\n");
            continue;
        }
        bool good = false;
        for (int k = 0; 2 * k <= m && k <= n; ++k) {
            int on = n - k;
            int om = m - 2 * k;
            if (on == om || om == on + 1 || om == on + 2) {
                for (int i = 0; i < k; ++i)
                    printf("110");
                for (int i = 0; i < on; ++i)
                    printf("10");
                om -= on;
                for (int i = 0; i < om; ++i)
                    printf("1");
                printf("\n");
                good = true;
                break;
            }
        }
        if (!good) {
            printf("-1\n");
        }
    }

    
    return 0;
}