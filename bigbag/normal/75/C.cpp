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

int a, b, n;
vector<int> d, d1, d2;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b >> n;
    for (int i = 1; i * i <= min(a, b); ++i) {
        int x = a / i, y = b / i;
        if (a % i == 0 && b % i == 0) {
            d.push_back(i);
        }
        if (a % i == 0 && a % x == 0 && b % x == 0) {
            d.push_back(x);
        }
        if (b % i == 0 && a % y == 0 && b % y == 0) {
            d.push_back(y);
        }
    }
    sort(d.begin(), d.end());
    while (n--) {
        int l, r, f = 0;
        scanf("%d%d", &l, &r);
        for (int i = d.size() - 1; i >= 0; --i) {
            if (d[i] >= l && d[i] <= r) {
                f = 1;
                printf("%d\n", d[i]);
                break;
            }
        }
        if (f == 0) {
            printf("-1\n");
        }
    }
    return 0;
}