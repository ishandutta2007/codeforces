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

const int max_n = 333;

int n;
char a[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
      
    while (scanf("%d\n", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                scanf("%c", &a[i][j]);
            scanf("\n");
        }
        
        bool good = true;
        char c1 = a[0][0];
        char c2 = a[0][1];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) 
                if (i == j || j == n - i - 1) {
                    if (a[i][j] != c1) {
                        good = false;
                    }
                } else {
                    if (a[i][j] != c2) {
                        good = false;
                    }
                }
        if (c1 == c2) good = false;
        printf(good == true ? "YES" : "NO");
        printf("\n");
    }
    

    return 0;
}