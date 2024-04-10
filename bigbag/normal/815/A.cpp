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

const int max_n = 111, inf = 1011111111;

int n, m, a[max_n][max_n], b[max_n][max_n];
vector<pair<int, int> > v;

int solve(int n, int m, int a[max_n][max_n]) {
    v.clear();
    int b[max_n][max_n];
    pair<int, int> mn = make_pair(inf, inf);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            mn = min(mn, make_pair(a[i][j], j));
        }
    }
    int pos = mn.second;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j == pos) {
                continue;
            }
            b[i][j] = a[i][j] - a[i][pos];
            if (b[i][j] != b[0][j]) {
                return inf;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        if (i == pos) {
            continue;
        }
        for (int j = 0; j < b[0][i]; ++j) {
            v.push_back(make_pair(1, i));
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < a[i][pos]; ++j) {
            v.push_back(make_pair(0, i));
        }
    }
    return v.size();
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
            b[j][i] = a[i][j];
        }
    }
    int ans1 = solve(n, m, a);
    int ans2 = solve(m, n, b);
    int ans = min(ans1, ans2);
    if (ans == inf) {
        printf("-1\n");
        return 0;
    }
    if (ans1 == ans) {
        solve(n, m, a);
    } else {
        solve(m, n, b);
        for (int i = 0; i < v.size(); ++i) {
            v[i].first ^= 1;
        }
    }
    printf("%d\n", v.size());
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].first == 0) {
            printf("row ");
        } else {
            printf("col ");
        }
        printf("%d\n", v[i].second + 1);
    }
    return 0;
}