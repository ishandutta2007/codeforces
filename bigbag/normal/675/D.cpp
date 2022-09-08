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

int n, x;
set<int> l, r, q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &x);
    --n;
    q.insert(x);
    while (n--) {
        scanf("%d", &x);
        set<int>::iterator it = q.lower_bound(x);
        int ans = -1;
        if (it != q.end()) {
            int y = *it;
            if (!l.count(y)) {
                l.insert(y);
                ans = y;
            }
        }
        if (ans == -1) {
            --it;
            ans = *it;
            r.insert(ans);
        }
        q.insert(x);
        printf("%d ", ans);
    }
    printf("\n");
    return 0;
}