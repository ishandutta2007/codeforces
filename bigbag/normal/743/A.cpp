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

int n, a, b;
char s[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d%s", &n, &a, &b, s);
    --a;
    --b;
    int ans = inf;
    for (int i = 0; i < n; ++i) {
        if (s[i] == s[b]) {
            if (s[i] == s[a]) {
                ans = 0;
            } else {
                ans = min(ans, abs(a - i));
            }
        }
    }
    if (ans) {
        ans = 1;
    }
    printf("%d\n", ans);
    return 0;
}