#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

const int max_n = 2e3 + 20;

int n;
int a[max_n][max_n];
int used[max_n];
vector<int> top;
int cmps;
int cmp[max_n];

void top_sort(int v) {
    used[v] = 1;
    for (int i = 0; i < n; ++i)
        if (a[v][i] && !used[i])
            top_sort(i);
    top.push_back(v);
}

void dfs(int v) {
    cmp[v] = cmps;
    for (int i = 0; i < n; ++i)
        if (a[i][v] && !cmp[i])
            dfs(i);
}

int main() {
  //  freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);

    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &a[i][j]);
        top.clear();
        for (int i = 0; i < n; ++i)
            used[i] = 0;
        for (int i = 0; i < n; ++i)
            if (!used[i])
                top_sort(i);
        reverse(top.begin(), top.end());
        cmps = 0;
        for (int i = 0; i < n; ++i)
            cmp[i] = 0;
        for (int i = 0; i < n; ++i)
            if (!cmp[top[i]]) {
                ++cmps;
                dfs(top[i]);
            }
        bool good = true;
        for (int i = 1; i < n; ++i)
            if (cmp[i] != cmp[0]) {
                good = false;
                break;
            }
        printf((good == true) ? "YES\n" : "NO\n");
    }

    return 0;
}