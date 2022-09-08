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
long long s, sum;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%I64d", &n, &s);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    for (int i = 0; i < n; ++i) {
        long long mn = n - 1;
        int r = min((long long) a[i], s - mn);
        long long mx = sum - a[i];
        int l = max(1LL, s - mx);
        printf("%d ", a[i] - (r - l + 1));
        //printf("%d %d\n", l, r);
    }
    return 0;
}