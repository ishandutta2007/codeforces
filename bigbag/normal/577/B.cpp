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

const int max_n = 1111, inf = 1111111111;

int n, m, a[max_n], dp[2][max_n];
vector<int> v;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        ++a[x % m];
    }
    for (int i = 0; i < m; ++i) {
        if (a[i]) {
            int x = 1;
            while (x <= a[i]) {
                a[i] -= x;
                v.push_back((x * i) % m);
                x *= 2;
            }
            if (a[i]) {
                v.push_back((a[i] * i) % m);
            }
        }
    }
    int q1 = 0, q2 = 1;
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < m; ++j) {
            dp[q2][j] = dp[q1][j];
        }
        dp[q2][v[i]] = 1;
        for (int j = 0; j < m; ++j) {
            if (dp[q1][j]) {
                dp[q2][(j + v[i]) % m] = 1;
            }
        }
        swap(q1, q2);
    }
    if (dp[q1][0]) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}