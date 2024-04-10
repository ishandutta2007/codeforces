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

int n, p, l[max_n], r[max_n];
long double ans;

int get(int r) {
    return r / p;
}

int get(int l, int r) {
    return get(r) - get(l - 1);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &p);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &l[i], &r[i]);
    }
    l[n] = l[0];
    r[n] = r[0];
    for (int i = 0; i < n; ++i) {
        long long c1 = get(l[i], r[i]);
        long long c2 = get(l[i + 1], r[i + 1]);
        long long l1 = r[i] - l[i] + 1;
        long long l2 = r[i + 1] - l[i + 1] + 1;
        long long c = c1 * l2 + c2 * l1 - c1 * c2;
        long double q = c;
        q /= (l1 * l2);
        ans += q;
    }
    printf("%.10f\n", (double) ans * 2000);
    return 0;
}