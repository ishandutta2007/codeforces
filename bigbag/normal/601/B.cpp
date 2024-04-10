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

int n, q, a[max_n], b[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        b[i] = abs(a[i] - a[i + 1]);
    }
    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        --l;
        --r;
        vector<int> v1, v2;
        long long ans = 0, sum = 0;
        for (int i = l; i < r; ++i) {
            while (v1.size() && b[i] >= v1.back()) {
                int b = v1.back(), i = v2.back();
                v1.pop_back();
                v2.pop_back();
                int last = l - 1;
                if (v1.size()) {
                    last = v2.back();
                }
                sum -= 1LL * (i - last) * b;
            }
            int last = l - 1;
            if (v1.size()) {
                last = v2.back();
            }
            v1.push_back(b[i]);
            v2.push_back(i);
            sum += 1LL * (v2.back() - last) * b[i];
            ans += sum;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}