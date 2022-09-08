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

const int max_n = 222222, inf = 1111111111;

int n, b, t[max_n], d[max_n];
long long ans[max_n];
queue<int> q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    memset(ans, -1, sizeof(ans));
    scanf("%d%d", &n, &b);
    long long x = -1;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &t[i], &d[i]);
        while (q.size()) {
            if (x <= t[i]) {
                int num = q.front();
                q.pop();
                x = max(1LL * t[num], x) + d[num];
                ans[num] = x;
            } else {
                break;
            }
        }
        if (q.size() < b) {
            q.push(i);
        }
    }
    while (q.size()) {
        int num = q.front();
        q.pop();
        x = max(1LL * t[num], x) + d[num];
        ans[num] = x;
    }
    for (int i = 0; i < n; ++i) {
        printf("%I64d ", ans[i]);
    }
    printf("\n");
    return 0;
}