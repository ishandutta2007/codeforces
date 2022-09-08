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

const int max_n = 111111, inf = 1111111111;

int n, k, l, ans, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    int cnt = 0;
    while (k--) {
        scanf("%d", &l);
        for (int i = 0; i < l; ++i) {
            scanf("%d", &a[i]);
        }
        int poz = 0;
        while (poz + 1 < l && a[0] == 1 && a[poz] + 1 == a[poz + 1]) {
            ++poz;
        }
        ans += l - poz - 1;
        cnt += l - poz;
    }
    ans += cnt - 1;
    printf("%d\n", ans);
    return 0;
}