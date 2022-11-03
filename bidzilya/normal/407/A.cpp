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

const int max_a = 1e3 + 300;

int a, b;

void calc_ans() {
    a *= a;
    b *= b;
    for (int i = -max_a; i < max_a; ++i)
        for (int j = -max_a; j < max_a; ++j)    
            if (i != 0 && j != 0 && i * i + j * j == a)
                for (int ni = -max_a; ni < max_a; ++ni)
                    for (int nj = -max_a; nj < max_a; ++nj)
                        if ((ni - i) != 0 && (nj - j) != 0 && ni * ni + nj * nj == b && ni * i + nj * j == 0) {
                            printf("YES\n");
                            printf("%d %d\n%d %d\n%d %d\n", ni, nj, 0, 0, i, j);
                            return;
                        }
    printf("NO\n");
}
    
int main() {
 //   freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

    while (scanf("%d%d", &a, &b) != EOF) {
        calc_ans();
    }
   
    return 0;
}