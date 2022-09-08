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

const int max_n = 111, inf = 1111111111;

int n, m, ans, cnt;
char s[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        int sum = 0;
        for (int j = 0; j < m; ++j) {
            sum += s[j] - '0';
        }
        if (sum < m) {
            ++cnt;
        } else {
            ans = max(ans, cnt);
            cnt = 0;
        }
    }
    ans = max(ans, cnt);
    printf("%d\n", ans);
    return 0;
}