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

int n, k, ans;
vector<int> v;
long long a[max_n], b[max_n];

void proc() {
    for (int i = 0; i + 1 < max_n; ++i) {
        b[i + 1] += b[i] / 2;
        b[i] %= 2;
        if (b[i] < 0) {
            b[i] = 1;
            --b[i + 1];
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    ++n;
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", &a[i]);
        b[i] = a[i];
    }
    proc();
    int z = 1;
    if (b[max_n - 1] == -1) {
        memset(b, 0, sizeof(b));
        for (int i = 0; i < n; ++i) {
            b[i] = -a[i];
            z = -1;
        }
        proc();
    }
    for (int i = 0; i < max_n; ++i) {
        if (b[i] != 0) {
            v.push_back(i);
        }
    }
    if (v.size() > 1 && v.back() - v[0] > 40) {
        printf("0\n");
        return 0;
    }
    long long x = 0;
    for (int i = 0; i < v.size(); ++i) {
        x += (1LL << (v[i] - v[0]));
    }
    for (int i = v[0]; i >= 0; --i) {
        long long y = a[i];
        y -= z * x;
        if (-k <= y && y <= k) {
            ++ans;
            if (i + 1 == n && y == 0) {
                --ans;
            } else if (i >= n) {
                --ans;
            }
        }
        if (x > 111111111111LL) {
            break;
        }
        x *= 2;
    }
    printf("%d\n", ans);
    return 0;
}