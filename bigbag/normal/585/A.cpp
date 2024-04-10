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

const int max_n = 4444, inf = 1111111111;

int n, v[max_n], d[max_n], p[max_n], f[max_n];
vector<int> ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &v[i], &d[i], &p[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (f[i] == 0) {
            ans.push_back(i);
            int cnt = v[i];
            for (int j = i + 1; j < n && cnt > 0; ++j) {
                if (f[j] == 0 && p[j] >= 0) {
                    p[j] -= cnt;
                    --cnt;
                }
            }
        }
        for (int j = i + 1; j < n; ++j) {
            if (f[j] == 0 && p[j] < 0) {
                f[j] = 1;
                for (int k = j + 1; k < n; ++k) {
                    p[k] -= d[j];
                    if (p[k] < 0) {
                        p[k] = -1;
                    }
                }
            }
        }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d ", ans[i] + 1);
    }
    return 0;
}