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

const int max_n = 111111, inf = 1011111111;

int n, cnt, ans, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    n *= 2;
    while (n--) {
        int x;
        scanf("%d", &x);
        ++a[x];
        if (a[x] == 1) {
            ++cnt;
        } else if (a[x] == 2) {
            --cnt;
        }
        ans = max(ans, cnt);
    }
    printf("%d\n", ans);
    return 0;
}