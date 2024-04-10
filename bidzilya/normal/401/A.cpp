#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int n, x, s;

int main() {
   // freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

    while (scanf("%d%d", &n, &x) != EOF) {
        s = 0;
        for (int i = 0; i < n; ++i) {
            int a;
            scanf("%d", &a);
            s += a;
        }
        s = abs(s);
        int ans = s / x + ((s % x) != 0);
        printf("%d\n", ans);
    }
    
    return 0;
}