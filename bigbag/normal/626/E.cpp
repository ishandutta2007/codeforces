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

int n, a[max_n];
long long sum[max_n];

long long get_sum(int l, int r) {
    if (l == 0) {
        return sum[r];
    }
    return sum[r] - sum[l - 1];
}

pair<long long, long long> f(int poz, int len) {
    long long s = get_sum(poz - len, poz) + get_sum(n - len, n - 1) - 1LL * (2 * len + 1) * a[poz];
    return make_pair(s, 2 * len + 1);
}

bool cmp(pair<long long, long long> p1, pair<long long, long long> p2) {
    return p1.first * p2.second < p2.first * p1.second;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    sum[0] = a[0];
    for (int i = 1; i < n; ++i) {
        sum[i] = sum[i - 1] + a[i];
    }
    int poz = -1, len;
    pair<long long, long long> ans = make_pair(0, 1);
    for (int i = 1; i + 1 < n; ++i) {
        int l = 0, r = min(i + 1, n - i);
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (cmp(f(i, mid - 1), f(i, mid))) {
                l = mid;
            } else {
                r = mid;
            }
        }
        if (cmp(ans, f(i, l))) {
            ans = f(i, l);
            poz = i;
            len = l;
        }
    }
    if (poz == -1) {
        printf("1\n%d\n", a[0]);
    } else {
        printf("%d\n", 2 * len + 1);
        for (int i = poz - len; i <= poz; ++i) {
            printf("%d ", a[i]);
        }
        for (int i = n - len; i < n; ++i) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    return 0;
}