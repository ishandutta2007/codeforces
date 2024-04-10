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

long long a, b, k;
double ans = 1e18;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b;
    if (a < b) {
        printf("-1\n");
        return 0;
    }
    k = a / b;
    for (long long i = max(1LL, k - 5); i < (k + 5); ++i) {
        if (i % 2 == 1 && i * b <= a) {
            ans = min(ans, 1.0 * (a - i * b) / (i + 1));
        }
    }
    printf("%.10f\n", b + ans);
    return 0;
}