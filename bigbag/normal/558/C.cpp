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

int n, x, a[max_n], cnt[max_n * 100];
vector<int> v[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0, x = 1; x < 10 * max_n; ++i, x *= 2) {
        cnt[x] = i;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        a[i] = x;
        while (x) {
            v[i].push_back(x % 2);
            x /= 2;
        }
        reverse(v[i].begin(), v[i].end());
    }
    int ans = inf;
    int x = 0;
    for (int i = 0; i < v[0].size(); ++i) {
        x = x * 2 + v[0][i];
        int X = x;
        for (int j = i; j < 20; ++j) {
            int res = v[0].size() - i - 1 + j - i, f = 0;
            for (int k = 1; k < n; ++k) {
                int y = a[k];
                while (x % y) {
                    y /= 2;
                    ++res;
                }
                res += cnt[x / y];
                if (x != y && cnt[x / y] == 0) {
                    f = 1;
                    break;
                }
            }
            x *= 2;
            if (f == 0) {
                //cout << i << " " << j << " - " << res << endl;
                ans = min(ans, res);
            }
        }
        x = X;
    }
    printf("%d\n", ans);
    return 0;
}